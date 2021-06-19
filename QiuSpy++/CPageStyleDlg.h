#pragma once


// CPageStyleDlg dialog

class CPageStyleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPageStyleDlg)

public:
	CPageStyleDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPageStyleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PAGE_STYLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    CString GetWindowStyle(HWND hWnd);
    CString GetExtendStyle(HWND hWnd);

	DECLARE_MESSAGE_MAP()
public:
    HWND m_hHandle;        //选中的窗口句柄

    CListBox m_cListStyle;
    CListBox m_cListStyleEx;
    virtual BOOL OnInitDialog();
};
