wxArrayString getNameChoices(){
    std::vector<std::string> objectList = {"Option 1","Option 2", "Option 3","Object 1","Object 2","Object 3", "Subject 1", "Subject 2", "Subject 3"};
    wxArrayString choices;
    for (const auto& obj : objectList)
        choices.Add(obj);
    return choices;
}