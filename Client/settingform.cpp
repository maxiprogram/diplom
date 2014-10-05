#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingForm)
{
    ui->setupUi(this);

    QString path=QApplication::applicationDirPath();
    QFile file(path+"\\data.config");

    if (file.open(QIODevice::ReadOnly | QIODevice::Truncate))
    {
        QTextStream in(&file);
        QString buf;
        in>>buf;
        ui->EditHost->setText(buf);
        in>>buf;
        ui->EditDB->setText(buf);
        in>>buf;
        ui->EditLogin->setText(buf);
        in>>buf;
        ui->EditPassword->setText(buf);
        file.close();
    }

}

SettingForm::~SettingForm()
{
    delete ui;
}

void SettingForm::on_pushButton_2_clicked()
{
    close();
}

void SettingForm::on_pushButton_clicked()
{
    QString path=QApplication::applicationDirPath();
    QFile file(path+"\\data.config");

    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&file);
        out<<ui->EditHost->text()<<endl;
        out<<ui->EditDB->text()<<endl;
        out<<ui->EditLogin->text()<<endl;
        out<<ui->EditPassword->text()<<endl;

//        file.write(ui->EditHost->text().toAscii());
//        file.putChar('\r');
//        file.putChar('\n');
//        file.write(ui->EditDB->text().toAscii());
//        file.putChar('\r');
//        file.putChar('\n');
//        file.write(ui->EditLogin->text().toAscii());
//        file.putChar('\r');
//        file.putChar('\n');
//        file.write(ui->EditPassword->text().toAscii());
//        file.putChar('\r');
//        file.putChar('\n');
        file.close();
    }

    close();
}
