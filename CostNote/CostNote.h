// CostNote.h : main header file for the COSTNOTE application
//

#if !defined(AFX_COSTNOTE_H__3D07B09D_A861_4CA2_AC27_B13BF58C22DD__INCLUDED_)
#define AFX_COSTNOTE_H__3D07B09D_A861_4CA2_AC27_B13BF58C22DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Login.h"
/////////////////////////////////////////////////////////////////////////////
// CCostNoteApp:
// See CostNote.cpp for the implementation of this class
//

class CCostNoteApp : public CWinApp
{
public:
	CCostNoteApp();
	// 定义ADO连接变量指针
	_ConnectionPtr	m_pConnection;
	Login loginTemp;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCostNoteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCostNoteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COSTNOTE_H__3D07B09D_A861_4CA2_AC27_B13BF58C22DD__INCLUDED_)
