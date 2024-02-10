#include <iostream>
#include <vector>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
using namespace std;


class Product{
    int ID,Rate,Quantity;
    std::string Name;
    // std::vector<Product>productVector;

    public:
    Product(){}

    Product(int id,std::string n,int r, int q):ID(id),Name(n),Rate(r),Quantity(q){}

    std::tuple<int, std::string, int, int> getInfo(){

        return std::make_tuple(this->ID,this->Name,this->Rate,this->Quantity);
    }


    void setInfo(int id, std::string name, int rate, int qty){
        this->ID = id;
        this->Name = name;
        this->Rate = rate;
        this->Quantity = qty;
    }
std::vector<Product> SellDetailsVector(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
    std::vector<Product> products;
   Product p;
    for (const auto& details : detailsVector) {
        int IDValue = std::get<0>(details);
        std::string nameValue = std::get<1>(details);
        int rateValue = std::get<2>(details);
        int qtyValue = std::get<3>(details);
        
        if (p.Name == nameValue && p.quantity >= qtyValue) {
                p.quantity += qtyValue;
                std::cout << "Purchase successful. Total cost: $" << (product.price * quantity) << std::endl;
                return true;
            }
        }
        std::cout << "Product not found or insufficient quantity." << std::endl;
        return false;

        p.setInfo(IDValue,nameValue,rateValue,qtyValue);
        products.push_back(p);
    }

    return products;
}

std::vector<Product> BuyDetailsVector(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
    std::vector<Product> products;

    for (const auto& details : detailsVector) {
        int IDValue = std::get<0>(details);
        std::string nameValue = std::get<1>(details);
        int rateValue = std::get<2>(details);
        int qtyValue = std::get<3>(details);
         
        // Create Product object and add it to the vector
        products.push_back(Product(IDValue, nameValue, rateValue, qtyValue));
        return products;
    }

    
};




