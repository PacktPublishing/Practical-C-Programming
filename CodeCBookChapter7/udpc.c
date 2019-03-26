#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#include<stdlib.h> 
#include<unistd.h> 

int main() 
{    
    	char msgReceived[255]; 
	char msgforserver[255];
    	int UDPSocket, n; 
    	struct sockaddr_in client_Address;     
             	printf("Enter the message to send to the server: ");
	gets(msgforserver);
    	bzero(&client_Address, sizeof(client_Address)); 
    	client_Address.sin_addr.s_addr = INADDR_ANY; 
    	client_Address.sin_port = htons(2000); 
    	client_Address.sin_family = AF_INET;       
     	if ( (UDPSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        		perror("Socket could not be created"); 
        		exit(1); 
    	} 

    	if(connect(UDPSocket, (struct sockaddr *)&client_Address, sizeof(client_Address)) < 0) 
    	{ 
        		printf("\n Error : Connect Failed \n"); 
        		exit(0); 
    	}  
    	sendto(UDPSocket, msgforserver, 255, 0, (struct sockaddr*)NULL, sizeof(client_Address)); 
	printf("Message to the server sent. \n");
    	recvfrom(UDPSocket, msgReceived, sizeof(msgReceived), 0, (struct sockaddr*)NULL, NULL); 
      	printf("Received from the server: ");
    	puts(msgReceived); 
    	close(UDPSocket); 
} 