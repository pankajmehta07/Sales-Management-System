#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>

wxArrayString getNameChoices(){
    std::vector<std::string> objectList = {"Option 1","Option 2", "Option 3","Object 1","Object 2","Object 3", "Subject 1", "Subject 2", "Subject 3"};
    wxArrayString choices;
    for (const auto& obj : objectList)
        choices.Add(obj);
    return choices;
}

std::tuple<int, int> getProductDetailsOnNameGiven(const std::string& name) {
    /*
    This is a function in which the details of the product will be returned when the product name is given as argument.
    Parameters:
    string name -> Product name

    Returns:
    tuple -> (id and rate) of the product.
    */


    int id = 10000;
    int rate = 400;
    if(name=="option 1"){
        rate = 100;    
        id = 10001;
    }
    else if(name=="option 2"){
        rate = 200;    
        id = 10002;
    }
    else if(name=="option 3"){
        rate = 300;    
        id = 10003;
    }
    else if(name=="object 1"){
        rate = 1100;    
        id = 10004;
    }
    else if(name=="object 2"){
        rate = 1200;    
        id = 10005;
    }
    else if(name=="object 3"){
        rate = 1300;    
        id = 10006;
    }
    else if(name=="subject 1"){
        rate = 2100;    
        id = 10007;
    }
    else if(name=="subject 2"){
        rate = 2200;    
        id = 10008;
    }
    else if(name=="subject 3"){
        rate = 2300;    
        id = 10009;
    }
    return std::make_tuple(id, rate);
}


wxArrayString getIDChoices(){
    std::vector<std::string> objectList = {"10001","10002", "10003","10004","10005","10006", "10007", "10008", "10009"};
    wxArrayString choices;
    for (const auto& obj : objectList)
        choices.Add(obj);
    return choices;
}



std::tuple<int, int,int > getInventoryonName(const std::string& name) {
    /*
    This is a function in which the details of the product will be returned when the product ID is given as argument.
    Parameters:
    int id -> Product ID

    Returns:
    tuple -> (name and rate) of the product.
    */



    int id = 10000;
    int qty = 10;
    int rate = 400;
    if(name=="option 1"){
        rate = 100;    
        id = 10001;
        qty = 12;
    }
    else if(name=="option 2"){
        rate = 200;    
        id = 10002;
        qty = 1223;
    }
    else if(name=="option 3"){
        rate = 300;    
        id = 10003;
        qty = 124;
    }
    else if(name=="object 1"){
        rate = 1100;    
        id = 10004;
        qty = 13;
    }
    else if(name=="object 2"){
        rate = 1200;    
        id = 10005;
        qty = 13;
    }
    else if(name=="object 3"){
        rate = 1300;    
        id = 10006;
        qty = 154;
    }
    else if(name=="subject 1"){
        rate = 2100;    
        id = 10007;
        qty = 165;
    }
    else if(name=="subject 2"){
        rate = 2200;    
        id = 10008;
        qty = 1243;
    }
    else if(name=="subject 3"){
        rate = 2300;    
        id = 10009;
        qty = 124;
    }
    return std::make_tuple(id, rate,qty);
}


