#ifndef SEARCH_OBJECT_FRAME
#define SEARCH_OBJECT_FRAME
// #ifndef MENU_FRAME_H
// class MenuFrame;
#include"MenuFrame.h"
// #endif

class SearchObjectFrame : public wxFrame{
    public:
        SearchObjectFrame(const wxString& title,const wxPoint& pos,const wxSize& size);
    
    private:
    int display =1;
    wxTextCtrl* Name;
    MyScrolledWindow* MenuPanel;
    // wxPanel* contentPanel;
    wxPanel* contentPanel;
    wxBoxSizer* MenuPanelSizer;
    // wxBoxSizer* contentPanelSizer;
    wxBoxSizer* contentPanelSizer;
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
        void SearchButtonClick(wxCommandEvent& event);
        void SearchTextEnter(wxCommandEvent& event);
        void MenuButtonClick(wxFrame*);
        wxDECLARE_EVENT_TABLE();
};


wxBEGIN_EVENT_TABLE(SearchObjectFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, SearchObjectFrame::OnAbout)
    EVT_MENU(add::wxID_HELLO, SearchObjectFrame::OnHello)
    EVT_MENU(wxID_EXIT, SearchObjectFrame::OnQuit)
    EVT_CLOSE(SearchObjectFrame::onClose)
    EVT_BUTTON(add::searchButtonId,SearchObjectFrame::SearchButtonClick)
wxEND_EVENT_TABLE();




SearchObjectFrame::SearchObjectFrame(const wxString& title,const wxPoint& pos,const wxSize& size):wxFrame(NULL,wxID_ANY,title,pos,size){
    // SetIcon(wxIcon(wxT("photo.ico")));
    SetMinSize(wxSize(750,540));
    
    wxMenu *menuFile = new wxMenu;
    wxBitmap searchIcon = wxArtProvider::GetBitmap(wxART_FIND, wxART_MENU);
    wxMenuItem* searchMenuItem = new wxMenuItem(menuFile, wxID_ANY, "Search");
    searchMenuItem->SetBitmap(searchIcon);
    wxAcceleratorEntry accel(wxACCEL_CTRL, 'F', wxID_ANY);
    searchMenuItem->SetAccel(&accel);
    Bind(wxEVT_MENU, &SearchObjectFrame::SearchButtonClick, this, searchMenuItem->GetId());
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
    
    MenuPanel = new MyScrolledWindow(this,wxID_ANY);
    // MenuPanel->SetBackgroundColour(wxColour(200,200,100));
    MainSizer->Add(MenuPanel,1,wxEXPAND);
    MenuPanelSizer = new wxBoxSizer(wxVERTICAL);
    MenuPanel->SetSizer(MenuPanelSizer);

    wxPanel* TopicPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(TopicPanel,0,wxEXPAND);
    wxBoxSizer* TopicPanelSizer = new wxBoxSizer(wxVERTICAL);
    TopicPanel->SetSizer(TopicPanelSizer);
    TopicPanelSizer->Add(0,20);
    wxStaticText* topic = new wxStaticText(TopicPanel,wxID_ANY,wxT("Search Items"));
    wxFont topicFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
    topic->SetFont(topicFont);
    TopicPanelSizer->Add(topic,1,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,5);
    TopicPanelSizer->Add(0,20);

    contentPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(contentPanel,1,wxEXPAND);
    contentPanelSizer = new wxBoxSizer(wxVERTICAL);
    contentPanel->SetSizer(contentPanelSizer);
    contentPanelSizer->Add(0,20);
    wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
    Name = new wxTextCtrl(contentPanel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxSize(350,35),wxTE_PROCESS_ENTER);
    Name->SetHint("Product Name");
    ContentSizer->Add(Name,0,wxCENTER,5);
    Name->Bind(wxEVT_TEXT_ENTER, [this](wxCommandEvent& event) {
            SearchButtonClick(event);
        });
    Name->Bind(wxEVT_TEXT, [this](wxCommandEvent& event) {
            SearchTextEnter(event);
        });
    // ContentSizer->AddStretchSpacer();
    ContentSizer->Add(50,0);
    wxButton* SearchObjectButton = new wxButton(contentPanel,menu::searchButtonId, "Search", wxDefaultPosition, wxSize(100,35), wxBORDER_NONE | wxBU_EXACTFIT);
    SearchObjectButton->SetBitmap(searchIcon);
    SearchObjectButton->SetToolTip("Search");
    ContentSizer->Add(SearchObjectButton,0,wxCENTER,5);
    SearchObjectButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            SearchButtonClick(event);
    });
    contentPanelSizer->Add(ContentSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL,5);

    wxPanel* AddItemPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(AddItemPanel,0,wxEXPAND|wxALL,10);
    wxBoxSizer* AddItemSizer=new wxBoxSizer(wxHORIZONTAL);
    AddItemPanel->SetSizer(AddItemSizer);
    wxButton* MenuButton = new wxButton(AddItemPanel,add::menuButtonId,"Main Menu");
    AddItemSizer->Add(MenuButton,0,wxALIGN_LEFT|wxLEFT,20);
    AddItemSizer->AddStretchSpacer();
    
    MenuButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            MenuButtonClick(this);
    });




    Centre();
    SetSizer(MainSizer);


    CreateStatusBar();
    SetStatusText(wxT("Status Bar"));
}


