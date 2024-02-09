
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
};
