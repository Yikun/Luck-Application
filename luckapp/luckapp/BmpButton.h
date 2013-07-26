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

	// ���ð�ť��ͼƬ
	void SetTheBitmap( UINT iNormalID, UINT iHotID, UINT iFocusID, UINT iDisableID );
	// ���ð�ť��ʾ���ֵĴ�С
	void SetFontSize( int iSize );
	// ��ť�軭����
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
	CBitmap m_bmpNormal;	// ��ͨ״̬ʱ�İ�ťͼƬ
	CBitmap m_bmpHot;		// �������ʱ�İ�ťͼƬ
	CBitmap m_bmpFocus;		// ��갴��ʱ�İ�ťͼƬ
	CBitmap m_bmpDisable;	// ��ť������ʱ�İ�ťͼƬ

	int		m_iMouseType;	// ����밴ť��λ�ù�ϵ��0Ϊ��ͨ״̬��1Ϊ������ϣ�2Ϊ��갴��
	CSize   m_szText;		// ��ť��ʾ���ֵĴ�С
	CFont	m_TextFont;		// ��ť���ֵ�����

private:
	void CBmpButton::TransparentBlt2( HDC hdcDest,      // Ŀ��DC
		int nXOriginDest,   // Ŀ��Xƫ��
		int nYOriginDest,   // Ŀ��Yƫ��
		int nWidthDest,     // Ŀ����
		int nHeightDest,    // Ŀ��߶�
		HDC hdcSrc,         // ԴDC
		int nXOriginSrc,    // ԴX���
		int nYOriginSrc,    // ԴY���
		int nWidthSrc,      // Դ���
		int nHeightSrc,     // Դ�߶�
		UINT crTransparent  // ͸��ɫ,COLORREF����
		);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBUTTON_H__EADB9EA7_D935_4736_9791_1B36C960C8ED__INCLUDED_)
