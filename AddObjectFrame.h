#ifndef ADD_OBJECT_FRAME_H
#define ADD_OBJECT_FRAME_H

// class MenuFrame;
#include"MenuFrame.h"


class MyScrolledWindow : public wxScrolledWindow {
public:
    MyScrolledWindow(wxWindow* parent, wxWindowID id = wxID_ANY, int scrollbarOrientation = wxBOTH)
        : wxScrolledWindow(parent, id)
    {
        // Set up the scrollbar
        SetScrollbar(scrollbarOrientation, 0, 10, 100);
        // SetScrollbar(wxVERTICAL, 0, 10, 100);
        SetScrollRate(5, 5);
    }

private:
    // Event handlers, if needed

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyScrolledWindow, wxScrolledWindow)
    // Event handling, if needed
wxEND_EVENT_TABLE()



class AddObjectFrame : public wxFrame{
    public:
        AddObjectFrame(const wxString& title,const wxPoint& pos,const wxSize& size);
    
    private:
    wxPanel* MenuPanel;
    wxBoxSizer* MenuPanelSizer;
    wxTextCtrl* textCtrl;

    // Menu Click 
        void OnQuit(wxCommandEvent& event);
        void OnHello(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void onClose(wxCloseEvent& event);
        // Buttons Click 
        void ModifyButtonClick(wxCommandEvent& event);
        void AddItem(wxPanel*,wxBoxSizer*,MyScrolledWindow*,wxBoxSizer*);
        void BuyButtonClick(wxCommandEvent& event);
        void SellButtonClick(wxCommandEvent& event);
        void SearchButtonClick(wxCommandEvent& event);
        void MenuButtonClick(wxFrame*);
        wxDECLARE_EVENT_TABLE();
};


wxBEGIN_EVENT_TABLE(AddObjectFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, AddObjectFrame::OnAbout)
    EVT_MENU(add::wxID_HELLO, AddObjectFrame::OnHello)
    EVT_MENU(wxID_EXIT, AddObjectFrame::OnQuit)
    EVT_CLOSE(AddObjectFrame::onClose)

