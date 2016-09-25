// Class dectaration(type) is placed in .h file.


#ifndef AMBULANCE_H
#define AMBULANCE_H


#include <QWidget>


#define MAX_CHARS_MODEM_NAME 12


extern int sendSMS(char *modemDevName);
extern int xfer2as(char dirRotation, char numRotation, char *serverID);


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
  //void on_stepperNumRotations_cursorPositionChanged(int arg1, int arg2);
  void on_stepperNumRotations_editingFinished();

  void on_microAdjPushButton_clicked();

private:
  // only used by member functions
  Ui::ambulance *ui;

  char modemDevName[MAX_CHARS_MODEM_NAME]; // modem device name, for SMS's

  char serverID[15]; // arduinoServer IPaddress or Hostname
  char dirRotation; // motor rotation, clockwise='1' & counterclockwise='0'
  char numRotation; // number of motor rotations; not applicable to
                    // stepper motor

};

#endif // AMBULANCE_H
