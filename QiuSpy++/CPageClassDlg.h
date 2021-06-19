#pragma once


// CPageClassDlg dialog

class CPageClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPageClassDlg)

public:
	CPageClassDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPageClassDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PAGE_CLASS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    CString GetHwndClassName(HWND hWnd);
    CString GetClassStyle(HWND hWnd);
    CString GetClassBytesCount(HWND hWnd);
    CString GetInstanceHandle(HWND hWnd);
    CString GetWinProc(HWND hWnd);
    CString GetMenuName(HWND hWnd);
    CString GetIconHandle(HWND hWnd);
    CString GetCursorHandle(HWND hWnd);
    CString GetBackgroundBrush(HWND hWnd);
    CString GetClassAtom(HWND hWnd);
    CString GetWindowBytes(HWND hWnd);
    
    
	DECLARE_MESSAGE_MAP()
public:
    HWND m_hHandle;        //选中的窗口句柄
    virtual BOOL OnInitDialog();
    CComboBox m_cClassStyles;
    CComboBox m_cClassBytes;


};
