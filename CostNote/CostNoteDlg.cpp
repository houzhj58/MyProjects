// CostNoteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CostNote.h"
#include "CostNoteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern CCostNoteApp theApp;       // �ڴ�����Ӧ�����е�theApp����ȡ������ָ��
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCostNoteDlg dialog

CCostNoteDlg::CCostNoteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCostNoteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCostNoteDlg)
	m_Amount = _T("");
	m_DateTime = 0;
	m_Describe = _T("");
	m_Type = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCostNoteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCostNoteDlg)
	DDX_Control(pDX, IDC_Type, m_Types);
	DDX_Control(pDX, IDC_MainList, m_MainList);
	DDX_Text(pDX, IDC_Amount, m_Amount);
	DDX_DateTimeCtrl(pDX, IDC_DateTime, m_DateTime);
	DDX_Text(pDX, IDC_Describe, m_Describe);
	DDX_CBString(pDX, IDC_Type, m_Type);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCostNoteDlg, CDialog)
	//{{AFX_MSG_MAP(CCostNoteDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AddNewRecords, OnAddNewRecords)
	ON_BN_CLICKED(IDC_SalaryItems, OnSalaryItems)
	ON_NOTIFY(NM_CLICK, IDC_MainList, OnClickMainList)
	ON_BN_CLICKED(IDC_ReLogin, OnReLogin)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCostNoteDlg message handlers

