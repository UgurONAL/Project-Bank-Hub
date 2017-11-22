#include "Conn.h"

#include <iostream>
#include <string>
#include "mysql\include\mysql.h"

using namespace std;
using namespace System;

MYSQL *mysql;
MYSQL_RES *sonuc;
MYSQL_ROW satir;
MYSQL *conn;
int sorgu;

Conn::Conn()
{
	mysql = mysql_init(NULL);
	conn = mysql_real_connect(mysql, "localhost", "root", "", "bankhub", 0, NULL, 0);
	/*
	sorgu=mysql_query(baglan, "select * from tablo");
	sonuc = mysql_store_result(baglan);
	satir = mysql_fetch_row(sonuc);
	while((satir=mysql_fetch_row(sonuc))!=NULL)
	{
	printf("int: %s, char: %sn", satir[0], satir[1]);
	}


	*/

	mysql_close(conn);
	//mysql_free_result(sonuc);

}

Conn::~Conn()
{
}

