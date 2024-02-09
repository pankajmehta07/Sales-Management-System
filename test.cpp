#include <iostream>
#include <vector>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
using namespace std;

class Product{
    int ID,Rate,Quantity;
    std::string Name;
    std::vector<Product>productVector;
}
public:
Product(){}

Product(int id,std::string n,int r, int q):ID(i),Name(n),Rate(r),Quantity(q){}

std::tuple<int, std::string, int, int> getInfo()
for (const auto& product : productVector){
    int id= this->ID;
    std::string name= this->Name;
    int rate= this->Rate;
    int quantity= this->Quantity;

    return std::make_tuple(id,name,rate,qty);

}

std::tuple<int, std::string, int, int> GetInfo()
for (const auto& product : productVector){
    int id= this->ID;
    std::string name= this->Name;
    int rate= this->Rate;
    int quantity= this->Quantity;

    return std::make_tuple(id,name,rate,qty);

}

Product setInfo (std::tuple<int, std::string, int, int> details){
     this->ID = std::get<0>(details);
     this->Name = std::get<1>(details);
     this->Rate = std::get<2>(details);
     this->Quantity = std::get<3>(details);
}


