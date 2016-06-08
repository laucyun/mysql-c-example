/*
* CMysql.h
*
*  Created on: 2016-6-7
*      Author: Liuker <lzq@liuker.xyz>
*/

#ifndef CMYSQL_H_
#define CMYSQL_H_

#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include "mysql.h"

MYSQL * Mysql_Content(MYSQL *mysql);
MYSQL * Mysql_Query(MYSQL *mysql,
	const char *q);
void Mysql_Close(MYSQL *mysql);


#endif /* CMYSQL_H_ */
