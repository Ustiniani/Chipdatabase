// DengJi.cpp : 实现文件
//

#include "stdafx.h"
#include "resource.h"
#include "DengJi.h"

#include "DBHelper.h"
// CDengJi

IMPLEMENT_DYNCREATE(CDengJi, CFormView)

CDengJi::CDengJi()
	: CFormView(IDD_DIALOG_DengJi)
	, _value(_T(""))
{

}

CDengJi::~CDengJi()
{
}

void CDengJi::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST1, _list);
	DDX_Control(pDX, IDC_COMBO1, _combo1);
	DDX_Control(pDX, IDC_COMBO2, _combo2);
	//  DDX_Control(pDX, IDC_EDIT1, _value);
	DDX_Text(pDX, IDC_EDIT1, _value);
}

BEGIN_MESSAGE_MAP(CDengJi, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDengJi::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDengJi::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDengJi::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// CDengJi 诊断

#ifdef _DEBUG
void CDengJi::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDengJi::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDengJi 消息处理程序


void CDengJi::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CString strsql1;
	MYSQL_RES* res1;
	MYSQL_ROW row1;


	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql1.Format(TEXT("select chip_NUM from chipdata"));

	res1 = DBHelper::Query(strsql1);

	while (row1 = mysql_fetch_row(res1))
	{
		CString Sno(row1[0]);
		_combo1.AddString(Sno);
	}

	DBHelper::Close();
}


void CDengJi::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int index = _combo1.GetCurSel();
	int index2 = _combo2.GetCurSel();
	CString _num;
	CString _num1;


	if (index == -1)
	{
		MessageBox(TEXT("查询失败，您未选中任何芯片"));
		return;
	}
	if (index2 == -1)
	{
		MessageBox(TEXT("查询失败，您未选中任何属性"));
		return;
	}
	_combo1.GetLBText(index, _num);
	_combo2.GetWindowText(_num1);


	UpdateData(TRUE);


	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}
	//select chip_RANK from chiprank where WDLow<abs((select WD from chipdata where chip_NUM = 3) - 50) and WDUp>abs((select WD from chipdata where chip_NUM = 3) - 50);
	strsql.Format(TEXT("select chip_RANK from chiprank where %sLow<abs((select %s from chipdata where chip_NUM = %s) - 50) and %sUp>abs((select %s from chipdata where chip_NUM = %s) - 50)"), _num1, _num1, _num, _num1, _num1, _num);
	MessageBox(TEXT("查询语句为:")+strsql);
	res=DBHelper::Query(strsql);

	if (row = mysql_fetch_row(res)) {
		CString slevel(row[0]);
		_value = slevel;
	}
	else {
		MessageBox(TEXT("查询错误，数据在等级划分之外"));
	}

	UpdateData(FALSE);


	


}


void CDengJi::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(FALSE);
}


void CDengJi::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(FALSE);
}
