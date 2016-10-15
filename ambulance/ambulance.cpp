// c++ based:
#include <iostream>

// c based:
#include <unistd.h>
#include <stdio.h>

// local:
#include "ambulance.hpp"
#include "ui_ambulance.h"



ambulance::ambulance(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ambulance){

  ui->setupUi(this);
  
  fprintf(stderr, "Hello Ambulance World!\n");


  // Initialises SMS variables.
  strcpy(modemDevName, "/dev/ttyUSB0"); // default modem device
  strcpy(phoneNum, "+61401858908"); // default SMS phone number(smagri)
  strcpy(msgTxt, "Payload has arrived.\r\n");//default payload arrival msg
  //              123451234512345123451 2 3, NULL is 23rd char

  ui->messageTextTextEdit->setText("Payload has arrived.\r\n");

  fprintf(stderr, "Default device to be opened is %s\n", modemDevName);
  fprintf(stderr, "Default phone number for SMS=%s\n", phoneNum);
  fprintf(stderr, "Default payload delivered message sent is=%s\n", msgTxt);

  fprintf(stderr, "Number of chars in message=%ld\n", sizeof(msgTxt));
  //
  for (int i=0; i<(MAX_msgTxt_CHARS+1); i++){
    if (msgTxt[i] == '.'){
      fprintf(stderr, "full stop is at index %d\n", (i+1));
    }
    else if (msgTxt[i] == '\r'){
      fprintf(stderr, "CR at index %d\n", (i+1));
    }
    else if (msgTxt[i] == '\n'){
      fprintf(stderr, "CR+LF, or newline at index %d\n", (i+1));
    }
    else if(msgTxt[i] == '\0'){
      msgTxtLength = i + 1;
      fprintf(stderr,"c str terminating null char at index %d\n", msgTxtLength);
      break;
    }
  }



  // Motor control related initialisations.
  dirRotation='1'; // clockwise rotation, winch down
  ui->winchDownRadioButton->setChecked(1);
 
  numRotation=3; // default number of rotations is 3
  ui->stepperNumRotations->setText("3");

  lastMotorSpecEdited = 1;


  // Attempt  to play  streamed video  from the  gopro hero4  black on
  // startup.  If this  fails you may need to  manually reinitiate the
  // process with the 'Restart Video Stream' pushbutton.
  playStreamedCameraVideo();

}


ambulance::~ambulance(){

  delete ui;
}



void ambulance::on_deliverPayloadPushButton_clicked(){

  fprintf(stderr, "deliverPayloadPushButton_clicked\n");

}



void ambulance::on_sendSMSPushButton_clicked(){

  fprintf(stderr, "sendSMSPushButton_clicked\n");

  
  sendSMS(modemDevName, phoneNum, msgTxt, msgTxtLength);

}



void ambulance::on_modemDevNameComboBox_activated(const QString &arg1){

  string str; // standard c++ string
  const char *mdn; // temporary

  fprintf(stderr, "modemDevNameComboBox_activated\n");

  str = arg1.toStdString(); // QString member function to c++ 'string'
  mdn = str.c_str();// c++ 'string' to pointer to char(ie char *)
  strcpy(modemDevName, mdn);
  fprintf(stderr, "QString pointer, &arg1=modemDevName %s\n", modemDevName);
  fprintf(stderr, "QString pointer, &arg1=mdn %s\n", mdn);

}


// void ambulance::on_stepperNumRotations_cursorPositionChanged(int arg1,
// 							     int arg2){

//  fprintf(stderr, "stepperNumRotations_cursorPositionChanged\n");

//  fprintf(stderr, "Current cursor  postn is in front of position arg2\n");
//  fprintf(stderr, "Gone from arg1 to arg2 position narg1=%d, arg2=%d\n",
// 	 arg1, arg2);
  
// }


// void ambulance::on_stepperNumRotations_editingFinished(){

// }

// void ambulance::on_servoDelaySec_editingFinished(){
  
// }



