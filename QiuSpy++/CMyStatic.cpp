// CMyPictureCtrl.cpp : implementation file
//

#include "pch.h"
#include "QiuSpy++.h"
#include "CMyStatic.h"


// CMyPictureCtrl

IMPLEMENT_DYNAMIC(CMyStatic, CStatic)

CMyStatic::CMyStatic()
{
    this->m_hIconUp = AfxGetApp()->LoadIcon(ICON_UP);
    this->m_hIconDown = AfxGetApp()->LoadIcon(ICON_DOWN);
    this->m_hCursor = AfxGetApp()->LoadCursor(CUR_DOWN);

    this->m_hPreWindow = nullptr;
    this->m_pHandle = nullptr;
    this->m_pCaption = nullptr;
    this->m_pClass = nullptr;
    this->m_pStyle = nullptr;
    this->m_pRect = nullptr;

    this->m_bLeftButtonDown = false;
}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMyPictureCtrl message handlers




void CMyStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default

    SetIcon(m_hIconDown);
    ::SetCursor(m_hCursor);
    SetCapture();

    this->m_bLeftButtonDown = true;

    CStatic::OnLButtonDown(nFlags, point);
}

void CMyStatic::HighlightWindowBorder(HWND hwnd)
{
    HDC hWinDC; // edi
    HGDIOBJ v3; // eax
    int v4; // esi
    COLORREF v5; // eax
    HBRUSH hBrush; // esi
    HPEN hPen; // [esp+Ch] [ebp-30h]
    HGDIOBJ v8; // [esp+10h] [ebp-2Ch]
    HGDIOBJ h; // [esp+14h] [ebp-28h]
    int v10; // [esp+18h] [ebp-24h]
    int v11; // [esp+18h] [ebp-24h]
    int w; // [esp+1Ch] [ebp-20h]
    int v13; // [esp+20h] [ebp-1Ch]
    int v14; // [esp+20h] [ebp-1Ch]
    HRGN hRgn; // [esp+24h] [ebp-18h]
    CRect cRect; // [esp+28h] [ebp-14h] BYREF

    v13 = GetSystemMetrics(SM_CXBORDER);
    v10 = GetSystemMetrics(SM_CYBORDER);
    hWinDC = ::GetWindowDC(hwnd);
    if (hWinDC)
    {
        hRgn = CreateRectRgn(0, 0, 0, 0);
        hPen = CreatePen(PS_INSIDEFRAME, 3 * v13, 0);
        v8 = SelectObject(hWinDC, hPen);
        v3 = GetStockObject(NULL_BRUSH);
        h = SelectObject(hWinDC, v3);
        SetROP2(hWinDC, R2_NOT);
        if (::GetWindowRgn(hwnd, hRgn))
        {
            v5 = GetSysColor(COLOR_WINDOWFRAME);
            hBrush = CreateHatchBrush(HS_DIAGCROSS, v5);
            FrameRgn(hWinDC, hRgn, hBrush, 3 * v13, 3 * v10);
            DeleteObject(hBrush);
        }
        else
        {
            w = GetSystemMetrics(SM_CXFRAME);
            v14 = GetSystemMetrics(SM_CYFRAME);
            v11 = GetSystemMetrics(SM_CXSCREEN);
            v4 = GetSystemMetrics(SM_CYSCREEN);
            ::GetWindowRect(hwnd, &cRect);
            if (::IsZoomed(hwnd))
                Rectangle(hWinDC, w, v14, w + v11, v4 + v14);
            else
                Rectangle(hWinDC, 0, 0, cRect.right - cRect.left, cRect.bottom - cRect.top);
        }
        SelectObject(hWinDC, h);
        SelectObject(hWinDC, v8);
        DeleteObject(hPen);
        DeleteObject(hRgn);
        ::ReleaseDC(hwnd, hWinDC);
    }
}


void CMyStatic::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default

    SetIcon(m_hIconUp);
    ::SetCursor(NULL);

    ReleaseCapture();
    this->m_bLeftButtonDown = false;

    CStatic::OnLButtonUp(nFlags, point);
}


