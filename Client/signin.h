#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT
    
public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();
    
private slots:
    void on_ok_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::SignIn *ui;
    QString db_name;
};

#endif // SIGNIN_H
