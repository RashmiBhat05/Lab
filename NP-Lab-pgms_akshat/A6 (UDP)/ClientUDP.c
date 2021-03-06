/* Author : Akshat Agarwal

5. Using UDP, write a client – server program, to exchange messages between client and the server. */

/* Client Program */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
 
#define MAX 1024 

int main() 
{
	char buffer[MAX], msg[MAX]; 
	struct sockaddr_in servaddr; 

	// Creating socket file descriptor 
	int sock = socket(AF_INET, SOCK_DGRAM, 0);

	memset(&servaddr, 0, sizeof(servaddr)); 
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(1234); // htons(port)
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	
	while(1)
	{
		printf("Client : ");
		fgets(msg, MAX, stdin); 
		sendto(sock, (const char *)msg, strlen(msg), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
			
		int n = recvfrom(sock, (char *)buffer, sizeof(buffer), 0, NULL, NULL); 
		buffer[n] = '\0'; 
		printf("Server : %s", buffer); 
	}
	return 0; 
} 