void SearchObjectFrame::OnHello(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Welcome to the Sales Management Software"));
    wxMessageBox(msg, wxT("Package"), wxOK | wxICON_INFORMATION, this);
    PushStatusText(msg);
    wxSleep(2);
    PopStatusText();
}

void SearchObjectFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("This is the Sales Management Software"));
    wxMessageBox(msg, wxT("About Package"), wxOK | wxICON_INFORMATION, this);
}

void SearchObjectFrame::OnQuit(wxCommandEvent& event)
{
    bool veto = Close();
}

void SearchObjectFrame::onClose(wxCloseEvent& event){
    if(event.CanVeto()){
        int answer = wxMessageBox(_("Do you want to exit"), _("Confirm?"),wxICON_QUESTION | wxYES_NO);
        if(answer!=wxYES){
            event.Veto();
            return;
        }
    }
    Destroy();
}


void SearchObjectFrame::MenuButtonClick(wxFrame* frame){
    MenuFrame* addframe = new MenuFrame(wxT("Byapar"),frame->GetPosition(),wxSize(frame->GetSize().GetWidth(),frame->GetSize().GetHeight()));
    addframe->Show(true);
    frame->Close(true);
}

void SearchObjectFrame::SearchTextEnter(wxCommandEvent& event){
//  wxString name = Name->GetValue(); 
    if(!display){
        SearchObjectFrame* addFrame = new SearchObjectFrame(wxT("Byapar"),this->GetPosition(),wxSize(this->GetSize().GetWidth(),this->GetSize().GetHeight()));
        addFrame->Show(true);
        this->Close(true);
    }
    event.Skip();
}
void SearchObjectFrame::SearchButtonClick(wxCommandEvent& event){
    wxString name = Name->GetValue();    
    if (name.IsEmpty()) {
        wxMessageBox(_("Please Enter any clue to search"), "Search", wxOK | wxICON_NONE | wxOK_DEFAULT);
    } 
    else{
        display = 0;
        std::vector<std::tuple<int, std::string, int, int>> vector1;
        vector1 = SearchDetails(name.ToStdString());
        wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
        ContentSizer->Add(20,0);
        wxStaticText* text= new wxStaticText(contentPanel,wxID_ANY,wxT("ID"), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
        // text->SetFont(font2);
        ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
        ContentSizer->AddStretchSpacer();
        text = new wxStaticText(contentPanel,wxID_ANY,wxT("Product Name"), wxDefaultPosition, wxSize(350, 18), wxALIGN_CENTER);
        // text->SetFont(font2);
        ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
        ContentSizer->AddStretchSpacer();
        text = new wxStaticText(contentPanel,wxID_ANY,wxT("Rate"), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
        
        ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
        ContentSizer->AddStretchSpacer();
        text = new wxStaticText(contentPanel,wxID_ANY,wxT("Quantity"), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
        
        ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
        ContentSizer->Add(20,0);    

        contentPanelSizer->Add(ContentSizer, 0, wxEXPAND | wxALL,5);
        contentPanelSizer->Layout();
        contentPanelSizer->FitInside(contentPanel);
        contentPanel->Refresh();
        MenuPanelSizer->Layout();
        MenuPanelSizer->FitInside(MenuPanel);
        MenuPanel->Refresh();
        for (const auto& item : vector1) {
            int id = std::get<0>(item);
            std::string name = std::get<1>(item);
            int rate = std::get<2>(item);
            int quantity = std::get<3>(item);
            wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
            ContentSizer->Add(20,0);
            wxStaticText* text= new wxStaticText(contentPanel,wxID_ANY,wxString::Format("%d", id), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
            // text->SetFont(font2);
            ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
            ContentSizer->AddStretchSpacer();
            text = new wxStaticText(contentPanel,wxID_ANY,wxString::FromUTF8(name.c_str()), wxDefaultPosition, wxSize(350, 18), wxALIGN_CENTER);
            // text->SetFont(font2);
            ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
            ContentSizer->AddStretchSpacer();
            text = new wxStaticText(contentPanel,wxID_ANY,wxString::Format("%d", rate), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
            
            ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
            ContentSizer->AddStretchSpacer();
            text = new wxStaticText(contentPanel,wxID_ANY,wxString::Format("%d", quantity), wxDefaultPosition, wxSize(100, 18), wxALIGN_CENTER);
            
            ContentSizer->Add(text,0,wxEXPAND|wxALL,5);
            ContentSizer->Add(20,0);    

            contentPanelSizer->Add(ContentSizer, 0, wxEXPAND | wxALL,5);
            contentPanelSizer->Layout();
            contentPanelSizer->Fit(contentPanel);
            contentPanel->Refresh();
            MenuPanel->Layout();
            MenuPanelSizer->FitInside(MenuPanel);
            MenuPanel->Refresh();
        
        }
        
    }
}

#endif