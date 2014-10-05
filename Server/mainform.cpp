#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    tray=new QSystemTrayIcon(this);
    tray->setIcon(QIcon(":/ico/imac.png"));
    tray->setContextMenu(ui->menu);
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(ShowHide(QSystemTrayIcon::ActivationReason)));
    tray->show();

    myserver=new MyServer();
    on_pushButton_clicked();
}

MainForm::~MainForm()
{
    myserver->close();
    delete myserver;
    delete ui;
}


void MainForm::on_pushButton_clicked()
{
    myserver->listen(QHostAddress::Any,22079);
    if (myserver->isListening())
    {
        tray->showMessage("Информация","Сервер удачно запущен");
        ui->statusBar->showMessage("Сервер запущен");
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        tray->showMessage("Информация","Не удалось запустить сервер!",QSystemTrayIcon::Critical);
        ui->statusBar->showMessage("Не удалось запустить сервер!");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }
}

void MainForm::on_pushButton_2_clicked()
{
    myserver->close();
    tray->showMessage("Информация","Сервер удачно остановлен");
    ui->statusBar->showMessage("Сервер остановлен");
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void MainForm::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainForm::on_actionStart_triggered()
{
    on_pushButton_clicked();
}

void MainForm::on_actionStop_triggered()
{
    on_pushButton_2_clicked();
}

void MainForm::ShowHide(QSystemTrayIcon::ActivationReason reason)
{
    if (reason==QSystemTrayIcon::Trigger)
    {
        if (this->isVisible())
            hide();
        else
            show();
    }
}
