#ifndef SHUTDOWNFORM_H
#define SHUTDOWNFORM_H

#include <QDialog>

namespace Ui {
class ShutDownForm;
}

class ShutDownForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit ShutDownForm(QWidget *parent = 0);
    ~ShutDownForm();
    
signals:
    void SignalPowerPC(int cmd);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ShutDownForm *ui;
};

#endif // SHUTDOWNFORM_H
