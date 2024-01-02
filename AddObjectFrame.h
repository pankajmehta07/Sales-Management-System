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

    // Menu Click 
        void OnQuit(wxCommandEvent& event);
        void OnHello(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void onClose(wxCloseEvent& event);
        // Buttons Click 
        void ModifyButtonClick(wxCommandEvent& event);
        void BuyButtonClick(wxCommandEvent& event);
        void SellButtonClick(wxCommandEvent& event);
        void SearchButtonClick(wxCommandEvent& event);
        void MenuButtonClick(wxFrame*,wxPanel*);
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
    SetMinSize(wxSize(100,100));
    
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
    // SetScrollbar(wxVERTICAL, 0, 10, 100);
    // MenuPanel->SetScrollRate(5, 5);

    wxButton*  BuyObjectButton= new wxButton(MenuPanel,add::buyButtonId,"Add-> Buy ");
    wxButton*  SellObjectButton= new wxButton(MenuPanel,add::sellButtonId,"Add-> Sell ");
    wxButton* MenuObjectButton = new wxButton(MenuPanel,add::menuButtonId,"Add-> Menu ");
    wxButton* ModifyObjectButton = new wxButton(MenuPanel,add::modifyButtonId,"Add-> Modify ");
    wxButton* SearchObjectButton = new wxButton(MenuPanel,add::searchButtonId,"Add-> Search ");

    MenuObjectButton->Bind(wxEVT_BUTTON, [this, MenuPanel](wxCommandEvent& event) {
            MenuButtonClick(this,MenuPanel);
        });

    MenuPanelSizer->Add(0,40);

    MenuPanelSizer->Add(BuyObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(SellObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(MenuObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(ModifyObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(SearchObjectButton,0,wxALIGN_CENTER|wxALL,5);


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
void AddObjectFrame::MenuButtonClick(wxFrame* frame,wxPanel* panel){
    MenuFrame* addframe = new MenuFrame(wxT("Byappar"),frame->GetPosition(),wxSize(frame->GetSize().GetWidth(),frame->GetSize().GetHeight()));
    addframe->Show(true);
    frame->Close(true);
}
void AddObjectFrame::ModifyButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Modify Button Clicked"));
}
void AddObjectFrame::SellButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Sell Button Clicked"));
}
void AddObjectFrame::BuyButtonClick(wxCommandEvent& event){
    wxMessageBox(_("Buy Button Clicked"));
}




#endif