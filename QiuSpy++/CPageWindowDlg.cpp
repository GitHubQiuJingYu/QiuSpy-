// CPageWindowDlg.cpp : implementation file
//

#include "pch.h"
#include "QiuSpy++.h"
#include "CPageWindowDlg.h"
#include "afxdialogex.h"

#include "CQiuPropertyDlg.h"
// CPageWindowDlg dialog

IMPLEMENT_DYNAMIC(CPageWindowDlg, CDialogEx)

CPageWindowDlg::CPageWindowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(PAGE_WINDOW, pParent)
{
    
    this->m_hHandle = nullptr;             
    this->m_hPreHandle = nullptr;
    this->m_hNextHandle = nullptr;
    this->m_hParentHandle = nullptr;
    this->m_hFirstChildHandle = nullptr;
    this->m_hOwnerHandle = nullptr;

    this->m_pWnd = nullptr;
}

CPageWindowDlg::~CPageWindowDlg()
{
}

void CPageWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

CString CPageWindowDlg::HandleToString(HWND hWnd)
{
    CString strBuffer;

    if (hWnd == nullptr)
    {
        strBuffer.Format("(None)");

    }
    else
    {
        strBuffer.Format("%08X", (DWORD)hWnd);
    }
    return strBuffer;
}

CString CPageWindowDlg::GetHandleCaption(HWND hWnd)
{
    CString strBuffer;
    char szBuffer[255] = { 0 };

    ::GetWindowText(hWnd, szBuffer, 255);

    strBuffer.Format("%s", szBuffer);
    return strBuffer;
}


BEGIN_MESSAGE_MAP(CPageWindowDlg, CDialogEx)
    ON_STN_CLICKED(TEXT_NEXT_WINDOW_HANDLE, &CPageWindowDlg::OnClickedTextNextWindowHandle)
    ON_STN_CLICKED(TEXT_PREVIOUS_WINDOW_HANDLE, &CPageWindowDlg::OnClickedTextPreviousWindowHandle)
    ON_STN_CLICKED(TEXT_PARENT_WINDOW_HANDLE, &CPageWindowDlg::OnClickedTextParentWindowHandle)
    ON_STN_CLICKED(TEXT_OWNER_WINDOW_HANDLE, &CPageWindowDlg::OnClickedTextOwnerWindowHandle)
    ON_STN_CLICKED(TEXT_FIRSTCHILD_WINDOW_HANDLE, &CPageWindowDlg::OnClickedTextFirstchildWindowHandle)
END_MESSAGE_MAP()


// CPageWindowDlg message handlers


BOOL CPageWindowDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  Add extra initialization here
    //为所有的句柄赋值
    this->m_hPreHandle = ::GetWindow(this->m_hHandle, GW_HWNDPREV);
    this->m_hNextHandle = ::GetWindow(this->m_hHandle, GW_HWNDNEXT);
    this->m_hParentHandle = ::GetParent(this->m_hHandle);
    if (this->m_hParentHandle == nullptr && this->m_hHandle != (HWND)0x00010010)    //父窗口是Desktop
    {
        this->m_hParentHandle = (HWND)0x00010010;
    }
    else if (this->m_hHandle == (HWND)0x00010010)
    {
        this->m_hParentHandle = nullptr;
    }
    this->m_hFirstChildHandle = ::GetWindow(this->m_hHandle, GW_CHILD);
    this->m_hOwnerHandle = ::GetWindow(this->m_hHandle, GW_OWNER);

    SetDlgItemText(TEXT_NEXT_WINDOW_HANDLE, this->HandleToString(this->m_hNextHandle));
    SetDlgItemText(TEXT_PREVIOUS_WINDOW_HANDLE, this->HandleToString(this->m_hPreHandle));
    SetDlgItemText(TEXT_PARENT_WINDOW_HANDLE, this->HandleToString(this->m_hParentHandle));
    SetDlgItemText(TEXT_FIRSTCHILD_WINDOW_HANDLE, this->HandleToString(this->m_hFirstChildHandle));
    SetDlgItemText(TEXT_OWNER_WINDOW_HANDLE, this->HandleToString(this->m_hOwnerHandle));

    SetDlgItemText(EDIT_NEXT_WINDOW_CAPTION, this->GetHandleCaption(this->m_hNextHandle));
    SetDlgItemText(EDIT_PREVIOUS_WINDOW_CAPTION, this->GetHandleCaption(this->m_hPreHandle));
    SetDlgItemText(EDIT_PARENT_WINDOW_CAPTION, this->GetHandleCaption(this->m_hParentHandle));
    SetDlgItemText(EDIT_FIRSTCHILD_WINDOW_CAPTION, this->GetHandleCaption(this->m_hFirstChildHandle));
    SetDlgItemText(EDIT_OWNER_WINDOW_CAPTION, this->GetHandleCaption(this->m_hOwnerHandle));

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPageWindowDlg::OnClickedTextNextWindowHandle()
{
    // TODO: Add your control notification handler code here
    if (this->m_hNextHandle != nullptr)
    {
        ((CQiuPropertyDlg*)this->m_pWnd)->m_hHandle = this->m_hNextHandle;
        ((CQiuPropertyDlg*)this->m_pWnd)->OnBnClickedRefresh();
    }
    //this->m_hParentHandle
}

void CPageWindowDlg::OnClickedTextPreviousWindowHandle()
{
    // TODO: Add your control notification handler code here
    if (this->m_hPreHandle != nullptr)
    {
        ((CQiuPropertyDlg*)this->m_pWnd)->m_hHandle = this->m_hPreHandle;
        ((CQiuPropertyDlg*)this->m_pWnd)->OnBnClickedRefresh();
    }
}


void CPageWindowDlg::OnClickedTextParentWindowHandle()
{
    // TODO: Add your control notification handler code here
    if (this->m_hParentHandle != nullptr)
    {
        ((CQiuPropertyDlg*)this->m_pWnd)->m_hHandle = this->m_hParentHandle;
        ((CQiuPropertyDlg*)this->m_pWnd)->OnBnClickedRefresh();
    }
}


void CPageWindowDlg::OnClickedTextOwnerWindowHandle()
{
    // TODO: Add your control notification handler code here
    if (this->m_hOwnerHandle != nullptr)
    {
        ((CQiuPropertyDlg*)this->m_pWnd)->m_hHandle = this->m_hOwnerHandle;
        ((CQiuPropertyDlg*)this->m_pWnd)->OnBnClickedRefresh();
    }
}


void CPageWindowDlg::OnClickedTextFirstchildWindowHandle()
{
    // TODO: Add your control notification handler code here
    if (this->m_hFirstChildHandle != nullptr)
    {
        ((CQiuPropertyDlg*)this->m_pWnd)->m_hHandle = this->m_hFirstChildHandle;
        ((CQiuPropertyDlg*)this->m_pWnd)->OnBnClickedRefresh();
    }
}
