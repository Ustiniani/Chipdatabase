#include "stdafx.h"
#include "CReport.h"

#include"DBHelper.h"

// CReport
IMPLEMENT_DYNCREATE(CReport, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CReport::CReport() : CFormView(IDD_REPORT) {

}

CReport::~CReport()
{
}

BEGIN_MESSAGE_MAP(CReport, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CReport::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CReport::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CReport::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CReport::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CReport::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUGCStudentSystemApp

void CReport::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);
	DDX_Control(pDX, IDC_LIST3, _list);
	DDX_Control(pDX, IDC_COMBO1, _combox);
}


void CReport::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	_list.SetExtendedStyle(_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CString str[] = { TEXT("chip_num"),TEXT("X"),TEXT("Y"),TEXT("VF") ,TEXT("WP") ,TEXT("WD") ,TEXT("WH") ,TEXT("IR"),TEXT("IV") };
	for (int i = 0; i < 9; i++)
	{
		_list.InsertColumn(i, str[i], LVCFMT_LEFT, 100);
	}

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql.Format(TEXT("select chip_NUM,X,Y,VF,WP,WD,WH,IR,IV from chipdata"));

	res = DBHelper::Query(strsql);

	int i = 0;
	while (row = mysql_fetch_row(res))
	{
		CString chip_NUM(row[0]), X(row[1]), Y(row[2]), VF(row[3]), WP(row[4]), WD(row[5]), WH(row[6]), IR(row[7]), IV(row[8]);
		_list.InsertItem(i, chip_NUM);
		_list.SetItemText(i, 1, X);
		_list.SetItemText(i, 2, Y);
		_list.SetItemText(i, 3, VF);
		_list.SetItemText(i, 4, WP);
		_list.SetItemText(i, 5, WD);
		_list.SetItemText(i, 6, WH);
		_list.SetItemText(i, 7, IR);
		_list.SetItemText(i, 8, IV);
		i++;
	}
	
	_combox.AddString(TEXT("升序"));
	_combox.AddString(TEXT("降序"));
	_combox.SetCurSel(0);
	DBHelper::Close();
}


void CReport::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int select = _combox.GetCurSel();

	_list.DeleteAllItems();

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	if (select == 1)
		strsql.Format(TEXT("select chip_NUM,X,Y,VF,WP,WD,WH,IR,IV from chipdata order by chip_NUM desc"));
	else
		strsql.Format(TEXT("select chip_NUM,X,Y,VF,WP,WD,WH,IR,IV from chipdata order by chip_NUM"));

	res = DBHelper::Query(strsql);

	int i = 0;
	while (row = mysql_fetch_row(res))
	{
		CString chip_NUM(row[0]), X(row[1]), Y(row[2]), VF(row[3]), WP(row[4]), WD(row[5]), WH(row[6]), IR(row[7]), IV(row[8]);
		_list.InsertItem(i, chip_NUM);
		_list.SetItemText(i, 1, X);
		_list.SetItemText(i, 2, Y);
		_list.SetItemText(i, 3, VF);
		_list.SetItemText(i, 4, WP);
		_list.SetItemText(i, 5, WD);
		_list.SetItemText(i, 6, WH);
		_list.SetItemText(i, 7, IR);
		_list.SetItemText(i, 8, IV);
		i++;
	}
	DBHelper::Close();
}


void CReport::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int select = _combox.GetCurSel();

	_list.DeleteAllItems();

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	if (select == 1)
		strsql.Format(TEXT("select chip_NUM,X,Y,VF,WP,WD,WH,IR,IV from chipdata order by Y desc"));
	else
		strsql.Format(TEXT("select chip_NUM,X,Y,VF,WP,WD,WH,IR,IV from chipdata order by Y"));

	res = DBHelper::Query(strsql);

	int i = 0;
	while (row = mysql_fetch_row(res))
	{
		CString chip_NUM(row[0]), X(row[1]), Y(row[2]), VF(row[3]), WP(row[4]), WD(row[5]), WH(row[6]), IR(row[7]), IV(row[8]);
		_list.InsertItem(i, chip_NUM);
		_list.SetItemText(i, 1, X);
		_list.SetItemText(i, 2, Y);
		_list.SetItemText(i, 3, VF);
		_list.SetItemText(i, 4, WP);
		_list.SetItemText(i, 5, WD);
		_list.SetItemText(i, 6, WH);
		_list.SetItemText(i, 7, IR);
		_list.SetItemText(i, 8, IV);
		i++;
	}
	DBHelper::Close();
}


void CReport::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

}
