
// luckappDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "luckapp.h"
#include "luckappDlg.h"
#include "afxdialogex.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CluckappDlg �Ի���




CluckappDlg::CluckappDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CluckappDlg::IDD, pParent)
{
	runFlag=0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	readName();
	srand((unsigned)timeGetTime());
	m_font.CreatePointFont(120,"����");
	luckapp= (CluckappApp *)AfxGetApp();
}

// ensure not repeat
void CluckappDlg::genRandNum(int randnum[], int max)
{
	int continueflag=1;
	while(continueflag)
	{
		for (int i=0;i<6;i++)
		{
			randnum[i]=GetRand(0,max);
		}
		continueflag=0;
		for(int m=0;m<6;m++)
		{
			for(int n=0;n<6;n++)
			{
				if(m!=n && randnum[m]==randnum[n])
				{
					continueflag=1;
				}
			}
		}
	}

}

void CluckappDlg::genRandomResultNum()
{

	int i=0;
	int randnum[6];
	genRandNum(randnum, 100);
	//11��
	for(i=0;i<6;i++)
	{
		luckapp->ResultNum.Add(strNum11.GetAt(randnum[i]));
	}
	genRandNum(randnum, 97);
	//12��
	for(i=0;i<5;i++)
		luckapp->ResultNum.Add(strNum12.GetAt(randnum[i]));
	genRandNum(randnum, 101);
	//13��
	for(i=0;i<5;i++)
		luckapp->ResultNum.Add(strNum13.GetAt(randnum[i]));
	genRandNum(randnum, 100);
	//14��
	for(i=0;i<5;i++)
		luckapp->ResultNum.Add(strNum14.GetAt(randnum[i]));
	//15��
	genRandNum(randnum, 105);
	for(i=0;i<6;i++)
	{
		//int test=GetRand(0,111);
		luckapp->ResultNum.Add(strNum15.GetAt(randnum[i]));
	}
	genRandNum(randnum, 120);
	//31��
	for(i=0;i<5;i++)
		luckapp->ResultNum.Add(strNum31.GetAt(randnum[i]));
	genRandNum(randnum, 35);
	//41��
	for(i=0;i<2;i++)
		luckapp->ResultNum.Add(strNum41.GetAt(randnum[i]));
	genRandNum(randnum, 98);
	//51��
	for(i=0;i<5;i++)
		luckapp->ResultNum.Add(strNum51.GetAt(randnum[i]));
	genRandNum(randnum, 58);
	//52��
	for(i=0;i<3;i++)
		luckapp->ResultNum.Add(strNum52.GetAt(randnum[i]));
	genRandNum(randnum, 57);
	//91��
	for(i=0;i<3;i++)
		luckapp->ResultNum.Add(strNum91.GetAt(randnum[i]));
}

