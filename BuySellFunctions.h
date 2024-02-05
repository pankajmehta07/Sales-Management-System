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



std::tuple<std::string, int> getProductDetailsOnIDGiven(const int id) {
    /*
    This is a function in which the details of the product will be returned when the product ID is given as argument.
    Parameters:
    int id -> Product ID

    Returns:
    tuple -> (name and rate) of the product.
    */


    std::string name;
    int rate = 400;
    if(id==10001){
        name=="option 1";
        rate = 100;    
    }
    else if(id==10002){
        rate = 200;    
        name="option 2";
    }
    else if(id==10003){
        rate = 300;    
        name="option 3";
    }
    else if(id==10004){
        rate = 1100;    
        name="object 1";
    }
    else if(id==10005){
        rate = 1200;    
        name="object 2";
    }
    else if(id==10006){
        rate = 1300;    
        name="object 3";
    }
    else if(id==10007){
        rate = 2100;    
        name="subject 1";
    }
    else if(id==10008){
        rate = 2200;    
        name="subject 2";
    }
    else if(id==10009){
        rate = 2300;    
        name="subject 3";
    }
    return std::make_tuple(name, rate);
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

void BuyDetailsVector(const std::vector<std::tuple<int, std::string, int, int>>& detailsVector) {
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
void SearchDetails(std::string name) {
    std::cout<<name<<endl;
}