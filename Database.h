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

std::tuple<int, int> getProductDetailsOnNameGiven(const std::string& name) {
        int id = -1;
        int rate = -

        try {
            sql::Statement *stmt = con->createStatement();
            sql::ResultSet *res = stmt->executeQuery("SELECT Name FROM Inventory;");

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

Product getInventoryOnName(const std::string& name) {
int id,rate,qty;
        try {
            sql::Statement *stmt = con->createStatement();
            sql::ResultSet *res = stmt->executeQuery("SELECT * FROM inventory WHERE name =\"%s\";",name);

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
        Product p(id,name,rate,qty);
        return p;
    }

// void BuyUpdateDB(Product p) {
//     sql::mysql::MySQL_Driver *driver;
//     sql::Connection *con;

//         // Check if the ID is already in the database
//         sql::Statement *check = con->createStatement();
//         std::string checkQuery = "SELECT COUNT(*) FROM Inventory WHERE ID=" + std::to_string(IDValue);
//         sql::ResultSet *result = check->executeQuery(checkQuery);
//         result->next();
//         int rowCount = result->getInt(1);
//         delete result;
//         delete check;

//         if (rowCount > 0) {
//             // Case 1: ID already in database, update the existing record
//             sql::Statement *updateStmt = con->createStatement();
//             wxString updateStr = wxString::Format("UPDATE Inventory SET Quantity=%d WHERE ID=%d;",p.getQty(),p.getID());
//             updateStmt->execute(updateStr.ToStdString());
//             delete updateStmt;
//             std::cout << "Item updated in Inventory successfully." << std::endl;
//         } else {
//             // Case 2: ID not in database, insert a new record
//             sql::Statement *insertStmt = con->createStatement();
//             wxString insertStr = wxString::Format("INSERT INTO Inventory (ID, Name, Rate, Quantity) VALUES (%d, \"%s\", %d, %d);", p.getID(), p.getName(), p.getRate(),p.getQty());
//             insertStmt->execute(insertStr.ToStdString());
//             delete insertStmt;
//             std::cout << "Item added to Inventory successfully." << std::endl;
//         }
   
// }

void BuyUpdateDB(std::vector<Product>& buyVector) {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        // Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        // con = driver->connect("192.168.1.119:3306", "pankaj", "Pankaj");
        con = driver->connect("172.16.1.145:3306", "pankaj", "Pankaj");

        // Select the SMS database
        con->setSchema("SMS");
        for (auto& product : buyVector) {
            std::tuple<int, std::string, int, int> details;
            details = product.getInfo();
            sql::Statement *check = con->createStatement();
            std::string checkQuery = "SELECT COUNT(*) FROM Inventory WHERE ID=" + std::to_string(std::get<0>(details));
            sql::ResultSet *result = check->executeQuery(checkQuery);
            result->next();
            int rowCount = result->getInt(1);
            delete result;
            delete check;

            if (rowCount > 0) {
                // Case 1: ID already in database, update the existing record
                sql::Statement *updateStmt = con->createStatement();
                wxString updateStr = wxString::Format("UPDATE Inventory SET Rate=%d, Quantity=%d WHERE ID=%d;", std::get<2>(details), std::get<3>(details), std::get<0>(details));
                updateStmt->execute(updateStr.ToStdString());
                delete updateStmt;
                std::cout << "Item updated in Inventory successfully." << std::endl;
            } else {
                // Case 2: ID not in database, insert a new record
                sql::Statement *insertStmt = con->createStatement();
                wxString insertStr = wxString::Format("INSERT INTO Inventory (ID, Name, Rate, Quantity) VALUES (%d, \"%s\", %d, %d);", std::get<0>(details), std::get<1>(details), std::get<2>(details), std::get<3>(details));
                insertStmt->execute(insertStr.ToStdString());
                delete insertStmt;
                std::cout << "Item added to Inventory successfully." << std::endl;
            }
        }

    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
        return;
    }

    // Cleanup
    delete con;
}


void updateDatabase(Product p) {
        // Update the 'Inventory' table
        sql::Statement *stmt = con->createStatement();
        wxString str = wxString::Format("UPDATE Inventory SET Rate=%d, Quantity=%d WHERE ID=%d and Name=\"%s\";", p.getRate(),p.getQty(),p.getID(),p.getName());
        stmt->execute(str.ToStdString());
        delete stmt;
}

void SellUpdateDB(std::vector<Product> products) {
            //  update the existing record
            
    for (const auto& p : products){
        sql::Statement *updateStmt = con->createStatement();
        wxString updateStr = wxString::Format("UPDATE Inventory SET Quantity=%d WHERE ID=%d;", p.getQty(), p.getID());
        updateStmt->execute(updateStr.ToStdString());
        delete updateStmt;
    }
}



















#endif