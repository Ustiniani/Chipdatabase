#include "stdafx.h"
#include "CModifyDlg.h"
#include"DBHelper.h"

// CDisplayView
IMPLEMENT_DYNCREATE(CModifyDlg, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CModifyDlg::CModifyDlg() : CFormView(IDD_DIALOG_MODIFY)
, _X(_T(""))
, _Y(_T(""))
, _VF(_T(""))
, _WP(_T(""))
, _WD(_T(""))
, _WH(_T(""))
, _IR(_T(""))
, _IV(_T(""))
{

}

CModifyDlg::~CModifyDlg()
{
}

BEGIN_MESSAGE_MAP(CModifyDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CModifyDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CModifyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CModifyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CModifyDlg::OnBnClickedButton5)
	//ON_EN_CHANGE(IDC_EDIT_WH, &CModifyDlg::OnEnChangeEditWh)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CModifyDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CModifyDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);

	DDX_Control(pDX, IDC_COMBO1, _combo);
	DDX_Text(pDX, IDC_EDIT1, _X);
	DDX_Text(pDX, IDC_EDIT2, _Y);
	DDX_Text(pDX, IDC_EDIT5, _VF);
	DDX_Text(pDX, IDC_EDIT6, _WP);
	DDX_Text(pDX, IDC_EDIT3, _WD);
	DDX_Text(pDX, IDC_EDIT7, _WH);
	DDX_Text(pDX, IDC_EDIT8, _IR);
	DDX_Text(pDX, IDC_EDIT9, _IV);
}


void CModifyDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql.Format(TEXT("select chip_NUM from chipdata"));

	res = DBHelper::Query(strsql);

	while (row = mysql_fetch_row(res))
	{
		CString Sno(row[0]);
		_combo.AddString(Sno);
	}

	DBHelper::Close();

	//_combo.SetCurSel(0);
	//OnCbnSelchangeCombo1();
}


void CModifyDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int index = _combo.GetCurSel();
	CString _num;

	_combo.GetLBText(index, _num);

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql.Format(TEXT("select X,Y,VF,WP,WD,WH,IR,IV from chipdata where chip_NUM='%s'"), _num);

	res = DBHelper::Query(strsql);

	while (row = mysql_fetch_row(res))
	{

		CString X(row[0]), Y(row[1]), VF(row[2]), WP(row[3]), WD(row[4]), WH(row[5]), IR(row[6]), IV(row[7]);
		_X = X;
		_Y = Y;
		_VF = VF;
		_WP = WP;
		_WD = WD;
		_WH = WH;
		_IR = IR;
		_IV = IV;
	}

	DBHelper::Close();

	UpdateData(FALSE);
}


void CModifyDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int index = _combo.GetCurSel();
	CString _num;


	if (index == -1)
	{
		MessageBox(TEXT("修改失败，您未选中任何芯片"));
		return;
	}
	_combo.GetLBText(index, _num);
	

	UpdateData(TRUE);

	if (_X.IsEmpty() || _Y.IsEmpty() || _VF.IsEmpty() || _WP.IsEmpty() || _WD.IsEmpty() || _WH.IsEmpty() || _IR.IsEmpty() || _IV.IsEmpty())
	{
		MessageBox(TEXT("修改的信息不能为空"));
		return;
	}

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql.Format(TEXT("update chipdata set X='%s',Y='%s',VF=%s,WP=%s,WD=%s,WH=%s,IR=%s,IV=%s where chip_NUM='%s'"), _X, _Y, _VF,_WP,_WD,_WH,_IR,_IV, _num);

	DBHelper::Update(strsql);
	
	UpdateData(FALSE);

	MessageBox(TEXT("修改成功"));
}


void CModifyDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int index = _combo.GetCurSel();
	CString _num;

	if (index == -1)
	{
		MessageBox(TEXT("请选中一个人"));
		return;
	}

	_combo.GetLBText(index, _num);

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql.Format(TEXT("select X,Y,VF,WP,WD,WH,IR,IV from chipdata where chip_NUM='%s'", _num));

	res = DBHelper::Query(strsql);

	while (row = mysql_fetch_row(res))
	{
		CString X(row[0]), Y(row[1]), VF(row[2]), WP(row[3]), WD(row[4]), WH(row[5]), IR(row[6]), IV(row[7]);
		_X = X;
		_Y = Y;
		_VF = VF;
		_WP = WP;
		_WD = WD;
		_WH = WH;
		_IR = IR;
		_IV = IV;
	}

	DBHelper::Close();

	UpdateData(FALSE);
	MessageBox(TEXT("已取消修改"));
}


void CModifyDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;

	int index = _combo.GetCurSel();
	CString _num;

	if (index == -1)
	{
		MessageBox(TEXT("删除失败，您未选中任何芯片"));
		return;
	}

	_combo.GetLBText(index, _num);

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql.Format(TEXT("delete from chipdata where chip_NUM='%s'"), _num);

	_combo.DeleteString(_combo.GetCurSel());
	_combo.SetCurSel(-1);
	
	_X = "";
	_Y = "";
	_VF = "";
	_WP = "";
	_WD = "";
	_WH = "";
	_IR = "";
	_IV = "";

	DBHelper::Update(strsql);
	DBHelper::Close();
	
	UpdateData(FALSE);
	MessageBox(TEXT("删除成功"));

}


void CModifyDlg::OnEnChangeEditWh()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
