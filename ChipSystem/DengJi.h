#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CDengJi 窗体视图

class CDengJi : public CFormView
{
	DECLARE_DYNCREATE(CDengJi)

protected:
	CDengJi();           // 动态创建所使用的受保护的构造函数
	virtual ~CDengJi();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DengJi };
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
//	CListCtrl _list;
	CComboBox _combo1;
	CComboBox _combo2;
public:
	afx_msg void OnBnClickedButton1();
private:
//	CEdit _value;
	CString _value;
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
};


