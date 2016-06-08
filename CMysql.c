/*
* CMysql.c
*
*  Created on: 2016-6-7
*      Author: Liuker <lzq@liuker.xyz>
*/

#include "CMysql.h"

struct stu_mysqlconfig{
	char *host;
	char *user;
	char *passwd;
	char *db;
	unsigned int port;
	char *unix_socket;
	unsigned long clientflag;
}config = { "localhost", "root", "root", "demo", 0, NULL, 0 };



MYSQL * Mysql_Content(MYSQL *mysql){
	mysql = mysql_init(NULL);
	if (!mysql) {
		return NULL;
	}

	// connect
	mysql = mysql_real_connect(mysql, config.host, 
		config.user,
		config.passwd,
		config.db,
		config.port,
		config.unix_socket,
		config.clientflag
		);
	if (mysql)
	{
		return mysql;
	}
	else
	{
		printf("Failed to connect to %s!\n", config.host);
		return NULL;
	}
}


MYSQL * Mysql_Query(MYSQL *mysql,
	const char *q){
	int res;
	if (mysql)
	{
		res = mysql_query(mysql, q);
		if (!res)
		{
			return mysql;
		}
		else
		{
			fprintf(stderr, "Query error %d: %s\n", mysql_errno(mysql), mysql_error(mysql));
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

void Mysql_Close(MYSQL *mysql){
	mysql_close(mysql);
}
