/*
* table_user.h
*
*  Created on: 2016-6-7
*      Author: Liuker <lzq@liuker.xyz>
*/

#ifndef TABLE_USER_H_
#define TABLE_USER_H_

#include <stdio.h>
#include <stdlib.h>

#include "CMysql.h"

#define QUERY_SUCCESS 1
#define QUERY_FAILURE 0


int user_select(MYSQL *mysql);
int user_delete(MYSQL *mysql);
int user_insert(MYSQL *mysql);
int user_update(MYSQL *mysql);


#endif /* TABLE_USER_H_ */