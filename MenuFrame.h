class MenuFrame : public wxFrame{
    public:
        MenuFrame(const wxString& title,const wxPoint& pos,const wxSize& size);
    
    private:
    wxPanel* MenuPanel;
    wxBoxSizer* MenuPanelSizer;

    // Menu Click 
        void OnQuit(wxCommandEvent& event);
        void OnHello(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void onClose(wxCloseEvent& event);
        // Buttons Click 
        void AddButtonClick(wxCommandEvent& event);
        void BuyButtonClick(wxCommandEvent& event);
        void SearchButtonClick(wxCommandEvent& event);
        void ModifyButtonClick(wxPanel*);
        wxDECLARE_EVENT_TABLE();
};


wxBEGIN_EVENT_TABLE(MenuFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MenuFrame::OnAbout)
    EVT_MENU(menu::wxID_HELLO, MenuFrame::OnHello)
    EVT_MENU(wxID_EXIT, MenuFrame::OnQuit)
    EVT_CLOSE(MenuFrame::onClose)

    EVT_BUTTON(menu::addButtonId,MenuFrame::AddButtonClick)
    EVT_BUTTON(menu::buyButtonId,MenuFrame::BuyButtonClick)
    EVT_BUTTON(menu::searchButtonId,MenuFrame::SearchButtonClick)
wxEND_EVENT_TABLE();




MenuFrame::MenuFrame(const wxString& title,const wxPoint& pos,const wxSize& size):wxFrame(NULL,wxID_ANY,title,pos,size){
    // SetIcon(wxIcon(wxT("photo.ico")));
    SetMinSize(wxSize(600,400));
    
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(menu::wxID_HELLO, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);




    // Menu Contents

    wxBoxSizer* MenuSizer = new wxBoxSizer(wxVERTICAL);
    
    wxPanel* MenuPanel = new wxPanel(this,wxID_ANY);
    MenuPanel->SetBackgroundColour(wxColour(200,200,100));
    MenuSizer->Add(MenuPanel,1,wxALIGN_CENTER|wxEXPAND);
    wxBoxSizer* MenuPanelSizer = new wxBoxSizer(wxVERTICAL);
    MenuPanel->SetSizer(MenuPanelSizer);

    wxButton*  BuyObjectButton= new wxButton(MenuPanel,menu::buyButtonId,"Buy ");
    wxButton* AddObjectButton = new wxButton(MenuPanel,menu::addButtonId,"Add Item ");
    wxButton* ModifyObjectButton = new wxButton(MenuPanel,menu::modifyButtonId,"Modify ");
    wxButton* SearchObjectButton = new wxButton(MenuPanel,menu::searchButtonId,"Search ");

    ModifyObjectButton->Bind(wxEVT_BUTTON, [this, MenuPanel](wxCommandEvent& event) {
            ModifyButtonClick(MenuPanel);
        });

    MenuPanelSizer->Add(0,60);

    MenuPanelSizer->Add(BuyObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(AddObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(ModifyObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(SearchObjectButton,0,wxALIGN_CENTER|wxALL,5);


    Centre();
    SetSizer(MenuSizer);


    CreateStatusBar();
    SetStatusText(_("Status Bar"));
}


void MenuFrame::OnHello(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Welcome to the Sales Management Software"));
    wxMessageBox(msg, wxT("Package"), wxOK | wxICON_INFORMATION, this);
    PushStatusText(msg);
    wxSleep(2);
    PopStatusText();
}

void MenuFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("This is the Sales Management Software"));
    wxMessageBox(msg, wxT("About Package"), wxOK | wxICON_INFORMATION, this);
}

void MenuFrame::OnQuit(wxCommandEvent& event)
{
    bool veto = Close();
}

void MenuFrame::onClose(wxCloseEvent& event){
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
void MenuFrame::SearchButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Search Button Clicked "));
    
    // this->Show(false);
}
void MenuFrame::ModifyButtonClick(wxPanel* panel){
    wxMessageBox(_("Modify Button Clicked "+panel->GetName()));
    
    // this->Show(false);
}
void MenuFrame::AddButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Add Button Clicked"));
}
void MenuFrame::BuyButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Buy Button Clicked"));
}