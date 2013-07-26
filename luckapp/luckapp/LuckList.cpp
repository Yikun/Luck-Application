// LuckList.cpp : implementation file
//

#include "stdafx.h"
#include "luckapp.h"
#include "LuckList.h"
#include "afxdialogex.h"


// LuckList dialog

IMPLEMENT_DYNAMIC(LuckList, CDialog)

LuckList::LuckList(CWnd* pParent /*=NULL*/)
	: CDialog(LuckList::IDD, pParent)
{
	//m_listctrl.AddString("test");
	luckapp= (CluckappApp *)AfxGetApp();
}

BOOL LuckList::OnInitDialog()
{
	CDialog::OnInitDialog();
	for(int i=0;i<45;i++)
	{
			m_listctrl.AddString(luckapp->ResultNum.GetAt(i));
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

LuckList::~LuckList()
{
}

void LuckList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}


BEGIN_MESSAGE_MAP(LuckList, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &LuckList::OnBnClickedButton1)
END_MESSAGE_MAP()


// LuckList message handlers




void LuckList::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	char* pFileName = "Result.txt";
	MessageBox("获奖名单已导出！");
	CStdioFile file;
	file.Open(pFileName,CFile::modeWrite|CFile::typeText|CFile::modeCreate);
	for(int i=0;i<45;i++)
	{
		//m_listctrl.AddString(luckapp->ResultNum.GetAt(i));
		file.WriteString(luckapp->ResultNum.GetAt(i));
		file.WriteString("\r\n");
	}
	file.Close();
}
