#include "signin.h"
#include "ui_signin.h"

SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);

    QString path=QApplication::applicationDirPath();
    QFile file(path+"\\data.config");

    if (file.open(QIODevice::ReadOnly | QIODevice::Truncate))
    {
        QTextStream in(&file);
        QString buf;
        in>>buf;
        ui->edit_host->setText(buf);
        in>>buf;
        db_name=buf;
        in>>buf;
        ui->edit_user->setText(buf);
        in>>buf;
        ui->edit_password->setText(buf);
        file.close();
    }
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_ok_button_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(ui->edit_host->text());
    db.setDatabaseName(db_name);
    db.setUserName(ui->edit_user->text());
    db.setPassword(ui->edit_password->text());
    if (db.open())
    {
        qDebug()<<"OK Connect!";
        accept();
    }
    else
    {
        qDebug()<<"NO Connect!";
        QMessageBox::critical(this,"Подключение к БД",db.lastError().text());
    }
}

void SignIn::on_cancel_button_clicked()
{
    done(0);
}
