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

}


void ambulance::on_modemDevNameComboBox_activated(const QString &arg1){

  string str; // standard c++ string
  const char *mdn; // temporary
  char modemDevName[12];

  fprintf(stderr, "modemDevNameComboBox_activated\n");

  str = arg1.toStdString();//QString member function, QString to std c++ string
  mdn = str.c_str();
  strcpy(modemDevName, mdn);
  fprintf(stderr, "QString pointer, &arg1=modemDevName %s\n", modemDevName);
  fprintf(stderr, "QString pointer, &arg1=mdn %s\n", mdn);

  //sendSMS(mdn);

}
