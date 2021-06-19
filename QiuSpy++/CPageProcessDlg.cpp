// CPageProcessDlg.cpp : implementation file
//

#include "pch.h"
#include "QiuSpy++.h"
#include "CPageProcessDlg.h"
#include "afxdialogex.h"


// CPageProcessDlg dialog

IMPLEMENT_DYNAMIC(CPageProcessDlg, CDialogEx)

CPageProcessDlg::CPageProcessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(PAGE_PROCESS, pParent)
{
    this->m_hHandle = nullptr;
}

CPageProcessDlg::~CPageProcessDlg()
{
}

void CPageProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

CString CPageProcessDlg::GetProcessID(HWND hWnd)
{
    CString strBuffer;
    DWORD dwProcessID = 0;

    GetWindowThreadProcessId(hWnd, &dwProcessID);

    strBuffer.Format("%08X", dwProcessID);

    return strBuffer;
}

CString CPageProcessDlg::GetThreadID(HWND hWnd)
{
    CString strBuffer;
    DWORD dwThreadID = 0;

    dwThreadID = GetWindowThreadProcessId(hWnd, nullptr);

    strBuffer.Format("%08X", dwThreadID);

    return strBuffer;
}


BEGIN_MESSAGE_MAP(CPageProcessDlg, CDialogEx)
END_MESSAGE_MAP()


// CPageProcessDlg message handlers


BOOL CPageProcessDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  Add extra initialization here
    SetDlgItemText(TEXT_PROCESS_ID, this->GetProcessID(this->m_hHandle));
    SetDlgItemText(TEXT_THREAD_ID, this->GetThreadID(this->m_hHandle));



    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}
