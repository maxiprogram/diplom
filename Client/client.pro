#-------------------------------------------------
#
# Project created by QtCreator 2014-03-13T09:36:59
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    signin.cpp \
    Class/ping.cpp \
    Class/testonline.cpp \
    newprocessform.cpp \
    settingform.cpp \
    shutdownform.cpp \
    messageform.cpp \
    aboutform.cpp

HEADERS  += mainform.h \
    signin.h \
    Class/ping.h \
    Class/defstruct.h \
    Class/testonline.h \
    newprocessform.h \
    settingform.h \
    shutdownform.h \
    messageform.h \
    aboutform.h

FORMS    += mainform.ui \
    signin.ui \
    newprocessform.ui \
    settingform.ui \
    shutdownform.ui \
    messageform.ui \
    aboutform.ui

RESOURCES += \
    resource.qrc
