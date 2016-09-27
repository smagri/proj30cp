// Class dectaration(type) is placed in .h file.


#ifndef AMBULANCE_H
#define AMBULANCE_H


#include <QWidget>


#define MAX_modemDevName_CHARS 12
#define MAX_phoneNum_CHARS 12
#define MAX_msgTxt_CHARS 160


extern int sendSMS(char *modemDevName, char *phoneNum,
		   char *msgTxt, int msgTxtLength);
extern int xfer2as(char dirRotation, unsigned int numRotation, char *serverID);


using namespace std;

namespace Ui{
  class ambulance;
}


class ambulance : public QWidget{
  
  Q_OBJECT
  
public:
  explicit ambulance(QWidget *parent = 0);
  ~ambulance();
  //nowrks: extern int sendSMS(char *modemDevName);

private slots:
  void on_deliverPayloadPushButton_clicked();

  void on_sendSMSPushButton_clicked();

  void on_modemDevNameComboBox_activated(const QString &arg1);

  void on_stepperNumRotations_editingFinished();

  void on_microAdjPushButton_clicked();

  void on_winchDownRadioButton_clicked();

  void on_winchUpRadioButton_clicked();

  void on_mobileNumLineEdit_editingFinished();

  void on_messageTextTextEdit_textChanged();

private:
  // only used by member functions
  Ui::ambulance *ui;

  char modemDevName[MAX_modemDevName_CHARS+1];// modem device name for SMS's

  char phoneNum[MAX_phoneNum_CHARS+1];// phone number for SMS

  char msgTxt[MAX_msgTxt_CHARS+1];
  int msgTxtLength;  // location of terminating NULL in msgTxt

  char serverID[15]; // arduinoServer IPaddress or Hostname
  unsigned char dirRotation; // motor rotation, clockwise='1' &
			     // counterclockwise='0'
  unsigned int numRotation; // number of motor rotations; not
			    // applicable to stepper motor
};

#endif // AMBULANCE_H
