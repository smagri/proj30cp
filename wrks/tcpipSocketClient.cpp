/* TCP/IP socket client that connects to the Arduino Server(arduinoServer). */

/* INPUTS: ----------------------------------------------------------------- */

/* ------------------------------------------------------------------------ */

/* OUTPUTS: ---------------------------------------------------------------- */
/* returns 0 all ok */

/* NOTE: perhaps need to change these exits to return's so client can
   take more approprite acton for it's application */

/* exits (1) - fatal error while trying to open a socket for this client */
/* exits (2) - fator error while converting hostname to network byte order */
/* exits (3) - fatal error while trying to connect to server */
/* exits (4) - fatal error while trying to write to server */
/* exits (5) - fatal error while trying to read from server */
/* exits (6) - fatal error while closing this client's socket fd */

/* chXfer - character transfered between client and server <->. */

/*-----------------------------------------------------------------------------
 History:

 27-Aug-2016	Simone Magri	Original routine

 End History.
-----------------------------------------------------------------------------*/

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

// #include <generic.h>



int main(int argc, char *argv[]){


  int client_fd = -1; /* this clients' socket file descriptor */
  struct sockaddr_in server_sockaddr; /* server listen socket address */
  const unsigned short int server_port = 23; /* server listen socket port */
  struct hostent *server_host; /* contains server host address in
				  network byte order */

  ssize_t retval;

  // Name of host which server(arduinoServer) is running on.
  //
  // smagri owned arduino uno rev3 and arduino wifi shield
  //char server_hostname[] = "192.168.3.117";
  //
  // UTS owned arduino uno rev3 and arduino wifi shield
  char server_hostname[] = "192.168.3.121";
  //char chXfer[]="?";

  // I think the arduino doesn't cope with anything other than reading
  // a char at a time.
  //
  char dirRotation='1'; // default rotation direction is clockwise
  //unsigned int dirRotation=1; // default rotation direction is clockwise
  char numRotation='3'; // default number of rotations required
  //unsigned int numRotation=3; // default number of rotations required
  char handShake='0'; // default number of rotations required
  char loopNum=1;


  while(loopNum){

    fprintf(stderr, "dbg: dirRotation=%u, numRotation=%u, handShake=%u\n",
	    dirRotation, numRotation, handShake);
    /* Open a tcp socket to allow us to make connections from the client
       to the server. */
    if ( (client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
      perror("tcpipSocketClient");
      fprintf(stderr, "%s: Error in socket call to server@%s.\n",
	      "tcpipSocketClient", server_hostname);
      exit(1);
    }


    /* Specify the server's socket address(TCP IP address and port number)
       that this client will connect to. */
    memset( ((void *) &server_sockaddr), 0, sizeof(server_sockaddr) );
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(server_port); /* convert port number to
						      network byte order */
    /* convert server host name to host address in network byte order */
    server_host = gethostbyname(server_hostname);
    if (server_host == ((struct hostent *) NULL)){
      fprintf(stderr, "%s: Error in gethostbyname for server@%s.\n",
	      "tcpipSocketClient", server_hostname);
      exit(2);
    }
    memcpy(&server_sockaddr.sin_addr,server_host->h_addr,server_host->h_length);

    /* Connect client's socket to the server's listening socket. */
    /* (blocks till a connection is made or there is an error) */
    if (connect(client_fd, ((struct sockaddr *)&server_sockaddr),
		sizeof(server_sockaddr)) <0){
      /* Connection failed or in progress */
      perror("tcpipSocketClient");
      fprintf(stderr, "%s: Error in connect to server@%s.\n.",
	      "tcpipSocketClient", server_hostname);
      close(client_fd);
      exit(3);
    }

  
    /* Send char/s to server. */
    //
    // Winch down command.
    //  delay(emperically or asyncronously)
    // Winch up command.
    //
    /* if ( (retval=write(client_fd, &handShake, sizeof(handShake)) == -1) ){
       perror("tcpipSocketClient");
       fprintf(stderr, "%s: Error in writing to server@%s.\n",
       "tcpipSocketClient", server_hostname);
       exit(4);
       } */
    if ( (retval=write(client_fd, &dirRotation, sizeof(dirRotation)) == -1) ){
      perror("tcpipSocketClient");
      fprintf(stderr, "%s: Error in writing to server@%s.\n",
	      "tcpipSocketClient", server_hostname);
      exit(4);
    }
    if ( (retval=write(client_fd, &numRotation, sizeof(numRotation)) == -1) ){
      perror("tcpipSocketClient");
      fprintf(stderr, "%s: Error in writing to server@%s.\n",
	      "tcpipSocketClient", server_hostname);
      exit(4);
    }


    // Read a response from the server.
    //
    // read() should block till a character is sent by the server.
    //
/*    if ( (retval = read(client_fd, &handShake, sizeof(handShake)) == -1) ){
      perror("tcpipSocketClient");
      fprintf(stderr, "%s: Error in reading from server@%s\n",
	      "tcpipSocketClient", server_hostname);
      exit(5);
      }
*/

  
    if (close(client_fd) == -1){
      perror("tcpipSocketClient");
      fprintf(stderr, "%s: Error in closing socket fd\n.", "tcpipSocketClient");
      exit(6);
    }
    

    if(loopNum==1){
      dirRotation='0';
      numRotation='5'; // irrelevant for a servo loop
      loopNum++;

      // This is the delay time  between winching down and up. The delay
      // probably needs  to be  determined emperically.  Or,  command to
      // winch down given asycncronously.  
      sleep(20);

      // Winch up for the next loop
    }
    else{
      // end xfer pair of chars to server
      loopNum=0;
    }


  } // end: while(loopNum)    

  return (0); /* return dataset xfer(ie ds_get's) return value */
  
} /* end: main() */	   
