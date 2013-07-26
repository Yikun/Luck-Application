#pragma once
#include "afxwin.h"


// LuckList dialog

class LuckList : public CDialog
{
	DECLARE_DYNAMIC(LuckList)

public:
	LuckList(CWnd* pParent = NULL);   // standard constructor
	virtual ~LuckList();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listctrl;
	CluckappApp *luckapp;
	afx_msg void OnBnClickedButton1();
};
