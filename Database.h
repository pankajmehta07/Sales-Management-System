#ifndef DATABASE_FRAME
#define DATABASE_FRAME
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <tuple>

sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("172.16.1.145:3306", "pankaj", "Pankaj");
            con->setSchema(SMS);
        } catch (sql::SQLException &e) {
            std::cerr << "SQLException: " << e.what() << std::endl;
        }

    wxArrayString getChoicesFromDatabase(const std::string& query) {
        wxArrayString choices;
        try {
            sql::Statement *stmt = con->createStatement();
            sql::ResultSet *res = stmt->executeQuery(query);

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

std::tuple<int, int> getProductDetailsOnNameGiven(const std::string& name) {
        int id = -1;
        int rate = -1;

        try {
            sql::Statement *stmt = con->createStatement();
            sql::ResultSet *res = stmt->executeQuery("SELECT *FROM Inventory WHERE Name=\"%s\";" ,name);

            if (res->next()) {
                id = res->getInt(1);
                rate = res->getInt(2);
            }

            delete res;
            delete stmt;
        } catch (sql::SQLException &e) {
            std::cerr << "SQLException: " << e.what() << std::endl;
        }

        return std::make_tuple(id, rate);
    }

std::tuple<int, int, int> getInventoryOnName(const std::string& name) {
        int id = -1;
        int rate = -1;
        int qty = -1;

        try {
            sql::Statement *stmt = con->createStatement();
            sql::ResultSet *res = stmt->executeQuery("SELECT * FROM inventory WHERE name =\"%s"\";",name);

            if (res->next()) {
                id = res->getInt(1);
                rate = res->getInt(2);
                qty = res->getInt(3);
            }

            // delete res;
            // delete stmt;
        } catch (sql::SQLException &e) {
            std::cerr << "SQLException: " << e.what() << std::endl;
        }

        return std::make_tuple(id, rate, qty);
    }

void BuyUpdateDB(int IDValue, const std::string& nameValue, int rateValue, int qtyValue) {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

        // Check if the ID is already in the database
        sql::Statement *check = con->createStatement();
        std::string checkQuery = "SELECT COUNT(*) FROM Inventory WHERE ID=" + std::to_string(IDValue);
        sql::ResultSet *result = check->executeQuery(checkQuery);
        result->next();
        int rowCount = result->getInt(1);
        delete result;
        delete check;

        if (rowCount > 0) {
            // Case 1: ID already in database, update the existing record
            sql::Statement *updateStmt = con->createStatement();
            wxString updateStr = wxString::Format("UPDATE Inventory SET Rate=%d, Quantity=%d WHERE ID=%d;", rateValue, qtyValue, IDValue);
            updateStmt->execute(updateStr.ToStdString());
            delete updateStmt;
            std::cout << "Item updated in Inventory successfully." << std::endl;
        } else {
            // Case 2: ID not in database, insert a new record
            sql::Statement *insertStmt = con->createStatement();
            wxString insertStr = wxString::Format("INSERT INTO Inventory (ID, Name, Rate, Quantity) VALUES (%d, \"%s\", %d, %d);", IDValue, nameValue, rateValue, qtyValue);
            insertStmt->execute(insertStr.ToStdString());
            delete insertStmt;
            std::cout << "Item added to Inventory successfully." << std::endl;
        }
   
}


void updateDatabase(int IDValue, const std::string& nameValue, int rateValue, int qtyValue) {
    

        // Update the 'Inventory' table
        sql::Statement *stmt = con->createStatement();
        wxString str = wxString::Format("UPDATE Inventory SET Rate=%d, Quantity=%d WHERE ID=%d and Name=\"%s\";", rateValue,qtyValue,IDValue,nameValue);
        stmt->execute(str.ToStdString());
        delete stmt;

        std::cout << "Item updated in Inventory successfully." << std::endl;

}




















#endif