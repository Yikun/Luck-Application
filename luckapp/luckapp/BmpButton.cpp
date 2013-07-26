/*******************************************************************************
* File Name :    BmpButton.cpp
* Created   :    2008-5-13
* Author    :    huzb
* Model     :    
* Description    可加载4张bmp图片，并根据图片创建不规则按钮的按钮类
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
// 设置按钮图片(正常状态下，鼠标移上，鼠标按下，按钮不可用4种状态)
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

// 设置字体大小(因按钮的大小不一，所以提供了该函数，可以根据实际需要，设置字体的大小)
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
		_T("黑体")
		);
}

// 鼠标移动到按钮上
void CBmpButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	CButton::OnMouseMove(nFlags, point);

	if( 1 != m_iMouseType )
	{
		m_iMouseType = 1;
		Invalidate( FALSE );
	}

	// 发送鼠标离开按钮的消息
	TRACKMOUSEEVENT event ;
	event.cbSize = sizeof( event );
	event.dwFlags = TME_LEAVE ;
	event.dwHoverTime = 0 ;
	event.hwndTrack = GetSafeHwnd() ;
	
	VERIFY( _TrackMouseEvent( &event ) ) ;
}

// 鼠标按下
void CBmpButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( 2 != m_iMouseType )
	{
		m_iMouseType = 2;
		Invalidate( FALSE );
	}

	CButton::OnLButtonDown(nFlags, point);
}

// 鼠标抬起
void CBmpButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( 1 != m_iMouseType )
	{
		m_iMouseType = 1;
		Invalidate( FALSE );
	}

	CButton::OnLButtonUp(nFlags, point);
}

// 鼠标离开消息处理函数(注意OnMouseMove里的最后几句代码)
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
		// 获取显示文字
		CString strText = _T("");
		GetWindowText( strText );
		
		// 获取按钮矩形区域
		CRect rect = CRect( 0, 0, 0, 0 );
		GetClientRect( rect );

		// 按钮是否可用
		BOOL bEnable = IsWindowEnabled();
		
		// 创建临时dc
		CDC memdc;
		memdc.CreateCompatibleDC( pDc );
		
		// 设置反色
		COLORREF crMask = RGB( 0xFF,0x00, 0xFF );

		BITMAP bm;
		if( bEnable )
		{
			// 通常状态按钮
			if( 0 == m_iMouseType && m_bmpNormal.m_hObject )
			{
				memdc.SelectObject( &m_bmpNormal );
				m_bmpNormal.GetObject( sizeof( bm ), &bm );
			}
			// 鼠标移上时
			else if( 1 == m_iMouseType && m_bmpHot.m_hObject )
			{
				memdc.SelectObject( &m_bmpHot );
				m_bmpNormal.GetObject( sizeof( bm ), &bm );
			}
			// 鼠标按下时
			else if( 2 == m_iMouseType && m_bmpFocus.m_hObject )
			{
				memdc.SelectObject( &m_bmpFocus );
				m_bmpNormal.GetObject( sizeof( bm ), &bm );
			}
		}
		// 按钮不可用时
		else if( !bEnable && m_bmpDisable.m_hObject )
		{
			memdc.SelectObject( &m_bmpDisable );
			m_bmpNormal.GetObject( sizeof( bm ), &bm );
		}
		
		// 描画透明处理后的图片
		TransparentBlt2( pDc->m_hDC, 0, 0, rect.Width(), rect.Height(), memdc.m_hDC, 0, 0, bm.bmWidth, bm.bmHeight, crMask );
		
		memdc.DeleteDC();
		
		int nPrevMode = pDc->SetBkMode( TRANSPARENT );
		COLORREF textColor = pDc->SetTextColor( RGB( 255, 255, 255 ) );
		CFont* pOldFont = pDc->SelectObject( &m_TextFont );

		// 取文字的大小
		m_szText = pDc->GetTextExtent( strText );
		// 计算，使文字显示在按钮中间
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

// 讲bmp图片进行透明处理(网上提供)
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
								 )
{
	HBITMAP hOldImageBMP, hImageBMP = CreateCompatibleBitmap(hdcDest, nWidthDest, nHeightDest);	// 创建兼容位图
	HBITMAP hOldMaskBMP, hMaskBMP = CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);			// 创建单色掩码位图
	HDC		hImageDC = CreateCompatibleDC(hdcDest);
	HDC		hMaskDC = CreateCompatibleDC(hdcDest);
	hOldImageBMP = (HBITMAP)SelectObject(hImageDC, hImageBMP);
	hOldMaskBMP = (HBITMAP)SelectObject(hMaskDC, hMaskBMP);
	
	// 将源DC中的位图拷贝到临时DC中
	if (nWidthDest == nWidthSrc && nHeightDest == nHeightSrc)
		BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, SRCCOPY);
	else
		StretchBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, 
		hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, SRCCOPY);
	
	// 设置透明色
	SetBkColor(hImageDC, crTransparent);
	
	// 生成透明区域为白色，其它区域为黑色的掩码位图
	BitBlt(hMaskDC, 0, 0, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCCOPY);
	
	// 生成透明区域为黑色，其它区域保持不变的位图
	SetBkColor(hImageDC, RGB(0,0,0));
	SetTextColor(hImageDC, RGB(255,255,255));
	BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
	
	// 透明部分保持屏幕不变，其它部分变成黑色
	SetBkColor(hdcDest,RGB(0xff,0xff,0xff));
	SetTextColor(hdcDest,RGB(0,0,0));
	BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
	
	// "或"运算,生成最终效果
	BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCPAINT);
	
	SelectObject(hImageDC, hOldImageBMP);
	DeleteDC(hImageDC);
	SelectObject(hMaskDC, hOldMaskBMP);
	DeleteDC(hMaskDC);
	DeleteObject(hImageBMP);
	DeleteObject(hMaskBMP);
}

// 背景描画函数,直接return TRUE,不进行背景描画
BOOL CBmpButton::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}
