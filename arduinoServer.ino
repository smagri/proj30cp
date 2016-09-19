// This  is  the  arduinoServer,  which  can  be  the  servoServer  or
// stepperServer    when    MOTOR_Servo/MOTOR_Stepper   are    defined
// respectively.
//
// xfer2as() is the library function that clients talk to this server with.
// ---------------------------------------------------------------------------
//
// Circuit: WiFi shield attached to Arduino Uno rev3.
// 
// Derived from the arduinoIDE 1.0.5 examples:
// WiFi->WiFiChatServer
// Servo->Sweep
// Servo->upDown
// Stepper->stepper_oneRevolution
// Stepper->stepperRevFwdForever
//
// ---------------------------------------------------------------------------

#include <SPI.h>
#include <WiFi.h>

// Which motor type are we building this server for, servo motor or
// stepper motor.
//
//#define MOTOR_Servo 1
#define MOTOR_Stepper 1


#ifdef MOTOR_Servo
#include <Servo.h>
#endif

#ifdef MOTOR_Stepper
#include <Stepper.h>
#endif



// WiFi server to use:
//
//char ssid[] = "Vagri_G";  //  network SSID@home
//
// @Simmy Spot, my mobile phone hotspot, so should work at uni and
// at home, or anywhere really, password is the same as @home.
char ssid[] = "Simmy Spot";  // network SSID@Simmy Spot 
char pass[] = "jb-HDR85"; // WPA network password, same for @home & @Simmy Spot

int keyIndex = 0; // your network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;
WiFiServer server(23); // This server will be connected to port 23
boolean alreadyConnected = false; // whether or not the client was
				  // connected previously

#ifdef MOTOR_Servo
//
// We are building code for the servo motor:
//
Servo payloadServo;	     // using there servo control code

// Note: nested #ifdef's do not work:
//
// Set static IP address for the wifi shield, otherwise uses DHCP
//
//IPAddress ip(192,168,3,200);
IPAddress ip(192,168,43,200);
#endif


#ifdef MOTOR_Stepper
//
// We are building the code for the stepper motor:
//
// motor specific value, is the number of steps per revolution for your motor
const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11
Stepper payloadStepper(stepsPerRevolution, 8,9,10,11);            

// Set static IP address for the wifi shield, otherwise uses DHCP
//IPAddress ip(192,168,3,201);
IPAddress ip(192,168,43,201);
#endif


// Arduino doesn't seem to be able to cope with reading any type other than
// a char, eg unsigned int.
char dirRotation; // Direction of rotations
char numRotation; // Number of rotations required
unsigned int i; // loop increment



void setup(){

  //
  // setup() function executes only once
  //

  // Initialize serial port and wait for port to open. 
  //
  // Remove this line to stop output to serial port, yet still proper
  // program operation.
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  // Check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    while(true); // don't continue
  } 
  

  // Attempt to connect to Wifi network:
  while(status != WL_CONNECTED){ 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network.
    //
    // Configures wifi shield with a static ip address, otherwise uses DHCP
    WiFi.config(ip);
    
    status = WiFi.begin(ssid, pass);

    delay(10000); // Wait 10 sec for connection
  }

  server.begin(); // Start the server, thus START LISTENING FOR CLIENTS.

  printWifiStatus(); // You're connected now, so print out the status.
  

// #ifdef MOTOR_Servo
//   payloadServo.attach(9);
// #endif
#ifdef MOTOR_Stepper
  // Set speed to 60rpm, code does not work
  // Set speed to 180rpm, code works
  // Minimum speed apprears to be 160rpm, for code to work
  // Goto 280 for hexo+ power
  payloadStepper.setSpeed(180);
#endif

} // end: setup()




void loop(){
  //
  // loop() function re-loops forever
  //

  // There is a bit of a  wait here before this loop starts executing.
  // Seems  to be  due to  the  WiFi header  and code  being added  to
  // program overall.

  // Wait for a new client:
  WiFiClient client = server.available();


  if (client.available() > 0){
    // There are bytes available to be read, from client.

    // Flush the buffer to clean out old crap???
    //client.flush();
    //delay(500);

    Serial.println("dbg: Client Available");

    dirRotation = client.read();
    Serial.print("dbg: First client byte read dirRotation = ");
    Serial.println(dirRotation - '0');

    delay(500); // millisecond delay, to make sure second byte arrived

    numRotation = client.read();
    Serial.print("dbg: Second client byte read numRotation = ");
    Serial.print(numRotation - '0');
    Serial.println(", not applicable to servo motor.");

  
    //Serial.println("dbg: motor control starts.");
    //delay(5000);

#ifdef MOTOR_Servo
  
    if( (dirRotation=='1') ){
      payloadServo.attach(9);
      Serial.println("dbg: winch down cmd.");
      payloadServo.write(0); // winch down
      // delay(5000); // wrks
      delay(10000);
      payloadServo.detach();  // stop winch down
      delay(500);
      //    payloadServo.write(90); // stop winching
      //    delay(500);
    }
    else if( (dirRotation=='0') ){
      payloadServo.attach(9);
      Serial.println("dbg: winch up cmd.");
      payloadServo.write(180); // winch up
      delay(10000);
      payloadServo.detach(); // stop winch up
      delay(500);
      //    payloadServo.write(90); // stop winching
      //    delay(500);
    }
    else{
      Serial.println("Invalid direction of rotation char sent from client, ");
      Serial.print("direction is: ");
      Serial.println(dirRotation - '0');
      delay(500);
    }
  
#endif


#ifdef MOTOR_Stepper

    if(numRotation>'0'){
      if( (dirRotation=='1') ){
	for(i='0'; i<numRotation; i++){
	  // step one revolution  in one direction
	  Serial.print("clockwise, revolution number ");
	  Serial.println((i+1)-'0');
	  payloadStepper.step(stepsPerRevolution);
	  delay(500);
	}
      }
      else if(dirRotation=='0'){
	for(i='0'; i<numRotation; i++){ 
	  // step one revolution in the other direction
	  Serial.print("counterclockwise, revolution number ");
	  Serial.println((i+1)-'0');
	  payloadStepper.step(-stepsPerRevolution);
	  //delay(1000);
	  delay(500);
	}
      }
      else{
	Serial.print("Invalid char sent from client, ");
	Serial.print("direction is: ");
	Serial.print(dirRotation - '0');
	delay(500);
      }
    }
    else{
      Serial.print("Invalid char sent from client, ");
      Serial.print("number of rotations is: ");
      Serial.println(numRotation - '0');
      delay(500);
    } // end: if(numRotation>'0')

#endif


    //Serial.println("dbg: motor control ends.");
  
  } // end: if (client.available() > 0)
  

  // This loop() function executes/re-loops forever.
  //
  //Serial.print("end of loop() number ");
  //Serial.println(i);
  //i++;
  
  
  //Serial.println("sending handshake signal=99 to client.");
  //exit(0); kills the loop badly
  // break statement not within loop or switch is the error message
  //break;
  //server.write(99); // end server, but client exits too early.
  //delay(10000);

} // end: loop()
	


void printWifiStatus(){

// Which server have we built?
#ifdef MOTOR_Servo
  Serial.println("servoServer configured");
#else
  // MOTOR_stepper
  Serial.println("stepperServer configured");
#endif

  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  //server.write(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  
  // display wifi shield firmware version, version < 1.1 requres a
  // firmware update of wifi shield.
  Serial.print("Firmware Version(version < 1.1.0 requires firmware upgrade):");
  Serial.println(WiFi.firmwareVersion());
  
}

