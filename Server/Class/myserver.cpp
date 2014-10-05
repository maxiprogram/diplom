#include "myserver.h"

MyServer::MyServer()
{
}

void MyServer::incomingConnection(int handle)
{
    qDebug()<<"New client";
    ReadCommand(handle);
}

void MyServer::ReadCommand(int handle)
{
    QTcpSocket client;
    client.setSocketDescriptor(handle);
    client.waitForReadyRead();

    //QDataStream data_client(client);
    int cmd;
    //data_client>>cmd;
    client.read((char*)&cmd,sizeof(cmd));

    switch (cmd)
    {

//Отправка списка процессов
/*G_P:*/case CMD_GET_PROCESS:
        {
            qDebug()<<"SEND MESSAGE 'CMD_GET_PROCESS' for CLIENT";
            ManagerProcess manager_process;
            QList<Process>* list=manager_process.GetListProcess();

            QByteArray buf;
            QDataStream data(&buf,QIODevice::WriteOnly);
            data<<CMD_GET_PROCESS;
            data<<list->size();
            for (int i=0;i<list->size();i++)
            {
                data<<list->value(i).pid<<list->value(i).name;
                //qDebug()<<"PID="<<list->value(i).pid<<"Name="<<list->value(i).name;
            }
            qDebug()<<"Size:"<<buf.size()<<"Count:"<<list->size();
            client.write(buf);
            client.waitForBytesWritten();
            break;
        }

//Завершить процесс
        case CMD_KILL_PROCESS:
        {
            qDebug()<<"SEND MESSAGE 'CMD_KILL_PROCESS' for CLIENT";
            int pid;
            //data_client>>pid;
            client.read((char*)&pid,sizeof(pid));
            qDebug()<<"PID="<<pid;

            ManagerProcess manager_process;
            QString message=manager_process.KillProcess(pid);
            qDebug()<<"Message: "<<message;

//            QByteArray buf;
//            QDataStream data(&buf,QIODevice::WriteOnly);
//            data<<CMD_MESSAGE;
//            int b=1;
//            data<<b;
//            //data<<message;
//            client.write(buf);
//            client.waitForBytesWritten();

            //goto G_P;
            break;
        }

//Запустить процесс
        case CMD_NEW_PROCESS:
        {
            qDebug()<<"SEND MESSAGE 'CMD_NEW_PROCESS' for CLIENT";
            QString name_process;
            name_process=client.readLine();
            qDebug()<<"Name process:"<<name_process;

            ManagerProcess manager_process;
            QString message=manager_process.NewProcess(name_process);
            qDebug()<<"Message:"<<message;

//            QByteArray buf;
//            QDataStream data(&buf,QIODevice::WriteOnly);
//            data<<CMD_MESSAGE;
//            int b=1;
//            data<<b;
//            //data<<message;
//            client.write(buf);
//            client.waitForBytesWritten();

            //goto G_P;
            break;
        }

//Отправка списка файлов
        case CMD_GET_FILE:
        {
            qDebug()<<"SEND MESSAGE 'CMD_GET_FILE' for CLIENT";
            QString path;
            path=client.readLine();
            qDebug()<<"Name process:"<<path;

            ManagerFile manager_file;
            QList<File>* list;
            if (path=="/")
                list=manager_file.GetListRoot();
            else
                list=manager_file.GetListFile(path);

            QByteArray buf;
            QDataStream data(&buf,QIODevice::WriteOnly);
            data<<CMD_GET_FILE;
            data<<list->size();
            for (int i=0;i<list->size();i++)
            {
                data<<list->value(i).name<<list->value(i).path<<list->value(i).size<<list->value(i).type;
                //qDebug()<<"PID="<<list->value(i).pid<<"Name="<<list->value(i).name;
            }
            qDebug()<<"Size:"<<buf.size()<<"Count:"<<list->size();
            client.write(buf);
            client.waitForBytesWritten();

            break;
        }

//Отправка файла
        case CMD_DOWNLOAD_FILE:
        {
            qDebug()<<"SEND MESSAGE 'CMD_DOWNLOAD_FILE' for CLIENT";

            QString path_file;
            QDataStream data_c(&client);
            data_c>>path_file;

            QFileInfo name_info(path_file);
            QString name=name_info.fileName();
            qint64 size_file=name_info.size();

            QFile file(path_file);
            if (file.open(QIODevice::ReadOnly))
            {
                qDebug()<<"SEND file "<<path_file;
                qDebug()<<"Name file "<<name;
                qDebug()<<"Size file "<<size_file;

                QByteArray buf_client;
                QDataStream data(&buf_client,QIODevice::WriteOnly);

                data<<CMD_DOWNLOAD_FILE;
                data<<name;
                data<<size_file;

                client.write(buf_client);
                client.waitForBytesWritten();

                qint64 s=0;
                while (!file.atEnd())
                {
                    QByteArray buf;
                    buf=file.readAll();
                    s+=buf.size();
                    client.write(buf);
                    client.waitForBytesWritten();
                    qDebug()<<"Current size="<<s;
                }
                file.close();
            }else
                qDebug()<<"Error Oper FIle!";

            break;
        }

//Приём файла
        case CMD_UPLOAD_FILE:
        {
            qDebug()<<"SEND MESSAGE 'CMD_UPLOAD_FILE' for CLIENT";

            QString path_file;

            QDataStream data_c(&client);
            data_c>>path_file;

            qint64 size_file;
            data_c>>size_file;

            qDebug()<<"File "<<path_file;
            qDebug()<<"Size "<<size_file;

            QFile file(path_file);
            if (file.open(QIODevice::WriteOnly))
            {
                qint64 current_size=0;
                while(current_size<size_file)
                {
                    //Sleep(30000);
                    QByteArray buf;
                    client.waitForReadyRead();
                    buf=client.readAll();
                    if ((buf.size()+current_size)>size_file)
                        current_size+=file.write(buf,(size_file-current_size));
                    else
                        current_size+=file.write(buf);
                    qDebug()<<"Current size="<<current_size;
                    qDebug()<<"All size="<<client.size();
                }
                file.close();
            }
            break;
        }

//Приём сообщения
        case CMD_MESSAGE:
        {
            qDebug()<<"SEND MESSAGE 'CMD_MESSAGE' for CLIENT";
            QDataStream data(&client);

            QString title;
            QString text;
            int type;
            data>>title;
            data>>text;
            data>>type;
            qDebug()<<"title="<<title<<"text="<<text<<"type="<<type;
            if (type==0)
                QMessageBox::information(0,title,text);
            if (type==1)
                QMessageBox::warning(0,title,text);
            if (type==2)
                QMessageBox::critical(0,title,text);
            break;
        }

//Приём команды выключения ПК
        case CMD_POWER:
        {
            qDebug()<<"SEND MESSAGE 'CMD_POWER' for CLIENT";
            ManagerProcess manager_process;
            int cmd;
            client.read((char*)&cmd,sizeof(cmd));
            qDebug()<<"cmd="<<cmd;

#ifdef Q_WS_WIN
            if (cmd==0)
                manager_process.NewProcess("shutdown -s");
            if (cmd==1)
                manager_process.NewProcess("shutdown -r");
            if (cmd==2)
                manager_process.NewProcess("shutdown -l");
#endif

            break;
        }

//Приём команды удалить файл
        case CMD_DELETE_FILE:
        {
            qDebug()<<"SEND MESSAGE 'CMD_DELETE_FILE' for CLIENT";
            QString path_file;
            path_file=client.readLine();
            qDebug()<<"Path="<<path_file;
            if (QFile(path_file).remove())
                qDebug()<<"Good delete file";
            else
                qDebug()<<"Bad delete file!";
            break;
        }

    }
    qDebug()<<"Kill client";
    client.close();
}
