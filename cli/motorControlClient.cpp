// This  program is  the  client program  that  communicates with  the
// arduinoServer(arduinoServer.ino).  Note that  the arduio server can
// be configured for servo motor control or stepper motor control(with
// a #define).
//
// This  client connects  to the  arduino server  via a  TCP/IP socket
// connection.
//


// INPUTS: -------------------------------------------------------------------

// dirRotation	- motor rotation direction(clockwise=1, counterclockwise=0)
// numRotation	- number of motor rotations required; irrelivant for contiuous
//		  servo, only valid for a stepper motor.
//
// argv[1]	- the static IP address of the wifi arduino server.  This
//		  address is set within the arduinoServer.
//
// handShake='0'; // to be fushed in server/end comms???

// ---------------------------------------------------------------------------


// OUTPUTS: ------------------------------------------------------------------
// returns 0 all ok

// NOTE: perhaps need to change these exits to return's so client can
// take more approprite acton for it's application

// exits (1) - fatal error while trying to open a socket for this client
// exits (2) - fatalerror while converting hostname to network byte order
// exits (3) - fatal error while trying to connect to server
// exits (4) - fatal error while trying to write to server 
// exits (5) - fatal error while trying to read from server
// exits (6) - fatal error while closing this client's socket fd

// ---------------------------------------------------------------------------


// History:

// 27aug2016    Simone Magri    Original routine
// 05sep2016    Simone Magri    Convert to motorControlClient() via xfer2as()
// 7-10sep2016  Simone Magri    redo last changes as accidently deleated them
// 7-10sep2016	Simone Magri	redo pass by value to xfer2as
// 7-10sep2016	Simone Magri	redo comments

// End History.
// ---------------------------------------------------------------------------


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


extern int xfer2as(char dirRotation, char numRotation, char *serverID);




int main(int argc, char *argv[]){

  char serverID[15]; // arduinoServer IPaddress or Hostname

  char dirRotation; // motor rotation, clockwise='1' & counterclockwise='0'
  char numRotation; // number of motor rotations; not applicable to
		    // stepper motor

  //char handShake='0'; // flush() required in server???
  int retval; // return value from xferas() fn



  // Copy first command line parameter to the IPaddress of the arduino
  // server, for clarity.
  strcpy(serverID, argv[1]);


  // Winch DOWN the payload using a servo or stepper motor. Motor
  // rotation is in the clockwise direction.  For the servo motor the
  // number of rotations is irrelevant and not used.
  dirRotation='1';
  numRotation='3';
  retval = xfer2as(dirRotation, numRotation, serverID);
  if (retval){
    fprintf(stderr, "Error occured during xfer to arduinoServer.\n");
    return retval;
  }


  // This is the delay time  between winching down and up. The delay
  // probably needs  to be  determined emperically.  Or,  command to
  // winch down given asycncronously. 
  //
  sleep(20);
  //sleep(5); // stepper motor delay


  // Winch UP the payload using a servo or stepper motor.  Motor
  // rotation is in the counterclockwise direction.  For the servo
  // motor the number of rotations is irrelevant and not used.
  dirRotation='0';
  numRotation='5';
  retval = xfer2as(dirRotation, numRotation, serverID);
  if (retval){
    fprintf(stderr, "Error occured during xfer to arduinoServer.\n");
    return retval;
  }


  return (0); /* return dataset xfer(ie ds_get's) return value */
  
} /* end: main() */	   
