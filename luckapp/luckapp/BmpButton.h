#if !defined(AFX_BMPBUTTON_H__EADB9EA7_D935_4736_9791_1B36C960C8ED__INCLUDED_)
#define AFX_BMPBUTTON_H__EADB9EA7_D935_4736_9791_1B36C960C8ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BmpButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBmpButton window

class CBmpButton : public CButton
{
// Construction
public:
	CBmpButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBmpButton();

	// 设置按钮的图片
	void SetTheBitmap( UINT iNormalID, UINT iHotID, UINT iFocusID, UINT iDisableID );
	// 设置按钮显示文字的大小
	void SetFontSize( int iSize );
	// 按钮描画函数
	void Draw( CDC *pDc );

	// Generated message map functions
protected:
	//{{AFX_MSG(CBmpButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam , LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	CBitmap m_bmpNormal;	// 普通状态时的按钮图片
	CBitmap m_bmpHot;		// 鼠标移上时的按钮图片
	CBitmap m_bmpFocus;		// 鼠标按下时的按钮图片
	CBitmap m_bmpDisable;	// 按钮不可用时的按钮图片

	int		m_iMouseType;	// 鼠标与按钮的位置关系。0为普通状态；1为鼠标移上；2为鼠标按下
	CSize   m_szText;		// 按钮显示文字的大小
	CFont	m_TextFont;		// 按钮文字的字体

private:
	void CBmpButton::TransparentBlt2( HDC hdcDest,      // 目标DC
		int nXOriginDest,   // 目标X偏移
		int nYOriginDest,   // 目标Y偏移
		int nWidthDest,     // 目标宽度
		int nHeightDest,    // 目标高度
		HDC hdcSrc,         // 源DC
		int nXOriginSrc,    // 源X起点
		int nYOriginSrc,    // 源Y起点
		int nWidthSrc,      // 源宽度
		int nHeightSrc,     // 源高度
		UINT crTransparent  // 透明色,COLORREF类型
		);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBUTTON_H__EADB9EA7_D935_4736_9791_1B36C960C8ED__INCLUDED_)
