#pragma once


// CPageGeneralDlg dialog

class CPageGeneralDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPageGeneralDlg)

public:
	CPageGeneralDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPageGeneralDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PAGE_GENERAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    CString GetCaption(HWND hWnd);
    CString GetHandle(HWND hWnd);
    CString GetWinProc(HWND hWnd);
    CString GetRectangle(HWND hWnd);    //当前大小
    CString GetRestoredRect(HWND hWnd); //还原后的大小
    CString GetClientRect(HWND hWnd);   //客户端大小
    CString GetInstanceHandle(HWND hWnd);
    CString GetMenuHandle(HWND hWnd);
    CString GetControlID(HWND hWnd);
    CString GetUserData(HWND hWnd);
    void GetWindowBytes(HWND hWnd, BYTE* pData, DWORD dwCount);


	DECLARE_MESSAGE_MAP()
public:
    HWND m_hHandle;        //选中的窗口句柄

    virtual BOOL OnInitDialog();
    CComboBox m_cComBox;
};
