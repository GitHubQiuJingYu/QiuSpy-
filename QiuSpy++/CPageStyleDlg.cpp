// CPageStyleDlg.cpp : implementation file
//

#include "pch.h"
#include "QiuSpy++.h"
#include "CPageStyleDlg.h"
#include "afxdialogex.h"


// CPageStyleDlg dialog

IMPLEMENT_DYNAMIC(CPageStyleDlg, CDialogEx)

CPageStyleDlg::CPageStyleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(PAGE_STYLE, pParent)
{
    this->m_hHandle = nullptr;
}

CPageStyleDlg::~CPageStyleDlg()
{
}

void CPageStyleDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, LIST_WINDOW_STYLE, m_cListStyle);
    DDX_Control(pDX, LIST_EXTEND_STYLE, m_cListStyleEx);
}

CString CPageStyleDlg::GetWindowStyle(HWND hWnd)
{
    CString strBuffer;
    DWORD dwStyle = 0;

    dwStyle = GetWindowLong(hWnd, GWL_STYLE);

    strBuffer.Format("%08X", dwStyle);


    if ((dwStyle & WS_POPUPWINDOW) == WS_POPUPWINDOW)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_POPUPWINDOW");
    }
    else
    {
        if (dwStyle & WS_POPUP)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "WS_POPUP");
        }
    }
    if (dwStyle & WS_MINIMIZE)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_MINIMIZE");
    }
    if (dwStyle & WS_VISIBLE)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_VISIBLE");
    }
    if (dwStyle & WS_DISABLED)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_DISABLED");
    }
    if (dwStyle & WS_CLIPSIBLINGS)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_CLIPSIBLINGS");
    }
    if (dwStyle & WS_CLIPCHILDREN)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_CLIPCHILDREN");
    }
    if (dwStyle & WS_MAXIMIZE)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_MAXIMIZE");
    }
    if ((dwStyle & WS_OVERLAPPEDWINDOW) == WS_OVERLAPPEDWINDOW)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_OVERLAPPEDWINDOW");
    }
    else
    {
        if ((dwStyle & WS_CAPTION) == WS_CAPTION)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "WS_OVERLAPPED");

            iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "WS_CAPTION");
        } // end if (dwStyle & WS_CAPTION)
        else
        {

            if (dwStyle & WS_DLGFRAME)
            {
                int iIndex = this->m_cListStyle.GetCount();
                this->m_cListStyle.InsertString(iIndex, "WS_DLGFRAME");
            }
        } // end else - if (dwStyle & WS_CAPTION) 

        if (dwStyle & WS_THICKFRAME)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "WS_THICKFRAME");
        }

        if (dwStyle & WS_MINIMIZEBOX)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "WS_MINIMIZEBOX");
        }
        if (dwStyle & WS_MAXIMIZEBOX)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "WS_MAXIMIZEBOX");
        }
    } // end else - if (dwStyle & WS_OVERLAPPEDWINDOW)
    if (dwStyle & WS_VSCROLL)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_VSCROLL");
    }
    if (dwStyle & WS_HSCROLL)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_HSCROLL");
    }
    if (dwStyle & WS_CHILDWINDOW)
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_CHILDWINDOW");
    }
    if (dwStyle & WS_SYSMENU && 
        ((dwStyle & WS_OVERLAPPEDWINDOW) != WS_OVERLAPPEDWINDOW) && 
        ((dwStyle & WS_POPUPWINDOW) != WS_POPUPWINDOW))
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_SYSMENU");
    }
    if (dwStyle & WS_BORDER && 
        ((dwStyle & WS_POPUPWINDOW) != WS_POPUPWINDOW) &&
        ((dwStyle & WS_CAPTION) != WS_CAPTION)  )
    {
        int iIndex = this->m_cListStyle.GetCount();
        this->m_cListStyle.InsertString(iIndex, "WS_BORDER");
    }

    TCHAR szBuffer[MAXBYTE] = { 0 };
    DWORD dwCount = MAXBYTE;
    GetClassName(this->m_hHandle, szBuffer, dwCount);
    //区分tooltips_class32的样式  和 Dialog样式
    if (_tcsicmp(szBuffer, "tooltips_class32") == 0)
    {
        if (dwStyle & TTS_ALWAYSTIP)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "TTS_ALWAYSTIP");
        }
        if (dwStyle & TTS_NOPREFIX)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "TTS_NOPREFIX");
        }
        if (dwStyle & TTS_NOANIMATE)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "TTS_NOANIMATE");
        }
        if (dwStyle & TTS_NOFADE)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "TTS_NOFADE");
        }
        if (dwStyle & TTS_BALLOON)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "TTS_BALLOON");
        }
        if (dwStyle & TTS_CLOSE)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "TTS_CLOSE");
        }
        if (dwStyle & TTS_USEVISUALSTYLE)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "TTS_USEVISUALSTYLE");
        }
    }
    else
    {
        if ((dwStyle & DS_SHELLFONT) == DS_SHELLFONT)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_SHELLFONT");
        }
        else
        {
            if (dwStyle & DS_SETFONT)
            {
                int iIndex = this->m_cListStyle.GetCount();
                this->m_cListStyle.InsertString(iIndex, "DS_SETFONT");
            }
            if (dwStyle & DS_FIXEDSYS)
            {
                int iIndex = this->m_cListStyle.GetCount();
                this->m_cListStyle.InsertString(iIndex, "DS_FIXEDSYS");
            }
        }
        if (dwStyle & DS_ABSALIGN)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_ABSALIGN");
        }
        if (dwStyle & DS_LOCALEDIT)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_LOCALEDIT");
        }
        if (dwStyle & DS_MODALFRAME)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_MODALFRAME");
        }
        if (dwStyle & DS_NOIDLEMSG)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_NOIDLEMSG");
        }
        if (dwStyle & DS_SETFOREGROUND)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_SETFOREGROUND");
        }
        if (dwStyle & DS_3DLOOK)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_3DLOOK");
        }
        if (dwStyle & DS_NOFAILCREATE)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_NOFAILCREATE");
        }
        if (dwStyle & DS_CONTROL)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_CONTROL");
        }
        if (dwStyle & DS_CENTER)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_CENTER");
        }
        if (dwStyle & DS_CENTERMOUSE)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_CENTERMOUSE");
        }
        if (dwStyle & DS_CONTEXTHELP)
        {
            int iIndex = this->m_cListStyle.GetCount();
            this->m_cListStyle.InsertString(iIndex, "DS_CONTEXTHELP");
        }
    }

    return strBuffer;
}

