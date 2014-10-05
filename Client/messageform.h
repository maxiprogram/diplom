#ifndef MESSAGEFORM_H
#define MESSAGEFORM_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class MessageForm;
}

class MessageForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit MessageForm(QWidget *parent = 0);
    ~MessageForm();

signals:
    void SignalSendMessage(QString title,QString text,int type);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MessageForm *ui;
};

#endif // MESSAGEFORM_H
