#include <QApplication>
#include <QTextCodec>
#include "mainform.h"
#include "signin.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);

    MainForm mainform;
    SignIn signin;

    if (signin.exec()==0)
        return 0;
    else
    {
        mainform.Initialize();
        mainform.PrintTable(Ui::Device);
        mainform.showMaximized();
    }

    return a.exec();
}
