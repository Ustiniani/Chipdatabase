#pragma once

#include <afxext.h>
#include "resource.h" 

class CModifyDlg : public CFormView
{
	DECLARE_DYNCREATE(CModifyDlg)

protected:
	CModifyDlg();
public:
	virtual ~CModifyDlg();

	enum {
		IDD = IDD_DIALOG_MODIFY
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
private:
	CComboBox _combo;
public:
	afx_msg void OnCbnSelchangeCombo1();
private:
	CString _X;
	CString _Y;
	CString _VF;
	CString _WP;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
private:
	CString _WD;
	CString _WH;
	CString _IR;
	CString _IV;
public:
	afx_msg void OnEnChangeEditWh();
};