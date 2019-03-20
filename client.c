#include <stdio.h> 
#include <sys/socket.h> 

#include <stdlib.h> 
#include <netinet/in.h> 

#include <string.h>
#include <unistd.h>

#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *Annyeonghasaeyo = "Annyeonghasaeyo from client"; 
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\n Annyeonghasaeyo, server! \n"); 
        return -1; 
    } 
    send(sock , Annyeonghasaeyo , strlen(Annyeonghasaeyo) , 0 ); 
    printf("Annyeonghasaeyo message sent\n"); 
    valread = read ( sock , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
} 
