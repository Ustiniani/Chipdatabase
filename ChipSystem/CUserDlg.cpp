#include "stdafx.h"
#include "CUserDlg.h"

#include"ExternValue.h"
#include"DBHelper.h"
#include "CInfoFile.h"

// CDisplayView
IMPLEMENT_DYNCREATE(CUserDlg, CFormView)
//IDD_DISPLAYVIEW模态框的ID
CUserDlg::CUserDlg() : CFormView(IDD_DIALOG_USER)
, _name(_T(""))
, _user(_T(""))
, _newPwd(_T(""))
, _surePwd(_T(""))
{

}


CUserDlg::~CUserDlg()
{
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, sdf);
	DDX_Text(pDX, IDC_EDIT1, _name);
	DDX_Text(pDX, IDC_EDIT2, _user);
	DDX_Text(pDX, IDC_EDIT3, _newPwd);
	DDX_Text(pDX, IDC_EDIT4, _surePwd);
}

void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	_user = TEXT("管理员");
	_name = ExternValue::UserName;
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	UpdateData(TRUE);
	if (_newPwd.IsEmpty())
	{
		MessageBox(TEXT("新密码为空"));
		return;
	}
	if (_surePwd.IsEmpty())
	{
		MessageBox(TEXT("确认密码为空"));
		return;
	}
	if (_newPwd != _surePwd)
	{
		MessageBox(TEXT("新密码与确认密码不一致"));
		return;
	}

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}
	

	strsql.Format(TEXT("select Password from user where UserName='%s'"), _name);

	res = DBHelper::Query(strsql);

	while (row = mysql_fetch_row(res))
	{
		CString pwd(row[0]);
		if (pwd == _newPwd)
		{
			MessageBox(TEXT("新密码与原密码一致"));
			DBHelper::Close();
			return;
		}

	}

	strsql.Format(TEXT("update user set Password='%s' where UserName='%s'"), _newPwd, _name);
	DBHelper::Update(strsql);
	DBHelper::Close();
	MessageBox(TEXT("密码修改成功"));

	CInfoFile file;
	file.WritePwd(((CStringA)_name).GetBuffer(), ((CStringA)_newPwd).GetBuffer());

	_newPwd.Empty();
	_surePwd.Empty();
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	_newPwd.Empty();
	_surePwd.Empty();
	UpdateData(FALSE);
	MessageBox(TEXT("已将你输入的密码清空"));
}