void CluckappDlg::readName()
{
	CString strText = _T("");
	CString szLine = _T("");
	//��ȡѧ���ļ�
	CStdioFile file;
	file.Open(_T("res/num/010911.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum11.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010912.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum12.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010913.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum13.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010914.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum14.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010915.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum15.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010931.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum31.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010941.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum41.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010951.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum51.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�
	file.Open(_T("res/num/010952.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum52.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
	//��ȡѧ���ļ�

	file.Open(_T("res/num/010991.txt"),CFile::modeRead); 
	while( file.ReadString( szLine ) )
	{
		strNum91.Add(szLine);
	}
	//MessageBox(strNum11.GetAt(strNum11.GetCount()-1)); 
	file.Close();
}

HBRUSH CluckappDlg::OnCtlColor(CDC*   pDC,   CWnd*   pWnd,   UINT   nCtlColor) 
{

	pDC-> SetBkMode(TRANSPARENT);
	pDC-> SetTextColor(RGB(222,222,222)); //������ɫ
	//pDC-> SetBkColor(RGB(0, 0, 0)); //���屳��ɫ
	if (pWnd->GetDlgCtrlID()==IDC_RESULT1 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT2 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT3 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT4 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT5 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT6 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT7 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT8 ||
		pWnd->GetDlgCtrlID()==IDC_RESULT9
		)  
	{
		pDC->SelectObject(&m_font);   
	}
	return (HBRUSH)GetStockObject(HOLLOW_BRUSH);

}

void CluckappDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_START, m_startbtn);
	DDX_Control(pDX, IDC_LIST, m_listbtn);
}

BEGIN_MESSAGE_MAP(CluckappDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CluckappDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_LIST, &CluckappDlg::OnBnClickedList)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CluckappDlg ��Ϣ�������

BOOL CluckappDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
// 	CRect m_FullScreenRect;
// 	int nFullWidth=GetSystemMetrics(SM_CXSCREEN);
// 	int nFullHeight=GetSystemMetrics(SM_CYSCREEN);
// 
// 	m_FullScreenRect.left = 0;
// 	m_FullScreenRect.top = 0;
// 	m_FullScreenRect.right = m_FullScreenRect.left + nFullWidth;
// 	m_FullScreenRect.bottom = m_FullScreenRect.top + nFullHeight;
// 
// 	MoveWindow(0,0,m_FullScreenRect.Width(),m_FullScreenRect.Height(),1);

	ShowWindow(SW_SHOWMAXIMIZED);
// 	m_bmpDlgBg.LoadBitmap( IDB_BMP_DLG_BG );
// 	m_brushDlgBg.CreatePatternBrush( &m_bmpDlgBg );

	m_startbtn.SetTheBitmap( IDB_START_NORMAL, IDB_START_FOCUS, IDB_START_CLICK, IDB_START_NORMAL );
	m_startbtn.SetFontSize( 16 );

	m_listbtn.SetTheBitmap( IDB_LIST_NORMAL, IDB_LIST_FOCUS, IDB_LIST_CLICK, IDB_LIST_NORMAL );
	m_listbtn.SetFontSize( 16 );


	hBitmap= (HBITMAP)LoadImage(AfxGetInstanceHandle(),  
		MAKEINTRESOURCE(IDB_BITMAP2),  
		IMAGE_BITMAP,0,0,  
		LR_LOADMAP3DCOLORS);
	nIndex=0;
	for(int i=0;i<45;i++)
		bmp[i].LoadBitmap(IDB_BITMAP6+i);
// 	bmp[0].LoadBitmap(IDB_BITMAP_INIT);
// 	bmp[1].LoadBitmap(IDB_BITMAP3);
// 	bmp[2].LoadBitmap(IDB_BITMAP4);
// 	bmp[3].LoadBitmap(IDB_BITMAP5);
	SetTimer(1,100,NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

HDC DrawBmp(HDC hDC, HBITMAP hBitmap) //�˴��������͸�ΪHDC
{
	HDC hdcImage;
	HDC hdcMEM;
	HANDLE hOld;
	hdcMEM = CreateCompatibleDC(hDC);

	SelectObject(hdcMEM, hBitmap); //��λͼѡ����ڴ�DC

	StretchBlt(hDC, 0, 0, 100, 100, hdcMEM, 0, 0, 100, 100, SRCCOPY); //�������������ͼ����hdcImage�е�λͼֱ�Ӹ��Ƶ��ڴ滺����

	SelectObject(hdcImage, hOld);
	DeleteObject(hdcImage);
	return hdcMEM; //�����ڴ滺����.
}

void CluckappDlg::OnPaint()
{
// 	CWnd *m_pDrawWnd = GetDlgItem(IDC_PIC1);
// 	CRect rect;
// 	m_pDrawWnd->GetClientRect(&rect);
// 	CDC* pDC = m_pDrawWnd->GetDC();
// 	CDC m_memDC;
// 	m_memDC.SelectObject(bmp[(nIndex++) % 3]);
// 	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_memDC, 0, 0, SRCCOPY);
// 	m_pDrawWnd->ReleaseDC(pDC);

// 

/*	CDialog::OnPaint();*/
	CPaintDC dc(this);
	CPaintDC *pDC=&dc;
	CDC MemDC1;
	CDC MemDC2;
	MemDC1.CreateCompatibleDC(NULL);
	MemDC2.CreateCompatibleDC(NULL);
	//����λͼ
	CBitmap bitmap;
	BITMAP BMInfo;
	bitmap.LoadBitmap(IDB_BITMAP2);
	bitmap.GetBitmap(&BMInfo);
	//���ڴ�С
	CRect rect;
	GetClientRect(rect);
	MemDC1.SelectObject(&bitmap);
	//���ŵ��ڶ��ڴ�DC
	CBitmap Membitmap;
	Membitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
	MemDC2.SelectObject(&Membitmap);
	MemDC2.StretchBlt(0,0,rect.Width(),rect.Height(),&MemDC1,0,0,rect.Width(),rect.Height(),SRCCOPY);//BMInfo.bmWidth ,BMInfo.bmHeight,SRCCOPY);

	HBITMAP hOldbmp;// = (HBITMAP)
	if(runFlag==1)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				//GetRand(0,3)
				//hOldbmp = (HBITMAP)memDC.SelectObject(bmp[(nIndex[i*3+j]++) % 4+i]);
				hOldbmp = (HBITMAP)MemDC1.SelectObject(bmp[GetRand(0,44)]);// % 4+i
				MemDC2.StretchBlt(216+i*226,177+j*186,150,150,&MemDC1,0,0, 150, 150,SRCCOPY);//BMInfo.bmWidth ,BMInfo.bmHeight,SRCCOPY);//rect.Width(),rect.Height(),SRCCOPY);
			}
		}
	}
	else if(runFlag==2)
	{
		// ��ʾ�齱���
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				hOldbmp = (HBITMAP)MemDC1.SelectObject(bmp[(nIndex%5)*9+i+3*j]);// % 4+i
				MemDC2.StretchBlt(216+i*226,177+j*186,150,150,&MemDC1,0,0, 150, 150,SRCCOPY);//BitBlt(216+i*226, 177+j*195, 150, 150, &memDC, 0, 0, SRCCOPY);//rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
			}
		}
	}

	//MemDC2.TextOut(0,0,_T("���ǹ̶��ı�"));


	//�������Ļ��ʾ����
	//pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&MemDC2,0,0,BMInfo.bmWidth ,BMInfo.bmHeight,SRCCOPY);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&MemDC2,0,0,SRCCOPY);
	//pDC->TextOut(100,100,_T("ʱ����ʾ"));
	bitmap.DeleteObject();
	MemDC1.DeleteDC();
	MemDC2.DeleteDC();
	Membitmap.DeleteObject();
