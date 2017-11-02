/***************************************************************
 * Name:      AcademicoPtrnMain.h
 * Purpose:   Defines Application Frame
 * Author:    Doris Serruto (doris.serruto@ucsp.edu.pe)
 * Created:   2010-05-28
 * Copyright: Doris Serruto ()
 * License:
 **************************************************************/

#ifndef ACADEMICOPTRNMAIN_H
#define ACADEMICOPTRNMAIN_H



#include "AcademicoPtrnApp.h"



#include "GUIDialog.h"

class AcademicoPtrnDialog: public GUIDialog
{
    public:
        AcademicoPtrnDialog(wxDialog *dlg);
        ~AcademicoPtrnDialog();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};
#endif // ACADEMICOPTRNMAIN_H
