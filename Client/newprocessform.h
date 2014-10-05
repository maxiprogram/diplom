#ifndef NEWPROCESSFORM_H
#define NEWPROCESSFORM_H

#include <QDialog>

namespace Ui {
class NewProcessForm;
}

class NewProcessForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewProcessForm(QWidget *parent = 0);
    ~NewProcessForm();

signals:
    void SignalNewProcess(QByteArray name);
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::NewProcessForm *ui;
};

#endif // NEWPROCESSFORM_H
