#include<wx/wx.h>
#include<wx/textctrl.h>
#include <wx/statline.h>
#include <vector>
#include <map>
#include <array>
#include <tuple>
#include"id.h"
#include"BuySellFunctions.h"
#include"MenuFrame.h"
#include"AddObjectFrame.h"
#include"SellObjectFrame.h"
#include"BuyObjectFrame.h"
#include"ShowObjectFrame.h"

class myApp : public wxApp{
    public:
        virtual bool OnInit();
} ;


// wxDECLARE_APP(myApp);
wxIMPLEMENT_APP(myApp);
bool myApp::OnInit(){
    // wxWindow::SetMinSize(500);
    MenuFrame *Menuframe = new MenuFrame(wxT("Byapar"),wxPoint(50,50),wxSize(700,600));
    Menuframe -> Show(true);
    return true;
}
