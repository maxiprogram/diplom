#include "managerprocess.h"

QList<Process>* ManagerProcess::GetListProcess()
{
    list_process.clear();

#ifdef Q_WS_WIN
    HANDLE h=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    PROCESSENTRY32 proc;
    proc.dwSize=sizeof(proc);

    for (bool b=Process32First(h,&proc);b==true;b=Process32Next(h,&proc))
    {
        Process tmp;
        tmp.name=QString::fromWCharArray(proc.szExeFile);
        tmp.pid=proc.th32ProcessID;
        list_process.append(tmp);
        //qDebug()<<tmp.name<<tmp.pid;
    }

    //qDebug()<<"Count Process="<<list_process.size();

    CloseHandle(h);
#endif

    return &list_process;
}

QString ManagerProcess::NewProcess(QString name)
{
    QProcess* proc_new=new QProcess();
    proc_new->start(name);

    QString message;
    if (proc_new->state()==QProcess::NotRunning)
        message="Не удалось запустить процесс";
    else
        message="Процесс удачно запущен";

    return message;
}

QString ManagerProcess::KillProcess(int pid)
{
    QProcess proc_kill;
#ifdef Q_WS_WIN
    proc_kill.start("taskkill /pid "+QString::number(pid)+" /f");
#endif
    QString message;
    if (!proc_kill.waitForFinished())
        message="Не удалось завершить процесс!";
    else
        message="Процесс удачно завершён";

    //message=proc_kill.readAll();

    return message;
}
