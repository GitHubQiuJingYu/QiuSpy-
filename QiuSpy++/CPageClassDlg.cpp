// CPageClassDlg.cpp : implementation file
//

#include "pch.h"
#include "QiuSpy++.h"
#include "CPageClassDlg.h"
#include "afxdialogex.h"


// CPageClassDlg dialog

IMPLEMENT_DYNAMIC(CPageClassDlg, CDialogEx)

CPageClassDlg::CPageClassDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(PAGE_CLASS, pParent)
{
    this->m_hHandle = nullptr;
}

CPageClassDlg::~CPageClassDlg()
{
}

void CPageClassDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, COM_CLASS_STYLES, m_cClassStyles);
    DDX_Control(pDX, COM_CLASS_BYTES, m_cClassBytes);
}

CString CPageClassDlg::GetHwndClassName(HWND hWnd)
{
    CString strBuffer;
    char szBuffer[255] = { 0 };

    ::GetClassName(hWnd, szBuffer, 255);

    strBuffer.Format("%s", szBuffer);
    return strBuffer;
}

CString CPageClassDlg::GetClassStyle(HWND hWnd)
{
    CString strBuffer;
    DWORD dwStyle = 0;

    //::GetClassName(hWnd, szBuffer, 255);
    if (::IsWindowUnicode(hWnd))
    {
        dwStyle = ::GetClassLongW(hWnd, GCL_STYLE);
    }
    else
    {
        dwStyle = ::GetClassLongA(hWnd, GCL_STYLE);
    }

    strBuffer.Format("%08X", dwStyle);

    //将样式添加到控件上
    if (dwStyle & CS_VREDRAW)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_VREDRAW");
    }
    if (dwStyle & CS_HREDRAW)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_HREDRAW");
    }
    if (dwStyle & CS_DBLCLKS)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_DBLCLKS");
    }
    if (dwStyle & CS_OWNDC)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_OWNDC");
    }
    if (dwStyle & CS_CLASSDC)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_CLASSDC");
    }
    if (dwStyle & CS_PARENTDC)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_PARENTDC");
    }
    if (dwStyle & CS_NOCLOSE)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_NOCLOSE");
    }
    if (dwStyle & CS_SAVEBITS)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_SAVEBITS");
    }
    if (dwStyle & CS_BYTEALIGNCLIENT)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_BYTEALIGNCLIENT");
    }
    if (dwStyle & CS_BYTEALIGNWINDOW)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_BYTEALIGNWINDOW");
    }
    if (dwStyle & CS_GLOBALCLASS)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_GLOBALCLASS");
    }
    if (dwStyle & CS_IME)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_IME");
    }
    if (dwStyle & CS_DROPSHADOW)
    {
        this->m_cClassStyles.InsertString(this->m_cClassStyles.GetCount(), "CS_DROPSHADOW");
    }

    //如果有属性，则选中第一个属性
    if (dwStyle)
    {
        this->m_cClassStyles.SetCurSel(0);
    }
    return strBuffer;
}

CString CPageClassDlg::GetClassBytesCount(HWND hWnd)
{
    CString strBuffer;
    char szBuffer[255] = { 0 };
    WNDCLASS wc = { 0 };

    ::GetClassName(hWnd, szBuffer, 255);
    if (::IsWindowUnicode(hWnd))
    {
        ::GetClassInfo((HINSTANCE)GetWindowLongW(hWnd, GWL_HINSTANCE), szBuffer, &wc);
    }
    else
    {
        ::GetClassInfo((HINSTANCE)GetWindowLongA(hWnd, GWL_HINSTANCE), szBuffer, &wc);
    }

    strBuffer.Format("%d", wc.cbClsExtra);
    return strBuffer;
}

CString CPageClassDlg::GetInstanceHandle(HWND hWnd)
{
    CString strBuffer;
    DWORD dwInstance = 0;

    if (::IsWindowUnicode(hWnd))
    {
        dwInstance = ::GetClassLongW(hWnd, GCL_HMODULE);
    }
    else
    {
        dwInstance = ::GetClassLongA(hWnd, GCL_HMODULE);
    }

    strBuffer.Format("%08X", dwInstance);
    return strBuffer;
}

CString CPageClassDlg::GetWinProc(HWND hWnd)
{
    CString strBuffer;
    DWORD dwWndProc = 0;

    if (::IsWindowUnicode(hWnd))
    {
        dwWndProc = ::GetClassLongW(hWnd, GCL_WNDPROC);
    }
    else
    {
        dwWndProc = ::GetClassLongA(hWnd, GCL_WNDPROC);
    }

    strBuffer.Format("%08X", dwWndProc);
    return strBuffer;
}

