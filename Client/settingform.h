#ifndef SETTINGFORM_H
#define SETTINGFORM_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class SettingForm;
}

class SettingForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingForm(QWidget *parent = 0);
    ~SettingForm();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::SettingForm *ui;
};

#endif // SETTINGFORM_H
