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
	ifstream ifs; //�����ļ��������
	ifs.open(_F_REM);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	Rname = _ttoi(CString(buf));	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	Rpwd = _ttoi(CString(buf));	//��char* ת��ΪCString

	ifs.close();	//�ر��ļ�
}

void CInfoFile::WriteRemember(int & Rname, int & Rpwd)
{
	ofstream ofs; //�����ļ��������
	ofs.open(_F_REM); //���ļ�

	ofs << Rname << endl;	//nameд���ļ�
	ofs << Rpwd << endl;	//pwdд���ļ�

	ofs.close();	//�ر��ļ�
}

//��ȡ��¼��Ϣ
void CInfoFile::ReadLogin(CString &name, CString &pwd)
{
	ifstream ifs; //�����ļ��������
	ifs.open(_F_LOGIN);

	char buf[1024] = { 0 };

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	name = CString(buf);	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	pwd = CString(buf);	//��char* ת��ΪCString

	ifs.close();	//�ر��ļ�
}
//�޸�����
void CInfoFile::WritePwd(char* name, char* pwd)
{
	ofstream ofs; //�����ļ��������
	ofs.open(_F_LOGIN); //���ļ�

	ofs << name << endl;	//nameд���ļ�
	ofs << pwd << endl;	//pwdд���ļ�

	ofs.close();	//�ر��ļ�
}