void CMyStatic::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    if (nFlags & MK_LBUTTON)
    {
        ::SetCursor(m_hCursor);

        ClientToScreen(&point);
        HWND hCurWin = ::WindowFromPoint(point);

        /*
        ////1、获取鼠标所在的窗口大小
        //CRect cWinRect;
        //::GetWindowRect(hCurWin, &cWinRect);

        ////2、绘制黑色矩形
        //if (this->m_hPreWindow != hCurWin)
        //{
        //    CRect cPreRect;
        //    ::GetWindowRect(this->m_hPreWindow, &cPreRect);

        //    HDC dcWindow = ::GetWindowDC(NULL);
        //    HPEN hPen = ::CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
        //    ::SelectObject(dcWindow, hPen);
        //    ::SetROP2(dcWindow, R2_NOT);
        //    ::SelectObject(dcWindow, GetStockObject(NULL_BRUSH));
        //    ::Rectangle(dcWindow, cPreRect.left, cPreRect.top, cPreRect.right, cPreRect.bottom);//取消原窗口的边框
        //    ::Rectangle(dcWindow, cWinRect.left, cWinRect.top, cWinRect.right, cWinRect.bottom);//绘制新窗口的边框

        //    this->m_hPreWindow = hCurWin;
        //}
        */

        if (this->m_hPreWindow != hCurWin)
        {
            //消除边框
            this->HighlightWindowBorder(this->m_hPreWindow);  

            //绘制边框
            this->HighlightWindowBorder(hCurWin);

            //获取窗口对应的值
            this->GetHandle(hCurWin);
            this->GetCaption(hCurWin);
            this->GetClass(hCurWin);
            this->GetStyle(hCurWin);
            this->GetWindowRectInfo(hCurWin);

            //给窗口赋新值
            this->m_hPreWindow = hCurWin;
        }

    }

    CStatic::OnMouseMove(nFlags, point);
}

void CMyStatic::SetHandlePoint(CString* strHandle)
{
    this->m_pHandle = strHandle;
}

void CMyStatic::SetCaptionPoint(CString* strCaption)
{
    this->m_pCaption = strCaption;
}

void CMyStatic::SetClassPoint(CString* strClass)
{
    this->m_pClass = strClass;
}

void CMyStatic::SetStylePoint(CString* strStyle)
{
    this->m_pStyle = strStyle;
}

void CMyStatic::SetRectPoint(CString* strRect)
{
    this->m_pRect = strRect;
}


void CMyStatic::GetHandle(HWND hWnd)
{
    if (this->m_pHandle != nullptr)
    {
        this->m_pHandle->Format("%08X", (DWORD)hWnd);
    }
}

void CMyStatic::GetCaption(HWND hWnd)
{
    if (this->m_pCaption != nullptr)
    {
        char szBuffer[255] = {0};

        ::GetWindowText(hWnd, szBuffer, 255);

        this->m_pCaption->Format("%s", szBuffer);
    }
}

void CMyStatic::GetClass(HWND hWnd)
{
    if (this->m_pClass != nullptr)
    {
        char szBuffer[255] = { 0 };

        ::GetClassName(hWnd, szBuffer, 255);

        this->m_pClass->Format("%s", szBuffer);
    }
}

void CMyStatic::GetStyle(HWND hWnd)
{
    if (this->m_pStyle != nullptr)
    {
        LONG lStyle = ::GetWindowLong(hWnd, GWL_STYLE);

        this->m_pStyle->Format("%08X", lStyle);
    }
}

void CMyStatic::GetWindowRectInfo(HWND hWnd)
{
    if (this->m_pRect != nullptr)
    {
        CRect cRect;

        ::GetWindowRect(hWnd, &cRect);

        this->m_pRect->Format("(%d, %d)-(%d, %d) %d x %d", 
            cRect.left, cRect.top, 
            cRect.right, cRect.bottom, 
            cRect.Width(), cRect.Height());
    }

}


