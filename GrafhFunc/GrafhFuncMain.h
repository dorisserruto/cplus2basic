/***************************************************************
 * Name:      GrafhFuncMain.h
 * Purpose:   Defines Application Frame
 * Author:    Doris Serruto (doris.serruto@ucsp.edu.pe)
 * Created:   2010-06-11
 * Copyright: Doris Serruto ()
 * License:
 **************************************************************/

#ifndef GRAFHFUNCMAIN_H
#define GRAFHFUNCMAIN_H



#include "GrafhFuncApp.h"


#include "GUIFrame.h"

class GrafhFuncFrame: public GUIFrame
{
    public:
        GrafhFuncFrame(wxFrame *frame);
        ~GrafhFuncFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // GRAFHFUNCMAIN_H
