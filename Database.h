#ifndef DATABASE_FRAME
#define DATABASE_FRAME
#include"Product.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/sqlstring.h>
#include <cppconn/prepared_statement.h> 
#include "txndetails.h"

sql::mysql::MySQL_Driver *driver;
sql::Connection *con;
void connectToDatabase(){
    try{
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("127.00.0.1", "username", "password");
        con->setSchema("SMS");
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
}

wxArrayString getNameChoices() {
    wxArrayString choices;
    try {
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT Name FROM Inventory;");
        while (res->next()) {
            choices.Add(wxString(res->getString(1)));
        }

        delete res;
        delete stmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }
    return choices;
}

Product getInventoryOnName(std::string name) {
        int id,rate,qty;
        connectToDatabase();
        try {

            sql::Statement *stmt = con->createStatement();

            sql::SQLString query = "SELECT * FROM Inventory WHERE name = '" + name + "'";

            sql::ResultSet *res = stmt->executeQuery(query);
            if (res->next()) {
                id = res->getInt(1);
                rate = res->getInt(3);
                qty = res->getInt(4);
            }

            delete res;
            delete stmt;
        } catch (sql::SQLException &e) {
            std::cerr << "SQLException: " << e.what() << std::endl;
        }
        Product p(id,name,rate,qty);
        return p;
    }

void BuyUpdateDB(std::vector<Product>& buyVector) {
    try {
        int total=0;
        for (auto& product : buyVector) {
            connectToDatabase();
            sql::Statement *check = con->createStatement();
            total += product.getRate()*product.getQty();
            std::string checkQuery = "SELECT COUNT(*) FROM Inventory WHERE ID=" + std::to_string(product.getID())+" and Name=\""+product.getName()+"\";";
            sql::ResultSet *result = check->executeQuery(checkQuery);
            result->next();
            int rowCount = result->getInt(1);
            delete result;
            delete check;

            if (rowCount > 0) {
                // Case 1: ID already in database, update the existing record
                sql::Statement *updateStmt = con->createStatement();
                Product p = getInventoryOnName(product.getName());
                wxString updateStr = wxString::Format("UPDATE Inventory SET Quantity=%d WHERE ID=%d and Name=\"%s\";", p.getQty()+product.getQty(), p.getID(),p.getName());
                updateStmt->execute(updateStr.ToStdString());
                delete updateStmt;
            } else {
                // Case 2: ID not in database, insert a new record
                sql::Statement *insertStmt = con->createStatement();
                std::string insertStr ="INSERT INTO Inventory (ID, Name, Rate, Quantity) VALUES ("+ std::to_string(product.getID())+",'"+ product.getName()+"',"+std::to_string(product.getRate())+","+std::to_string(product.getQty())+");";
                insertStmt->execute(insertStr);
                delete insertStmt;
            }
        }
        Transaction t(" Purchase ",total);
        t.writeToFile();

    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
        return;
    }
}


void updateDatabase(Product p) {
        // Update the 'Inventory' table
        connectToDatabase();
        sql::Statement *stmt = con->createStatement();
        wxString str = wxString::Format("UPDATE Inventory SET Rate=%d, Quantity=%d WHERE ID=%d and Name=\"%s\";", p.getRate(),p.getQty(),p.getID(),p.getName());
        stmt->execute(str.ToStdString());
        delete stmt;
}
std::tuple<bool,std::string>SellDetailsVector(std::vector<Product>& detailsVector) {
    Product p;
    for (auto& product : detailsVector) {
        
        p = getInventoryOnName(product.getName());
        int finalQty = p.getQty();
        if (finalQty >= product.getQty()) {
            finalQty -= product.getQty() ;
            product.setQty(finalQty);
        }
        else{
            return make_tuple(false,"Insufficient quantity of "+p.getName());
        }
    }
    SellUpdateDB(detailsVector);
    return make_tuple(true,"Transaction Successful."); 
}
void SellUpdateDB(std::vector<Product> products) {
    //  update the existing record
    int total=0;        
    for (auto& p : products){
        connectToDatabase();
        sql::Statement *updateStmt = con->createStatement();
        Product product = getInventoryOnName(p.getName());
        total += p.getRate()*(product.getQty()-p.getQty());
        wxString updateStr = wxString::Format("UPDATE Inventory SET Quantity=%d WHERE ID=%d and Name=\"%s\";", p.getQty(), p.getID(),p.getName());
        updateStmt->execute(updateStr.ToStdString());
        delete updateStmt;
    }
    Transaction t("   Sale   ",total);
    t.writeToFile(); 
}
std::vector<Product> SearchDetails(const std::string& itemName) {
    std::vector<Product> products;
    try {
        connectToDatabase();
        wxString updateStr = wxString::Format("SELECT * FROM Inventory WHERE Name LIKE '%%%s%%'", itemName);
        sql::PreparedStatement *stmt = con->prepareStatement(updateStr.ToStdString());
        sql::ResultSet *res = stmt->executeQuery();
        while (res->next()) {
            Product p(res->getInt(1),res->getString(2),res->getInt(3),res->getInt(4));
            products.push_back(p);

        }

        delete res;
        delete stmt;



    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
    }
    return products;

}
#endif