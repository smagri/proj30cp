// c++ based:
#include <iostream>

// c based:
#include <stdio.h>

// local:
#include "ambulance.hpp"
#include "ui_ambulance.h"


//extern int sendSMS(char *modemDevName);



ambulance::ambulance(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ambulance){

  ui->setupUi(this);


  fprintf(stderr, "Hello Ambulance World!\n");
}


ambulance::~ambulance(){

  delete ui;
}


void ambulance::on_deliverPayloadPushButton_clicked(){

  fprintf(stderr, "deliverPayloadPushButton_clicked\n");

}


void ambulance::on_sendSMSPushButton_clicked(){

  fprintf(stderr, "sendSMSPushButton_clicked\n");

  sendSMS(modemDevName);

}


void ambulance::on_modemDevNameComboBox_activated(const QString &arg1){

  string str; // standard c++ string
  const char *mdn; // temporary
  //char modemDevName[12];

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


void ambulance::on_stepperNumRotations_editingFinished(){

  // *_editingFinished is called on CR or moving the cursor outside
  // the box via the mouse or keyboard commands(eg tab).
  //
  fprintf(stderr, "stepperNumRotations_editingFinished\n");

  numRotation = ((char) ui->stepperNumRotations->text().toInt());
  fprintf(stderr, "numRotation=%i\n", numRotation);
  dirRotation = '1'; // for debugging
  strcpy(serverID, "192.168.43.200");

}


void ambulance::on_microAdjPushButton_clicked(){

  //int retval; // return value from xferas() fn

  fprintf(stderr, "microAdjPushButton_clicked\n");

//  retval = xfer2as(dirRotation, numRotation, serverID);
//  retval = xfer2as(dirRotation, dirRotation, serverID);

  //fprintf(stderr, "microAdjPushButton_clicked: xfer2as retval=%d\n", retval);
}

