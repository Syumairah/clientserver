#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    // code for a client connecting to a server
    // namely a stream socket to www.example.com on port 80 (http)
    // either IPv4 or IPv6
    
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    memset (&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // use AF_INET6 to force IPv6
    hints.ai_socktype = SOCK_STREAM;
    if ((rv = getaddrinfo("192.168.2.4", "50000", &hints, &servinfo)) != 0) 
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }
    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
        p->ai_protocol)) == -1) 
        {
            perror("socket");

        continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) 
        {
            close(sockfd);
            perror("connected");
            continue;
        }
        break; // if we get here, we must have connected successfully
    }

    if (p == NULL)
    {
        // looped off the end of the list with no connection
        fprintf(stderr, "failed to connect\n");
        exit(2);
    }

    freeaddrinfo(servinfo); // all done with this structure

}
