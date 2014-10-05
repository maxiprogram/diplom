#include "newprocessform.h"
#include "ui_newprocessform.h"

NewProcessForm::NewProcessForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProcessForm)
{
    ui->setupUi(this);

    connect(this,SIGNAL(SignalNewProcess(QByteArray)),parent,SLOT(NewProcess(QByteArray)));
}

NewProcessForm::~NewProcessForm()
{
    delete ui;
}

void NewProcessForm::on_pushButton_2_clicked()
{
    close();
}

void NewProcessForm::on_pushButton_clicked()
{
    emit SignalNewProcess(ui->lineEdit->text().toAscii());
    close();
}
