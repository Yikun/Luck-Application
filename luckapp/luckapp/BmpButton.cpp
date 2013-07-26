/*******************************************************************************
* File Name :    BmpButton.cpp
* Created   :    2008-5-13
* Author    :    huzb
* Model     :    
* Description    �ɼ���4��bmpͼƬ��������ͼƬ����������ť�İ�ť��
* ---------------------------------------------------------------------------- *
* Revision History
* No    Date        Revised by      Description
* --    ----        ----------      -----------
*******************************************************************************/

#include "stdafx.h"
#include "BmpButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpButton

CBmpButton::CBmpButton()
{
	m_iMouseType = 0;
	m_szText = CSize( 0, 0 );
}

CBmpButton::~CBmpButton()
{
	m_bmpNormal.DeleteObject();
	m_bmpHot.DeleteObject();
	m_bmpFocus.DeleteObject();
	m_bmpDisable.DeleteObject();
	
	m_TextFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CBmpButton, CButton)
	//{{AFX_MSG_MAP(CBmpButton)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_MESSAGE( WM_MOUSELEAVE , OnMouseLeave )
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpButton message handlers
// ���ð�ťͼƬ(����״̬�£�������ϣ���갴�£���ť������4��״̬)
void CBmpButton::SetTheBitmap( UINT iNormalID, UINT iHotID, UINT iFocusID, UINT iDisableID )
{
	if( iNormalID <= 0 || iHotID <= 0 || iFocusID <= 0 || iDisableID <= 0 )
	{
		return;
	}
	
	if( m_bmpNormal.m_hObject )
	{
		m_bmpNormal.DeleteObject();
	}
	if( m_bmpHot.m_hObject )
	{
		m_bmpHot.DeleteObject();
	}
	if( m_bmpFocus.m_hObject )
	{
		m_bmpFocus.DeleteObject();
	}
	if( m_bmpDisable.m_hObject )
	{
		m_bmpDisable.DeleteObject();
	}

	m_bmpNormal.LoadBitmap( iNormalID );
	m_bmpHot.LoadBitmap( iHotID );
	m_bmpFocus.LoadBitmap( iFocusID );
	m_bmpDisable.LoadBitmap( iDisableID );
}

// ���������С(��ť�Ĵ�С��һ�������ṩ�˸ú��������Ը���ʵ����Ҫ����������Ĵ�С)
void CBmpButton::SetFontSize( int iSize )
{
	int iFontSize = iSize;
	if( iFontSize <= 0 )
	{
		iFontSize = 16;
	}

	if( m_TextFont.m_hObject )
	{
		m_TextFont.DeleteObject();
	}
	
	m_TextFont.CreateFont(
		iFontSize,
		0,
		0,
		0,
		400,
		FALSE,
		FALSE,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_ROMAN,
		_T("����")
		);
}

// ����ƶ�����ť��
void CBmpButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	CButton::OnMouseMove(nFlags, point);

	if( 1 != m_iMouseType )
	{
		m_iMouseType = 1;
		Invalidate( FALSE );
	}

	// ��������뿪��ť����Ϣ
	TRACKMOUSEEVENT event ;
	event.cbSize = sizeof( event );
	event.dwFlags = TME_LEAVE ;
	event.dwHoverTime = 0 ;
	event.hwndTrack = GetSafeHwnd() ;
	
	VERIFY( _TrackMouseEvent( &event ) ) ;
}

// ��갴��
void CBmpButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( 2 != m_iMouseType )
	{
		m_iMouseType = 2;
		Invalidate( FALSE );
	}

	CButton::OnLButtonDown(nFlags, point);
}

// ���̧��
void CBmpButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( 1 != m_iMouseType )
	{
		m_iMouseType = 1;
		Invalidate( FALSE );
	}

	CButton::OnLButtonUp(nFlags, point);
}

// ����뿪��Ϣ������(ע��OnMouseMove�����󼸾����)
LRESULT CBmpButton::OnMouseLeave( WPARAM wParam , LPARAM lParam )
{	
	if( 0 != m_iMouseType )
	{
		m_iMouseType = 0;
		Invalidate( FALSE );
	}

	return 0 ;
}

