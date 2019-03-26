#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
	int serverSocket, toSend;
  	char str[255];
  	struct sockaddr_in server_Address;

  	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  	server_Address.sin_family = AF_INET;
  	server_Address.sin_port = htons(2000);
  	server_Address.sin_addr.s_addr  = inet_addr("127.0.0.1");
  	memset(server_Address.sin_zero, '\0', sizeof server_Address.sin_zero);  
  	bind(serverSocket, (struct sockaddr *) &server_Address, sizeof(server_Address));
  	if(listen(serverSocket,5)==-1)
	{
      		printf("Not able to listen\n");
      		return -1;
	}
   	printf("Enter text to send to the client: ");
   	gets(str);
	toSend = accept(serverSocket, (struct sockaddr *) NULL, NULL);
  	send(toSend,str, strlen(str),0);
	return 0;
}
