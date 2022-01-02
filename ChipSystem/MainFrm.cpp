
// MainFrm.cpp: CMainFrame 类的实现
//

#include "stdafx.h"
#include "StudentSystem.h"

#include "MainFrm.h"
#include "CInfoFile.h"

#include"CSelectView.h"
#include"CDisplayView.h"
#include"CUserDlg.h"
#include"CModifyDlg.h"
#include"CReport.h"
#include"CAddDlg.h"
#include"LevelDlg.h"
#include"DengJi.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)
	ON_MESSAGE(NM_F, OnMyChange)

	ON_COMMAND(ID_32775, &CMainFrame::On32775)
	ON_COMMAND(ID_32771, &CMainFrame::On32771)
	ON_COMMAND(ID_32772, &CMainFrame::On32772)
	ON_COMMAND(ID_32773, &CMainFrame::On32773)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_COMMAND(ID_32777, &CMainFrame::On32777)
	ON_COMMAND(ID_32778, &CMainFrame::On32778)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//设置图标
	//SetClassLong(m_hWnd, GCLP_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_MAIN));
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_DOG);
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	//设置右侧标题
	SetTitle(TEXT("Chip_database"));
	//设置窗口大小
	MoveWindow(0, 0, 1200, 600);
	//设置居中
	CenterWindow();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.style &= ~WS_MAXIMIZEBOX; //禁止窗口最大化
	//cs.style &= ~WS_MINIMIZEBOX; //禁止窗口最小化
	//cs.style &= ~WS_SYSMENU; //取消Title上的按钮
	cs.style &= ~WS_THICKFRAME;//使窗口不能用鼠标改变大小

	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//拆分成一行两列
	_splitter.CreateStatic(this, 1, 2);

	//分配空间
	_splitter.CreateView(0, 0,RUNTIME_CLASS (CSelectView), CSize(200, 600), pContext);
	_splitter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(1000, 600), pContext);

	return true;//代表自己拆分
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

LRESULT CMainFrame::OnMyChange(WPARAM wparam, LPARAM lparam)
{
	CCreateContext _context;
	if (wparam == NM_A)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0,1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(1000, 600), &_context);
		CUserDlg *pNewView = (CUserDlg *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_B)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CModifyDlg);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CModifyDlg), CSize(1000, 600), &_context);
		CModifyDlg *pNewView = (CModifyDlg *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_C)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CReport);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CReport), CSize(1000, 600), &_context);
		CReport *pNewView = (CReport *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_D)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CAddDlg);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CAddDlg), CSize(1000, 600), &_context);
		CAddDlg *pNewView = (CAddDlg *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_E)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CLevelDlg);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CLevelDlg), CSize(1000, 600), &_context);
		CLevelDlg *pNewView = (CLevelDlg *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	else if (wparam == NM_F)
	{
		_context.m_pNewViewClass = RUNTIME_CLASS(CDengJi);
		_context.m_pCurrentFrame = this;
		_context.m_pLastView = (CFormView *)_splitter.GetPane(0, 1);
		_splitter.DeleteView(0, 1);
		_splitter.CreateView(0, 1, RUNTIME_CLASS(CDengJi), CSize(1000, 600), &_context);
		CDengJi *pNewView = (CDengJi *)_splitter.GetPane(0, 1);
		_splitter.RecalcLayout();//在调整行或列大小后调用以重新显示拆分器窗口
		pNewView->OnInitialUpdate();
		_splitter.SetActivePane(0, 1);
	}
	return 0;
}


void CMainFrame::On32775()
{
	// TODO: 在此添加命令处理程序代码
	exit(0);
}


void CMainFrame::On32771()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_A, (LPARAM)NM_A, 0);
}


void CMainFrame::On32772()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_B, (LPARAM)NM_B, 0);
}


void CMainFrame::On32773()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_C, (LPARAM)NM_C, 0);
}


void CMainFrame::On32774()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_D, (LPARAM)NM_D, 0);
}


void CMainFrame::On32777()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_E, (LPARAM)NM_E, 0);
}

void CMainFrame::On32778()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), (WPARAM)NM_F, (LPARAM)NM_F, 0);
}
