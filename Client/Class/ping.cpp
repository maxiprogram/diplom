#include "ping.h"

bool Ping::PingHost(QString host)
{
#ifdef Q_WS_WIN
    QProcess proc_ping;
    proc_ping.start("ping -n 2 "+host);
    if (!proc_ping.waitForFinished())
        qDebug()<<"Error END";
    QByteArray buf=proc_ping.readAll();

    QList<QByteArray> list=buf.split(',');
    if (list.size()==1)
        return false;
    buf=list.at(1);
    buf.remove(0,12);
    //qDebug()<<"Replace buf="<<buf;
    if (buf.toInt()>0)
        return true;
    else
        return false;

#endif
    return false;
}

bool Ping::isOpenPort(QString host,int port)
{
    QTcpSocket sock;
    sock.connectToHost(host,port);
    if (sock.waitForConnected())
    {
        sock.close();
        return true;
    }
    else
        return false;
}
