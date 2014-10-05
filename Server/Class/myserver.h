#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include "defstruct.h"
#include "managerprocess.h"
#include "managerfile.h"
#include <QDebug>

class MyServer: public QTcpServer
{
public:
    MyServer();

private slots:
    void ReadCommand(int handle);

protected:
    void incomingConnection(int handle);
};

#endif // MYSERVER_H
