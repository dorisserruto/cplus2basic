/***************************************************************
 * Name:      GrafhFuncMain.cpp
 * Purpose:   Code for Application Frame
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

#include "GrafhFuncMain.h"
#include <winbgim.h>

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


GrafhFuncFrame::GrafhFuncFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

GrafhFuncFrame::~GrafhFuncFrame()
{
}

void GrafhFuncFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void GrafhFuncFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void GrafhFuncFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    //wxMessageBox(msg, _("Welcome to..."));
}
