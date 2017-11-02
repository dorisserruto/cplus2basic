///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );
	
	mbar->Append( fileMenu, wxT("&File") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, wxT("&Help") ); 
	
	this->SetMenuBar( mbar );
	
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmapfunc = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_bitmapfunc, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_txtFuncion = new wxStaticText( this, wxID_ANY, wxT("Haga click en la funcion que desea graficar"), wxDefaultPosition, wxDefaultSize, 0 );
	m_txtFuncion->Wrap( -1 );
	bSizer1->Add( m_txtFuncion, 0, wxALL, 5 );
	
	m_btnFncConst = new wxButton( this, wxID_ANY, wxT("Funcion Constante"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_btnFncConst, 0, wxALL, 5 );
	
	m_btnFncIdent = new wxButton( this, wxID_ANY, wxT("Funcion Identidad"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_btnFncIdent, 0, wxALL, 5 );
	
	m_btnFncSeno = new wxButton( this, wxID_ANY, wxT("Funcion Seno       "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_btnFncSeno, 0, wxALL, 5 );
	
	m_btnFncCos = new wxButton( this, wxID_ANY, wxT("Funcion Coseno   "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_btnFncCos, 0, wxALL, 5 );
	
	m_btnFncVAbs = new wxButton( this, wxID_ANY, wxT("Funcion V. Absoluto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_btnFncVAbs, 0, wxALL, 5 );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Funcion Logaritmo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_button6, 0, wxALL, 5 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Funcion Exponencial"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_button7, 0, wxALL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_btnFncConst->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncConstOnButtonClick ), NULL, this );
	m_btnFncIdent->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncIdentOnButtonClick ), NULL, this );
	m_btnFncSeno->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncSenoOnButtonClick ), NULL, this );
	m_btnFncCos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncCosOnButtonClick ), NULL, this );
	m_btnFncVAbs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncVAbsOnButtonClick ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_button6OnButtonClick ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_button7OnButtonClick ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_btnFncConst->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncConstOnButtonClick ), NULL, this );
	m_btnFncIdent->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncIdentOnButtonClick ), NULL, this );
	m_btnFncSeno->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncSenoOnButtonClick ), NULL, this );
	m_btnFncCos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncCosOnButtonClick ), NULL, this );
	m_btnFncVAbs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_btnFncVAbsOnButtonClick ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_button6OnButtonClick ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::m_button7OnButtonClick ), NULL, this );
	
}
