// This is the arduinoStepperServer, that is, the arduino stepper motor server.
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
#include <Stepper.h>


// WiFi server to use:
//
//char ssid[] = "Vagri_G";  //  network SSID@home
//
// @Simmy Spot, my mobile phone hotspot, so should work at uni and
// at home, or anywhere really, password is the same as @home.
//char ssid[] = "Simmy Spot";  // network SSID@Simmy Spot 
//char pass[] = "jb-HDR85";// WPA network password, same for @home & @Simmy Spot
char ssid[] = "magiclab"; // uts magiclab
char pass[] = "mRpr342kz";// uts magiclab

int keyIndex = 0; // your network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;
WiFiServer server(23); // This server will be connected to port 23
boolean alreadyConnected = false; // whether or not the client was
				  // connected previously

// motor specific value, is the number of steps per revolution for your motor
const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11
Stepper payloadStepper(stepsPerRevolution, 8,9,10,11);            

// Set static IP address for the wifi shield, otherwise uses DHCP
//IPAddress ip(192,168,3,201); // @home
//IPAddress ip(192,168,43,201); // @mobile hotspot
IPAddress ip(138,25,61,101); // 


// Arduino doesn't seem to be able to cope with reading any type other than
// a char, eg unsigned int.
unsigned char dirRotation; // direction of rotations, clockwise or anticlockwise

// uint32_t
unsigned char numRotationByte[4]; // each byte, comming from client,
				  // that makes up numRotation
//unsigned long int numRotation; // number of rotations required
unsigned long int numRotation; // number of rotations required

int numCharsAvailable; // number of characters ready for reading
unsigned int i; // loop increment
unsigned long int tmpInt;

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
  
  // Set speed to 60rpm, code does not work
  // Set speed to 180rpm, code works
  // Minimum speed apprears to be 160rpm, for code to work
  // Goto 280 for hexo+ power
  //
  // best 9V battery:
  // payloadStepper.setSpeed(240);
  //
  // ok on hexo battery
  // payloadStepper.setSpeed(260);
  //
  payloadStepper.setSpeed(240);

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



  if ( (numCharsAvailable = client.available()) > 0){
    // There are bytes available to be read, from client.

    // Flush the buffer to clean out old crap???
    //client.flush();
    //delay(500);

    Serial.print("dbg: Client has bytes available, number of bytes = ");
    Serial.println(numCharsAvailable);

    dirRotation = client.read();
    Serial.print("dbg: First client byte read dirRotation = ");
    Serial.println(dirRotation);

    delay(500); // millisecond delay, to make sure second byte arrived

    for (i=0; i<4; i++){
      numRotationByte[i] = client.read();
      Serial.print("dbg: client byte read numRotationByte = ");
      Serial.println(numRotationByte[i]);
      delay(500);
    }


    // Again this is  done in the most portable  method, were there is
    // no need to worry about the  size(number of bytes) of an int and
    // endianness, BTW arduino  is little endian(MSB<-LSB), like intel
    // machines.
    //
    tmpInt=numRotationByte[0]; numRotation = (tmpInt << 0);
    tmpInt=numRotationByte[1]; numRotation = (numRotation | (tmpInt << 8));
    tmpInt=numRotationByte[2]; numRotation = (numRotation | (tmpInt << 16));
    tmpInt=numRotationByte[3]; numRotation = (numRotation | (tmpInt << 24));

    Serial.print("dbg: unsigned int numRotation=");
    Serial.println(numRotation);
    Serial.print("dbg: unsigned int bytes=");
    Serial.println(sizeof(unsigned int));
    Serial.print("dbg: unsigned long int bytes=");
    Serial.println(sizeof(unsigned long int));
    

    if ( (numRotation <= 0) || (numRotation > 0x00FFFFFF ) ){
      Serial.print("Invalid number of rotations requested: ");
      Serial.println(numRotation);
      // Howto exit/not execute code after this if block.
      // break;
      // or perhaps use goto LABEL:
      // or just a simple return; here, returns to top of loop i think
      // exit(0); // zero is required to prevent compile error
      return;
    }
    
    Serial.print("dbg: numCharsAvailable=");
    Serial.println(numCharsAvailable);
    
    
    if( (dirRotation=='1') ){
      for(i=0; i<numRotation; i++){
	// step one revolution  in one direction
	Serial.print("clockwise, revolution number ");
	Serial.println(i+1);
	payloadStepper.step(stepsPerRevolution);
	delay(500);
      }
    }
    else if(dirRotation=='0'){
      for(i=0; i<numRotation; i++){ 
	// step one revolution in the other direction
	Serial.print("counterclockwise, revolution number ");
	Serial.println(i+1);
	payloadStepper.step(-stepsPerRevolution);
	delay(500);
      }
    }
    else{
      Serial.print("Invalid char sent from client, ");
      Serial.print("rotation direction is: ");
      Serial.print(dirRotation - '0');
      delay(500);
      return;
    }

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


  Serial.println("arduinoStepperServer configured");

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

