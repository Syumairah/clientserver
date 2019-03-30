#include <stdio.h> 
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h> 
#include <unistd.h> 
#include <arpa/inet.h>
   
int main() 
{ 
    struct sockaddr_in serv_addr; 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(5132);
    serv_addr.sin_addr.s_addr = ip address;
   
    char serverMsg[1024] = "Hello yaww"; 
    
    int status = connect(network_socket,(struct sockaddr *) &server_address, sizeof(server_address));
   
   if (status == -1)
   {
      printf("There was an error %s\n");
   }
   
   send(network_socket, serverMsg, sizeof(serverMsg), 0);
   
   char serverResponse [1024];
   recv(network_socket, &serverResponse, sizeof(serverResponse), 0);
   
   printf("Annyeonghaseyo, server! : %s\n", serverResponse );
   close (network_socket);
   
   return 0; 
} 
