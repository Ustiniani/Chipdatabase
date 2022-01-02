// CSelectView.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CSelectView.h"

#include"MainFrm.h"

// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	_tree=&GetTreeCtrl();
	HICON icon_user = AfxGetApp()->LoadIcon(IDI_ICON_DOG1);
	HICON icon_add= AfxGetApp()->LoadIcon(IDI_ICON_DOG1);
	HICON icon_look = AfxGetApp()->LoadIcon(IDI_ICON_DOG1);
	HICON icon_modify= AfxGetApp()->LoadIcon(IDI_ICON_DOG1);
	HICON icon_level = AfxGetApp()->LoadIcon(IDI_ICON_DOG1);
	HICON icon_dengji = AfxGetApp()->LoadIcon(IDI_ICON_DOG1);

	_imageIist.Create(50, 50, ILC_COLOR32,6,6);
	_imageIist.Add(icon_user);
	_imageIist.Add(icon_add);
	_imageIist.Add(icon_look);
	_imageIist.Add(icon_modify);
	_imageIist.Add(icon_level);
	_imageIist.Add(icon_dengji);

	_tree->SetImageList(&_imageIist, TVSIL_NORMAL);
	_tree->InsertItem(TEXT("管理信息"), 0, 0, NULL);
	_tree->InsertItem(TEXT("管理芯片数据"), 1, 1, NULL);
	_tree->InsertItem(TEXT("芯片数据"), 2, 2, NULL);
	_tree->InsertItem(TEXT("添加芯片数据"), 3, 3, NULL);
	_tree->InsertItem(TEXT("芯片分级系统"), 4, 4, NULL);
	_tree->InsertItem(TEXT("芯片等级数据"), 5, 5, NULL);
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	HTREEITEM item = _tree->GetSelectedItem();
	CString str = _tree->GetItemText(item);

	if (str == "管理信息")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_A, (LPARAM)NM_A, 0);
	}
	else if (str == "管理芯片数据")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_B, (LPARAM)NM_B, 0);
	}
	else if (str == "芯片数据")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_C, (LPARAM)NM_C, 0);
	}
	else if (str == "添加芯片数据")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_D, (LPARAM)NM_D, 0);
	}
	else if (str == "芯片分级系统")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_E, (LPARAM)NM_E, 0);
	}
	else if (str == "芯片等级数据")
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_F, (LPARAM)NM_F, 0);
	}
}
