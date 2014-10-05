#ifndef TESTONLINE_H
#define TESTONLINE_H

#include <QThread>
#include <QtSql>
#include <QList>
#include <Class/defstruct.h>
#include <Class/ping.h>

class TestOnline: public QThread
{
public:
    void run();
    QList<Comp>* GetList();

private:
    QList<Comp> list_comp;
    Ping test_ping;
};

#endif // TESTONLINE_H
