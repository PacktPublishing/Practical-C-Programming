#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
  	int clientSocket;
  	char str[255];
  	struct sockaddr_in client_Address;
  	socklen_t address_size;

  	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    	client_Address.sin_family = AF_INET;
  	client_Address.sin_port = htons(2000);
  	client_Address.sin_addr.s_addr = inet_addr("127.0.0.1");
  	memset(client_Address.sin_zero, '\0', sizeof client_Address.sin_zero);  
  	address_size = sizeof client_Address;
  	connect(clientSocket, (struct sockaddr *) &client_Address, address_size);
  	recv(clientSocket, str, 255, 0);
  	printf("Data received froms server: %s",str);   
  	return 0;
}
