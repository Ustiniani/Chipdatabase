#include "stdafx.h"
#include "DB_Help.h"

_ConnectionPtr DB_Help:: pMyConnect;

DB_Help::DB_Help()
{
}


DB_Help::~DB_Help()
{
}

bool DB_Help::Open()
{
	pMyConnect = NULL;
	HRESULT hr = pMyConnect.CreateInstance(__uuidof(Connection));
	if (FAILED(hr))
		return false;
	//��ʼ�����Ӳ���
	_bstr_t strConnect = "Driver={sql server};server=127.0.0.1;uid=sa;pwd=123456;database=test0;";
	//ִ������
	try
	{
		// Open���������ִ�������BSTR����_bstr_t����
		pMyConnect->Open(strConnect, "", "", NULL);
	}
	catch (_com_error &e)
	{
		return false;
	}
	return true;
}

_RecordsetPtr DB_Help::ExcuteReader(CString strsql)
{
	_RecordsetPtr pRecordset;
	pRecordset.CreateInstance(__uuidof(Recordset));
	pRecordset = pMyConnect->Execute(_bstr_t(strsql), NULL, adCmdText);//����ѯ���ݵ���pRecordset��������
	return pRecordset;
}

void DB_Help::ExcuteUpdate(CString strsql)
{
	pMyConnect->Execute(_bstr_t(strsql), NULL, adCmdText);
}
