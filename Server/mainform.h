#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "Class/myserver.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionExit_triggered();

    void on_actionStart_triggered();

    void on_actionStop_triggered();

    void ShowHide(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainForm *ui;
    QSystemTrayIcon* tray;
    MyServer* myserver;
};

#endif // MAINFORM_H
