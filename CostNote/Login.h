#if !defined(AFX_LOGIN_H__A4535191_83CF_4952_84A1_87E7A8AA3C52__INCLUDED_)
#define AFX_LOGIN_H__A4535191_83CF_4952_84A1_87E7A8AA3C52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Login dialog

class Login : public CDialog
{
// Construction
public:
	Login(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Login)
	enum { IDD = IDD_Login };
	CString	m_name;
	CString	m_password;
	CString	m_wrongmessage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Login)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Login)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__A4535191_83CF_4952_84A1_87E7A8AA3C52__INCLUDED_)
