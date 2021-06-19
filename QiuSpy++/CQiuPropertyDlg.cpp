// CProperty.cpp : implementation file
//

#include "pch.h"
#include "QiuSpy++.h"
#include "CQiuPropertyDlg.h"
#include "afxdialogex.h"


// CProperty dialog

IMPLEMENT_DYNAMIC(CQiuPropertyDlg, CDialogEx)

CQiuPropertyDlg::CQiuPropertyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DLG_PROPERTY, pParent)
{
    this->m_hHandle = nullptr;
}

CQiuPropertyDlg::~CQiuPropertyDlg()
{
}

void CQiuPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, TAB_PROPERTY, m_cTableCtrl);
}


BEGIN_MESSAGE_MAP(CQiuPropertyDlg, CDialogEx)
    ON_NOTIFY(TCN_SELCHANGE, TAB_PROPERTY, &CQiuPropertyDlg::OnSelchangeTabProperty)
    ON_BN_CLICKED(BTN_REFRESH, &CQiuPropertyDlg::OnBnClickedRefresh)
END_MESSAGE_MAP()


// CProperty message handlers


BOOL CQiuPropertyDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  Add extra initialization here

    //设置table ctrl 的标题
    this->m_cTableCtrl.InsertItem(0, "General");
    this->m_cTableCtrl.InsertItem(1, "Styles");
    this->m_cTableCtrl.InsertItem(2, "Windows");
    this->m_cTableCtrl.InsertItem(3, "Class");
    this->m_cTableCtrl.InsertItem(4, "Process");

    this->m_cPageGeneralDlg.m_hHandle = this->m_hHandle;
    this->m_cPageWindowDlg.m_hHandle = this->m_hHandle;
    this->m_cPageStyleDlg.m_hHandle = this->m_hHandle;
    this->m_cPageProcessDlg.m_hHandle = this->m_hHandle;
    this->m_cPageClassDlg.m_hHandle = this->m_hHandle;

    //创建窗口
    this->m_cPageGeneralDlg.Create(PAGE_GENERAL, &this->m_cTableCtrl);
    this->m_cPageWindowDlg.Create(PAGE_WINDOW, &this->m_cTableCtrl);
    this->m_cPageStyleDlg.Create(PAGE_STYLE, &this->m_cTableCtrl);
    this->m_cPageProcessDlg.Create(PAGE_PROCESS, &this->m_cTableCtrl);
    this->m_cPageClassDlg.Create(PAGE_CLASS, &this->m_cTableCtrl);

    //移动到合适位置
    CRect cRect;
    this->m_cTableCtrl.GetClientRect(&cRect);
    cRect.top += 20;

    this->m_cPageGeneralDlg.MoveWindow(cRect);
    this->m_cPageWindowDlg.MoveWindow(cRect);
    this->m_cPageStyleDlg.MoveWindow(cRect);
    this->m_cPageProcessDlg.MoveWindow(cRect);
    this->m_cPageClassDlg.MoveWindow(cRect);

    this->m_cPageGeneralDlg.ShowWindow(SW_SHOW);

    this->m_cPageWindowDlg.m_pWnd = this;

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}


void CQiuPropertyDlg::OnSelchangeTabProperty(NMHDR* pNMHDR, LRESULT* pResult)
{
    // TODO: Add your control notification handler code here

    int nIndex = this->m_cTableCtrl.GetCurSel();

    //隐藏所有窗口
    this->m_cPageGeneralDlg.ShowWindow(SW_HIDE);
    this->m_cPageWindowDlg.ShowWindow(SW_HIDE);
    this->m_cPageStyleDlg.ShowWindow(SW_HIDE);
    this->m_cPageProcessDlg.ShowWindow(SW_HIDE);
    this->m_cPageClassDlg.ShowWindow(SW_HIDE);

    //切换显示
    switch (nIndex)
    {
    case 0:
        this->m_cPageGeneralDlg.ShowWindow(SW_SHOW);
        break;
    case 1:
        this->m_cPageStyleDlg.ShowWindow(SW_SHOW);
        break;
    case 2:
        this->m_cPageWindowDlg.ShowWindow(SW_SHOW);
        break;
    case 3:
        this->m_cPageClassDlg.ShowWindow(SW_SHOW);
        break;
    case 4:
        this->m_cPageProcessDlg.ShowWindow(SW_SHOW);
        break;
    }


    *pResult = 0;
}


void CQiuPropertyDlg::OnBnClickedRefresh()
{
    // TODO: Add your control notification handler code here

    this->m_cPageGeneralDlg.m_hHandle = this->m_hHandle;
    this->m_cPageWindowDlg.m_hHandle = this->m_hHandle;
    this->m_cPageStyleDlg.m_hHandle = this->m_hHandle;
    this->m_cPageProcessDlg.m_hHandle = this->m_hHandle;
    this->m_cPageClassDlg.m_hHandle = this->m_hHandle;

    this->m_cPageGeneralDlg.OnInitDialog();
    this->m_cPageWindowDlg.OnInitDialog();
    this->m_cPageStyleDlg.OnInitDialog();
    this->m_cPageProcessDlg.OnInitDialog();
    this->m_cPageClassDlg.OnInitDialog();
}

