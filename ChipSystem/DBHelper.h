#pragma once
#include "mysql.h"
#include<Windows.h>
#include <stdio.h>
#include<winsock2.h>

class DBHelper
{
public:
	DBHelper();
	~DBHelper();
	static bool Connect();
	static void Close();
	static MYSQL_RES* Query(CString str);
	static int Update(CString str);
	static MYSQL mysql;
};

