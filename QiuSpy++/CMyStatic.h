#pragma once


// CMyPictureCtrl

class CMyStatic : public CStatic
{
	DECLARE_DYNAMIC(CMyStatic)

public:
	CMyStatic();
	virtual ~CMyStatic();
    BOOL m_bLeftButtonDown;     //判断鼠标左键是否按下

protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);


    void SetHandlePoint(CString* strHandle);
    void SetCaptionPoint(CString* strCaption);
    void SetClassPoint(CString* strClass);
    void SetStylePoint(CString* strStyle);
    void SetRectPoint(CString* strRect);
    void GetHandle(HWND hWnd);
    void GetCaption(HWND hWnd);
    void GetClass(HWND hWnd);
    void GetStyle(HWND hWnd);
    void GetWindowRectInfo(HWND hWnd);

private:
    HICON m_hIconUp;
    HICON m_hIconDown;
    HCURSOR m_hCursor;
    HWND m_hPreWindow;

    CString* m_pHandle;
    CString* m_pCaption;
    CString* m_pClass;
    CString* m_pStyle;
    CString* m_pRect;

    void HighlightWindowBorder(HWND hwnd);
};


