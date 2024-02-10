#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h> 
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
std::vector<Product> showItemDetails(const std::string& itemName) {
    std::vector<Product> products;
    try {
        connectToDatabase();
        wxString updateStr = wxString::Format("SELECT * FROM Inventory WHERE Name LIKE '%%%s%%'", itemName);
        sql::PreparedStatement *stmt = con->prepareStatement(updateStr.ToStdString());
       sql::ResultSet *res = stmt->executeQuery();

        // Display the details
        while (res->next()) {
            // std::cout << "ID: " << res->getInt(1) << std::endl;
            // std::cout << "Name: " << res->getString(2) << std::endl;
            // std::cout << "Rate: " << res->getInt(3) << std::endl;
            // std::cout << "Quantity: " << res->getInt(4) << std::endl;
            Product p(res->getInt(1),res->getString(2),res->getInt(3),res->getInt(4));
            products.push_back(p);

        }

        delete res;
        delete stmt;



    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
        // return ;
    }

    // std::cout<<"Show Items Details";
    return products;

}
