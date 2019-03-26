#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	MYSQL *conn;
     	char *server = "127.0.0.1";
     	char *user = "root";
     	char *password = "Bintu2018$"; 
     	char *database = "ecommerce";
     	char emailaddress[30], upassword[30],deliveryaddress[255],sqlquery[255];
     	conn = mysql_init(NULL);
     	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        		fprintf(stderr, "%s\n", mysql_error(conn));
        		exit(1);
    	}
    	printf("Enter email address: ");
    	scanf("%s", emailaddress);
    	printf("Enter password: ");
    	scanf("%s", upassword);
    	printf("Enter address of delivery: ");
	getchar();
    	gets(deliveryaddress);
	strcpy(sqlquery,"INSERT INTO users(email_address, password, address_of_delivery)VALUES (\'");
	strcat(sqlquery,emailaddress);
	strcat(sqlquery,"\', \'");
	strcat(sqlquery,upassword);
	strcat(sqlquery,"\', \'");
	strcat(sqlquery,deliveryaddress);
	strcat(sqlquery,"\')");
 	if (mysql_query(conn, sqlquery) != 0)                  
  	{                                                                                                  
    		fprintf(stderr, "Row could not be inserted into users table\n");                                                              
        		exit(1);                                                                      
  	}   
	printf("Row is inserted successfully in users table\n"); 
    	mysql_close(conn);
}