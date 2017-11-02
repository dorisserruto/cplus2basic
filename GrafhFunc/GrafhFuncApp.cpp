/***************************************************************
 * Name:      GrafhFuncApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Doris Serruto (doris.serruto@ucsp.edu.pe)
 * Created:   2010-06-11
 * Copyright: Doris Serruto ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "GrafhFuncApp.h"
#include "GrafhFuncMain.h"

IMPLEMENT_APP(GrafhFuncApp);

bool GrafhFuncApp::OnInit()
{
    GrafhFuncFrame* frame = new GrafhFuncFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
