// Login.cpp : implementation file
//

#include "stdafx.h"
#include "CostNote.h"
#include "Login.h"
#include "CostNoteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CCostNoteApp theApp;
/////////////////////////////////////////////////////////////////////////////
// Login dialog


Login::Login(CWnd* pParent /*=NULL*/)
	: CDialog(Login::IDD, pParent)
{
	//{{AFX_DATA_INIT(Login)
	m_name = _T("houzhijian");
	m_password = _T("");
	m_wrongmessage = _T("");
	//}}AFX_DATA_INIT
}


void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Login)
	DDX_Text(pDX, IDC_Name, m_name);
	DDX_Text(pDX, IDC_Password, m_password);
	DDX_Text(pDX, IDC_wrong, m_wrongmessage);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Login, CDialog)
	//{{AFX_MSG_MAP(Login)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Login message handlers

void Login::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (m_name == "houzhijian"
		&& m_password == "fml")
	{
		theApp.m_pMainWnd = NULL;
		this->ShowWindow(0);
		m_name = m_password = m_wrongmessage= "";
	//	UpdateData(FALSE);
	//	CCostNoteDlg costnotedlg;
		//costnotedlg.DoModal();
		CDialog::OnOK();
	}else
	{
		m_wrongmessage = "密码或用户名错误!";
		m_name = m_password =  "";
		UpdateData(FALSE);
	//	MessageBox("Password wrong!");
	}
}
