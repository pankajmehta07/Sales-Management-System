#ifndef PRODUCT_FRAME
#define PRODUCT_FRAME
#include <iostream>
#include <vector>
#include"declarations.h"

using namespace std;
class Product{
    int ID,Rate,Quantity;
    std::string Name;

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
    
     
};



#endif

