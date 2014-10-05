#include "shutdownform.h"
#include "ui_shutdownform.h"

ShutDownForm::ShutDownForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShutDownForm)
{
    ui->setupUi(this);

    connect(this,SIGNAL(SignalPowerPC(int)),parent,SLOT(PowerPC(int)));
}

ShutDownForm::~ShutDownForm()
{
    delete ui;
}

void ShutDownForm::on_pushButton_2_clicked()
{
    close();
}

void ShutDownForm::on_pushButton_clicked()
{
    if (ui->radioPower->isChecked())
        emit SignalPowerPC(0);
    if (ui->radioReset->isChecked())
        emit SignalPowerPC(1);
    if (ui->radioLogout->isChecked())
        emit SignalPowerPC(2);
    close();
}
