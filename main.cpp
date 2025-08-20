#include<wx/wx.h>
#include<wx/menu.h>
#include<wx/textctrl.h>
#include <wx/statline.h>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <array>
#include <tuple>
#include"id.h"
#include"Database.h"
#include"MenuFrame.h"
#include"SellObjectFrame.h"
#include"BuyObjectFrame.h"

class myApp : public wxApp{
    public:
        virtual bool OnInit();
} ;


wxIMPLEMENT_APP(myApp);
bool myApp::OnInit(){
    connectToDatabase();
    MenuFrame *Menuframe = new MenuFrame(wxT("Byapar"),wxPoint(50,50),wxSize(700,600));
    Menuframe -> Show(true);
    return true;
}