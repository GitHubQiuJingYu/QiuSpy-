#pragma once

//#include "CQiuPropertyDlg.h"
// CPageWindowDlg dialog

class CPageWindowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPageWindowDlg)

public:
	CPageWindowDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPageWindowDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PAGE_WINDOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    CString HandleToString(HWND hWnd);
    CString GetHandleCaption(HWND hWnd);

	DECLARE_MESSAGE_MAP()

public:
    HWND m_hHandle;             //选中的窗口句柄
    HWND m_hPreHandle;          //选中的窗口的上一个窗口句柄
    HWND m_hNextHandle;          //选中的窗口的下一个窗口句柄
    HWND m_hParentHandle;       //选中的窗口的父窗口句柄
    HWND m_hFirstChildHandle;   //选中的窗口的第一个子窗口句柄
    HWND m_hOwnerHandle;        //选中的窗口的所有者窗口句柄

    CWnd* m_pWnd;

    virtual BOOL OnInitDialog();
    afx_msg void OnClickedTextNextWindowHandle();
    afx_msg void OnClickedTextPreviousWindowHandle();
    afx_msg void OnClickedTextParentWindowHandle();
    afx_msg void OnClickedTextOwnerWindowHandle();
    afx_msg void OnClickedTextFirstchildWindowHandle();
};
