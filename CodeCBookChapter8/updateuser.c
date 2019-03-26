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
     	char emailaddress[30], sqlquery[255], upassword[30],deliveryaddress[255];
     	conn = mysql_init(NULL);
     	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        		fprintf(stderr, "%s\n", mysql_error(conn));
        		exit(1);
    	}
    	printf("Enter email address of the user to update: ");
    	scanf("%s", emailaddress);
	strcpy(sqlquery,"SELECT * FROM users where email_address like \'");
	strcat(sqlquery,emailaddress);
	strcat(sqlquery,"\'");
 	if (mysql_query(conn, sqlquery) != 0)                  
  	{                                                                                                  
    		fprintf(stderr, "No row found in the users table with this email address\n");                                                              
        		exit(1);                                                                      
  	}   
	resultset = mysql_store_result(conn);
	if(mysql_num_rows(resultset) >0)
	{
		printf("The details of the user with this email address are as follows:\n"); 
    		while ((row = mysql_fetch_row(resultset)) != NULL)
		{
        			printf("Email Address: %s \n", row[0]);
 			printf("Password: %s \n", row[1]);
 			printf("Address of delivery: %s \n", row[2]);
		}
    		mysql_free_result(resultset);
  		printf("Enter new password: ");
    		scanf("%s", upassword);
    		printf("Enter new address of delivery: ");
		getchar();
    		gets(deliveryaddress);
		strcpy(sqlquery,"UPDATE users set password=\'");
		strcat(sqlquery,upassword);
		strcat(sqlquery,"\', address_of_delivery=\'");
		strcat(sqlquery,deliveryaddress);
		strcat(sqlquery,"\' where email_address like \'");
		strcat(sqlquery,emailaddress);
		strcat(sqlquery,"\'");
		if (mysql_query(conn, sqlquery) != 0)                  
  		{                                                                                                  
    			fprintf(stderr, "The desired row in users table could not be updated\n");                                                              
        			exit(1);                                                                      
  		}   
		printf("The information of user is updated successfully in users table\n"); 
	}
	else
		printf("No user found with this email address\n");
    	mysql_close(conn);
}