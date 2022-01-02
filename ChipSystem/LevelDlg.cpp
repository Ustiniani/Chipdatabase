// LevelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "resource.h"
#include "LevelDlg.h"

#include"DBHelper.h"
// CLevelDlg

IMPLEMENT_DYNCREATE(CLevelDlg, CFormView)

CLevelDlg::CLevelDlg()
	: CFormView(IDD_DIALOG_LEVEL)
{

}

CLevelDlg::~CLevelDlg()
{
}

void CLevelDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, _list);
}

BEGIN_MESSAGE_MAP(CLevelDlg, CFormView)
END_MESSAGE_MAP()


// CLevelDlg ���

#ifdef _DEBUG
void CLevelDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLevelDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLevelDlg ��Ϣ�������


void CLevelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	_list.SetExtendedStyle(_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CString str[] = { TEXT("оƬ�ȼ�"),
		TEXT("VF����") ,TEXT("VF����"),TEXT("WP����") ,TEXT("WP����") ,TEXT("WD����") ,TEXT("WD����") ,
		TEXT("WH����") ,TEXT("WH����") ,TEXT("IR����"),TEXT("IR����"),TEXT("IV����"),TEXT("IV����") };
	for (int i = 0; i < 13; i++)
	{
		_list.InsertColumn(i, str[i], LVCFMT_LEFT, 100);
	}

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("����ʧ��"));
		return;
	}

	strsql.Format(TEXT("select chip_RANK,VFLow,VFUp,WPLow,WPUp,WHLow,WHUp,WDLow,WDUp,IRLow,IRUp,IVLow,IVUp from chiprank"));

	res = DBHelper::Query(strsql);

	int i = 0;
	while (row = mysql_fetch_row(res))
	{
		CString chip_RANK(row[0]), VFLow(row[1]), VFUp(row[2]), WPLow(row[3]), WPUp(row[4]), WHLow(row[5]), WHUp(row[6]), WDLow(row[7]), WDUp(row[8])
			, IRLow(row[9]), IRUp(row[10]), IVLow(row[11]), IVUp(row[12]);
		_list.InsertItem(i, chip_RANK);
		_list.SetItemText(i, 1, VFLow);
		_list.SetItemText(i, 2, VFUp);
		_list.SetItemText(i, 3, WPLow);
		_list.SetItemText(i, 4, WPUp);
		_list.SetItemText(i, 5, WHLow);
		_list.SetItemText(i, 6, WHUp);
		_list.SetItemText(i, 7, WDLow);
		_list.SetItemText(i, 8, WDUp);
		_list.SetItemText(i, 9, IRLow);
		_list.SetItemText(i, 10, IRUp);
		_list.SetItemText(i, 11, IVLow);
		_list.SetItemText(i, 12, IVUp);
		i++;
	}
}