void SellDetailsVector(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
    for (const auto& details : detailsVector) {
        int IDValue = std::get<0>(details);
        std::string nameValue = std::get<1>(details);
        int rateValue = std::get<2>(details);
        int qtyValue = std::get<3>(details);

        // Process the details or print them
        std::cout << "ID: " << IDValue << "\tName: " << nameValue
                  << "\tRate: " << rateValue << "\tQuantity: " << qtyValue << std::endl;
    }
}
void BuyUpdateDB();
void BuyDetailsVector(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
    for (const auto& details : detailsVector) {
        int IDValue = std::get<0>(details);
        std::string nameValue = std::get<1>(details);
        int rateValue = std::get<2>(details);
        int qtyValue = std::get<3>(details);

        // Process the details or print them
        std::cout << "ID: " << IDValue << "\tName: " << nameValue
                  << "\tRate: " << rateValue << "\tQuantity: " << qtyValue << std::endl;
    BuyUpdateDB();
    }

}
std::vector<std::tuple<int, std::string, int, int>> SearchDetails(std::string name) {
    std::cout<<name<<std::endl;
    std::vector<std::tuple<int, std::string, int, int>> vector1;
    // std::tuple<int, std::string, int, int> tuple1;
    vector1.push_back(std::make_tuple(100001, "option 1",100,150));
    vector1.push_back(std::make_tuple(100002, "option 2",200,250));
    vector1.push_back(std::make_tuple(100003, "option 3",300,350));
    return vector1;
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        // Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        // con = driver->connect("192.168.1.119:3306", "pankaj", "Pankaj");
        con = driver->connect("172.16.1.145:3306", "pankaj", "Pankaj");
        

        // Use the 'con' connection object to perform MySQL operations

        // Select the SMS database
        con->setSchema("SMS");

        // Add an item to the 'Inventory' table
        sql::Statement *stmt = con->createStatement();
        wxString str = wxString::Format("SELECT *FROM Inventory WHERE IName=\"%s\";" ,nameValue);
        // wxString str = wxString::Format("INSERT INTO Inventory (ID,Name, Rate,Quantity) VALUES (%d,\"%s\",%d,%d)", IDValue,nameValue,rateValue,qtyValue);
     
        stmt->execute(str.ToStdString());
        delete stmt;

        std::cout << "Item added to Inventory successfully." << std::endl;

    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
        return;
    }

    // Cleanup
    delete con;
}


void updateDatabase();
void ModifyDetails(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
    for (const auto& details : detailsVector) {
        int IDValue = std::get<0>(details);
        std::string nameValue = std::get<1>(details);
        int rateValue = std::get<2>(details);
        int qtyValue = std::get<3>(details);

        // Process the details or print them
        std::cout << "ID: " << IDValue << "\tName: " << nameValue
                  << "\tRate: " << rateValue << "\tQuantity: " << qtyValue << std::endl;
    }
    updateDatabase();
}
void updateDatabase(){
     
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        // Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        // con = driver->connect("192.168.1.119:3306", "pankaj", "Pankaj");
        con = driver->connect("172.16.1.145:3306", "pankaj", "Pankaj");
        

        // Use the 'con' connection object to perform MySQL operations

        // Select the SMS database
        con->setSchema("SMS");

        // Add an item to the 'Inventory' table
        sql::Statement *stmt = con->createStatement();
        int IDValue = 12421;
        std::string nameValue = "Bottle";
        int rateValue = 1300;
        int qtyValue = 25;
        wxString str = wxString::Format("UPDATE Inventory SET Rate=%d, Quantity=%d WHERE ID=%d and Name=\"%s\";", rateValue,qtyValue,IDValue,nameValue);
        // wxString str = wxString::Format("INSERT INTO Inventory (ID,Name, Rate,Quantity) VALUES (%d,\"%s\",%d,%d)", IDValue,nameValue,rateValue,qtyValue);
     
        stmt->execute(str.ToStdString());
        delete stmt;

        std::cout << "Item added to Inventory successfully." << std::endl;

    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
        return;
    }

    // Cleanup
    delete con;
}
void BuyUpdateDB() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        int IDValue = 29390;
            std::string nameValue = "Rohan";
            int rateValue = 1000;
            int qtyValue = 5;
        // Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("172.16.1.145:3306", "pankaj", "Pankaj");

        // Select the SMS database
        con->setSchema("SMS");

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

    } catch (sql::SQLException &e) {
        std::cerr << "MySQL error: " << e.what() << std::endl;
        return;
    }

    // Cleanup
    delete con;
}


// NOTE:
// Get last row of the table
// SELECT * FROM Inventory ORDER BY ID DESC LIMIT 1;