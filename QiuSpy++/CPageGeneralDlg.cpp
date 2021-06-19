// CPageGeneralDlg.cpp : implementation file
//

#include "pch.h"
#include "QiuSpy++.h"
#include "CPageGeneralDlg.h"
#include "afxdialogex.h"


// CPageGeneralDlg dialog

IMPLEMENT_DYNAMIC(CPageGeneralDlg, CDialogEx)

CPageGeneralDlg::CPageGeneralDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(PAGE_GENERAL, pParent)
{
    this->m_hHandle = nullptr;
}

CPageGeneralDlg::~CPageGeneralDlg()
{
}

void CPageGeneralDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, COM_WINDOW_BYTES, m_cComBox);
}

CString CPageGeneralDlg::GetCaption(HWND hWnd)
{
    CString strBuffer;
    char szBuffer[255] = { 0 };

    ::GetWindowText(hWnd, szBuffer, 255);

    strBuffer.Format("%s", szBuffer);
    return strBuffer;
}

CString CPageGeneralDlg::GetHandle(HWND hWnd)
{
    CString strBuffer;

    strBuffer.Format("%08X", (DWORD)hWnd);
    return strBuffer;
}

CString CPageGeneralDlg::GetWinProc(HWND hWnd)
{
    CString strBuffer;
    LONG lAddress = 0;

    //区分是否是Unicode编码
    if (IsWindowUnicode(hWnd) == TRUE)
    {
        lAddress = GetClassLongW(hWnd, GCL_WNDPROC);
        strBuffer.Format("%08X (Unicode)", lAddress);
    }
    else
    {
        lAddress = GetClassLongA(hWnd, GCL_WNDPROC);
        strBuffer.Format("%08X", lAddress);
    }

    return strBuffer;
}

//窗口的边框。 矩形的大小也会显示。 单位是屏幕坐标中的像素。
CString CPageGeneralDlg::GetRectangle(HWND hWnd)
{
    CString strBuffer;

    CRect cRect;
    ::GetWindowRect(hWnd, &cRect);

    //判断是否最大化
    if (::IsZoomed(hWnd))
    {
        strBuffer.Format("(%d, %d)-(%d, %d) %d x %d (Maximized)",
            cRect.left, cRect.top,
            cRect.right, cRect.bottom,
            cRect.Width(), cRect.Height());
    }
    else
    {
        strBuffer.Format("(%d, %d)-(%d, %d) %d x %d",
            cRect.left, cRect.top,
            cRect.right, cRect.bottom,
            cRect.Width(), cRect.Height());
    }

    return strBuffer;
}

//还原的窗口的边框。 矩形的大小也会显示。 仅当窗口最大化或最小化时，还原矩形才会与矩形不同。 单位是屏幕坐标中的像素。
CString CPageGeneralDlg::GetRestoredRect(HWND hWnd)
{
    CString strBuffer;

    WINDOWPLACEMENT wp = {0};
    ::GetWindowPlacement(hWnd, &wp);

    CPoint cPoint1(wp.rcNormalPosition.left, wp.rcNormalPosition.top);
    CPoint cPoint2(wp.rcNormalPosition.right, wp.rcNormalPosition.bottom);

    //转换坐标
    ::ClientToScreen(hWnd, &cPoint1);
    ::ClientToScreen(hWnd, &cPoint2);

    //strBuffer.Format("(%d, %d)-(%d, %d) %d x %d",
    //    wp.rcNormalPosition.left, wp.rcNormalPosition.top,
    //    wp.rcNormalPosition.right, wp.rcNormalPosition.bottom,
    //    wp.rcNormalPosition.right - wp.rcNormalPosition.left,
    //    wp.rcNormalPosition.bottom - wp.rcNormalPosition.top);

    strBuffer.Format("(%d, %d)-(%d, %d) %d x %d",
        cPoint1.x, cPoint1.y,
        cPoint2.x, cPoint2.y,
        wp.rcNormalPosition.right - wp.rcNormalPosition.left,
        wp.rcNormalPosition.bottom - wp.rcNormalPosition.top);
    return strBuffer;
}

//窗口工作区的边框。 矩形的大小也会显示。 单位是相对于窗口工作区左上角的像素。
CString CPageGeneralDlg::GetClientRect(HWND hWnd)
{
    CString strBuffer;

    CRect cRect;
    ::GetClientRect(hWnd, &cRect);

    //CPoint cPoint1(cRect.left, cRect.top);
    //CPoint cPoint2(cRect.right, cRect.bottom);

    //转换坐标
    //::ClientToScreen(hWnd, &cPoint1);
    //::ClientToScreen(hWnd, &cPoint2);

    //strBuffer.Format("(%d, %d)-(%d, %d) %d x %d",
    //    cPoint1.x, cPoint1.y,
    //    cPoint2.x, cPoint2.y,
    //    cRect.Width(), cRect.Height());

    strBuffer.Format("(%d, %d)-(%d, %d) %d x %d",
        cRect.left, cRect.top,
        cRect.right, cRect.bottom,
        cRect.Width(), cRect.Height());
    return strBuffer;
}

