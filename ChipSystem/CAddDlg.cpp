#include "stdafx.h"
#include "CAddDlg.h"

#include"DBHelper.h"

// CAddDlg
IMPLEMENT_DYNCREATE(CAddDlg, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CAddDlg::CAddDlg() : CFormView(IDD_DIALOG_ADD), _X(_T(""))
, _Y(_T(""))
, _VF(_T(""))
, _WP(_T(""))
, _WD(_T(""))
, _WH(_T(""))
, _IR(_T(""))
, _IV(_T(""))
{

}

CAddDlg::~CAddDlg()
{
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT6, &CAddDlg::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT2, &CAddDlg::OnEnChangeEdit2)
	//ON_EN_CHANGE(IDC_EDIT10, &CAddDlg::OnEnChangeEdit10)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);
	DDX_Text(pDX, IDC_EDIT1, _X);
	DDX_Text(pDX, IDC_EDIT2, _Y);
	DDX_Text(pDX, IDC_EDIT5, _VF);
	DDX_Text(pDX, IDC_EDIT6, _WP);
	DDX_Text(pDX, IDC_EDIT3, _WD);
	DDX_Text(pDX, IDC_EDIT7, _WH);
	DDX_Text(pDX, IDC_EDIT8, _IR);
	DDX_Text(pDX, IDC_EDIT9, _IV);
}


void CAddDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res=NULL;
	MYSQL_ROW row;

	UpdateData(TRUE);
	if (_X.IsEmpty() || _Y.IsEmpty() || _VF.IsEmpty() || _WP.IsEmpty()||_WD.IsEmpty()||_WH.IsEmpty()||_IR.IsEmpty()||_IV.IsEmpty())
	{
		MessageBox(TEXT("添加的信息不能为空"));
		return;
	}

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	//strsql.Format(TEXT("select Sno from card where Sno='%s'"), _sno);

	//res = DBHelper::Query(strsql);

	//if (res->row_count > 0)
	//{
	//	CString str;
	//	str.Format(TEXT("学号%s已存在"), _sno);
	//	MessageBox(str);
	//	DBHelper::Close();
	//	return;
	//}
	strsql.Format(TEXT("insert into chipdata(X,Y,VF,WP,WD,WH,IR,IV) values('%s','%s','%s','%s','%s','%s','%s',%s)"), _X, _Y, _VF, _WP,_WD,_WH,_IR,_IV);
	int resu=DBHelper::Update(strsql);
	DBHelper::Close();
	if (resu) {
	MessageBox(TEXT("添加失败"));
	}
	else {
	MessageBox(TEXT("添加成功"));
	}

}


void CAddDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	_X = "";
	_Y = "";
	_VF = "";
	_WP = "";
	_WD = "";
	_WH = "";
	_IR = "";
	_IV = "";
	UpdateData(FALSE);
}


void CAddDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAddDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAddDlg::OnEnChangeEdit10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