void CBmpButton::Draw( CDC *pDc )
{
	if( pDc )
	{
		// ��ȡ��ʾ����
		CString strText = _T("");
		GetWindowText( strText );
		
		// ��ȡ��ť��������
		CRect rect = CRect( 0, 0, 0, 0 );
		GetClientRect( rect );

		// ��ť�Ƿ����
		BOOL bEnable = IsWindowEnabled();
		
		// ������ʱdc
		CDC memdc;
		memdc.CreateCompatibleDC( pDc );
		
		// ���÷�ɫ
		COLORREF crMask = RGB( 0xFF,0x00, 0xFF );

		BITMAP bm;
		if( bEnable )
		{
			// ͨ��״̬��ť
			if( 0 == m_iMouseType && m_bmpNormal.m_hObject )
			{
				memdc.SelectObject( &m_bmpNormal );
				m_bmpNormal.GetObject( sizeof( bm ), &bm );
			}
			// �������ʱ
			else if( 1 == m_iMouseType && m_bmpHot.m_hObject )
			{
				memdc.SelectObject( &m_bmpHot );
				m_bmpNormal.GetObject( sizeof( bm ), &bm );
			}
			// ��갴��ʱ
			else if( 2 == m_iMouseType && m_bmpFocus.m_hObject )
			{
				memdc.SelectObject( &m_bmpFocus );
				m_bmpNormal.GetObject( sizeof( bm ), &bm );
			}
		}
		// ��ť������ʱ
		else if( !bEnable && m_bmpDisable.m_hObject )
		{
			memdc.SelectObject( &m_bmpDisable );
			m_bmpNormal.GetObject( sizeof( bm ), &bm );
		}
		
		// �軭͸��������ͼƬ
		TransparentBlt2( pDc->m_hDC, 0, 0, rect.Width(), rect.Height(), memdc.m_hDC, 0, 0, bm.bmWidth, bm.bmHeight, crMask );
		
		memdc.DeleteDC();
		
		int nPrevMode = pDc->SetBkMode( TRANSPARENT );
		COLORREF textColor = pDc->SetTextColor( RGB( 255, 255, 255 ) );
		CFont* pOldFont = pDc->SelectObject( &m_TextFont );

		// ȡ���ֵĴ�С
		m_szText = pDc->GetTextExtent( strText );
		// ���㣬ʹ������ʾ�ڰ�ť�м�
		pDc->TextOut( rect.left + ( rect.Width() - m_szText.cx ) / 2, rect.top + ( rect.Height() - m_szText.cy ) / 2, strText );
		
		pDc->SelectObject( pOldFont );
		pDc->SetBkMode( nPrevMode );
		pDc->SetTextColor( textColor );
	}
}

void CBmpButton::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	Draw( &dc );
}

// ��bmpͼƬ����͸������(�����ṩ)
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
								 )
{
	HBITMAP hOldImageBMP, hImageBMP = CreateCompatibleBitmap(hdcDest, nWidthDest, nHeightDest);	// ��������λͼ
	HBITMAP hOldMaskBMP, hMaskBMP = CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);			// ������ɫ����λͼ
	HDC		hImageDC = CreateCompatibleDC(hdcDest);
	HDC		hMaskDC = CreateCompatibleDC(hdcDest);
	hOldImageBMP = (HBITMAP)SelectObject(hImageDC, hImageBMP);
	hOldMaskBMP = (HBITMAP)SelectObject(hMaskDC, hMaskBMP);
	
	// ��ԴDC�е�λͼ��������ʱDC��
	if (nWidthDest == nWidthSrc && nHeightDest == nHeightSrc)
		BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, SRCCOPY);
	else
		StretchBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, 
		hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, SRCCOPY);
	
	// ����͸��ɫ
	SetBkColor(hImageDC, crTransparent);
	
	// ����͸������Ϊ��ɫ����������Ϊ��ɫ������λͼ
	BitBlt(hMaskDC, 0, 0, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCCOPY);
	
	// ����͸������Ϊ��ɫ���������򱣳ֲ����λͼ
	SetBkColor(hImageDC, RGB(0,0,0));
	SetTextColor(hImageDC, RGB(255,255,255));
	BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
	
	// ͸�����ֱ�����Ļ���䣬�������ֱ�ɺ�ɫ
	SetBkColor(hdcDest,RGB(0xff,0xff,0xff));
	SetTextColor(hdcDest,RGB(0,0,0));
	BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
	
	// "��"����,��������Ч��
	BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCPAINT);
	
	SelectObject(hImageDC, hOldImageBMP);
	DeleteDC(hImageDC);
	SelectObject(hMaskDC, hOldMaskBMP);
	DeleteDC(hMaskDC);
	DeleteObject(hImageBMP);
	DeleteObject(hMaskBMP);
}

// �����軭����,ֱ��return TRUE,�����б����軭
BOOL CBmpButton::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}