CString CPageClassDlg::GetMenuName(HWND hWnd)
{
    CString strBuffer;
    DWORD dwMenuName = 0;

    if (::IsWindowUnicode(hWnd))
    {
        dwMenuName = ::GetWindowLongW(hWnd, GCL_MENUNAME);
    }
    else
    {
        dwMenuName = ::GetWindowLongA(hWnd, GCL_MENUNAME);
    }

    strBuffer.Format("%08X", dwMenuName);
    return strBuffer;
}

CString CPageClassDlg::GetIconHandle(HWND hWnd)
{
    CString strBuffer;
    DWORD dwIcon = 0;

    if (::IsWindowUnicode(hWnd))
    {
        dwIcon = ::GetClassLongW(hWnd, GCL_HICON);
    }
    else
    {
        dwIcon = ::GetClassLongA(hWnd, GCL_HICON);
    }

    //auto id = ::GetDlgCtrlID((HWND)dwIcon);

    strBuffer.Format("%08X", dwIcon);
    return strBuffer;
}

CString CPageClassDlg::GetCursorHandle(HWND hWnd)
{
    CString strBuffer;
    DWORD dwCursor = 0;

    if (::IsWindowUnicode(hWnd))
    {
        dwCursor = ::GetClassLongW(hWnd, GCL_HCURSOR);
    }
    else
    {
        dwCursor = ::GetClassLongA(hWnd, GCL_HCURSOR);
    }

    strBuffer.Format("%08X", dwCursor);
    return strBuffer;
}

CString CPageClassDlg::GetBackgroundBrush(HWND hWnd)
{
    CString strBuffer;
    DWORD dwBrush = 0;

    if (::IsWindowUnicode(hWnd))
    {
        dwBrush = ::GetClassLongW(hWnd, GCL_HBRBACKGROUND);
    }
    else
    {
        dwBrush = ::GetClassLongA(hWnd, GCL_HBRBACKGROUND);
    }

    strBuffer.Format("%08X", dwBrush);
    return strBuffer;
}

CString CPageClassDlg::GetClassAtom(HWND hWnd)
{
    CString strBuffer;
    DWORD dwAtom = 0;

    if (::IsWindowUnicode(hWnd))
    {
        dwAtom = ::GetClassLongW(hWnd, GCW_ATOM);
    }
    else
    {
        dwAtom = ::GetClassLongA(hWnd, GCW_ATOM);
    }

    strBuffer.Format("%04X", dwAtom);
    return strBuffer;
}

CString CPageClassDlg::GetWindowBytes(HWND hWnd)
{
    CString strBuffer;

    //获取数据的大小  wc.cbWndExtra
    TCHAR szClassName[MAXBYTE] = { 0 };

    WNDCLASSA wc = { 0 };
    ::GetClassName(hWnd, szClassName, MAXBYTE);
    if (::IsWindowUnicode(hWnd))
    {
        ::GetClassInfo((HINSTANCE)::GetClassLongW(hWnd, GCL_HMODULE), szClassName, &wc);
    }
    else
    {
        ::GetClassInfo((HINSTANCE)::GetClassLongA(hWnd, GCL_HMODULE), szClassName, &wc);
    }

    strBuffer.Format("%X", wc.cbWndExtra);
    return strBuffer;
}

BEGIN_MESSAGE_MAP(CPageClassDlg, CDialogEx)
END_MESSAGE_MAP()


// CPageClassDlg message handlers


BOOL CPageClassDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  Add extra initialization here
    SetDlgItemText(EDIT_CLASS_NAME, this->GetHwndClassName(this->m_hHandle));
    SetDlgItemText(EDIT_CLASS_STYLE, this->GetClassStyle(this->m_hHandle));
    SetDlgItemText(EDIT_CLASS_BYTES, this->GetClassBytesCount(this->m_hHandle));
    SetDlgItemText(EDIT_INSRANCE_HANDLE_CLASS, this->GetInstanceHandle(this->m_hHandle));
    SetDlgItemText(EDIT_WINDOW_PROC_CLASS, this->GetWinProc(this->m_hHandle));
    SetDlgItemText(EDIT_MENU_NAME, this->GetMenuName(this->m_hHandle));
    SetDlgItemText(EDIT_ICON_HANDLE, this->GetIconHandle(this->m_hHandle));
    SetDlgItemText(EDIT_CURSOR_HANDLE, this->GetCursorHandle(this->m_hHandle));
    SetDlgItemText(EDIT_BKGND_BRUSH, this->GetBackgroundBrush(this->m_hHandle));
    SetDlgItemText(EDIT_CLASS_ATOM, this->GetClassAtom(this->m_hHandle));
    SetDlgItemText(EDIT_WINDOW_BYTES_CLASS, this->GetWindowBytes(this->m_hHandle));
    

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}