CString CPageGeneralDlg::GetInstanceHandle(HWND hWnd)
{
    CString strBuffer;
    DWORD dwInstance = 0;

    //区分是否是Unicode编码
    if (IsWindowUnicode(hWnd) == TRUE)
    {
        dwInstance = GetWindowLongW(hWnd, GWL_HINSTANCE);
    }
    else
    {
        dwInstance = GetWindowLongA(hWnd, GWL_HINSTANCE);
    }

    strBuffer.Format("%08X", dwInstance);

    return strBuffer;
}

CString CPageGeneralDlg::GetMenuHandle(HWND hWnd)
{
    CString strBuffer;
    HMENU hMenu = nullptr;

    hMenu = ::GetMenu(hWnd);
    strBuffer.Format("%08X", (DWORD)hMenu);

    return strBuffer;
}

CString CPageGeneralDlg::GetControlID(HWND hWnd)
{
    CString strBuffer;
    int iID = 0;

    iID = ::GetDlgCtrlID(hWnd);
    strBuffer.Format("%08X", iID);

    return strBuffer;
}

CString CPageGeneralDlg::GetUserData(HWND hWnd)
{
    CString strBuffer;
    DWORD dwAddress = 0;

    //区分是否是Unicode编码
    if (IsWindowUnicode(hWnd) == TRUE)
    {
        dwAddress = GetWindowLongW(hWnd, GWL_USERDATA);
    }
    else
    {
        dwAddress = GetWindowLongA(hWnd, GWL_USERDATA);
    }

    strBuffer.Format("%08X", dwAddress);

    return strBuffer;
}

void CPageGeneralDlg::GetWindowBytes(HWND hWnd, BYTE* pData, DWORD dwCount)
{
    DWORD dwCurCount = 0;
    LPWORD pWordData = (LPWORD)pData;
    for (dwCurCount = 0; dwCurCount < dwCount; dwCurCount += 2)
    {
        pWordData[dwCurCount / 2] = ::GetWindowWord(hWnd, dwCurCount);
    }

    return;
}


BEGIN_MESSAGE_MAP(CPageGeneralDlg, CDialogEx)
END_MESSAGE_MAP()


// CPageGeneralDlg message handlers


BOOL CPageGeneralDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  Add extra initialization here
    SetDlgItemText(EDIT_WINDOW_CAPTION, this->GetCaption(this->m_hHandle));
    SetDlgItemText(EDIT_WINDOW_HANDLE, this->GetHandle(this->m_hHandle));
    SetDlgItemText(EDIT_WINDOW_PROC, this->GetWinProc(this->m_hHandle));
    SetDlgItemText(EDIT_RECTANGLE, this->GetRectangle(this->m_hHandle));
    SetDlgItemText(EDIT_RESTORED_RECT, this->GetRestoredRect(this->m_hHandle));
    SetDlgItemText(EDIT_CLIENT_RECT, this->GetClientRect(this->m_hHandle));
    SetDlgItemText(EDIT_INSTANCE_HANDLE, this->GetInstanceHandle(this->m_hHandle));

    if (::IsWindow(this->m_hHandle) == TRUE)
    {
        SetDlgItemText(TEXT_MENU_OR_ID, "Control ID:");
        SetDlgItemText(EDIT_MENU_HANDLE, this->GetControlID(this->m_hHandle));
    }
    else
    {
        SetDlgItemText(EDIT_MENU_HANDLE, this->GetMenuHandle(this->m_hHandle));
    }
    SetDlgItemText(EDIT_USER_DATA, this->GetUserData(this->m_hHandle));
    
    //获取Window 数据
    BYTE bDataArray[MAXBYTE] = { 0 };
    DWORD dwCount = 0;

    //获取数据的大小  wc.cbWndExtra
    DWORD dwCurCount = 0;
    TCHAR szClassName[MAXBYTE] = { 0 };
    LPDWORD pDwordData = (LPDWORD)bDataArray;
    LPWORD pWordData = (LPWORD)bDataArray;

    WNDCLASSA wc = { 0 };
    ::GetClassName(this->m_hHandle, szClassName, MAXBYTE);
    ::GetClassInfo((HINSTANCE)GetWindowLong(this->m_hHandle, GWL_HINSTANCE), szClassName, &wc);
    dwCount = wc.cbWndExtra;


    this->GetWindowBytes(this->m_hHandle, bDataArray, dwCount);

    //插入字符串
    for (dwCurCount = 0; dwCurCount < ((dwCount / 4) * 4); dwCurCount += 4)
    {
        CString strBuffer;
        strBuffer.Format("+%02d     %08X", dwCurCount, pDwordData[dwCurCount / 4]);
        this->m_cComBox.InsertString(dwCurCount / 4, strBuffer);
    }
    
    if (dwCount % 4 == 2)
    {
        CString strBuffer;
        strBuffer.Format("+%d     %04X", dwCurCount, pWordData[dwCurCount / 2]);
        this->m_cComBox.InsertString(dwCurCount / 4, strBuffer);
    }

    //选中第一个
    this->m_cComBox.SetCurSel(0);

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}
