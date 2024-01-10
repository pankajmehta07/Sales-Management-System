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


    int id = 4200;
    int rate = 100;
    if(name=="option 1"){
        rate = 100;    
        id = 4100;
    }
    else if(name=="option 2"){
        rate = 200;    
        id = 4200;
    }
    else if(name=="option 3"){
        rate = 300;    
        id = 4300;
    }
    else if(name=="object 1"){
        rate = 1100;    
        id = 5100;
    }
    else if(name=="object 2"){
        rate = 1200;    
        id = 5200;
    }
    else if(name=="object 3"){
        rate = 1300;    
        id = 5300;
    }
    else if(name=="subject 1"){
        rate = 2100;    
        id = 6100;
    }
    else if(name=="subject 2"){
        rate = 2200;    
        id = 6200;
    }
    else if(name=="subject 3"){
        rate = 2300;    
        id = 6300;
    }
    return std::make_tuple(id, rate);
}

