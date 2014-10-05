#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QtSql>
#include <newprocessform.h>
#include <settingform.h>
#include <shutdownform.h>
#include <messageform.h>
#include <aboutform.h>
#include <Class/testonline.h>
#include <QDebug>

namespace Ui {
class MainForm;
enum TableName {Subdivision,Specialty,Persona,TypeDevice,Device};
enum AdminName {Online,File,Process};
}

class MainForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
    void Initialize();
    void PrintTable(Ui::TableName table);
    void PrintAdmin(Ui::AdminName admin);
    void PrintProcess(QList<Process>* list_process);
    void PrintFile(QList<File>* list_file);

    bool eventFilter(QObject *target, QEvent *event);

private slots:

    void StartRefreshOnline();

    void EndRefreshOnline();

    void OnRead();

    void NewProcess(QByteArray name);

    void PowerPC(int cmd);

    void SendMessage(QString title,QString text,int type);

    void on_tabWidget_2_currentChanged(int index);

    void on_tabWidget_currentChanged(int index);

    void on_actionAdd_triggered();

    void on_actionDelete_triggered();

    void on_actionSave_triggered();

    void on_actionDeleteall_triggered();

    void on_actionCopy_triggered();

    void on_actionExit_triggered();

    void on_actionImport_triggered();

    void on_actionExport_triggered();

    void on_table_device_clicked(const QModelIndex &index);

    void on_tabWidget_3_currentChanged(int index);

    void on_actionRefresh_triggered();

    void on_tabWidget_4_currentChanged(int index);

    void on_table_process_doubleClicked(const QModelIndex &index);

    void on_actionNewProcess_triggered();

    void on_actionKillProcess_triggered();

    void on_actionRefreshProcess_triggered();

    void on_table_file_doubleClicked(const QModelIndex &index);

    void on_current_path_returnPressed();

    void on_actionRoot_triggered();

    void on_actionDownload_triggered();

    void on_actionUpload_triggered();

    void on_actionSetting_triggered();

    void on_actionAddDop_clicked();

    void on_actionSaveDop_clicked();

    void on_actionDeleteDop_clicked();

    void on_actionDeleteAllDop_clicked();

    void on_actionCopyDop_clicked();

    void on_actionAddDop2_clicked();

    void on_actionSaveDop2_clicked();

    void on_actionDeleteDop2_clicked();

    void on_actionDeleteAllDop2_clicked();

    void on_actionCopyDop2_clicked();

    void on_actionPower_triggered();

    void on_actionMessage_triggered();

    void on_actionDeleteFile_triggered();

    void on_actionAddMenu_triggered();

    void on_actionCopyMenu_triggered();

    void on_actionDeleteMenu_triggered();

    void on_actionDeleteallMenu_triggered();

    void on_actionSaveMenu_triggered();

    void on_actionRefreshMenu_triggered();

    void on_actionMessageMenu_triggered();

    void on_actionPowerMenu_triggered();

    void on_actionRootMenu_triggered();

    void on_actionDownloadMenu_triggered();

    void on_actionUploadMenu_triggered();

    void on_actionDeleteFileMenu_triggered();

    void on_actionNewProcessMenu_triggered();

    void on_actionKillProcessMenu_triggered();

    void on_actionRefreshProcessMenu_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainForm *ui;
    NewProcessForm* new_process_from;
    SettingForm* setting_form;
    ShutDownForm* shutdown_form;
    MessageForm* message_form;
    AboutForm* about_form;
    TestOnline test_online;
    QTcpSocket* client;
    QSqlTableModel* model_subdivision;
    QSqlTableModel* model_specialty;
    QSqlRelationalTableModel* model_persona;
    QSqlTableModel* model_type_device;
    QSqlRelationalTableModel* model_device;
    QSqlTableModel* model_characteristic;
    QSqlTableModel* model_repair;

};

#endif // MAINFORM_H
