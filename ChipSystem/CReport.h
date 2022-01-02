#pragma once
#include <afxext.h>
#include "resource.h" 

class CReport : public CFormView
{
	DECLARE_DYNCREATE(CReport)

protected:
	CReport();
public:
	virtual ~CReport();

	enum { IDD = IDD_REPORT};//IDD_DISPLAYVIEW模态窗口的ID

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl _list;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnCbnSelchangeCombo1();
private:
	CComboBox _combox;
};