    EVT_BUTTON(add::modifyButtonId,AddObjectFrame::ModifyButtonClick)
    EVT_BUTTON(add::buyButtonId,AddObjectFrame::BuyButtonClick)
    EVT_BUTTON(add::sellButtonId,AddObjectFrame::SellButtonClick)
    EVT_BUTTON(add::searchButtonId,AddObjectFrame::SearchButtonClick)
wxEND_EVENT_TABLE();




AddObjectFrame::AddObjectFrame(const wxString& title,const wxPoint& pos,const wxSize& size):wxFrame(NULL,wxID_ANY,title,pos,size){
    // SetIcon(wxIcon(wxT("photo.ico")));
    SetMinSize(wxSize(600,540));
    
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(add::wxID_HELLO, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
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
    MainSizer->Add(SellerPanel,0,wxALIGN_CENTER|wxEXPAND|wxALL);

    wxBoxSizer* SellerPanelSizer=new wxBoxSizer(wxVERTICAL);
    SellerPanel->SetSizer(SellerPanelSizer);


    SellerPanelSizer->Add(0,20);
    wxStaticText* SellerName = new wxStaticText(SellerPanel,wxID_ANY,wxT("Seller Name"));
    wxFont font1(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
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

    SellerPanelSizer->Add(0,8);

    wxStaticLine* separatorLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    wxColour separatorColour(150,150,150);
    separatorLine->SetForegroundColour(separatorColour);
    separatorLine->SetBackgroundColour(separatorColour);
    separatorLine->SetSize(wxDefaultCoord, wxDefaultCoord, wxDefaultCoord, 2);
    MainSizer->Add(separatorLine, 0, wxEXPAND | wxALL, 3);
    
    MyScrolledWindow* MenuPanel = new MyScrolledWindow(this,wxID_ANY);
    // MenuPanel->SetBackgroundColour(wxColour(200,200,100));
    MainSizer->Add(MenuPanel,1,wxALIGN_CENTER|wxEXPAND);
    wxBoxSizer* MenuPanelSizer = new wxBoxSizer(wxVERTICAL);
    MenuPanel->SetSizer(MenuPanelSizer);

    wxPanel* contentPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(contentPanel,1,wxALIGN_CENTER|wxEXPAND);
    wxBoxSizer* contentPanelSizer = new wxBoxSizer(wxVERTICAL);
    contentPanel->SetSizer(contentPanelSizer);

    
     for (int i = 0; i < 2; ++i)
    {
        wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
        textCtrl = new wxTextCtrl(contentPanel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        textCtrl->SetHint("ID");
        ContentSizer->Add(textCtrl,0,wxALIGN_CENTER|wxEXPAND|wxALL,5);
        textCtrl = new wxTextCtrl(contentPanel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        textCtrl->SetHint("Name");
        ContentSizer->Add(textCtrl,0,wxALIGN_CENTER|wxEXPAND|wxALL,5);
        textCtrl = new wxTextCtrl(contentPanel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        textCtrl->SetHint("Qty:");
        ContentSizer->Add(textCtrl,0,wxALIGN_CENTER|wxEXPAND|wxALL,5);

        contentPanelSizer->Add(ContentSizer, 0, wxEXPAND | wxALL, 10);
    }

    wxPanel* AddItemPanel = new wxPanel(MenuPanel,wxID_ANY);
    MenuPanelSizer->Add(AddItemPanel,0,wxALIGN_CENTER|wxEXPAND|wxALL);
    wxBoxSizer* AddItemSizer=new wxBoxSizer(wxHORIZONTAL);
    AddItemPanel->SetSizer(AddItemSizer);
    wxButton* MenuButton = new wxButton(AddItemPanel,add::menuButtonId,"Main Menu");
    AddItemSizer->Add(MenuButton,0,wxALIGN_LEFT|wxALL,5);
    wxButton* AddItemButton = new wxButton(AddItemPanel,add::AddItemId,"Add Item");
    AddItemSizer->Add(AddItemButton,0,wxALIGN_RIGHT|wxALL,5);

    AddItemButton->Bind(wxEVT_BUTTON, [this, contentPanel,contentPanelSizer,MenuPanel,MenuPanelSizer](wxCommandEvent& event) {
            AddItem(contentPanel,contentPanelSizer,MenuPanel,MenuPanelSizer);
    });
    MenuButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            MenuButtonClick(this);
    });




    Centre();
    SetSizer(MainSizer);


    CreateStatusBar();
    SetStatusText(wxT("Status Bar"));
}


void AddObjectFrame::OnHello(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Welcome to the Sales Management Software"));
    wxMessageBox(msg, wxT("Package"), wxOK | wxICON_INFORMATION, this);
    PushStatusText(msg);
    wxSleep(2);
    PopStatusText();
}

void AddObjectFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("This is the Sales Management Software"));
    wxMessageBox(msg, wxT("About Package"), wxOK | wxICON_INFORMATION, this);
}

void AddObjectFrame::OnQuit(wxCommandEvent& event)
{
    bool veto = Close();
}

void AddObjectFrame::onClose(wxCloseEvent& event){
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
void AddObjectFrame::SearchButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Search Button Clicked "));
    
    // this->Show(false);
}
void AddObjectFrame::ModifyButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Modify Button Clicked "));
}

void AddObjectFrame::MenuButtonClick(wxFrame* frame){
    MenuFrame* addframe = new MenuFrame(wxT("Byapar"),frame->GetPosition(),wxSize(frame->GetSize().GetWidth(),frame->GetSize().GetHeight()));
    addframe->Show(true);
    frame->Close(true);
}
void AddObjectFrame::AddItem(wxPanel* panel,wxBoxSizer* panelSizer,MyScrolledWindow* parentPanel,wxBoxSizer* parentSizer){
    wxBoxSizer* ContentSizer=new wxBoxSizer(wxHORIZONTAL);
    textCtrl = new wxTextCtrl(panel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    textCtrl->SetHint("ID");
    ContentSizer->Add(textCtrl,0,wxALIGN_CENTER|wxALL,5);
    textCtrl = new wxTextCtrl(panel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    textCtrl->SetHint("Name");
    ContentSizer->Add(textCtrl,0,wxALIGN_CENTER|wxALL,5);
    textCtrl = new wxTextCtrl(panel,wxID_ANY,wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    textCtrl->SetHint("Qty:");
    ContentSizer->Add(textCtrl,0,wxALIGN_CENTER|wxALL,5);
    panelSizer->Add(ContentSizer, 0, wxEXPAND | wxALL, 10);
    panelSizer->Layout();
    panelSizer->FitInside(panel);
    panel->Refresh();
    parentSizer->Layout();
    parentSizer->FitInside(parentPanel);
    parentPanel->Refresh();
}
void AddObjectFrame::SellButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Sell Button Clicked"));
}
void AddObjectFrame::BuyButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Buy Button Clicked"));
}




#endif