void ambulance::on_microAdjPushButton_clicked(){

  int retval; // return value from xferas() fn

  fprintf(stderr, "microAdjPushButton_clicked\n");
  
  fprintf(stderr, "  unsigned int numRotation=%u\n", numRotation);
  //fprintf(stderr, "  char numRotation=%c\n", numRotation);
  fprintf(stderr, "  dirRotation=%c\n", dirRotation);
  fprintf(stderr, "  lastMotorSpecEdited=%d\n", lastMotorSpecEdited);
  
  if (lastMotorSpecEdited == 1){
    // Stepper Motor control is required.
    //
    //strcpy(serverID, "192.168.43.201");
    strcpy(serverID, "138.25.61.101");
    fprintf(stderr, "  serverID=%s\n", serverID);
    //
    retval = xfer2as(dirRotation, numRotation, serverID);
    if (retval){
      fprintf(stderr, "Error returned from xfer2as()\n");
    }
    //sleep(2); // stepper needs shorter wait
    //sleep(6); // servo needs longer wait
    sleep(6); // servo needs longer wait
  }
  else if (lastMotorSpecEdited == 0){
    // Servo motor control is required.
    //
    //strcpy(serverID, "192.168.43.200")
    strcpy(serverID, "138.25.61.100");;
    fprintf(stderr, "  serverID=%s\n", serverID);
    numRotation = 0;
    dirRotation = '1';

    retval = xfer2as(dirRotation, numRotation, serverID);
    if (retval){
      fprintf(stderr, "Error returned from xfer2as()\n");
    }
    sleep(12);// wait for servo to stop before given next command, min=11sec
    //sleep(20);

    numRotation = 0;
    dirRotation = '0';
    fprintf(stderr, "Reverse Motor Direction, dirRotation=%c\n", dirRotation);

    retval = xfer2as(dirRotation, numRotation, serverID);
    if (retval){
      fprintf(stderr, "Error returned from xfer2as()\n");
    }
    sleep(12);// wait for servo to stop before given next command, min=11sec
    //sleep(6);

    // fprintf(stderr, "  unsigned int numRotation=%u\n", numRotation);
    // fprintf(stderr, "  char numRotation=%c\n", numRotation);
    // fprintf(stderr, "  dirRotation=%c\n", dirRotation);
    // fprintf(stderr, "  dirRotation=%d\n", dirRotation);
  } 

}


void ambulance::on_winchDownRadioButton_clicked(){

    if (ui->winchDownRadioButton->isChecked()){
        dirRotation = '1';
        fprintf(stderr, "winchDownRadioButton: dirRotation=%c\n", dirRotation);
    }
}


void ambulance::on_winchUpRadioButton_clicked(){

  if (ui->winchUpRadioButton->isChecked()){
    dirRotation = '0';
    fprintf(stderr, "winchUpRadioButton: dirRotation=%c\n", dirRotation);
  }

}

void ambulance::on_mobileNumLineEdit_editingFinished(){

  // Set new phone number for the SMS message.
  
  const char *phoneNumPtr; // temporary pointer for c string, includes
			   // null('\0') string delimiter


  phoneNumPtr = ui->mobileNumLineEdit->text().toStdString().c_str();
  strcpy(phoneNum, phoneNumPtr);
  fprintf(stderr, "New phone number for SMS=%s\n", phoneNum);

}

void ambulance::on_messageTextTextEdit_textChanged(){

  // New SMS message text has arrived.

  const char *msgTxtPtr; // temporary pointer for c string(=>NULL terminated)

  msgTxtPtr = ui->messageTextTextEdit->toPlainText().toStdString().c_str();

  strcpy(msgTxt, msgTxtPtr);

  for (int i=0; i<(MAX_msgTxt_CHARS+1); i++){
    if(msgTxt[i] == '\0'){
      msgTxt[i] = '\r';
      msgTxt[i+1] = '\n';
      msgTxt[i+2] = '\0';
      msgTxtLength = i + 3;
      fprintf(stderr,"msgTxtLength %d\n", msgTxtLength);
      break;
    }
  }

  fprintf(stderr, "New SMS message text is=%s\n", msgTxt);

}




