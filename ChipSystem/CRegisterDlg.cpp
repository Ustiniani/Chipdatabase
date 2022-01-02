// CRegisterDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CRegisterDlg.h"
#include "afxdialogex.h"
#include"DBHelper.h"

// CRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialogEx)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_REGISTER, pParent)
	, _UserName(_T(""))
	, _Password(_T(""))
{
}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PWD, _editboxPwd);
	DDX_Text(pDX, IDC_NAME, _UserName);
	DDX_Text(pDX, IDC_PWD, _Password);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CRegisterDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_REGISTER, &CRegisterDlg::OnBnClickedRegister)
END_MESSAGE_MAP()


// CRegisterDlg 消息处理程序


void CRegisterDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	int state = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	if (state == 1)
	{
		_editboxPwd.SetPasswordChar(NULL);
	}
	else
	{
		_editboxPwd.SetPasswordChar('*');
	}
	_editboxPwd.RedrawWindow();
}


BOOL CRegisterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CRegisterDlg::OnBnClickedRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	UpdateData(TRUE);
	if (_Password.IsEmpty() || _UserName.IsEmpty())
	{
		MessageBox(TEXT("输入的内容不能为空"));
		return;
	}

	if (!DBHelper::Connect())
	{
		MessageBox(TEXT("连接失败"));
		return;
	}

	strsql.Format(TEXT("select UserName from user where UserName='%s'"), _UserName);

	res = DBHelper::Query(strsql);

	if (res != nullptr)
	{
		if (res->row_count > 0)
		{
			MessageBox(TEXT("用户名已存在！请换一个比较个性的用户名！"));
			DBHelper::Close();
			return;
		}
	}
	

	strsql.Format(TEXT("insert into user values('%s','%s')"), _UserName, _Password);
	DBHelper::Update(strsql);
	
	DBHelper::Close();
	MessageBox(TEXT("恭喜注册成功！"));
}
