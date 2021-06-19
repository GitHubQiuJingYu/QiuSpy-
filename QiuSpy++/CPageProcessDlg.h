#pragma once


// CPageProcessDlg dialog

class CPageProcessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPageProcessDlg)

public:
	CPageProcessDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPageProcessDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PAGE_PROCESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    CString GetProcessID(HWND hWnd);
    CString GetThreadID(HWND hWnd);

	DECLARE_MESSAGE_MAP()
public:
    HWND m_hHandle;        //选中的窗口句柄
    virtual BOOL OnInitDialog();

};
