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

	//��ȡ�Ƿ��ס
	void ReadRemember(int &Rname, int &Rpwd);

	//д���Ƿ��ס
	void WriteRemember(int &Rname, int &Rpwd);

	//��ȡ��¼��Ϣ
	void ReadLogin(CString &name, CString &pwd);

	//�޸�����
	void WritePwd(char* name, char* pwd);

};