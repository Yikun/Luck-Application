
// luckappDlg.h : ͷ�ļ�
//

#pragma once

#include "BmpButton.h"
#include "LuckList.h"
// CluckappDlg �Ի���
class CluckappDlg : public CDialog
{
// ����
public:
	CluckappDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LUCKAPP_DIALOG };
	CBmpButton	m_startbtn;
	CBmpButton	m_listbtn;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC*   pDC,   CWnd*   pWnd,   UINT   nCtlColor);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedList();

// 	int nIndex;
// 	int nIndex2;
// 	int nIndex3;

	int runFlag;

	int nIndex;
	CBitmap bmp[45];
	HBITMAP hBitmap;
	afx_msg void OnTimer(UINT nIDEvent);
	int GetRand(double MAX,double MIN);

	int timeOut;

	void genRandomResult();

	void readName();
	CBitmap resultBmp[9];
	CStringArray strNum11;//103 6
	CStringArray strNum12;//102 5.1
	CStringArray strNum13;//102 5.1
	CStringArray strNum14;//103 5.1
	CStringArray strNum15;//112 5.7
	CStringArray strNum31;//122 6.1
	CStringArray strNum41;//38  1.9
	CStringArray strNum51;//100 5
	CStringArray strNum52;//61  3.05
	CStringArray strNum91;//60  3

	

	CFont m_font;

	void genRandomResultNum();

	CluckappApp *luckapp;

	LuckList dialog_list;

	void genRandNum(int randnum[], int max);
};
