#ifndef MANAGERPROCESS_H
#define MANAGERPROCESS_H

#include <QList>
#include <QProcess>
#include <Class/defstruct.h>
#include <QDebug>

#ifdef Q_WS_WIN
#include "windows.h"
#include "tlhelp32.h"
#endif

class ManagerProcess
{
public:
    QList<Process>* GetListProcess();
    QString NewProcess(QString name);
    QString KillProcess(int pid);

private:
    QList<Process> list_process;
};

#endif // MANAGERPROCESS_H
