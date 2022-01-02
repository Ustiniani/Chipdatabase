#include "stdafx.h"
#include "CInfoFile.h"

CInfoFile::CInfoFile()
{
}

CInfoFile::~CInfoFile()
{
}

void CInfoFile::ReadRemember(int & Rname, int & Rpwd)
{
	ifstream ifs; //创建文件输入对象
	ifs.open(_F_REM);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	Rname = _ttoi(CString(buf));	//将char* 转换为CString

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	Rpwd = _ttoi(CString(buf));	//将char* 转换为CString

	ifs.close();	//关闭文件
}

void CInfoFile::WriteRemember(int & Rname, int & Rpwd)
{
	ofstream ofs; //创建文件输出对象
	ofs.open(_F_REM); //打开文件

	ofs << Rname << endl;	//name写入文件
	ofs << Rpwd << endl;	//pwd写入文件

	ofs.close();	//关闭文件
}

//读取登录信息
void CInfoFile::ReadLogin(CString &name, CString &pwd)
{
	ifstream ifs; //创建文件输入对象
	ifs.open(_F_LOGIN);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	name = CString(buf);	//将char* 转换为CString

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	pwd = CString(buf);	//将char* 转换为CString

	ifs.close();	//关闭文件
}
//修改密码
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream ofs; //创建文件输出对象
	ofs.open(_F_LOGIN); //打开文件

	ofs << name << endl;	//name写入文件
	ofs << pwd << endl;	//pwd写入文件

	ofs.close();	//关闭文件
}
