#pragma once

#include "CPageClassDlg.h"
#include "CPageGeneralDlg.h"
#include "CPageProcessDlg.h"
#include "CPageStyleDlg.h"
#include "CPageWindowDlg.h"

// CProperty dialog

class CQiuPropertyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQiuPropertyDlg)

public:
	CQiuPropertyDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CQiuPropertyDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = DLG_PROPERTY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    HWND m_hHandle;        //选中的窗口句柄

    CTabCtrl m_cTableCtrl;

    CPageGeneralDlg     m_cPageGeneralDlg;
    CPageWindowDlg      m_cPageWindowDlg;
    CPageStyleDlg       m_cPageStyleDlg;
    CPageProcessDlg     m_cPageProcessDlg;
    CPageClassDlg       m_cPageClassDlg;

    virtual BOOL OnInitDialog();
    afx_msg void OnSelchangeTabProperty(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnBnClickedRefresh();

};
