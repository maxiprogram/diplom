#ifndef MANAGERFILE_H
#define MANAGERFILE_H

#include <QDir>
#include <Class/defstruct.h>
#include <QDebug>

class ManagerFile
{
public:
    QList<File>* GetListFile(QString path);
    QList<File>* GetListRoot();
private:
    QList<File> list_file;
};

#endif // MANAGERFILE_H
