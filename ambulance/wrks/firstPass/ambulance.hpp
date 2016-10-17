// Class dectaration(type) is placed in .h file.


#ifndef AMBULANCE_H
#define AMBULANCE_H


#include <QWidget>


extern int sendSMS(char *modemDevName);


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


private:
  Ui::ambulance *ui;
};

#endif // AMBULANCE_H
