#include "messageform.h"
#include "ui_messageform.h"

MessageForm::MessageForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageForm)
{
    ui->setupUi(this);

    connect(this,SIGNAL(SignalSendMessage(QString,QString,int)),parent,SLOT(SendMessage(QString,QString,int)));
}

MessageForm::~MessageForm()
{
    delete ui;
}

void MessageForm::on_pushButton_2_clicked()
{
    close();
}

void MessageForm::on_pushButton_clicked()
{
    if (ui->lineName->text()=="" || ui->textEdit->toPlainText()=="")
        QMessageBox::information(this,"Отправка сообщения","Все поля должны быть заполнены");
    else
    {
        emit SignalSendMessage(ui->lineName->text(),ui->textEdit->toPlainText(),ui->comboBox->currentIndex());
        close();
    }
}
