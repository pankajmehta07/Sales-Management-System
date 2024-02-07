
#ifndef MODIFY_INVENTORY
#define MODIFY_INVENTORY
// #ifndef MENU_FRAME_H
// class MenuFrame;
#include"MenuFrame.h"
// #endif

class ModifyInventory : public wxFrame{
    public:
        ModifyInventory(const wxString& title,const wxPoint& pos,const wxSize& size);
    
    private:
    wxPanel* MenuPanel;
    wxBoxSizer* MenuPanelSizer;
    wxTextCtrl* rateCtrl;
    wxTextCtrl* qtyCtrl;
    wxStaticText* rateText;
    wxStaticText* qtyText;
    wxBoxSizer* contentPanelSizer; 
    int count=1, nameid, rateid, qtyid;
    wxArrayString choices = getNameChoices();


    // Menu Click 
        void OnQuit(wxCommandEvent& event);
        void OnHello(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void onClose(wxCloseEvent& event);
        void SearchButtonClick(wxCommandEvent& event);
        void MenuButtonClick(wxFrame*);
        wxDECLARE_EVENT_TABLE();
};


wxBEGIN_EVENT_TABLE(ModifyInventory, wxFrame)
    EVT_MENU(wxID_ABOUT, ModifyInventory::OnAbout)
    EVT_MENU(add::wxID_HELLO, ModifyInventory::OnHello)
    EVT_MENU(wxID_EXIT, ModifyInventory::OnQuit)
    EVT_CLOSE(ModifyInventory::onClose)
    EVT_BUTTON(add::searchButtonId,ModifyInventory::SearchButtonClick)
wxEND_EVENT_TABLE();




ModifyInventory::ModifyInventory(const wxString& title,const wxPoint& pos,const wxSize& size):wxFrame(NULL,wxID_ANY,title,pos,size){
    // SetIcon(wxIcon(wxT("photo.ico")));
    SetMinSize(wxSize(750,540));
    
    wxMenu *menuFile = new wxMenu;
    wxBitmap searchIcon = wxArtProvider::GetBitmap(wxART_FIND, wxART_MENU);
    wxMenuItem* searchMenuItem = new wxMenuItem(menuFile, wxID_ANY, "Search");
    searchMenuItem->SetBitmap(searchIcon);
    wxAcceleratorEntry accel(wxACCEL_CTRL, 'F', wxID_ANY);
    searchMenuItem->SetAccel(&accel);
    Bind(wxEVT_MENU, &ModifyInventory::SearchButtonClick, this, searchMenuItem->GetId());
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
    // SellerPanel->SetBackgroundColour(wxColour(120,23,123));
    MainSizer->Add(SellerPanel,0,wxEXPAND|wxALL);

    wxBoxSizer* SellerPanelSizer=new wxBoxSizer(wxVERTICAL);
    SellerPanel->SetSizer(SellerPanelSizer);


    wxStaticText* SellerName = new wxStaticText(SellerPanel,wxID_ANY,wxT("Seller Name"));
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
    // MenuPanel->SetBackgroundColour(wxColour(200,200,100));
    MainSizer->Add(MenuPanel,1,wxEXPAND);
    wxBoxSizer* MenuPanelSizer = new wxBoxSizer(wxVERTICAL);
    MenuPanel->SetSizer(MenuPanelSizer);

    wxPanel* TopicPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(TopicPanel,0,wxEXPAND);
    wxBoxSizer* TopicPanelSizer = new wxBoxSizer(wxVERTICAL);
    TopicPanel->SetSizer(TopicPanelSizer);
    TopicPanelSizer->Add(0,20);
    wxStaticText* topic = new wxStaticText(TopicPanel,wxID_ANY,wxT("Modify Inventory"));
    wxFont topicFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
    topic->SetFont(topicFont);
    TopicPanelSizer->Add(topic,1,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,5);
    TopicPanelSizer->Add(0,20);

    wxPanel* newTopicPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(newTopicPanel,0,wxEXPAND);
    wxBoxSizer* newTopicPanelSizer = new wxBoxSizer(wxVERTICAL);
    newTopicPanel->SetSizer(newTopicPanelSizer);
    newTopicPanelSizer->Add(0,20);
    wxComboBox* comboBox = new wxComboBox(newTopicPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(350,35), choices, wxCB_DROPDOWN);
    comboBox->SetHint("Name");
    newTopicPanelSizer->Add(comboBox,1,wxCENTER,5);
    newTopicPanelSizer->Add(0,20);

    wxPanel* contentPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(contentPanel,1,wxEXPAND);
    contentPanelSizer = new wxBoxSizer(wxVERTICAL);
    contentPanel->SetSizer(contentPanelSizer);
    
    // contentPanelSizer->Add(0,50);
    wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
    rateText = new wxStaticText(contentPanel,wxID_ANY,wxT("Rate: "), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
    ContentSizer->Add(rateText,0,wxCENTER,5);
    ContentSizer->Add(50,0);
    rateCtrl =  new wxTextCtrl(contentPanel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxSize(100,35));
    rateCtrl->SetHint("New Rate");
    ContentSizer->Add(rateCtrl,0,wxCENTER,5);
    contentPanelSizer->Add(ContentSizer, 0, wxCENTER, 5);
    contentPanelSizer->Add(0,20);
    ContentSizer=new wxBoxSizer(wxHORIZONTAL);
    qtyText = new wxStaticText(contentPanel,wxID_ANY,wxT("Quantity: "), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
    ContentSizer->Add(qtyText,0,wxCENTER,5);
    ContentSizer->Add(50,0);
    qtyCtrl =  new wxTextCtrl(contentPanel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxSize(100,35));
    qtyCtrl->SetHint("New Quantity");
    ContentSizer->Add(qtyCtrl,0,wxCENTER,5);
    contentPanelSizer->Add(ContentSizer, 0, wxCENTER, 5);
    contentPanelSizer->Add(0,20);
    ContentSizer=new wxBoxSizer(wxHORIZONTAL);
    wxButton* UpdateButton = new wxButton(contentPanel,wxID_ANY,"Update");
    ContentSizer->Add(UpdateButton,0,wxLEFT,20);
    contentPanelSizer->Add(ContentSizer, 0, wxCENTER, 5);
    contentPanelSizer->Show(wxFalse);

    wxPanel* AddItemPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(AddItemPanel,0,wxEXPAND|wxALL,10);
    wxBoxSizer* AddItemSizer=new wxBoxSizer(wxHORIZONTAL);
    AddItemPanel->SetSizer(AddItemSizer);
    wxButton* MenuButton = new wxButton(AddItemPanel,add::menuButtonId,"Main Menu");
    AddItemSizer->Add(MenuButton,0,wxALIGN_LEFT|wxLEFT,20);
    AddItemSizer->AddStretchSpacer();
    wxButton* AddItemButton = new wxButton(AddItemPanel,add::AddItemId,"Add Item");
    AddItemSizer->Add(AddItemButton,0,wxRIGHT,20);

    // AddItemButton->Bind(wxEVT_BUTTON, [this, contentPanel,contentPanelSizer,MenuPanel,MenuPanelSizer](wxCommandEvent& event) {
    //         AddItem(contentPanel,contentPanelSizer,MenuPanel,MenuPanelSizer);
    // });
    MenuButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            MenuButtonClick(this);
    });




    Centre();
    SetSizer(MainSizer);


    CreateStatusBar();
    SetStatusText(wxT("Status Bar"));
}


void ModifyInventory::OnHello(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Welcome to the Sales Management Software"));
    wxMessageBox(msg, wxT("Package"), wxOK | wxICON_INFORMATION, this);
    PushStatusText(msg);
    wxSleep(2);
    PopStatusText();
}

void ModifyInventory::OnAbout(wxCommandEvent& event)
{
    // updateDatabase();
    wxString msg;
    msg.Printf(wxT("This is the Sales Management Software"));
    wxMessageBox(msg, wxT("About Package"), wxOK | wxICON_INFORMATION, this);
}

void ModifyInventory::OnQuit(wxCommandEvent& event)
{
    bool veto = Close();
}

void ModifyInventory::onClose(wxCloseEvent& event){
    if(event.CanVeto()){
        int answer = wxMessageBox(_("Do you want to exit"), _("Confirm?"),wxICON_QUESTION | wxYES_NO);
        if(answer!=wxYES){
            event.Veto();
            return;
        }
    }
    Destroy();
}


//Buttons Click:
void ModifyInventory::SearchButtonClick(wxCommandEvent& event){
    SearchObjectFrame* addFrame = new SearchObjectFrame(wxT("Byapar"),this->GetPosition(),wxSize(this->GetSize().GetWidth(),this->GetSize().GetHeight()));
    addFrame->Show(true);
    this->Close(true);
}


void ModifyInventory::MenuButtonClick(wxFrame* frame){
    MenuFrame* addframe = new MenuFrame(wxT("Byapar"),frame->GetPosition(),wxSize(frame->GetSize().GetWidth(),frame->GetSize().GetHeight()));
    addframe->Show(true);
    frame->Close(true);
}


#endif