#include "stdafx.h"
#include "DBHelper.h"
#include<string.h>


MYSQL DBHelper::mysql;

DBHelper::DBHelper()
{
}


DBHelper::~DBHelper()
{
}

bool DBHelper::Connect()
{
	//admin---schoolcard1
	mysql_init(&mysql);
	const char host[] = "localhost";//地址
	const char user[] = "root";//用户名
	const char passwd[] = "root";//密码
	const char db[] = "chipdb";//数据库
	unsigned int port = 3306;//端口
	if (mysql_real_connect(&mysql, host, user, passwd, db, port, 0, 0)) {
		//mysql_query(&mysql, "SET NAMES 'GB2312'");
		mysql_set_character_set(&mysql, "GB2312");
		return true;
	}
	else {
		return false;
	}
}

void DBHelper::Close()
{
	mysql_close(&mysql);
}

MYSQL_RES* DBHelper::Query(CString str)
{
	USES_CONVERSION;
	char* sql = T2A(str.GetBuffer(0));
	str.ReleaseBuffer();

	mysql_query(&mysql,sql);
	MYSQL_RES *m_res = mysql_store_result(&mysql);
	return m_res;
}

int DBHelper::Update(CString str)	
{
	USES_CONVERSION;
	char* sql = T2A(str.GetBuffer(0));
	str.ReleaseBuffer();

	mysql_query(&mysql, "SET NAMES 'GB2312'");
	return mysql_query(&mysql, sql);

	//mysql_real_query(&mysql, sql, (unsigned long)strlen(sql));
}
