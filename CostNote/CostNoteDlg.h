// CostNoteDlg.h : header file
//

#if !defined(AFX_COSTNOTEDLG_H__AAA170A6_0B44_419B_AE86_7E8CAEDC7CFA__INCLUDED_)
#define AFX_COSTNOTEDLG_H__AAA170A6_0B44_419B_AE86_7E8CAEDC7CFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCostNoteDlg dialog
struct  Record
{
	CString strAmount;
	CString strDateTime;
	CString	strDescribe;
	CString	strType;
	CString	strTotalAmount;
	
};
class CMyList: public CListCtrl
{
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
private:
};
class CCostNoteDlg : public CDialog
{
// Construction
public:
	CCostNoteDlg(CWnd* pParent = NULL);	// standard constructor
	// 定义ADO连接、命令、记录集变量指针
	_ConnectionPtr	m_pConnection;
	_CommandPtr		m_pCommand;
	_RecordsetPtr	m_pRecordset;
	CString         m_strTotalAmount;
	bool  ReadRecords();
	Record  Records;
	CMenu  m_Menu;
	CRect	m_rect;
	HBRUSH   m_hbrush;  

// Dialog Data
	//{{AFX_DATA(CCostNoteDlg)
	enum { IDD = IDD_COSTNOTE_DIALOG };
	CComboBox	m_Types;
	CMyList	m_MainList;
	CString	m_Amount;
	CTime	m_DateTime;
	CString	m_Describe;
	CString	m_Type;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCostNoteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCostNoteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddNewRecords();
	afx_msg void OnSalaryItems();
	afx_msg void OnClickMainList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReLogin();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COSTNOTEDLG_H__AAA170A6_0B44_419B_AE86_7E8CAEDC7CFA__INCLUDED_)
