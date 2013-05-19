// SalaryItems.cpp : implementation file
//

#include "stdafx.h"
#include "CostNote.h"
#include "SalaryItems.h"
#include "CostNoteDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SalaryItems dialog


SalaryItems::SalaryItems(CWnd* pParent /*=NULL*/)
	: CDialog(SalaryItems::IDD, pParent),m_lSalary(0)
{
	//{{AFX_DATA_INIT(SalaryItems)
	m_yanglao = 0;
	m_Comyanglao = 0;
	m_Totalyanglao = 0;
	m_Totalyiliao = 0;
	m_Totalshiye = 0;
	m_Totalgongshang = 0;
	m_Totalshengyu = 0.0;
	m_Totalgongjijin = 0;
	m_Comyiliao = 0;
	m_Comshiye = 0;
	m_Comgongshang = 0;
	m_Comshengyu = 0;
	m_Comgongjijin = 0;
	m_yiliao = 0;
	m_shiye = 0;
	m_gongshang = 0;
	m_shengyu = 0;
	m_gongjijin = 0;
	m_Total = 0;
	m_ComTotal = 0;
	m_mounths  = -1;
	//}}AFX_DATA_INIT
}


void SalaryItems::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SalaryItems)
	DDX_Control(pDX, IDC_SalaryItems, m_SalaryItems);
	DDX_Text(pDX, IDC_1, m_yanglao);
	DDX_Text(pDX, IDC_11, m_Comyanglao);
	DDX_Text(pDX, IDC_111, m_Totalyanglao);
	DDX_Text(pDX, IDC_112, m_Totalyiliao);
	DDX_Text(pDX, IDC_113, m_Totalshiye);
	DDX_Text(pDX, IDC_114, m_Totalgongshang);
	DDX_Text(pDX, IDC_115, m_Totalshengyu);
	DDX_Text(pDX, IDC_116, m_Totalgongjijin);
	DDX_Text(pDX, IDC_12, m_Comyiliao);
	DDX_Text(pDX, IDC_13, m_Comshiye);
	DDX_Text(pDX, IDC_14, m_Comgongshang);
	DDX_Text(pDX, IDC_15, m_Comshengyu);
	DDX_Text(pDX, IDC_16, m_Comgongjijin);
	DDX_Text(pDX, IDC_2, m_yiliao);
	DDX_Text(pDX, IDC_3, m_shiye);
	DDX_Text(pDX, IDC_4, m_gongshang);
	DDX_Text(pDX, IDC_5, m_shengyu);
	DDX_Text(pDX, IDC_6, m_gongjijin);
	DDX_Text(pDX, IDC_Total, m_Total);
	DDX_Text(pDX, IDC_ComTotal, m_ComTotal);
	//}}AFX_DATA_MAP
}
BOOL SalaryItems::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog	
	// TODO: Add extra initialization here
	m_SalaryItems.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT);
	m_SalaryItems.ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_LIST, LVS_REPORT);
    m_SalaryItems.InsertColumn(0,"发薪日期",LVCFMT_LEFT,110);
	m_SalaryItems.InsertColumn(1,"薪资金额",LVCFMT_LEFT,110);
	m_SalaryItems.InsertColumn(2,"薪资总额",LVCFMT_LEFT,130);

	_variant_t var;
	Record Records;
	try
	{
		if(!m_pRecordset->BOF)
			m_pRecordset->MoveFirst();
		else
		{
			AfxMessageBox("表内数据为空");
			return false;
		}
		// 读入库中各字段并加入列表框中
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("类型");
			if(var.vt != VT_NULL)
				Records.strType= (LPCSTR)_bstr_t(var);
			if ("工资" == Records.strType)
			{
				var = m_pRecordset->GetCollect("日期");
				if(var.vt != VT_NULL)
					Records.strDateTime= (LPCSTR)_bstr_t(var);
				var = m_pRecordset->GetCollect("金额");
				if(var.vt != VT_NULL)
					Records.strAmount = (LPCSTR)_bstr_t(var);
				m_lSalary += atoi(Records.strAmount);
				Records.strTotalAmount.Format("%d",m_lSalary);
				m_SalaryItems.InsertItem(0,Records.strDateTime);
				m_SalaryItems.SetItemText(0,1,Records.strAmount);
				m_SalaryItems.SetItemText(0,2,Records.strTotalAmount);
				m_mounths ++;
			}
			m_pRecordset->MoveNext();
		}
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
		return false;
	}
	SalaryItemsCal(m_lSalary);
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void SalaryItems::SalaryItemsCal(long Salary)
{
	UpdateData(TRUE);
	//Salary = Salary /0.81;
	Salary   = 3500*m_mounths;
	m_yanglao = Salary *0.08;
	m_yiliao = Salary *0.02;
	m_shiye = Salary *0.01;
	m_gongshang = Salary *0.00;
	m_shengyu = Salary *0.00;
	m_gongjijin = Salary *0.10;

	m_Comyanglao = Salary *0.19;
	m_Comyiliao = Salary *0.08;
	m_Comshiye = Salary *0.02;
	m_Comgongshang = Salary *0.02;
	m_Comshengyu = Salary *0.008;
	m_Comgongjijin = Salary *0.10;

	m_Totalyanglao= m_yanglao +m_Comyanglao;
	m_Totalyiliao= m_yiliao + m_Comyiliao;
	m_Totalshiye= m_shiye+m_Comshiye;
	m_Totalgongshang=m_gongshang+m_Comgongshang;
	m_Totalshengyu=m_shengyu+m_Comshengyu;
	m_Totalgongjijin=m_gongjijin+m_Comgongjijin;
	m_Total = m_yanglao+m_yiliao+m_shiye+m_gongshang+m_shengyu+m_gongjijin;
	m_ComTotal = m_Comyanglao+m_Comyiliao+m_Comshiye+m_Comgongshang+m_Comshengyu+m_Comgongjijin;
	UpdateData(FALSE);
}


BEGIN_MESSAGE_MAP(SalaryItems, CDialog)
	//{{AFX_MSG_MAP(SalaryItems)
	ON_NOTIFY(NM_CLICK, IDC_SalaryItems, OnClickSalaryItems)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SalaryItems message handlers


void SalaryItems::OnClickSalaryItems(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	POSITION pos = m_SalaryItems.GetFirstSelectedItemPosition();
	int nItem = m_SalaryItems.GetNextSelectedItem(pos);
	CString Salary = m_SalaryItems.GetItemText(nItem,2);
	m_lSalary = atoi(Salary);
	SalaryItemsCal(m_lSalary);
	UpdateData(FALSE);
	*pResult = 0;
}
