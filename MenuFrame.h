#ifndef MENU_FRAME_H
#define MENU_FRAME_H
#include <wx/artprov.h>
#include <wx/bitmap.h>

class MyScrolledWindow : public wxScrolledWindow {
public:
    MyScrolledWindow(wxWindow* parent, wxWindowID id = wxID_ANY, int scrollbarOrientation = wxBOTH)
        : wxScrolledWindow(parent, id)
    {
        SetScrollbar(scrollbarOrientation, 0, 10, 100);
        SetScrollRate(5, 5);
    }

private:

    wxDECLARE_EVENT_TABLE();
};
wxBEGIN_EVENT_TABLE(MyScrolledWindow, wxScrolledWindow)
wxEND_EVENT_TABLE()




class MenuFrame : public wxFrame{
    public:
        MenuFrame(const wxString& title,const wxPoint& pos,const wxSize& size);
    
    private:
    wxPanel* MenuPanel;
    wxBoxSizer* MenuPanelSizer;
        void OnQuit(wxCommandEvent& event);
        void OnHello(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void onClose(wxCloseEvent& event);
        void ModifyButtonClick(wxCommandEvent& event);
        void BuyButtonClick(wxCommandEvent& event,wxFrame*);
        void SellButtonClick(wxCommandEvent& event,wxFrame*);
        void SearchButtonClick(wxCommandEvent& event);
        wxDECLARE_EVENT_TABLE();
};

#include "SearchObjectFrame.h"
class SearchObjectFrame;

#include "BuyObjectFrame.h"
class BuyObjectFrame;

#include "SellObjectFrame.h"
class SellObjectFrame;
#include "ModifyInventory.h"
class ModifyInventory;



wxBEGIN_EVENT_TABLE(MenuFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MenuFrame::OnAbout)
    EVT_MENU(menu::wxID_HELLO, MenuFrame::OnHello)
    EVT_MENU(wxID_EXIT, MenuFrame::OnQuit)
    EVT_CLOSE(MenuFrame::onClose)

    EVT_BUTTON(menu::modifyButtonId,MenuFrame::ModifyButtonClick)
    EVT_BUTTON(menu::searchButtonId,MenuFrame::SearchButtonClick)
wxEND_EVENT_TABLE();




MenuFrame::MenuFrame(const wxString& title,const wxPoint& pos,const wxSize& size):wxFrame(NULL,wxID_ANY,title,pos,size){
   
    SetMinSize(wxSize(750,540));
    
    wxMenu *menuFile = new wxMenu;
    wxBitmap searchIcon = wxArtProvider::GetBitmap(wxART_FIND, wxART_MENU);
    wxMenuItem* searchMenuItem = new wxMenuItem(menuFile, wxID_ANY, "Search");
    searchMenuItem->SetBitmap(searchIcon);
    wxAcceleratorEntry accel(wxACCEL_CTRL, 'F', wxID_ANY);
    searchMenuItem->SetAccel(&accel);
    Bind(wxEVT_MENU, &MenuFrame::SearchButtonClick, this, searchMenuItem->GetId());
    menuFile->Append(searchMenuItem);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

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
    
    wxPanel* MenuPanel = new wxPanel(this,wxID_ANY);
    MainSizer->Add(MenuPanel,1,wxEXPAND);
    wxBoxSizer* MenuPanelSizer = new wxBoxSizer(wxVERTICAL);
    MenuPanel->SetSizer(MenuPanelSizer);

    wxButton* SearchObjectButton = new wxButton(MenuPanel,menu::searchButtonId, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE | wxBU_EXACTFIT);
    SearchObjectButton->SetBitmap(searchIcon);
    SearchObjectButton->SetToolTip("Search");

    wxButton*  BuyObjectButton= new wxButton(MenuPanel,menu::buyButtonId,"Buy Items");
    BuyObjectButton->SetToolTip("Buy Items");
    wxButton*  SellObjectButton= new wxButton(MenuPanel,menu::sellButtonId,"Sell Items");
    SellObjectButton->SetToolTip("Sell Items");
    wxButton* ModifyObjectButton = new wxButton(MenuPanel,menu::modifyButtonId,"Modify Inventory");
    ModifyObjectButton->SetToolTip("Modify Inventory");
    

    BuyObjectButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            BuyButtonClick(event,this);
        });
    SellObjectButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            SellButtonClick(event,this);
        });

    MenuPanelSizer->Add(0,20);
    MenuPanelSizer->Add(SearchObjectButton,0,wxALIGN_RIGHT|wxRIGHT,20);
    MenuPanelSizer->Add(0,10);

    MenuPanelSizer->Add(BuyObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(SellObjectButton,0,wxALIGN_CENTER|wxALL,5);
    MenuPanelSizer->Add(ModifyObjectButton,0,wxALIGN_CENTER|wxALL,5);


    Centre();
    SetSizer(MainSizer);


    CreateStatusBar();
    SetStatusText(wxT("Status Bar"));
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
    // delete con;
    Destroy();
}


//Buttons Click:
void MenuFrame::SearchButtonClick(wxCommandEvent& event){
    SearchObjectFrame* addFrame = new SearchObjectFrame(wxT("Byapar"),this->GetPosition(),wxSize(this->GetSize().GetWidth(),this->GetSize().GetHeight()));
    addFrame->Show(true);
    this->Close(true);
}
void MenuFrame::ModifyButtonClick(wxCommandEvent& event){
    ModifyInventory* addFrame = new ModifyInventory(wxT("Byapar"),this->GetPosition(),wxSize(this->GetSize().GetWidth(),this->GetSize().GetHeight()));
    addFrame->Show(true);
    this->Close(true);
    
}
void MenuFrame::SellButtonClick(wxCommandEvent& event,wxFrame* frame){
    SellObjectFrame* addFrame = new SellObjectFrame(wxT("Byapar"),frame->GetPosition(),wxSize(frame->GetSize().GetWidth(),frame->GetSize().GetHeight()));
    addFrame->Show(true);
    this->Close(true);
}
void MenuFrame::BuyButtonClick(wxCommandEvent& event,wxFrame* frame){
    BuyObjectFrame* addFrame = new BuyObjectFrame(wxT("Byapar"),frame->GetPosition(),wxSize(frame->GetSize().GetWidth(),frame->GetSize().GetHeight()));
    addFrame->Show(true);
    this->Close(true);
}



#endif