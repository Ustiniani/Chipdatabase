#pragma once
#pragma warning(disable : 4996)

#include <fstream>
#include <iostream>
#include <string>

#define _F_LOGIN "./login.ini"
#define _F_REM "./remeber.txt"

using namespace std;

class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//读取是否记住
	void ReadRemember(int &Rname, int &Rpwd);

	//写入是否记住
	void WriteRemember(int &Rname, int &Rpwd);

	//读取登录信息
	void ReadLogin(CString &name, CString &pwd);

	//修改密码
	void WritePwd(char* name, char* pwd);

};