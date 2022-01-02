#include "stdafx.h"
#include "CDisplayView.h"

// CDisplayView
IMPLEMENT_DYNCREATE(CDisplayView, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CDisplayView::CDisplayView() : CFormView(IDD_DISPLAYVIEW) {

}

CDisplayView::~CDisplayView()
{
}

BEGIN_MESSAGE_MAP(CDisplayView, CFormView)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CDisplayView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDisplayView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CDisplayView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);
}