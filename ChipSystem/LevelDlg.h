#pragma once
#include "afxcmn.h"



// CLevelDlg 窗体视图

class CLevelDlg : public CFormView
{
	DECLARE_DYNCREATE(CLevelDlg)

protected:
	CLevelDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CLevelDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LEVEL };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
private:
	CListCtrl _list;

};


