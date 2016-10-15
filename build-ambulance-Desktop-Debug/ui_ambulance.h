/********************************************************************************
** Form generated from reading UI file 'ambulance.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMBULANCE_H
#define UI_AMBULANCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ambulance
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *ambulanceGridLayout;
    QGroupBox *payloadDeliveryGroupBox;
    QGroupBox *motorControlGroupBox;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *servoDelaySec;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *stepperNumRotations;
    QPushButton *microAdjPushButton;
    QRadioButton *winchUpRadioButton;
    QRadioButton *winchDownRadioButton;
    QGroupBox *groupBox_2;
    QPushButton *deliverPayload2LPpushButton;
    QGroupBox *sendSMSGroupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *messageTextTextEdit;
    QPushButton *sendSMSPushButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *modemDevNameComboBox;
    QLineEdit *mobileNumLineEdit;
    QGroupBox *automatedControlGroupBox;
    QPushButton *deliverPayloadPushButton;
    QGroupBox *videoControlGroupBox;
    QPushButton *restartVideoPushButton;

    void setupUi(QWidget *ambulance)
    {
        if (ambulance->objectName().isEmpty())
            ambulance->setObjectName(QString::fromUtf8("ambulance"));
        ambulance->resize(798, 691);
        gridLayoutWidget = new QWidget(ambulance);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 761, 661));
        ambulanceGridLayout = new QGridLayout(gridLayoutWidget);
        ambulanceGridLayout->setSpacing(6);
        ambulanceGridLayout->setContentsMargins(11, 11, 11, 11);
        ambulanceGridLayout->setObjectName(QString::fromUtf8("ambulanceGridLayout"));
        ambulanceGridLayout->setContentsMargins(0, 0, 0, 0);
        payloadDeliveryGroupBox = new QGroupBox(gridLayoutWidget);
        payloadDeliveryGroupBox->setObjectName(QString::fromUtf8("payloadDeliveryGroupBox"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        payloadDeliveryGroupBox->setFont(font);
        payloadDeliveryGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"          border: 2px solid grey;\n"
"          border-radius: 5px;\n"
"          margin-top: 1ex;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
" 	subcontrol-origin: margin;\n"
"    subcontrol-position: top center; \n"
"    top: 0px; left: 5px; bottom: 0px;\n"
"	background-color: white;\n"
" }\n"
"\n"
"\n"
""));
        payloadDeliveryGroupBox->setAlignment(Qt::AlignCenter);
        motorControlGroupBox = new QGroupBox(payloadDeliveryGroupBox);
        motorControlGroupBox->setObjectName(QString::fromUtf8("motorControlGroupBox"));
        motorControlGroupBox->setGeometry(QRect(20, 190, 721, 221));
        motorControlGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"          border: 1px solid grey;\n"
"          border-radius: 5px;\n"
"          margin-top: 1ex;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"   	subcontrol-position: top left; /* position at top left */\n"
"   	top: 0px; left: 5px; bottom: 0px;\n"
"	background-color: white;\n"
" }"));
        groupBox = new QGroupBox(motorControlGroupBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 100, 701, 111));
        horizontalLayoutWidget_4 = new QWidget(groupBox);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 30, 471, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(250, 27));
        label_4->setMaximumSize(QSize(250, 27));

        horizontalLayout_4->addWidget(label_4);

        servoDelaySec = new QLineEdit(horizontalLayoutWidget_4);
        servoDelaySec->setObjectName(QString::fromUtf8("servoDelaySec"));
        servoDelaySec->setMinimumSize(QSize(200, 27));
        servoDelaySec->setMaximumSize(QSize(200, 27));
        servoDelaySec->setInputMethodHints(Qt::ImhDigitsOnly);
        servoDelaySec->setMaxLength(2);

        horizontalLayout_4->addWidget(servoDelaySec);

        horizontalLayoutWidget_5 = new QWidget(groupBox);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 70, 471, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(250, 27));
        label_5->setMaximumSize(QSize(250, 27));

        horizontalLayout_5->addWidget(label_5);

        stepperNumRotations = new QLineEdit(horizontalLayoutWidget_5);
        stepperNumRotations->setObjectName(QString::fromUtf8("stepperNumRotations"));
        stepperNumRotations->setMinimumSize(QSize(200, 27));
        stepperNumRotations->setMaximumSize(QSize(200, 27));
        stepperNumRotations->setInputMethodHints(Qt::ImhDigitsOnly);
        stepperNumRotations->setMaxLength(8);

        horizontalLayout_5->addWidget(stepperNumRotations);

        microAdjPushButton = new QPushButton(groupBox);
        microAdjPushButton->setObjectName(QString::fromUtf8("microAdjPushButton"));
        microAdjPushButton->setGeometry(QRect(500, 70, 191, 31));
        winchUpRadioButton = new QRadioButton(groupBox);
        winchUpRadioButton->setObjectName(QString::fromUtf8("winchUpRadioButton"));
        winchUpRadioButton->setGeometry(QRect(530, 40, 117, 22));
        winchDownRadioButton = new QRadioButton(groupBox);
        winchDownRadioButton->setObjectName(QString::fromUtf8("winchDownRadioButton"));
        winchDownRadioButton->setGeometry(QRect(530, 10, 117, 22));
        groupBox_2 = new QGroupBox(motorControlGroupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 701, 71));
        deliverPayload2LPpushButton = new QPushButton(groupBox_2);
        deliverPayload2LPpushButton->setObjectName(QString::fromUtf8("deliverPayload2LPpushButton"));
        deliverPayload2LPpushButton->setGeometry(QRect(230, 20, 241, 31));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        deliverPayload2LPpushButton->setFont(font1);
        deliverPayload2LPpushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #000080, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        deliverPayload2LPpushButton->setAutoDefault(false);
        sendSMSGroupBox = new QGroupBox(payloadDeliveryGroupBox);
        sendSMSGroupBox->setObjectName(QString::fromUtf8("sendSMSGroupBox"));
        sendSMSGroupBox->setGeometry(QRect(20, 420, 721, 221));
        sendSMSGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"          border: 1px solid grey;\n"
