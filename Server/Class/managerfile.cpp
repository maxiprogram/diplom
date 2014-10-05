#include "managerfile.h"

QList<File>* ManagerFile::GetListRoot()
{
    list_file.clear();

    QFileInfoList list=QDir::drives();
    QList<QFileInfo>::iterator it;
    for (it=list.begin();it!=list.end();it++)
    {
        File tmp;
        tmp.name=tmp.path=(*it).filePath();
        tmp.type=0;
        tmp.size=(*it).size();
        list_file.append(tmp);
        qDebug()<<(*it).filePath();
    }
    return &list_file;
}

QList<File>* ManagerFile::GetListFile(QString path)
{
    list_file.clear();

    QDir dir(path);
    QFileInfoList list=dir.entryInfoList();

    QList<QFileInfo>::iterator it;
    for (it=list.begin();it!=list.end();it++)
    {
        File tmp;
        tmp.name=(*it).fileName();
        tmp.path=(*it).filePath();
        tmp.type=2;
        if ((*it).isDir())
            tmp.type=1;
        else
            if ((*it).isExecutable())
                tmp.type=3;
            else
                if ((*it).isFile())
                    tmp.type=2;
        tmp.size=(*it).size();
        list_file.append(tmp);
        qDebug()<<(*it).filePath()<<(*it).size();
    }
    qDebug()<<"Count file="<<list_file.size();

    return &list_file;
}
