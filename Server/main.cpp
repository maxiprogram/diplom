#include <QApplication>
#include <QTextCodec>
#include "mainform.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);

    MainForm w;
    //w.show();
    
    return a.exec();
}
