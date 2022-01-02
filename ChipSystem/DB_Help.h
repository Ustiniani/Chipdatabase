#pragma once
#include "afxdialogex.h"
#include <icrsint.h>
#include <windows.h>  
#include <sqltypes.h>  
#include <sql.h>  
#include <sqlext.h>
#import "c:\program files\common files\system\ado\msado15.dll"  no_namespace rename("EOF", "adoEOF")

class DB_Help
{
public:
	DB_Help();
	~DB_Help();
	static _ConnectionPtr pMyConnect;
	static bool Open();
	static _RecordsetPtr ExcuteReader(CString strsql);
	static void ExcuteUpdate(CString strsql);
};

