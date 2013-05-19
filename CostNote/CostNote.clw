; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Login
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CostNote.h"

ClassCount=5
Class1=CCostNoteApp
Class2=CCostNoteDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_COSTNOTE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_Salary
Class4=SalaryItems
Resource4=IDD_ABOUTBOX
Resource5=IDD_PROPPAGE_SMALL (English (U.S.))
Class5=Login
Resource6=IDD_Login
Resource7=IDR_MENU1

[CLS:CCostNoteApp]
Type=0
HeaderFile=CostNote.h
ImplementationFile=CostNote.cpp
Filter=N

[CLS:CCostNoteDlg]
Type=0
HeaderFile=CostNoteDlg.h
ImplementationFile=CostNoteDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SalaryItems

[CLS:CAboutDlg]
Type=0
HeaderFile=CostNoteDlg.h
ImplementationFile=CostNoteDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COSTNOTE_DIALOG]
Type=1
Class=CCostNoteDlg
ControlCount=12
Control1=IDC_MainList,SysListView32,1350632453
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC1,static,1342308352
Control4=IDC_STATIC2,static,1342308352
Control5=IDC_STATIC3,static,1342308352
Control6=IDC_DateTime,SysDateTimePick32,1342242848
Control7=IDC_Amount,edit,1350631552
Control8=IDC_Type,combobox,1344340227
Control9=IDC_Describe,edit,1350631552
Control10=IDC_AddNewRecords,button,1342242816
Control11=IDC_SalaryItems,button,1342242816
Control12=IDC_ReLogin,button,1342242816

[CLS:SalaryItems]
Type=0
HeaderFile=SalaryItems.h
ImplementationFile=SalaryItems.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_1

[DLG:IDD_Salary]
Type=1
Class=SalaryItems
ControlCount=32
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SalaryItems,SysListView32,1350631425
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_1,edit,1350633600
Control8=IDC_11,edit,1350633600
Control9=IDC_111,edit,1350633600
Control10=IDC_2,edit,1350633600
Control11=IDC_12,edit,1350633600
Control12=IDC_112,edit,1350633600
Control13=IDC_3,edit,1350633600
Control14=IDC_13,edit,1350633600
Control15=IDC_113,edit,1350633600
Control16=IDC_4,edit,1350633600
Control17=IDC_14,edit,1350633600
Control18=IDC_114,edit,1350633600
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_5,edit,1350633600
Control24=IDC_15,edit,1350633600
Control25=IDC_115,edit,1350633600
Control26=IDC_6,edit,1350633600
Control27=IDC_16,edit,1350633600
Control28=IDC_116,edit,1350633600
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_Total,edit,1350633600
Control32=IDC_ComTotal,edit,1350633600

[DLG:IDD_PROPPAGE_SMALL (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:Login]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_Name
VirtualFilter=dWC

[DLG:IDD_Login]
Type=1
Class=Login
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_Name,edit,1350631552
Control6=IDC_Password,edit,1350631584
Control7=IDC_wrong,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
CommandCount=0

