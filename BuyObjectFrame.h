
#ifndef BUY_OBJECT_FRAME
#define BUY_OBJECT_FRAME
#include"MenuFrame.h"

class BuyObjectFrame : public wxFrame{
    public:
        BuyObjectFrame(const wxString& title,const wxPoint& pos,const wxSize& size);
    
    private:
    wxPanel* MenuPanel;
    wxBoxSizer* MenuPanelSizer;
    wxTextCtrl* textCtrl;
    int count=1, nameid, rateid, qtyid;
    wxArrayString choices = getNameChoices();
    int ids = wxID_HIGHEST+1;
    std::vector<std::array<int, 4>> IDVectors;


    // Menu Click 
        void OnQuit(wxCommandEvent& event);
        void OnHello(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void onClose(wxCloseEvent& event);
        // Buttons Click 
        void AddItem(wxPanel*,wxBoxSizer*,MyScrolledWindow*,wxBoxSizer*);
        void SearchButtonClick(wxCommandEvent& event);
        void ConfirmDetails(wxCommandEvent& event);
        void MenuButtonClick(wxFrame*);
        void OnNameEntered(wxCommandEvent& event,wxComboBox*,wxTextCtrl*,wxTextCtrl*,wxTextCtrl*);
        void OnIDEntered(wxCommandEvent& event,wxTextCtrl*);
        wxDECLARE_EVENT_TABLE();
};


wxBEGIN_EVENT_TABLE(BuyObjectFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, BuyObjectFrame::OnAbout)
    EVT_MENU(add::wxID_HELLO, BuyObjectFrame::OnHello)
    EVT_MENU(wxID_EXIT, BuyObjectFrame::OnQuit)
    EVT_CLOSE(BuyObjectFrame::onClose)
    EVT_BUTTON(add::searchButtonId,BuyObjectFrame::SearchButtonClick)
wxEND_EVENT_TABLE();




BuyObjectFrame::BuyObjectFrame(const wxString& title,const wxPoint& pos,const wxSize& size):wxFrame(NULL,wxID_ANY,title,pos,size){
    SetMinSize(wxSize(750,540));
    
    wxMenu *menuFile = new wxMenu;
    wxBitmap searchIcon = wxArtProvider::GetBitmap(wxART_FIND, wxART_MENU);
    wxMenuItem* searchMenuItem = new wxMenuItem(menuFile, wxID_ANY, "Search");
    searchMenuItem->SetBitmap(searchIcon);
    wxAcceleratorEntry accel(wxACCEL_CTRL, 'F', wxID_ANY);
    searchMenuItem->SetAccel(&accel);
    Bind(wxEVT_MENU, &BuyObjectFrame::SearchButtonClick, this, searchMenuItem->GetId());
    menuFile->Append(searchMenuItem);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    // Menu Contents

    wxBoxSizer* MainSizer = new wxBoxSizer(wxVERTICAL);

    wxPanel* SellerPanel = new wxPanel(this,wxID_ANY);
    MainSizer->Add(SellerPanel,0,wxEXPAND|wxALL);

    wxBoxSizer* SellerPanelSizer=new wxBoxSizer(wxVERTICAL);
    SellerPanel->SetSizer(SellerPanelSizer);


    wxStaticText* SellerName = new wxStaticText(SellerPanel,wxID_ANY,wxT("All in One Store"));
    wxFont font1(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    SellerName->SetFont(font1);
    SellerPanelSizer->Add(SellerName,1,wxALIGN_CENTER|wxALL,0);
    wxStaticText* SellerAddress1 = new wxStaticText(SellerPanel,wxID_ANY,wxT("Thapathali, Kathmandu-11, Kathmandu"));
    wxFont font2(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
    SellerAddress1->SetFont(font2);
    SellerPanelSizer->Add(SellerAddress1,1,wxALIGN_CENTER|wxALL,0);
    wxStaticText* SellerAddress2 = new wxStaticText(SellerPanel,wxID_ANY,wxT("Bagmati,Nepal"));
    SellerAddress2->SetFont(font2);
    SellerPanelSizer->Add(SellerAddress2,1,wxALIGN_CENTER|wxALL,0);
    wxStaticText* SellerPhoneNumber = new wxStaticText(SellerPanel,wxID_ANY,wxT("Tel: 01-6898964"));
    wxFont font3(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
    SellerPhoneNumber->SetFont(font3);
    SellerPanelSizer->Add(SellerPhoneNumber,1,wxALIGN_CENTER|wxALL,0);

    wxStaticLine* separatorLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    wxColour separatorColour(150,150,150);
    separatorLine->SetForegroundColour(separatorColour);
    separatorLine->SetBackgroundColour(separatorColour);
    separatorLine->SetSize(wxDefaultCoord, wxDefaultCoord, wxDefaultCoord, 2);
    MainSizer->Add(separatorLine, 0, wxEXPAND | wxALL, 3);
    
    MyScrolledWindow* MenuPanel = new MyScrolledWindow(this,wxID_ANY);
    MainSizer->Add(MenuPanel,1,wxEXPAND);
    wxBoxSizer* MenuPanelSizer = new wxBoxSizer(wxVERTICAL);
    MenuPanel->SetSizer(MenuPanelSizer);

    wxPanel* TopicPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(TopicPanel,0,wxEXPAND);
    wxBoxSizer* TopicPanelSizer = new wxBoxSizer(wxVERTICAL);
    TopicPanel->SetSizer(TopicPanelSizer);
    TopicPanelSizer->Add(0,20);
    wxStaticText* topic = new wxStaticText(TopicPanel,wxID_ANY,wxT("Buy Items"));
    wxFont topicFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
    topic->SetFont(topicFont);
    TopicPanelSizer->Add(topic,1,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,5);
    TopicPanelSizer->Add(0,20);

    wxPanel* contentPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(contentPanel,1,wxEXPAND);
    wxBoxSizer* contentPanelSizer = new wxBoxSizer(wxVERTICAL);
    contentPanel->SetSizer(contentPanelSizer);

    wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
    ContentSizer->Add(20,0);
    wxStaticText* text= new wxStaticText(contentPanel,wxID_ANY,wxT("ID"), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
    text->SetFont(font2);
    ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
    ContentSizer->AddStretchSpacer();
    text = new wxStaticText(contentPanel,wxID_ANY,wxT("Product Name"), wxDefaultPosition, wxSize(350, 18), wxALIGN_CENTER);
    text->SetFont(font2);
    ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
    ContentSizer->AddStretchSpacer();
    text = new wxStaticText(contentPanel,wxID_ANY,wxT("Rate"), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
    text->SetFont(font2);
    ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
    ContentSizer->AddStretchSpacer();
    text = new wxStaticText(contentPanel,wxID_ANY,wxT("Quantity"), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
    text->SetFont(font2);
    ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
    ContentSizer->Add(20,0);    

    contentPanelSizer->Add(ContentSizer, 0, wxEXPAND | wxALL,5);

     for (int i = 0; i < 2; ++i)
    {   
        std::array<int, 4> id;
        id[0] = ids;
        ids++;
        id[1] = ids;
        ids++;
        id[2] = ids;
        ids++;
        id[3] = ids;
        ids++;
        IDVectors.push_back(id);
        wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
        wxTextCtrl* IDTextCtrl = new wxTextCtrl(contentPanel,id[0],wxEmptyString, wxDefaultPosition,  wxSize(100,35), 0,wxTextValidator(wxFILTER_DIGITS));
        IDTextCtrl->SetHint("ID");
        ContentSizer->Add(IDTextCtrl,0,wxEXPAND|wxALL,5);
        IDTextCtrl->Bind(wxEVT_TEXT, [this,IDTextCtrl](wxCommandEvent& event) {
            OnIDEntered(event,IDTextCtrl);
        });
        ContentSizer->AddStretchSpacer();
        
        wxComboBox* comboBox = new wxComboBox(contentPanel, id[1], wxEmptyString, wxDefaultPosition, wxSize(350,35), choices, wxCB_DROPDOWN);
        comboBox->SetHint("Name");
        ContentSizer->Add(comboBox,0,wxEXPAND|wxALL,5);
        ContentSizer->AddStretchSpacer();
        wxTextCtrl* RateTextCtrl = new wxTextCtrl(contentPanel,id[2],wxEmptyString, wxDefaultPosition, wxSize(100,35), 0,wxTextValidator(wxFILTER_DIGITS));
        RateTextCtrl->SetHint("Rate");
        ContentSizer->Add(RateTextCtrl,0,wxEXPAND|wxALL,5);
        ContentSizer->AddStretchSpacer();
        wxTextCtrl* QuantityTextCtrl = new wxTextCtrl(contentPanel,id[3],wxEmptyString, wxDefaultPosition,  wxSize(100,35), 0,wxTextValidator(wxFILTER_DIGITS));
        QuantityTextCtrl->SetHint("Qty:");
        ContentSizer->Add(QuantityTextCtrl,0,wxEXPAND|wxALL,5);
        
        
        comboBox->Bind(wxEVT_TEXT, [this, comboBox,IDTextCtrl,RateTextCtrl,QuantityTextCtrl](wxCommandEvent& event) {
        OnNameEntered(event,comboBox,IDTextCtrl,RateTextCtrl,QuantityTextCtrl);
        });
       

        contentPanelSizer->Add(ContentSizer, 0, wxEXPAND | wxRIGHT|wxLEFT, 20);
        count++;
    }


    wxPanel* AddItemPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(AddItemPanel,0,wxEXPAND|wxALL,10);
    wxBoxSizer* AddItemSizer=new wxBoxSizer(wxHORIZONTAL);
    AddItemPanel->SetSizer(AddItemSizer);
    wxButton* MenuButton = new wxButton(AddItemPanel,add::menuButtonId,"Main Menu");
    AddItemSizer->Add(MenuButton,0,wxALIGN_LEFT|wxLEFT,20);
    AddItemSizer->AddStretchSpacer();
    wxButton* ShowItemButton = new wxButton(AddItemPanel,add::AddItemId,"Order");
    AddItemSizer->Add(ShowItemButton,0,wxCENTER,20);
    AddItemSizer->AddStretchSpacer();
    wxButton* AddItemButton = new wxButton(AddItemPanel,add::AddItemId,"Add Item");
    AddItemSizer->Add(AddItemButton,0,wxRIGHT,20);

    AddItemButton->Bind(wxEVT_BUTTON, [this, contentPanel,contentPanelSizer,MenuPanel,MenuPanelSizer](wxCommandEvent& event) {
            AddItem(contentPanel,contentPanelSizer,MenuPanel,MenuPanelSizer);
    });
    ShowItemButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            ConfirmDetails(event);
    });
    MenuButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            MenuButtonClick(this);
    });




    Centre();
    SetSizer(MainSizer);


    CreateStatusBar();
    SetStatusText(wxT("Status Bar"));
}


void BuyObjectFrame::OnHello(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Welcome to the Sales Management Software"));
    wxMessageBox(msg, wxT("Package"), wxOK | wxICON_INFORMATION, this);
    PushStatusText(msg);
    wxSleep(2);
    PopStatusText();
}

void BuyObjectFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("This is the Sales Management Software"));
    wxMessageBox(msg, wxT("About Package"), wxOK | wxICON_INFORMATION, this);
}

void BuyObjectFrame::OnQuit(wxCommandEvent& event)
{
    bool veto = Close();
}

void BuyObjectFrame::onClose(wxCloseEvent& event){
    if(event.CanVeto()){
        int answer = wxMessageBox(_("Do you want to exit"), _("Confirm?"),wxICON_QUESTION | wxYES_NO);
        if(answer!=wxYES){
            event.Veto();
            return;
        }
    }
    // delete con;
    Destroy();
}


//Buttons Click:
void BuyObjectFrame::SearchButtonClick(wxCommandEvent& event){
    SearchObjectFrame* addFrame = new SearchObjectFrame(wxT("Byapar"),this->GetPosition(),wxSize(this->GetSize().GetWidth(),this->GetSize().GetHeight()));
    addFrame->Show(true);
    this->Close(true);
}


void BuyObjectFrame::MenuButtonClick(wxFrame* frame){
    MenuFrame* addframe = new MenuFrame(wxT("Byapar"),frame->GetPosition(),wxSize(frame->GetSize().GetWidth(),frame->GetSize().GetHeight()));
    addframe->Show(true);
    this->Close(true);
}
void BuyObjectFrame::AddItem(wxPanel* panel,wxBoxSizer* panelSizer,MyScrolledWindow* parentPanel,wxBoxSizer* parentSizer){
    std::array<int, 4> id;
    id[0] = ids;
    ids++;
    id[1] = ids;
    ids++;
    id[2] = ids;
    ids++;
    id[3] = ids;
    ids++;
    IDVectors.push_back(id);
    wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
    wxTextCtrl* IDTextCtrl = new wxTextCtrl(panel,id[0],wxEmptyString, wxDefaultPosition,  wxSize(100,35), 0,wxTextValidator(wxFILTER_DIGITS));
    IDTextCtrl->SetHint("ID");
    ContentSizer->Add(IDTextCtrl,0,wxEXPAND|wxALL,5);
    IDTextCtrl->Bind(wxEVT_TEXT, [this,IDTextCtrl](wxCommandEvent& event) {
            OnIDEntered(event,IDTextCtrl);
        });


    ContentSizer->AddStretchSpacer();
    ids++;

    wxComboBox* comboBox = new wxComboBox(panel, id[1], wxEmptyString, wxDefaultPosition, wxSize(350,35), choices, wxCB_DROPDOWN );

    
    comboBox->SetHint("Name");
    ContentSizer->Add(comboBox,0,wxEXPAND|wxALL,5);
    ContentSizer->AddStretchSpacer();
    ids++;
    wxTextCtrl* RateTextCtrl = new wxTextCtrl(panel,id[2],wxEmptyString, wxDefaultPosition, wxSize(100,35), 0,wxTextValidator(wxFILTER_DIGITS));
    RateTextCtrl->SetHint("Rate");
    ContentSizer->Add(RateTextCtrl,0,wxEXPAND|wxALL,5);
    ContentSizer->AddStretchSpacer();
    ids++;
    wxTextCtrl* QuantityTextCtrl = new wxTextCtrl(panel,id[3],wxEmptyString, wxDefaultPosition,  wxSize(100,35), 0,wxTextValidator(wxFILTER_DIGITS));
    QuantityTextCtrl->SetHint("Qty:");
    ContentSizer->Add(QuantityTextCtrl,0,wxEXPAND|wxALL,5);
    ids++;

    comboBox->Bind(wxEVT_TEXT, [this, comboBox,IDTextCtrl,RateTextCtrl,QuantityTextCtrl](wxCommandEvent& event) {
        OnNameEntered(event,comboBox,IDTextCtrl,RateTextCtrl,QuantityTextCtrl);
    });

    panelSizer->Add(ContentSizer, 0, wxEXPAND | wxRIGHT|wxLEFT, 20);
    panelSizer->Layout();
    panelSizer->FitInside(panel);
    panel->Refresh();
    parentSizer->Layout();
    parentSizer->FitInside(parentPanel);
    parentPanel->Refresh();
    count++;
}

void BuyObjectFrame::OnNameEntered(wxCommandEvent& event,wxComboBox* comboBox,wxTextCtrl* ID,wxTextCtrl* Rate,wxTextCtrl* Quantity){
    wxString enteredText = comboBox->GetValue();
    wxArrayString filteredSuggestions;
    for (size_t i = 0; i < choices.GetCount(); i++){
        wxString choice = choices[i];
        if (choice.Lower()==enteredText.Lower())
        {   

            filteredSuggestions.Add(choice);
            if(comboBox->IsListEmpty()){
                comboBox->Insert(filteredSuggestions,0);
            }
            else{
                wxArrayString lists = comboBox->GetStrings();
                for (size_t i = 0; i < lists.GetCount(); i++){
                    comboBox->Delete(0);
                }
            }
            comboBox->Append(filteredSuggestions);;
            
            Product p = getInventoryOnName(enteredText.Lower().ToStdString());
            ID->SetValue(wxString::Format("%d", p.getID()));
            Rate->SetValue(wxString::Format("%d", p.getRate()));
            Quantity->SetValue(wxT("1"));
            event.Skip();
            return;
        }
        else if (choice.Lower().Contains(enteredText.Lower()))
        {

            filteredSuggestions.Add(choice);
            
        }
    }
    ID->SetValue(wxString::Format("%d", 0));
    Rate->SetValue(wxString::Format("%d", 0));
    Quantity->SetValue(wxT("0"));
    if(comboBox->IsListEmpty()){
        comboBox->Append(filteredSuggestions);
    }
    else{
        wxArrayString lists = comboBox->GetStrings();
        for (size_t i = 0; i < lists.GetCount(); i++){
            comboBox->Delete(0);
        }
    }
    comboBox->Append(filteredSuggestions);
    
    event.Skip();
    
}

void BuyObjectFrame::OnIDEntered(wxCommandEvent& event,wxTextCtrl* ID){
    wxString enteredText = ID->GetValue();
    if(enteredText.length()>5){
        ID->SetValue(enteredText.substr(0, 5));
    }
    ID->SetInsertionPointEnd();
    event.Skip();
}

void BuyObjectFrame::ConfirmDetails(wxCommandEvent& event){
    std::vector<Product> DetailsVector;
    wxString message,IDValue,nameValue,rateValue,qtyValue,namevar1;
    std::string namevar;
    message = "ID\t\t\tP.Name\t\t\tRate\tQty\n";
    int total=0;
    for (int i = 0; i < IDVectors.size(); i++) {
        wxTextCtrl* IDTextCtrl = wxDynamicCast(FindWindowById(IDVectors[i][0]), wxTextCtrl);
        if (IDTextCtrl){
            IDValue = IDTextCtrl->GetValue();
            if(IDValue=="\0"||IDValue=="0"){
                continue;
            }

        }
        wxComboBox* nameBox = wxDynamicCast(FindWindowById(IDVectors[i][1]), wxComboBox);
        if (nameBox){
            nameValue = nameBox->GetValue();
            namevar1 = nameValue;
            size_t currentLength = namevar1.length();
            if (currentLength < 30) {
                namevar1 += wxString(' ', 30 - currentLength);
            }
            namevar = namevar1.ToStdString();
            namevar.resize(30);

        }
        wxTextCtrl* rateTextCtrl = wxDynamicCast(FindWindowById(IDVectors[i][2]), wxTextCtrl);
        if (rateTextCtrl){
            rateValue = rateTextCtrl->GetValue();
            if(rateValue=="\0"||rateValue=="0"){
                continue;
            }

        }
        wxTextCtrl* qtyTextCtrl = wxDynamicCast(FindWindowById(IDVectors[i][3]), wxTextCtrl);
        if (qtyTextCtrl){
            qtyValue = qtyTextCtrl->GetValue();
            if(qtyValue=="\0"||qtyValue=="0"){
                continue;
            }

        }
        message = message+IDValue+"\t\t"+namevar+rateValue+"\t\t"+qtyValue+"\n";
        total += std::stoi(rateValue.ToStdString())*std::stoi(qtyValue.ToStdString());
        Product p(std::stoi(IDValue.ToStdString()),nameValue.ToStdString(),std::stoi(rateValue.ToStdString()),std::stoi(qtyValue.ToStdString()));
        DetailsVector.push_back(p);
    }
    message = message+"\n\nTotal\t:\t"+std::to_string(total)+"\n";
    if (DetailsVector.empty()) {
        wxMessageBox(_("Please Select any Item to Order"), "Confirm Order", wxOK | wxICON_NONE | wxOK_DEFAULT);
    } 
    else{
        int result = wxMessageBox(message, "Confirm Order", wxOK | wxCANCEL | wxICON_NONE | wxOK_DEFAULT);
        if (result == wxOK) {
            BuyUpdateDB(DetailsVector);
            BuyObjectFrame* addFrame = new BuyObjectFrame(wxT("Byapar"),this->GetPosition(),wxSize(this->GetSize().GetWidth(),this->GetSize().GetHeight()));
            addFrame->Show(true);
            this->Close(true);
        } 
    }
    

}

#endif