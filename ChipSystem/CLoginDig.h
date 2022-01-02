#pragma once


// CLoginDig 对话框

class CLoginDig : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDig)

public:
	CLoginDig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLoginDig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	HICON m_hIcon;
	CString _userName;
	CString _passWord;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	afx_msg void OnClose();
private:
	CButton _remName;
public:
	afx_msg void OnBnClickedCheck2();
private:
	CButton _remPwd;
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButtonRegister();
};
