#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	MYSQL *conn;
     	MYSQL_RES *resultset;
     	MYSQL_ROW row;
     	char *server = "127.0.0.1";
     	char *user = "root";
     	char *password = "Bintu2018$"; 
     	char *database = "ecommerce";
     	char emailaddress[30], sqlquery[255];
     	conn = mysql_init(NULL);
     	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        		fprintf(stderr, "%s\n", mysql_error(conn));
        		exit(1);
    	}
    	printf("Enter email address to search: ");
    	scanf("%s", emailaddress);
	strcpy(sqlquery,"SELECT * FROM users where email_address like \'");
	strcat(sqlquery,emailaddress);
	strcat(sqlquery,"\'");
 	if (mysql_query(conn, sqlquery) != 0)                  
  	{                                                                                                  
    		fprintf(stderr, "No row found in the users table with this email address\n");                                                              
        		exit(1);                                                                      
  	}   
	printf("The details of the user with this email address are as follows:\n"); 
   	resultset = mysql_use_result(conn);
    	while ((row = mysql_fetch_row(resultset)) != NULL)
	{
        		printf("Email Address: %s \n", row[0]);
 		printf("Password: %s \n", row[1]);
 		printf("Address of delivery: %s \n", row[2]);
	}
    	mysql_free_result(resultset);
    	mysql_close(conn);
}