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

    int getQty(){
        return this->Quantity;
    }

    void setQty(int q){
        this->Quantity = q;
    }

    int getID(){
        return this->ID;
    }

    std::string getName(){
        return this->Name;
    }

    int getRate(){
        return this->Rate;
    }


    std::tuple<int, std::string, int, int> getInfo(){

        return std::make_tuple(this->ID,this->Name,this->Rate,this->Quantity);
    }


    void setInfo(int id, std::string name, int rate, int qty){
        this->ID = id;
        this->Name = name;
        this->Rate = rate;
        this->Quantity = qty;
    }
std::tuple<bool,std::string>SellDetailsVector(const std::vector<Product>& detailsVector) {
    std::vector<Product> products;
   Product p;
    for (const auto& product : detailsVector) {
        
        p.getInventoryOnName(product.getName());
        int finalQty = p.getQty();
        if (finalQty >= product.getQty()) {
            finalQty -= product.getQty() ;
            product.setQty(finalQty);
            }
        else{return make_tuple(false,"Insufficient quantity of"+p.getName());}
    }
    return make_tuple(true,"Transaction Successful.");
    
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
}
    
};





