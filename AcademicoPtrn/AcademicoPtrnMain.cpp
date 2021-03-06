/***************************************************************
 * Name:      AcademicoPtrnMain.cpp
 * Purpose:   Code for Application Frame
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

#include "AcademicoPtrnMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}



AcademicoPtrnDialog::AcademicoPtrnDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{
}

AcademicoPtrnDialog::~AcademicoPtrnDialog()
{
}

void AcademicoPtrnDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void AcademicoPtrnDialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void AcademicoPtrnDialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
