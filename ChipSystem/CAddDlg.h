#pragma once
#include <afxext.h>
#include "resource.h" 

class CAddDlg : public CFormView
{
	DECLARE_DYNCREATE(CAddDlg)

protected:
	CAddDlg();
public:
	virtual ~CAddDlg();

	enum { IDD = IDD_DIALOG_ADD };//IDD_DISPLAYVIEW模态窗口的ID

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
private:
	CString _X;
	CString _Y;
	CString _VF;
	CString _WP;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit10();
private:
	CString _WD;
	CString _WH;
	CString _IR;
	CString _IV;
};