BOOL CCostNoteDlg::OnInitDialog()
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
	m_Menu.LoadMenu(IDR_MENU1);  
    SetMenu(&m_Menu);  
	GetClientRect(&m_rect);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_hbrush=CreateSolidBrush(RGB(255,255,0));
	m_MainList.SetExtendedStyle(LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT);
	m_MainList.ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_LIST, LVS_REPORT);
    m_MainList.InsertColumn(0,"��������",LVCFMT_LEFT,160);
	m_MainList.InsertColumn(1,"���׽��",LVCFMT_LEFT,100);
	m_MainList.InsertColumn(2,"��������",LVCFMT_LEFT,160);
	m_MainList.InsertColumn(3,"��ǰ���",LVCFMT_LEFT,100);
	m_MainList.InsertColumn(4,"���ױ�ע",LVCFMT_LEFT,360);
	m_Types.AddString("֧��");
	m_Types.AddString("����");
	m_Types.AddString("����");
	m_Types.AddString("���");
	m_Types.SetCurSel(3);
	//����ʱ��ѡ�����ĳ�ʼʱ��Ϊ���ڵ�ʱ��
	COleDateTime oleDate = COleDateTime::GetCurrentTime();  
	((CDateTimeCtrl *)GetDlgItem(IDC_DateTime))->SetTime(oleDate); 

	// ʹ��ADO�������ݿ��¼��
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	try
	{
		m_pRecordset->Open("SELECT * FROM CostNote",                // ��ѯstudentinfo���������ֶ�
							theApp.m_pConnection.GetInterfacePtr(),	   // ��ȡ��ӿ��IDispatchָ��
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	if (!ReadRecords())
	{
		AfxMessageBox("��ȡ���ݿ����!");
	} 
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCostNoteDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCostNoteDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCostNoteDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
bool CCostNoteDlg::ReadRecords()
{
	_variant_t var;
	try
	{
		if(!m_pRecordset->BOF)
			m_pRecordset->MoveFirst();
		else
		{
			AfxMessageBox("��������Ϊ��");
			return false;
		}
		// ������и��ֶβ������б����
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("����");
			if(var.vt != VT_NULL)
				Records.strDateTime= (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("���");
			if(var.vt != VT_NULL)
				Records.strAmount = (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("����");
			if(var.vt != VT_NULL)
				Records.strType= (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("���");
			if(var.vt != VT_NULL)
				Records.strTotalAmount= (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("��ע");
			if(var.vt != VT_NULL)
				Records.strDescribe= (LPCSTR)_bstr_t(var);
			m_MainList.InsertItem(0,Records.strDateTime);
			m_MainList.SetItemText(0,1,Records.strAmount);
			m_MainList.SetItemText(0,2,Records.strType);
			m_MainList.SetItemText(0,3,Records.strTotalAmount);
			m_MainList.SetItemText(0,4,Records.strDescribe);
			m_strTotalAmount = Records.strTotalAmount;
			m_pRecordset->MoveNext();
		}
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
		return false;
	}
	return true;
}

void CCostNoteDlg::OnAddNewRecords() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Records.strAmount = m_Amount;
	Records.strDateTime =  m_DateTime.Format("%Y-%m-%d");
	Records.strDescribe = m_Describe;
	Records.strType = m_Type;	

	long m_lTotalAmount,m_lAmount;
	m_lAmount = atoi(m_Amount);
	m_lTotalAmount = atoi(m_strTotalAmount);
	if (m_Type == "����"||
		m_Type == "����")
	{
		m_lTotalAmount += m_lAmount;
	} 
	else
	{
		m_lTotalAmount -= m_lAmount;
	}
	Records.strTotalAmount.Format("%d",m_lTotalAmount);
	if(Records.strAmount == ""||Records.strType == "")
	{
		AfxMessageBox("���׽���������Ϣ����Ϊ��!");
		return;
	}
	try
	{
		// д����ֶ�ֵ
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("���", _variant_t(Records.strAmount));
		m_pRecordset->PutCollect("����", _variant_t(Records.strDateTime));
		m_pRecordset->PutCollect("��ע", _variant_t(Records.strDescribe));
		m_pRecordset->PutCollect("����", _variant_t(Records.strType));
		m_pRecordset->PutCollect("���", _variant_t(Records.strTotalAmount));
		m_pRecordset->Update();
		AfxMessageBox("������ݳɹ�!");
		m_MainList.DeleteAllItems();
		if (!ReadRecords())
		{
		AfxMessageBox("�������ݿ����!");
		} 
		m_Describe = "";
		m_Amount   = "";
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	UpdateData(FALSE);
}

void CCostNoteDlg::OnSalaryItems() 
{
	// TODO: Add your control notification handler code here
	SalaryItems SalaryItem;
	SalaryItem.m_pRecordset = m_pRecordset ;
	SalaryItem.DoModal();
}

void CCostNoteDlg::OnClickMainList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CCostNoteDlg::OnReLogin() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CCostNoteDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CWnd *pWnd;
	for (int iID = -1;iID <=1036;iID++)
	{
		if (( iID>= 1000&& iID <1006)|| iID == 1008||(iID>1032 &&iID <1037)||iID == -1)
		{
			pWnd = GetDlgItem(iID);     //��ȡ�ؼ����
			if(pWnd && nType!=1)//�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����
			{
				CRect rect;   //��ȡ�ؼ��仯ǰ��С
				pWnd->GetWindowRect(&rect);
				ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
				// cx/m_rect.Width()Ϊ�Ի����ں���ı仯����
				rect.left=rect.left*cx/m_rect.Width();/////�����ؼ���С
				rect.right=rect.right*cx/m_rect.Width();
				rect.top=rect.top*cy/m_rect.Height();
				rect.bottom=rect.bottom*cy/m_rect.Height();
				pWnd->MoveWindow(rect);//���ÿؼ���С
			}
		}
	}
    GetClientRect(&m_rect);//���仯��ĶԻ����С��Ϊ�ɴ�С
}


void CMyList::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
   /* CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);  
    COLORREF crOldTextColor = RGB(250,23,70);;  
    COLORREF crOldBkColor = pDC->GetBkColor();  
	COLORREF crText = RGB(250,23,70);
    COLORREF crBack = RGB(240,230,140);
	CFont   font;  
	LOGFONT   log;  
	GetObject(::GetStockObject(DEFAULT_GUI_FONT),sizeof(log),&log);
	log.lfHeight=25;      //����߶�
	log.lfWidth=10;       //������
	log.lfWeight = 500;   //����ֶ�
	log.lfCharSet=GB2312_CHARSET;  
	lstrcpy(log.lfFaceName,"����");  
	font.CreateFontIndirect(&log);
	pDC->SelectObject(&font); //����������
    pDC->SetTextColor(crText);  
    pDC->SetBkColor(crBack);  
	//���ѡ���ѡ��״̬,��������������ɫ
	if( (lpDrawItemStruct->itemAction | ODA_SELECT) && (lpDrawItemStruct->itemState & ODS_SELECTED) )  
	{  
		pDC->SetTextColor( RGB(178,34,34));  
		pDC->SetBkColor(crBack);  
		pDC->FillSolidRect(&lpDrawItemStruct->rcItem, crBack);  
	}   
	//���ѡ���δѡ��״̬,�����������ɫ
	else{
		pDC->FillSolidRect(&lpDrawItemStruct->rcItem,   RGB(111,250,250));   
		
		CString itemString;
	//	GetText(lpDrawItemStruct->itemID, itemString );   //�õ���
		
		// SetItemHeight(0,log.lfHeight+10); //����box���ӵĸ߶�
		
		DrawText(lpDrawItemStruct->hDC, itemString, -1, &lpDrawItemStruct->rcItem, DT_LEFT | DT_SINGLELINE); // restore DC colors
		pDC->SetTextColor(crOldTextColor);   //�ָ�������ɫ
		pDC->SetBkColor(crOldBkColor);       //�ָ�������ɫ
 	} */ 
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect(lpDrawItemStruct->rcItem);                //ȡ�û�������
    int iItem = lpDrawItemStruct->itemID;                  //ȡ����
    TCHAR szBuff[MAX_PATH];
    LVITEM lvItem;               //ȡ��Item����LVITEM�ṹ��
    int iColumn = 0;            //DRAWITEMSTRUCT�в�������item������Ϣ
	
    CHeaderCtrl *Head = GetHeaderCtrl();
    int iMax = Head->GetItemCount();             //ȡ��������
    while(iMax > iColumn)
	{
        //����Ϊ��λ���д����ɸ����Լ���Ҫ����д���
        //ȡ��Item��������
        lvItem.mask = LVIF_TEXT;// | LVIF_IMAGE | LVIF_STATE | LVIF_INDENT;
        lvItem.iItem = iItem;
        lvItem.iSubItem = iColumn;
        lvItem.pszText = szBuff;
        lvItem.cchTextMax = sizeof(szBuff);
		//    lvItem.stateMask = LVIS_ACTIVATING | LVIS_FOCUSED | LVIS_SELECTED | LVIS_STATEIMAGEMASK;
        COLORREF txtColor;               //�ı���ɫ
        DWORD uformat;                    //�ı���ʽ
        CFont font;                               //�ı�����
        LOGFONT lf;
	//	COLORREF crBack = RGB(240,230,140);
//         if (iColumn < 1)
//         {
//             //��������
//             GetFont()->GetLogFont( &lf );
//             lf.lfHeight = abs(lf.lfHeight) + 2;
//             lf.lfWeight = FW_BOLD;
//             VERIFY(font.CreateFontIndirect(&lf));
//             pDC->SelectObject(font.m_hObject);
//             //������ɫ
//             txtColor = GetSysColor(COLOR_WINDOWTEXT);
//             pDC->SetTextColor(txtColor);
//             //ȡ�û�������
//             GetSubItemRect(iItem, iColumn, LVIR_BOUNDS, rect);
//             //�����ı���ʽ
//             uformat = DT_WORD_ELLIPSIS | DT_SINGLELINE | DT_LEFT | DT_VCENTER;
//         }
//         else
//         {
            GetFont()->GetLogFont( &lf );
			
			CString CSTempType = this->GetItemText(iItem,2);
			if (CSTempType == "����")
			{
				txtColor = RGB(0,250,0);
			//	pDC->FillSolidRect(&lpDrawItemStruct->rcItem, crBack);
			//	pDC->SetBkColor(crBack); 
			} else if (CSTempType == "���")
			{
				txtColor = RGB(250,0,0);
			}else if(CSTempType == "����"){
				txtColor = RGB(0,0,250);
			} else
			{
				txtColor = GetSysColor(COLOR_WINDOWTEXT);
			}
			//pDC->SetTextColor( RGB(178,34,34)); 
	 		//pDC->FillSolidRect(&lpDrawItemStruct->rcItem, crBack);  
            pDC->SelectObject(GetFont()->m_hObject);
            pDC->SetTextColor(txtColor );
            GetSubItemRect(iItem, iColumn, LVIR_BOUNDS, rect);
            uformat = DT_WORD_ELLIPSIS | DT_SINGLELINE | DT_LEFT | DT_VCENTER;
       // }
        GetItem(&lvItem);
        pDC->DrawText(lvItem.pszText, rect, uformat);                //�����ı�
        iColumn++;
    }
}

HBRUSH CCostNoteDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor==   CTLCOLOR_LISTBOX)   
	{   
        pDC->SetBkMode(TRANSPARENT);   
		//�˴������������ɫ   
	//	pDC->SetBkColor(RGB(0,0,255));
        pDC->SetTextColor(RGB(255,0,0)); 
        return   m_hbrush;   
	}
	//else   
       // return   CDialog::OnCtlColor(pDC,   pWnd,   nCtlColor);   
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