"          border-radius: 5px;\n"
"          margin-top: 1ex;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* position at top left */\n"
"    top: 0px; left: 5px; bottom: 0px;\n"
"	background-color: white;\n"
" }\n"
""));
        horizontalLayoutWidget = new QWidget(sendSMSGroupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 681, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 27));
        label_3->setMaximumSize(QSize(16777215, 27));
        label_3->setIndent(-1);

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 27));
        label_2->setMaximumSize(QSize(16777215, 27));

        horizontalLayout->addWidget(label_2);

        horizontalLayoutWidget_2 = new QWidget(sendSMSGroupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 120, 681, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 27));
        label->setMaximumSize(QSize(16777215, 27));

        horizontalLayout_2->addWidget(label);

        messageTextTextEdit = new QTextEdit(horizontalLayoutWidget_2);
        messageTextTextEdit->setObjectName(QString::fromUtf8("messageTextTextEdit"));
        messageTextTextEdit->setMinimumSize(QSize(0, 27));
        messageTextTextEdit->setMaximumSize(QSize(16777215, 27));
        messageTextTextEdit->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_2->addWidget(messageTextTextEdit);

        sendSMSPushButton = new QPushButton(sendSMSGroupBox);
        sendSMSPushButton->setObjectName(QString::fromUtf8("sendSMSPushButton"));
        sendSMSPushButton->setGeometry(QRect(310, 166, 99, 41));
        horizontalLayoutWidget_3 = new QWidget(sendSMSGroupBox);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 70, 681, 29));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        modemDevNameComboBox = new QComboBox(horizontalLayoutWidget_3);
        modemDevNameComboBox->setObjectName(QString::fromUtf8("modemDevNameComboBox"));

        horizontalLayout_3->addWidget(modemDevNameComboBox);

        mobileNumLineEdit = new QLineEdit(horizontalLayoutWidget_3);
        mobileNumLineEdit->setObjectName(QString::fromUtf8("mobileNumLineEdit"));
        mobileNumLineEdit->setMinimumSize(QSize(340, 27));
        mobileNumLineEdit->setMaximumSize(QSize(340, 27));
        mobileNumLineEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly|Qt::ImhPreferNumbers);
        mobileNumLineEdit->setMaxLength(12);

        horizontalLayout_3->addWidget(mobileNumLineEdit);

        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        sendSMSPushButton->raise();
        horizontalLayoutWidget_3->raise();
        automatedControlGroupBox = new QGroupBox(payloadDeliveryGroupBox);
        automatedControlGroupBox->setObjectName(QString::fromUtf8("automatedControlGroupBox"));
        automatedControlGroupBox->setGeometry(QRect(20, 30, 721, 71));
        deliverPayloadPushButton = new QPushButton(automatedControlGroupBox);
        deliverPayloadPushButton->setObjectName(QString::fromUtf8("deliverPayloadPushButton"));
        deliverPayloadPushButton->setGeometry(QRect(80, 20, 561, 41));
        deliverPayloadPushButton->setFont(font1);
        deliverPayloadPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #800000, stop: 1 #dadbde);\n"
