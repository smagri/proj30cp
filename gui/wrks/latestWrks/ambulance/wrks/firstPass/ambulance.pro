#-------------------------------------------------
#
# Project created by QtCreator 2016-09-15T19:37:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ambulance
TEMPLATE = app


SOURCES += main.cpp\
        ambulance.cpp xfer2as.cpp sendSMS.cpp


HEADERS  += \
    ambulance.hpp

FORMS    += ambulance.ui

OTHER_FILES +=


LIBS += /lu1/smagri/uni/subj/proj30cp/proj/ambulance/sendSMS.o

#OBJECTS += sendSMS.o