CString CPageStyleDlg::GetExtendStyle(HWND hWnd)
{
    CString strBuffer;
    DWORD dwStyleEx = 0;

    dwStyleEx = GetWindowLong(hWnd, GWL_EXSTYLE);

    strBuffer.Format("%08X", dwStyleEx);

    //依次插入属性
    this->m_cListStyleEx.InsertString(0, "WS_EX_LEFT");
    this->m_cListStyleEx.InsertString(1, "WS_EX_LTRREADING");
    this->m_cListStyleEx.InsertString(2, "WS_EX_RIGHTSCROLLBAR");

    if (dwStyleEx & WS_EX_RIGHTSCROLLBAR)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_RIGHTSCROLLBAR");
    }
    if (dwStyleEx & WS_EX_NOPARENTNOTIFY)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_NOPARENTNOTIFY");
    }
    if (dwStyleEx & WS_EX_ACCEPTFILES)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_ACCEPTFILES");
    }
    if (dwStyleEx & WS_EX_TRANSPARENT)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_TRANSPARENT");
    }
    if (dwStyleEx & WS_EX_MDICHILD)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_MDICHILD");
    }
    if (dwStyleEx & WS_EX_CONTEXTHELP)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_CONTEXTHELP");
    }
    if (dwStyleEx & WS_EX_RIGHT)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_RIGHT");
    }
    if (dwStyleEx & WS_EX_RTLREADING)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_RTLREADING");
    }
    if (dwStyleEx & WS_EX_LEFTSCROLLBAR)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_LEFTSCROLLBAR");
    }
    if (dwStyleEx & WS_EX_CONTROLPARENT)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_CONTROLPARENT");
    }
    if (dwStyleEx & WS_EX_STATICEDGE)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_STATICEDGE");
    }
    if (dwStyleEx & WS_EX_APPWINDOW)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_APPWINDOW");
    }
    if (dwStyleEx & WS_EX_LAYERED)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_LAYERED");
    }
    if (dwStyleEx & WS_EX_NOINHERITLAYOUT)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_NOINHERITLAYOUT");
    }
    if (dwStyleEx & WS_EX_NOREDIRECTIONBITMAP)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_NOREDIRECTIONBITMAP");
    }
    if (dwStyleEx & WS_EX_LAYOUTRTL)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_LAYOUTRTL");
    }
    if (dwStyleEx & WS_EX_COMPOSITED)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_COMPOSITED");
    }
    if (dwStyleEx & WS_EX_NOACTIVATE)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_NOACTIVATE");
    }
    if ((dwStyleEx & WS_EX_OVERLAPPEDWINDOW) == WS_EX_OVERLAPPEDWINDOW)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_OVERLAPPEDWINDOW");
    }
    else
    {
        //TTS_ALWAYSTIP
        //DS_3DLOOK
        if (dwStyleEx & WS_EX_CLIENTEDGE)
        {
            int iIndex = this->m_cListStyleEx.GetCount();
            this->m_cListStyleEx.InsertString(iIndex, "WS_EX_CLIENTEDGE");
        }
    }
    if ((dwStyleEx & WS_EX_PALETTEWINDOW) == WS_EX_PALETTEWINDOW)
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_PALETTEWINDOW");
    }
    else
    {
        if (dwStyleEx & WS_EX_TOOLWINDOW)
        {
            int iIndex = this->m_cListStyleEx.GetCount();
            this->m_cListStyleEx.InsertString(iIndex, "WS_EX_TOOLWINDOW");
        }
        if (dwStyleEx & WS_EX_TOPMOST)
        {
            int iIndex = this->m_cListStyleEx.GetCount();
            this->m_cListStyleEx.InsertString(iIndex, "WS_EX_TOPMOST");
        }
    }

    if (dwStyleEx & WS_EX_WINDOWEDGE &&
        ((dwStyleEx & WS_EX_OVERLAPPEDWINDOW) != WS_EX_OVERLAPPEDWINDOW) &&
        ((dwStyleEx & WS_EX_PALETTEWINDOW) != WS_EX_PALETTEWINDOW))
    {
        int iIndex = this->m_cListStyleEx.GetCount();
        this->m_cListStyleEx.InsertString(iIndex, "WS_EX_WINDOWEDGE");
    }

    return strBuffer;
}


BEGIN_MESSAGE_MAP(CPageStyleDlg, CDialogEx)
END_MESSAGE_MAP()


// CPageStyleDlg message handlers


BOOL CPageStyleDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  Add extra initialization here
    SetDlgItemText(EDIT_WINDOW_STYLE, this->GetWindowStyle(this->m_hHandle));
    SetDlgItemText(EDIT_EXTEND_STYLE, this->GetExtendStyle(this->m_hHandle));

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}