// 
 	CString strText="�齱�������Ŀ�Դ���";
// 	int testset=ResultNum.GetCount();
	if(runFlag==2)
	{

		CWnd* pWnd;
		pWnd = GetDlgItem(IDC_RESULT1);
		strText=luckapp->ResultNum.GetAt(0+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT2);
		strText=luckapp->ResultNum.GetAt(1+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT3);
		strText=luckapp->ResultNum.GetAt(2+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT4);
		strText=luckapp->ResultNum.GetAt(3+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT5);
		strText=luckapp->ResultNum.GetAt(4+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT6);
		strText=luckapp->ResultNum.GetAt(5+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT7);
		strText=luckapp->ResultNum.GetAt(6+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT8);
		strText=luckapp->ResultNum.GetAt(7+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT9);
		int testrrrr= 8+nIndex%5*9;
		strText=luckapp->ResultNum.GetAt(8+nIndex%5*9).Mid(7);
		pWnd->SetWindowText(strText);
	}else
	{
		strText.Format("�뿪ʼ��%d/5�ֳ齱", nIndex%5+1);
		CWnd* pWnd;
		pWnd = GetDlgItem(IDC_RESULT1);

		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT2);

		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT3);

		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT4);

		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT5);

		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT6);

		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT7);

		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT8);
		pWnd->SetWindowText(strText);

		pWnd = GetDlgItem(IDC_RESULT9);

		pWnd->SetWindowText(strText);
	}

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CluckappDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CluckappDlg::GetRand(double MAX,double MIN)
{
	int max;
	max=RAND_MAX;//rand()��������������ֵ
	int randnum=(int)(rand()*(MAX-MIN)/max+MIN);
	return randnum;
}

void CluckappDlg::genRandomResult()
{
	CImage *img=new CImage;
	CBitmap* bm;
	img->Load(_T("res/pic/photo.jpg"));

	HBITMAP hbmp =(HBITMAP)img->operator HBITMAP();
	for(int i=0; i<9; i++)
	{
		resultBmp[i].DeleteObject();
		resultBmp[i].Attach(hbmp);
	}

};

void CluckappDlg::OnBnClickedStart()
{
	if(nIndex<5)
	{
		if(runFlag==0)
		{
			if(nIndex==0)
			{
				genRandomResultNum();
			}
			PlaySound(_T("./defBKSound.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP); 
			runFlag=1;
			genRandomResult();

		}
		else if(runFlag==1)
		{
			PlaySound(_T("./defStopSound.wav"),NULL,SND_FILENAME|SND_ASYNC);//|SND_LOOP
			runFlag=2;
		}
		else if(runFlag==2)
		{
			nIndex++;
			runFlag=0;
		}

	}else
	{
		MessageBox("���ֳ齱�ѽ������뵼��������");
		dialog_list.DoModal();
	}

}


void CluckappDlg::OnBnClickedList()
{
	// TODO: Add your control notification handler code here
	//SetTimer(1,600,NULL);
	//MessageBox(_T("List"));
	if(luckapp->ResultNum.GetCount()!=0)
	{
		if(nIndex<4)
		{
			CString resultstatus;
			resultstatus.Format("�����5�ֳ齱�������ǵ�%d��", nIndex+1);
			MessageBox(resultstatus);
		}else{
			dialog_list.DoModal();
		}

	}
	else
		MessageBox("���Ƚ��г齱���ٲ鿴������");
}

void CluckappDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CDialog::OnTimer(nIDEvent);
}