"	color: white;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        videoControlGroupBox = new QGroupBox(payloadDeliveryGroupBox);
        videoControlGroupBox->setObjectName(QString::fromUtf8("videoControlGroupBox"));
        videoControlGroupBox->setGeometry(QRect(20, 110, 721, 71));
        videoControlGroupBox->setAutoFillBackground(false);
        videoControlGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        restartVideoPushButton = new QPushButton(videoControlGroupBox);
        restartVideoPushButton->setObjectName(QString::fromUtf8("restartVideoPushButton"));
        restartVideoPushButton->setGeometry(QRect(190, 30, 341, 31));
        restartVideoPushButton->setFont(font1);
        restartVideoPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #000080, stop: 1 #dadbde);\n"
"	color:white;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));

        ambulanceGridLayout->addWidget(payloadDeliveryGroupBox, 0, 0, 1, 1);


        retranslateUi(ambulance);

        modemDevNameComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ambulance);
    } // setupUi

    void retranslateUi(QWidget *ambulance)
    {
        ambulance->setWindowTitle(QApplication::translate("ambulance", "ambulance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        payloadDeliveryGroupBox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        payloadDeliveryGroupBox->setTitle(QApplication::translate("ambulance", "Ambulance Drone Control and Monitoring", 0, QApplication::UnicodeUTF8));
        motorControlGroupBox->setTitle(QApplication::translate("ambulance", "Motor Control", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ambulance", "Manual Control", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ambulance", "Servo  Motor, Delay in Seconds", 0, QApplication::UnicodeUTF8));
        servoDelaySec->setText(QString());
        label_5->setText(QApplication::translate("ambulance", "Stepper Motor, Number of Rotations", 0, QApplication::UnicodeUTF8));
        stepperNumRotations->setText(QString());
        microAdjPushButton->setText(QApplication::translate("ambulance", "microAdjustment", 0, QApplication::UnicodeUTF8));
        winchUpRadioButton->setText(QApplication::translate("ambulance", "Winch Up", 0, QApplication::UnicodeUTF8));
        winchDownRadioButton->setText(QApplication::translate("ambulance", "Winch Down", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ambulance", "Automated Control", 0, QApplication::UnicodeUTF8));
        deliverPayload2LPpushButton->setText(QApplication::translate("ambulance", "Deliver Payload to Landing Pad", 0, QApplication::UnicodeUTF8));
        sendSMSGroupBox->setTitle(QApplication::translate("ambulance", "Send SMS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ambulance", "<html><head/><body><p align=\"center\">Modem Device Name</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ambulance", "<html><head/><body><p align=\"center\">Moblie Phone Number</p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ambulance", "Message Text", 0, QApplication::UnicodeUTF8));
        sendSMSPushButton->setText(QApplication::translate("ambulance", "Send SMS", 0, QApplication::UnicodeUTF8));
        modemDevNameComboBox->clear();
        modemDevNameComboBox->insertItems(0, QStringList()
         << QApplication::translate("ambulance", "/dev/ttyUSB0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ambulance", "/dev/ttyUSB1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ambulance", "/dev/ttyUSB2", 0, QApplication::UnicodeUTF8)
        );
        mobileNumLineEdit->setText(QApplication::translate("ambulance", "+61", 0, QApplication::UnicodeUTF8));
        automatedControlGroupBox->setTitle(QApplication::translate("ambulance", "Automated Control", 0, QApplication::UnicodeUTF8));
        deliverPayloadPushButton->setText(QApplication::translate("ambulance", "Deliver Payload", 0, QApplication::UnicodeUTF8));
        videoControlGroupBox->setTitle(QApplication::translate("ambulance", "Video Control", 0, QApplication::UnicodeUTF8));
        restartVideoPushButton->setText(QApplication::translate("ambulance", "Restart Video", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ambulance: public Ui_ambulance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMBULANCE_H
