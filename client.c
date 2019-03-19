#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int main()
{
  // CREATE A SOCKET
  int network_socket;
  network_socket = socket (AF_INET, SOCK_STREAM, 0);

  // SPECIFY AN ADDRESS FOR THE SOCKET
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons (9302);
  server_address.sin_address.s_addr = INADOR_ANY;

  int connection_status = connect (network_socket, (struct sockaddr*) &server_address, sizeof (server_address));
  
  //CHECK FOR ERROR WITH CONNECTION
  if (connection_status == -1)
  {
    printf ("There was an error making a connection to the remote socket \n\n");
  }

  //RECEIVE DATA FROM SERVER 
  char server_response[256];
  recv(network_socket, &server_response, sizeof(server_response, 0), 0);

  // PRINT OUT THE SERVER'S RESPONSE
  printf("The server sent the data : %s\n", server_response);

  //END THE CLOSE THE SOCKET
  close(network_sock);
  return 0;
}
