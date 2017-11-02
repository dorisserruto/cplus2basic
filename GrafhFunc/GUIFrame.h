///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuQuit 1000
#define idMenuAbout 1001

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxStatusBar* statusBar;
		wxStaticBitmap* m_bitmapfunc;
		wxStaticText* m_txtFuncion;
		wxButton* m_btnFncConst;
		wxButton* m_btnFncIdent;
		wxButton* m_btnFncSeno;
		wxButton* m_btnFncCos;
		wxButton* m_btnFncVAbs;
		wxButton* m_button6;
		wxButton* m_button7;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_btnFncConstOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_btnFncIdentOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_btnFncSenoOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_btnFncCosOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_btnFncVAbsOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button6OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button7OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++: GRAFICADOR DE FUNCIONES"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 509,440 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUIFrame();
	
};

#endif //__GUIFrame__
