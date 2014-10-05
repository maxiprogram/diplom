#-------------------------------------------------
#
# Project created by QtCreator 2014-04-24T13:26:37
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    Class/myserver.cpp \
    Class/managerprocess.cpp \
    Class/managerfile.cpp

HEADERS  += mainform.h \
    Class/myserver.h \
    Class/managerprocess.h \
    Class/managerfile.h \
    Class/defstruct.h

FORMS    += mainform.ui

RESOURCES += \
    resource.qrc
