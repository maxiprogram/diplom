#ifndef PING_H
#define PING_H

#include <QProcess>
#include <QTcpSocket>
#include <QDebug>

class Ping
{
public:
    bool PingHost(QString host);
    bool isOpenPort(QString host,int port=22079);
};

#endif // PING_H
