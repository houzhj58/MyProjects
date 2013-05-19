#if !defined(AFX_SALARYITEMS_H__37B3C178_C6E3_48A9_837B_C239572A5133__INCLUDED_)
#define AFX_SALARYITEMS_H__37B3C178_C6E3_48A9_837B_C239572A5133__INCLUDED_
#include "resource.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SalaryItems.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SalaryItems dialog

class SalaryItems : public CDialog
{
// Construction
public:
	SalaryItems(CWnd* pParent = NULL);   // standard constructor
	void SalaryItemsCal(long Salary);

// Dialog Data
	//{{AFX_DATA(SalaryItems)
	enum { IDD = IDD_Salary };
	CListCtrl	m_SalaryItems;
	_RecordsetPtr	m_pRecordset;
	long            m_lSalary;
	long	m_yanglao;
	long	m_Comyanglao;
	long	m_Totalyanglao;
	long	m_Totalyiliao;
	long	m_Totalshiye;
	long	m_Totalgongshang;
	double	m_Totalshengyu;
	long	m_Totalgongjijin;
	long	m_Comyiliao;
	long	m_Comshiye;
	long	m_Comgongshang;
	long	m_Comshengyu;
	long	m_Comgongjijin;
	long	m_yiliao;
	long	m_shiye;
	long	m_gongshang;
	long	m_shengyu;
	long	m_gongjijin;
	long	m_Total;
	long	m_ComTotal;
	int     m_mounths;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SalaryItems)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SalaryItems)
	afx_msg void OnClickSalaryItems(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SALARYITEMS_H__37B3C178_C6E3_48A9_837B_C239572A5133__INCLUDED_)
