#pragma once
#include <afxext.h>
#include "resource.h" 

class CDisplayView : public CFormView
{
	DECLARE_DYNCREATE(CDisplayView)

protected:
	CDisplayView();
public:
	virtual ~CDisplayView();

	enum { IDD = IDD_DISPLAYVIEW };//IDD_DISPLAYVIEW模态窗口的ID

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
};