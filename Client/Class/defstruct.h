#ifndef DEFSTRUCT_H
#define DEFSTRUCT_H

#include <QString>

const int CMD_GET_PROCESS=1; //������� �������� ������ ���������
const int CMD_NEW_PROCESS=2; //������� ��������� �������
const int CMD_KILL_PROCESS=3; //������� ��������� �������

const int CMD_MESSAGE=4; //������� ���������

const int CMD_GET_FILE=5; //������� �������� ������ ������

const int CMD_DOWNLOAD_FILE=6; //������� ������� ����

const int CMD_UPLOAD_FILE=7; //������� ������� ����

const int CMD_POWER=8; //������� ���������� ��

const int CMD_DELETE_FILE=9; //������� �������� �����

struct Comp
{
    QString name;
    QString inn;
    QString fio;
    QString host;
    QString ip;
    bool online;
    bool open_port;
};

struct Process
{
    int pid;
    QString name;
};

struct File
{
    QString name;
    QString path;
    int type; /* 0 - Root; 1 - Dir; 2 - File; 3 - Executable*/
    //DateModified
    long long size;
};

#endif // DEFSTRUCT_H
