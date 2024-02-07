#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
struct Item {
    std::string name;
    int quantity,id,rate;
};

class Inventory {
private:
    std::vector<Item> items;


    void updateQuantity(int id,const std::string& name,int rate ,int quantity) {
        auto it = std::find_if(items.begin(), items.end(), [&](const Item& item) {
            return item.name == name;
        });

        if (it != items.end()) {
            it->quantity = quantity;
            it->rate = rate;
            it->id=id;
            std::cout << "Quantity updated.\n";
        } else {
            std::cout << "Item not found in inventory.\n";
        }
    }};
void updateDatabase(){
     
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        // Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        // con = driver->connect("192.168.1.119:3306", "pankaj", "Pankaj");
        con = driver->connect("172.16.6.186:3306", "pankaj", "Pankaj");
        

        // Use the 'con' connection object to perform MySQL operations

        // Select the SMS database
        con->setSchema("SMS");

        // Add an item to the 'Inventory' table
        sql::Statement *stmt = con->createStatement();
        
        stmt->execute("INSERT INTO Inventory (ID,Name, Rate,Quantity) VALUES (id,name,rate,quantity)");
        delete stmt;

        std::cout << "Item added to Inventory successfully." << std::endl;

    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
        return;
    }

    // Cleanup
    delete con;
}