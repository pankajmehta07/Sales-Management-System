#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include"Product.h"

std::vector<std::tuple<int, std::string, int, int>> SearchDetails(std::string name) {
    std::cout<<name<<std::endl;
    std::vector<std::tuple<int, std::string, int, int>> vector1;
    // std::tuple<int, std::string, int, int> tuple1;
    vector1.push_back(std::make_tuple(100001, "option 1",100,150));
    vector1.push_back(std::make_tuple(100002, "option 2",200,250));
    vector1.push_back(std::make_tuple(100003, "option 3",300,350));
    return vector1;
}
// void showItemDetails(const std::string& itemName) {
    // sql::mysql::MySQL_Driver *driver;
    // sql::Connection *con;

    // try {
    //     // Create a connection
    //     driver = sql::mysql::get_mysql_driver_instance();
    //     // con = driver->connect("172.16.1.145:3306", "pankaj", "Pankaj");
    //     con = driver->connect("192.168.1.119:3306", "pankaj", "Pankaj");

    //     // Select the SMS database
    //     con->setSchema("SMS");
    //     // "%"

    //     // Retrieve details from the 'Inventory' table based on the item name
    //     wxString updateStr = wxString::Format("SELECT * FROM Inventory WHERE Name LIKE \"%%s%\"",itemName);
    //     sql::PreparedStatement *stmt = con->prepareStatement(updateStr.ToStdString());
    //     stmt->setString(1, itemName);

    //     sql::ResultSet *res = stmt->executeQuery();

    //     // Display the details
    //     while (res->next()) {
    //         std::cout << "ID: " << res->getInt("ID") << std::endl;
    //         std::cout << "Name: " << res->getString("Name") << std::endl;
    //         std::cout << "Rate: " << res->getInt("Rate") << std::endl;
    //         std::cout << "Quantity: " << res->getInt("Quantity") << std::endl;
    //     }

    //     delete res;
    //     delete stmt;

    // } catch (sql::SQLException &e) {
    //     std::cerr << "MySQL error: " << e.what() << std::endl;
    //     return;
    // }

    // // Cleanup
    // delete con;
    // std::cout<<"Show Items Details";

// }
