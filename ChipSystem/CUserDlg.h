#pragma once
#include <afxext.h>
#include "resource.h" 

class CUserDlg : public CFormView
{
	DECLARE_DYNCREATE(CUserDlg)

protected:
	CUserDlg();
public:
	virtual ~CUserDlg();

	enum { IDD = IDD_DIALOG_USER
	};//IDD_DISPLAYVIEW模态窗口的ID

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
public:
	CString _name;
	CString _user;
	CString _newPwd;
	CString _surePwd;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};