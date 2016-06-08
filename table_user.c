/*
* table_user.c
*
*  Created on: 2016-6-7
*      Author: Liuker <lzq@liuker.xyz>
*/


#include "table_user.h"

int user_select(MYSQL *mysql){
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;
	int i, j;

	if (mysql) {
		mysql = Mysql_Query(mysql, "select uid,uname,upasswd,role from user");
		if (mysql)
		{
			// 取出结果集
			res_ptr = mysql_store_result(mysql);
			if (res_ptr)
			{
				printf("Total: %lu Rows\n", (unsigned long)mysql_num_rows(res_ptr));
				j = mysql_num_fields(res_ptr);

				// 依次取出记录
				while ((sqlrow = mysql_fetch_row(res_ptr)))
				{
					for (i = 0; i < j; i++)
						printf("%s\t", sqlrow[i]);
					printf("\n");
				}

				if (mysql_errno(mysql)) {
					fprintf(stderr, "Retrive error:%s\n", mysql_error(mysql));
				}
			}
			mysql_free_result(res_ptr);
		}
	}
	return QUERY_SUCCESS;
}

int user_delete(MYSQL *mysql){
	if (mysql)
	{
		mysql = Mysql_Query(mysql, "DELETE FROM `user` WHERE uname='admin'");

		if (mysql)
		{
			printf("Affected row: %lu\n", (unsigned long)mysql_affected_rows(mysql));
		}
		else
		{
			fprintf(stderr, "error %d: %s\n", mysql_errno(mysql), mysql_error(mysql));
		}
	}
	return QUERY_SUCCESS;
}


int user_insert(MYSQL *mysql){
	if (mysql)
	{
		mysql = Mysql_Query(mysql, "INSERT INTO `user`(uname,upasswd) VALUES('admin','password')");

		if (mysql)
		{
			printf("Affected row: %lu\n", (unsigned long)mysql_affected_rows(mysql));
		}
		else
		{
			fprintf(stderr, "Error %d: %s\n", mysql_errno(mysql), mysql_error(mysql));
		}
	}
	return QUERY_SUCCESS;
}

int user_update(MYSQL *mysql){
	if (mysql)
	{
		mysql = Mysql_Query(mysql, "UPDATE user SET upasswd='zaqwsx' WHERE uname='admin'");
		if (mysql)
		{
			printf("Affected row: %lu\n", (unsigned long)mysql_affected_rows(mysql));
		}
		else
		{
			fprintf(stderr, "Error %d: %s\n", mysql_errno(mysql), mysql_error(mysql));
		}
	}
	return QUERY_SUCCESS;
}



int main() {
	MYSQL *conn_ptr;
	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) {
		return EXIT_FAILURE;
	}
	conn_ptr = Mysql_Content(conn_ptr);
	
	user_delete(conn_ptr);
	user_select(conn_ptr);

	user_insert(conn_ptr);
	user_select(conn_ptr);

	user_update(conn_ptr);
	user_select(conn_ptr);

	Mysql_Close(conn_ptr);
	system("pause");
	return 0;
}
