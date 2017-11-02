/***************************************************************
 * Name:      AcademicoPtrnApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Doris Serruto (doris.serruto@ucsp.edu.pe)
 * Created:   2010-05-28
 * Copyright: Doris Serruto ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "AcademicoPtrnApp.h"
#include "AcademicoPtrnMain.h"

IMPLEMENT_APP(AcademicoPtrnApp);

bool AcademicoPtrnApp::OnInit()
{
    
    AcademicoPtrnDialog* dlg = new AcademicoPtrnDialog(0L);
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