void ambulance::on_servoDelaySec_returnPressed(){

  fprintf(stderr, "servoDelaySec_returnPressed\n");
  
  servoDelaySeconds = ui->servoDelaySec->text().toInt();
  
  lastMotorSpecEdited = 0;
 
  fprintf(stderr, " lastMotorSpecEdited=%d\n", lastMotorSpecEdited);
  fprintf(stderr, " servoDelaySeconds=%d\n", servoDelaySeconds);
  
}



void ambulance::on_stepperNumRotations_returnPressed(){
  
  // *_editingFinished is called on CR or moving the cursor outside
  // the box via the mouse or keyboard commands(eg tab).
  //
  fprintf(stderr, "stepperNumRotations_returnPressed\n");
  
  numRotation = ui->stepperNumRotations->text().toInt();
  
  lastMotorSpecEdited = 1;
  
  // if (numRotationInt > 127){
  //   // Improvements need to be made to the arduino server, if possible.
  //   fprintf(stderr, "Currently, stepper motor number of rotations > 127"
  // 	    " are invalid.\n");
  //   return;
  // }

  fprintf(stderr, " lastMotorSpecEdited=%d\n", lastMotorSpecEdited);
  fprintf(stderr, " unsigned int numRotation=%u\n", numRotation);

  // Only  works for numbers  that represent  characters in  the ascii
  // character set, otherwise you just get funny chars on the screen.
  //fprintf(stderr, "  char numRotation=%c\n", numRotation);

}



void ambulance::playStreamedCameraVideo(){

  // Play the GoPro Hero4 Black video stream.
  //
  // To  facilitate  this,  startup  the 'mplayer'  media  player,  an
  // external program that _must_ be installed on your system.

  fprintf(stderr, "playStreamedCameraVideo() called.\n");
  
  // Setup procedure for the stream.  
  // 
  // Detach  from this process,  acting like  a daemon  & has  its own
  // process.  Thus  this process persists after  this calling process
  // exits.
  QString progSS = "/bin/csh";
  QStringList argSS;
  argSS << "/lu1/smagri/uni/subj/proj30cp/proj/ambulance/startStreaming";
  QProcess *myProcSS = new QProcess(this);
  myProcSS->startDetached(progSS, argSS);

  fprintf(stderr, "Setup procedure for streaming done.\n");

  // Process does not persist after this calling process exits.
  QString program = "/usr/bin/mplayer";
  QStringList arguments;
  // wrks:
  arguments<<"-nosound"<<"-geometry"<<"532x340-16+65"<<"udp://:8554";
  // //
  // // wrks:
  // //arguments<<"-nosound"<<"-geometry"<<"532x340-16+65"<<
  // //  "/lu1/smagri/uni/subj/proj30cp/streamHero4black/stepperMotor1.mp4";
  //QProcess *myProcess = new QProcess(this);
  myProcess = new QProcess(this);
  myProcess->start(program, arguments);
  
  fprintf(stderr,"Stream will start soon...\n");
  fprintf(stderr,
	  "...if it doesn't start within 2min, press 'Restart Video'.\n");

  
  // Output stderr & stdout for myProcess(ie mplayer).
  connect(myProcess,SIGNAL(readyReadStandardError()),this,
	  SLOT(readyReadStandardError()));
  connect(myProcess,SIGNAL(readyReadStandardOutput()),this,
  	  SLOT(readyReadStandardOutput()));
  qDebug() << myProcess->readAllStandardError();
  qDebug() << myProcess->readAllStandardOutput();

}


void ambulance::readyReadStandardOutput(){
    qDebug() << myProcess->readAllStandardOutput();
}

void ambulance::readyReadStandardError(){
    qDebug() << myProcess->readAllStandardError();
}

void ambulance::on_deliverPayload2LPpushButton_clicked(){

  fprintf(stderr, "deliverPayload2LPpushButton_clicked\n");
}



void ambulance::on_restartVideoPushButton_clicked(){

  fprintf(stderr, "restartVideoPushButton_clicked()\n");

  playStreamedCameraVideo();

}
