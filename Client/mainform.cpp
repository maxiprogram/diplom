#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    new_process_from=new NewProcessForm(this);
    setting_form=new SettingForm(this);
    shutdown_form=new ShutDownForm(this);
    message_form=new MessageForm(this);
    about_form=new AboutForm(this);

    connect(&test_online,SIGNAL(started()),this,SLOT(StartRefreshOnline()));
    connect(&test_online,SIGNAL(finished()),this,SLOT(EndRefreshOnline()));

    client=new QTcpSocket(this);
    connect(client,SIGNAL(readyRead()),this,SLOT(OnRead()));

    ui->menuBar->installEventFilter(this);

    ui->toolBar_admin->hide();
}

MainForm::~MainForm()
{
    QSqlDatabase::database().close();
    delete ui;
}

//Инициализация моделей для отображения данных из БД
void MainForm::Initialize()
{
    model_subdivision=new QSqlTableModel(this);
    model_subdivision->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_subdivision->setTable("subdivision");
    model_subdivision->setHeaderData(1,Qt::Horizontal,"Наименование");
    model_subdivision->setSort(1,Qt::AscendingOrder);
    ui->table_subdivision->setModel(model_subdivision);
    //ui->table_subdivision->connect(ui->table_subdivision->horizontalHeader(),SIGNAL(sectionClicked(int)),ui->table_subdivision,SLOT(sortByColumn(int)));
    ui->table_subdivision->hideColumn(0);

    model_specialty=new QSqlTableModel(this);
    model_specialty->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_specialty->setTable("specialty");
    model_specialty->setHeaderData(1,Qt::Horizontal,"Наименование");
    model_specialty->setSort(1,Qt::AscendingOrder);
    ui->table_specialty->setModel(model_specialty);
    //ui->table_specialty->connect(ui->table_specialty->horizontalHeader(),SIGNAL(sectionClicked(int)),ui->table_specialty,SLOT(sortByColumn(int)));
    ui->table_specialty->hideColumn(0);

    model_persona=new QSqlRelationalTableModel(this);
    model_persona->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_persona->setTable("persona");
    model_persona->setRelation(4,QSqlRelation("subdivision","id","name"));
    model_persona->setRelation(5,QSqlRelation("specialty","id","name"));
    model_persona->relationModel(4)->setSort(1,Qt::AscendingOrder);
    model_persona->relationModel(5)->setSort(1,Qt::AscendingOrder);
    model_persona->relationModel(4)->select();
    model_persona->relationModel(5)->select();
    model_persona->setHeaderData(1,Qt::Horizontal,"Логин");
    model_persona->setHeaderData(2,Qt::Horizontal,"Пароль");
    model_persona->setHeaderData(3,Qt::Horizontal,"ФИО");
    model_persona->setHeaderData(4,Qt::Horizontal,"Подразделение");
    model_persona->setHeaderData(5,Qt::Horizontal,"Специальность");
    model_persona->setHeaderData(6,Qt::Horizontal,"Телефон");
    model_persona->setHeaderData(7,Qt::Horizontal,"Эл.почта");
    model_persona->setSort(3,Qt::AscendingOrder);
    ui->table_persona->setModel(model_persona);
    ui->table_persona->setItemDelegate(new QSqlRelationalDelegate(ui->table_persona));
    //ui->table_persona->connect(ui->table_persona->horizontalHeader(),SIGNAL(sectionClicked(int)),ui->table_persona,SLOT(sortByColumn(int)));
    ui->table_persona->hideColumn(0);

    model_type_device=new QSqlTableModel(this);
    model_type_device->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_type_device->setTable("type_device");
    model_type_device->setHeaderData(1,Qt::Horizontal,"Наименование");
    model_type_device->setSort(1,Qt::AscendingOrder);
    ui->table_type_device->setModel(model_type_device);
    //ui->table_type_device->connect(ui->table_type_device->horizontalHeader(),SIGNAL(sectionClicked(int)),ui->table_type_device,SLOT(sortByColumn(int)));
    ui->table_type_device->hideColumn(0);

    model_device=new QSqlRelationalTableModel(this);
    model_device->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_device->setTable("device");
    model_device->setRelation(1,QSqlRelation("type_device","id","name"));
    model_device->setRelation(5,QSqlRelation("persona","id","fio"));
    model_device->relationModel(1)->setSort(1,Qt::AscendingOrder);
    model_device->relationModel(5)->setSort(3,Qt::AscendingOrder);
    model_device->relationModel(1)->select();
    model_device->relationModel(5)->select();
    model_device->setHeaderData(1,Qt::Horizontal,"Тип устройства");
    model_device->setHeaderData(2,Qt::Horizontal,"Наименование");
    model_device->setHeaderData(3,Qt::Horizontal,"Инв.номер");
    model_device->setHeaderData(4,Qt::Horizontal,"Сер.номер");
    model_device->setHeaderData(5,Qt::Horizontal,"ФИО");
    model_device->setHeaderData(6,Qt::Horizontal,"HOST-имя");
    model_device->setHeaderData(7,Qt::Horizontal,"IP-адрес");
    model_device->setSort(1,Qt::AscendingOrder);
    ui->table_device->setModel(model_device);
    ui->table_device->setItemDelegate(new QSqlRelationalDelegate(ui->table_device));
    //ui->table_device->connect(ui->table_device->horizontalHeader(),SIGNAL(sectionClicked(int)),ui->table_device,SLOT(sortByColumn(int)));
    ui->table_device->connect(ui->table_device->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(on_table_device_clicked(QModelIndex)));
    ui->table_device->hideColumn(0);

    model_characteristic=new QSqlTableModel(this);
    model_characteristic->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_characteristic->setTable("characteristic");
    model_characteristic->setHeaderData(1,Qt::Horizontal,"Наименование");
    model_characteristic->setHeaderData(2,Qt::Horizontal,"Значение");
    model_characteristic->setSort(1,Qt::AscendingOrder);
    ui->table_characteristic->setModel(model_characteristic);
    //ui->table_characteristic->connect(ui->table_characteristic->horizontalHeader(),SIGNAL(sectionClicked(int)),ui->table_characteristic,SLOT(sortByColumn(int)));
    ui->table_characteristic->hideColumn(0);
    ui->table_characteristic->hideColumn(3);

    model_repair=new QSqlTableModel(this);
    model_repair->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_repair->setTable("repair");
    model_repair->setHeaderData(1,Qt::Horizontal,"Дата");
    model_repair->setHeaderData(2,Qt::Horizontal,"Наименование");
    model_repair->setHeaderData(3,Qt::Horizontal,"Комментарий");
    model_repair->setSort(1,Qt::AscendingOrder);
    ui->table_repair->setModel(model_repair);
    //ui->table_repair->connect(ui->table_repair->horizontalHeader(),SIGNAL(sectionClicked(int)),ui->table_repair,SLOT(sortByColumn(int)));
    ui->table_repair->hideColumn(0);
    ui->table_repair->hideColumn(4);

    ui->statusBar->showMessage("Готово");
}

//Вывод данных из таблиц БД
void MainForm::PrintTable(Ui::TableName table)
{
    switch (table)
    {
        case Ui::Subdivision:
        {
            model_subdivision->select();
            ui->table_subdivision->resizeColumnsToContents();
            break;
        }
        case Ui::Specialty:
        {
            model_specialty->select();
            ui->table_specialty->resizeColumnsToContents();
            break;
        }
        case Ui::Persona:
        {
            model_persona->relationModel(4)->select();
            model_persona->relationModel(5)->select();
            model_persona->select();
            ui->table_persona->resizeColumnsToContents();
            break;
        }
        case Ui::TypeDevice:
        {
            model_type_device->select();
            ui->table_type_device->resizeColumnsToContents();
            break;
        }
        case Ui::Device:
        {
            model_device->relationModel(1)->select();
            model_device->relationModel(5)->select();
            model_device->select();
            ui->table_device->resizeColumnsToContents();
            break;
        }
    }
}

//Вывод данных кто в сети, для администрирования
void MainForm::PrintAdmin(Ui::AdminName admin)
{
    QList<Comp>* list_comp=test_online.GetList();
    switch (admin)
    {
        case Ui::Online:
        {
            ui->table_online->clear();
            ui->table_online->setColumnCount(7);
            QStringList header;
            header<<"Наименование"<<"Инв.номер"<<"ФИО"<<"HOST-имя"<<"IP-адрес"<<"Online"<<"Готов";
            ui->table_online->setHorizontalHeaderLabels(header);

            ui->table_online->setRowCount(list_comp->size());
            //ui->statusBar->showMessage("Количство записей: "+QString::number(list_comp->size()));
            for (int i=0;i<list_comp->size();i++)
            {
                ui->table_online->setItem(i,0,new QTableWidgetItem(list_comp->value(i).name));
                ui->table_online->setItem(i,1,new QTableWidgetItem(list_comp->value(i).inn));
                ui->table_online->setItem(i,2,new QTableWidgetItem(list_comp->value(i).fio));
                ui->table_online->setItem(i,3,new QTableWidgetItem(list_comp->value(i).host));
                ui->table_online->setItem(i,4,new QTableWidgetItem(list_comp->value(i).ip));
                if (list_comp->value(i).online)
                    ui->table_online->setItem(i,5,new QTableWidgetItem(QIcon(":/ico/ball_green.png"),"Да"));
                else
                    ui->table_online->setItem(i,5,new QTableWidgetItem(QIcon(":/ico/ball_red.png"),"Нет"));
                if (list_comp->value(i).open_port)
                    ui->table_online->setItem(i,6,new QTableWidgetItem(QIcon(":/ico/ball_green.png"),"Да"));
                else
                    ui->table_online->setItem(i,6,new QTableWidgetItem(QIcon(":/ico/ball_red.png"),"Нет"));
            }
            break;
        }
        case Ui::File:
        {
            ui->current_path->setText("");
            ui->current_path->setEnabled(false);
            ui->table_file->clear();
            ui->table_file->setColumnCount(5);
            QStringList header;
            header<<"Наименование"<<"Инв.номер"<<"ФИО"<<"HOST-имя"<<"IP-адрес";
            ui->table_file->setHorizontalHeaderLabels(header);

            int count=0;
            ui->table_file->setRowCount(list_comp->size());
            for (int i=0;i<list_comp->size();i++)
            {
                if (list_comp->value(i).online==true && list_comp->value(i).open_port==true)
                {
                    ui->table_file->setItem(count,0,new QTableWidgetItem(list_comp->value(i).name));
                    ui->table_file->setItem(count,1,new QTableWidgetItem(list_comp->value(i).inn));
                    ui->table_file->setItem(count,2,new QTableWidgetItem(list_comp->value(i).fio));
                    ui->table_file->setItem(count,3,new QTableWidgetItem(list_comp->value(i).host));
                    ui->table_file->setItem(count,4,new QTableWidgetItem(list_comp->value(i).ip));
                    count++;
                }
            }
            ui->table_file->setRowCount(count);
            break;
        }
        case Ui::Process:
        {
            ui->table_process->clear();
            ui->table_process->setColumnCount(5);
            QStringList header;
            header<<"Наименование"<<"Инв.номер"<<"ФИО"<<"HOST-имя"<<"IP-адрес";
            ui->table_process->setHorizontalHeaderLabels(header);

            int count=0;
            ui->table_process->setRowCount(list_comp->size());
            for (int i=0;i<list_comp->size();i++)
            {
                if (list_comp->value(i).online==true && list_comp->value(i).open_port==true)
                {
                    ui->table_process->setItem(count,0,new QTableWidgetItem(list_comp->value(i).name));
                    ui->table_process->setItem(count,1,new QTableWidgetItem(list_comp->value(i).inn));
                    ui->table_process->setItem(count,2,new QTableWidgetItem(list_comp->value(i).fio));
                    ui->table_process->setItem(count,3,new QTableWidgetItem(list_comp->value(i).host));
                    ui->table_process->setItem(count,4,new QTableWidgetItem(list_comp->value(i).ip));
                    count++;
                }
            }
            ui->table_process->setRowCount(count);
            //ui->statusBar->showMessage("Количество записей: "+QString::number(count));
            break;
        }
    }
}

//Вывод списка процессов, полученного от сервера
void MainForm::PrintProcess(QList<Process>* list_process)
{
    ui->table_process->setSortingEnabled(false);
    ui->table_process->clear();
    ui->table_process->setColumnCount(2);
    ui->table_process->setRowCount(list_process->size());
    QStringList header;
    header<<"Имя процесса"<<"PID";
    ui->table_process->setHorizontalHeaderLabels(header);

    for (int i=0;i<list_process->size();i++)
    {
        ui->table_process->setItem(i,0,new QTableWidgetItem(QIcon(":ico/application-blue.png"),list_process->value(i).name));
        ui->table_process->setItem(i,1,new QTableWidgetItem(QString::number(list_process->value(i).pid)));
    }
    ui->table_process->setSortingEnabled(true);
}

//Вывод списка файлов, полученного от сервера
void MainForm::PrintFile(QList<File>* list_file)
{
    ui->table_file->setSortingEnabled(false);
    ui->table_file->clear();
    ui->table_file->setColumnCount(4);
    ui->table_file->setRowCount(list_file->size());
    QStringList header;
    header<<"Имя"<<"Тип"<<"Размер"<<"Полный путь";
    ui->table_file->setHorizontalHeaderLabels(header);

    for (int i=0;i<list_file->size();i++)
    {
        if (list_file->value(i).type==0)
            ui->table_file->setItem(i,0,new QTableWidgetItem(QIcon(":ico/drive.png"),list_file->value(i).name));
        if (list_file->value(i).type==1)
            ui->table_file->setItem(i,0,new QTableWidgetItem(QIcon(":ico/folder-horizontal.png"),list_file->value(i).name));
        if (list_file->value(i).type==2)
            ui->table_file->setItem(i,0,new QTableWidgetItem(QIcon(":ico/file.png"),list_file->value(i).name));
        if (list_file->value(i).type==3)
            ui->table_file->setItem(i,0,new QTableWidgetItem(QIcon(":ico/application-blue.png"),list_file->value(i).name));
        ui->table_file->setItem(i,1,new QTableWidgetItem(QString::number(list_file->value(i).type)));
        if (list_file->value(i).size==0)
            ui->table_file->setItem(i,2,new QTableWidgetItem("-"));
        else
            ui->table_file->setItem(i,2,new QTableWidgetItem(QString::number(list_file->value(i).size)));
        ui->table_file->setItem(i,3,new QTableWidgetItem(list_file->value(i).path));
    }
    ui->table_file->setSortingEnabled(true);
}

//Отправить серверу команду создать новый процесс
void MainForm::NewProcess(QByteArray name)
{
    QString host=ui->statusBar->currentMessage();

    client->connectToHost(host,22079);
    if (client->waitForConnected())
    {
        client->write((char*)&CMD_NEW_PROCESS,sizeof(CMD_NEW_PROCESS));
        client->write(name);
        client->close();
    }else
        QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
}

//Отправка серверу Выключить ПК
void MainForm::PowerPC(int cmd)
{
    QString host=ui->statusBar->currentMessage();

    client->connectToHost(host,22079);
    if (client->waitForConnected())
    {
        client->write((char*)&CMD_POWER,sizeof(CMD_POWER));
        client->write((char*)&cmd,sizeof(cmd));
        client->close();
    }else
        QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
}

//Отправка сообщения серверу
void MainForm::SendMessage(QString title,QString text,int type)
{
    //QMessageBox::information(this,title,text+" type="+QString::number(type));
    QString host=ui->statusBar->currentMessage();
    QByteArray buf;
    QDataStream data(&buf,QIODevice::WriteOnly);
    data<<title;
    data<<text;
    data<<type;
    client->connectToHost(host,22079);
    if (client->waitForConnected())
    {
        client->write((char*)&CMD_MESSAGE,sizeof(CMD_MESSAGE));
        client->write(buf);
        client->close();
    }else
        QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
}

//При старте потока сканирования, кто в сети
void MainForm::StartRefreshOnline()
{
    ui->statusBar->showMessage("Подождите идёт сканирование...");
}

//При зашершении потока сканирования, кто в сети
void MainForm::EndRefreshOnline()
{
    on_tabWidget_4_currentChanged(ui->tabWidget_4->currentIndex());
    ui->statusBar->showMessage("Сканирование завершено");
}

//Чтение данных от сервера
void MainForm::OnRead()
{
    QDataStream data(client);
    client->waitForReadyRead();
    int cmd;
    data>>cmd;

    switch (cmd)
    {
//Приём файла
        case CMD_DOWNLOAD_FILE:
        {
            QString name;
            data>>name;
            //QMessageBox::information(this,"Имя файла",name);
            qint64 size_file;
            data>>size_file;
            qDebug()<<"Sizefile "<<size_file;
            QString path_file=QFileDialog::getSaveFileName(this,"Сохранить как",name);

            if (!path_file.isEmpty())
            {
                QFile file(path_file);
                file.open(QIODevice::WriteOnly);

                qint64 current_size=0;
                while(current_size<size_file)
                {
                    //Sleep(30000);
                    QByteArray buf;
                    client->waitForReadyRead();
                    buf=client->readAll();
                    if ((buf.size()+current_size)>size_file)
                        current_size+=file.write(buf,(size_file-current_size));
                    else
                        current_size+=file.write(buf);
                    qDebug()<<"Current size="<<current_size;
                }

                file.close();
                QMessageBox::information(this,"Скачка файла","Файл удачно скачен");
            }else
                QMessageBox::information(this,"Скачка файла","Скачка файла отменена!");

            client->close();
            break;
        }

//Приём сообщения от сервера
        case CMD_MESSAGE:
        {
            QString message;
            //data>>message;
            int b;
            data>>b;
            //ui->statusBar->showMessage(message);
            //qDebug()<<"CMD_MESSAGE:"<<message;
            qDebug()<<"Result CMD:"<<b;
            client->close();
            break;
        }

//Приём списка файлов
        case CMD_GET_FILE:
        {
            qDebug()<<"Command Get File! Size:"<<data.device()->size();
            int count;
            data>>count;
            QList<File> list;
            for (int i=0;i<count;i++)
            {
                File tmp;
                data>>tmp.name;
                data>>tmp.path;
                data>>tmp.size;
                data>>tmp.type;
                list.append(tmp);
                qDebug()<<"Name="<<list.value(i).name<<"Path="<<list.value(i).path<<"Size="<<list.value(i).size<<"Type="<<list.value(i).type;
            }
            PrintFile(&list);
            client->close();
            break;
        }

//Приём списка процессов
        case CMD_GET_PROCESS:
        {
            qDebug()<<"Command Get Process! Size:"<<data.device()->size();
            int count;
            data>>count;
            QList<Process> list;
            for (int i=0;i<count;i++)
            {
                Process tmp;
                data>>tmp.pid;
                data>>tmp.name;
                list.append(tmp);
                //qDebug()<<"PID="<<list.value(i).pid<<"Name="<<list.value(i).name;
            }
            PrintProcess(&list);
            client->close();
            break;
        }
    }

}

//Выбор вкладок на вкладке БД
void MainForm::on_tabWidget_2_currentChanged(int index)
{
    switch (index)
    {
        case 0:
        {
            PrintTable(Ui::Device);
            break;
        }
        case 1:
        {
            PrintTable(Ui::TypeDevice);
            break;
        }
        case 2:
        {
            PrintTable(Ui::Persona);
            break;
        }
        case 3:
        {
            PrintTable(Ui::Specialty);
            break;
        }
        case 4:
        {
            PrintTable(Ui::Subdivision);
            break;
        }
    }
}

//Выбор вкладки БД или Администрирование
void MainForm::on_tabWidget_currentChanged(int index)
{
    switch (index)
    {
        case 0:
        {
            ui->toolBar_db->show();
            ui->toolBar_admin->hide();
            ui->menu_3->setEnabled(true);
            ui->menu_4->setEnabled(false);
            break;
        }
        case 1:
        {
            ui->toolBar_db->hide();
            ui->toolBar_admin->show();
            ui->menu_3->setEnabled(false);
            ui->menu_4->setEnabled(true);
            break;
        }
    }
}

//При добавлении записи
void MainForm::on_actionAdd_triggered()
{
    switch (ui->tabWidget_2->currentIndex())
    {
        case 0:
        {
            model_device->insertRow(model_device->rowCount());
            break;
        }
        case 1:
        {
            model_type_device->insertRow(model_type_device->rowCount());
            break;
        }
        case 2:
        {
            model_persona->insertRow(model_persona->rowCount());
            break;
        }
        case 3:
        {
            model_specialty->insertRow(model_specialty->rowCount());
            break;
        }
        case 4:
        {
            model_subdivision->insertRow(model_subdivision->rowCount());
            break;
        }
    }
}

//При удалении записи
void MainForm::on_actionDelete_triggered()
{
    switch (ui->tabWidget_2->currentIndex())
    {
        case 0:
        {
            model_device->removeRow(ui->table_device->currentIndex().row());
            break;
        }
        case 1:
        {
            model_type_device->removeRow(ui->table_type_device->currentIndex().row());
            break;
        }
        case 2:
        {
            model_persona->removeRow(ui->table_persona->currentIndex().row());
            break;
        }
        case 3:
        {
            model_specialty->removeRow(ui->table_specialty->currentIndex().row());
            break;
        }
        case 4:
        {
            model_subdivision->removeRow(ui->table_subdivision->currentIndex().row());
            break;
        }
    }
}

//При сохренение измененных данных
void MainForm::on_actionSave_triggered()
{
    switch (ui->tabWidget_2->currentIndex())
    {
        case 0:
        {
            model_device->submitAll();
            break;
        }
        case 1:
        {
            model_type_device->submitAll();
            break;
        }
        case 2:
        {
            model_persona->submitAll();
            break;
        }
        case 3:
        {
            model_specialty->submitAll();
            break;
        }
        case 4:
        {
            model_subdivision->submitAll();
            break;
        }
    }
}

//При удалении всех записей
void MainForm::on_actionDeleteall_triggered()
{
    switch (ui->tabWidget_2->currentIndex())
    {
        case 0:
        {
            model_device->removeRows(0,model_device->rowCount());
            break;
        }
        case 1:
        {
            model_type_device->removeRows(0,model_type_device->rowCount());
            break;
        }
        case 2:
        {
            model_persona->removeRows(0,model_persona->rowCount());
            break;
        }
        case 3:
        {
            model_specialty->removeRows(0,model_specialty->rowCount());
            break;
        }
        case 4:
        {
            model_subdivision->removeRows(0,model_subdivision->rowCount());
            break;
        }
    }
}

//При копировании записи
void MainForm::on_actionCopy_triggered()
{
    switch (ui->tabWidget_2->currentIndex())
    {
        case 0:
        {
            QSqlRecord rec= model_device->record(ui->table_device->currentIndex().row());
            rec.setValue(0,"");
            model_device->insertRecord(model_device->rowCount(),rec);
            break;
        }
        case 1:
        {
            QSqlRecord rec= model_type_device->record(ui->table_type_device->currentIndex().row());
            rec.setValue(0,"");
            model_type_device->insertRecord(model_type_device->rowCount(),rec);
            break;
        }
        case 2:
        {
            QSqlRecord rec= model_persona->record(ui->table_persona->currentIndex().row());
            rec.setValue(0,"");
            model_persona->insertRecord(model_persona->rowCount(),rec);
            break;
        }
        case 3:
        {            
            QSqlRecord rec= model_specialty->record(ui->table_specialty->currentIndex().row());
            rec.setValue(0,"");
            model_specialty->insertRecord(model_specialty->rowCount(),rec);
            break;
        }
        case 4:
        {
            QSqlRecord rec= model_subdivision->record(ui->table_subdivision->currentIndex().row());
            rec.setValue(0,"");
            model_subdivision->insertRecord(model_subdivision->rowCount(),rec);
            break;
        }
    }
}

//Файл -> Выход
void MainForm::on_actionExit_triggered()
{
    close();
}

//Файл -> Импорт
void MainForm::on_actionImport_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this);

    if (!filename.isEmpty())
    {
        QString result;
        if (QSqlDatabase::database().password()!="")
            result="mysql -u"+QSqlDatabase::database().userName()+" -p"+QSqlDatabase::database().password()+" -h"+QSqlDatabase::database().hostName()+" "+QSqlDatabase::database().databaseName();
        else
            result="mysql -u"+QSqlDatabase::database().userName()+" -h"+QSqlDatabase::database().hostName()+" "+QSqlDatabase::database().databaseName();
        qDebug()<<"String Import: "<<result;

        QProcess proc;
        proc.setStandardInputFile(filename);
        proc.start(result);
        if (!proc.waitForFinished())
        {
            qDebug()<<"Error Import";
            QMessageBox::critical(this,"Импорт БД","Ошибка при импорте БД");
        }
        else
        {
            qDebug()<<"GOOD Import";
            QMessageBox::information(this,"Импорт БД","Импорт БД завершён");
        }
    }
}

//Файл -> Экспорт
void MainForm::on_actionExport_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this);

    if (!filename.isEmpty())
    {
        QString result;
        if (QSqlDatabase::database().password()!="")
            result="mysqldump -u"+QSqlDatabase::database().userName()+" -p"+QSqlDatabase::database().password()+" -h"+QSqlDatabase::database().hostName()+" "+QSqlDatabase::database().databaseName();
        else
            result="mysqldump -u"+QSqlDatabase::database().userName()+" -h"+QSqlDatabase::database().hostName()+" "+QSqlDatabase::database().databaseName();
        qDebug()<<"String Export: "<<result;

        QProcess proc;
        proc.setStandardOutputFile(filename+".sql");
        proc.start(result);
        if (!proc.waitForFinished())
        {
            qDebug()<<"Error Export";
            QMessageBox::critical(this,"Экспорт БД","Ошибка при экспорте БД");
        }
        else
        {
            qDebug()<<"GOOD Export";
            QMessageBox::information(this,"Экспорт БД","Экспорт БД завершён");
        }
    }
}

void MainForm::on_table_device_clicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        QSqlRecord rec=model_device->record(index.row());
        if (ui->tabWidget_3->currentIndex()==0)
            model_characteristic->setFilter("id_device="+rec.value(0).toString());
        else
            model_repair->setFilter("id_device="+rec.value(0).toString());
    }else
    {
        if (ui->tabWidget_3->currentIndex()==0)
            model_characteristic->setFilter("id_device=-1");
        else
            model_repair->setFilter("id_device=-1");
    }
    model_characteristic->select();
    model_repair->select();
}

void MainForm::on_tabWidget_3_currentChanged(int index)
{
    this->on_table_device_clicked(ui->table_device->currentIndex());
}

//Сканировать, кто в сети
void MainForm::on_actionRefresh_triggered()
{
    test_online.start();
}

void MainForm::on_tabWidget_4_currentChanged(int index)
{
    ui->actionNewProcess->setEnabled(false);
    ui->actionKillProcess->setEnabled(false);
    ui->actionRefreshProcess->setEnabled(false);

    ui->actionRoot->setEnabled(false);
    ui->actionDownload->setEnabled(false);
    ui->actionUpload->setEnabled(false);
    ui->actionDeleteFile->setEnabled(false);

    ui->actionMessage->setEnabled(false);
    ui->actionPower->setEnabled(false);

    ui->actionNewProcessMenu->setEnabled(false);
    ui->actionKillProcessMenu->setEnabled(false);
    ui->actionRefreshProcessMenu->setEnabled(false);

    ui->actionRootMenu->setEnabled(false);
    ui->actionDownloadMenu->setEnabled(false);
    ui->actionUploadMenu->setEnabled(false);
    ui->actionDeleteFileMenu->setEnabled(false);

    ui->actionMessageMenu->setEnabled(false);
    ui->actionPowerMenu->setEnabled(false);

    switch (index)
    {
        case 0:
        {
            ui->actionMessage->setEnabled(true);
            ui->actionPower->setEnabled(true);

            ui->actionMessageMenu->setEnabled(true);
            ui->actionPowerMenu->setEnabled(true);

            PrintAdmin(Ui::Online);
            break;
        }
        case 1:
        {
            PrintAdmin(Ui::File);
            break;
        }
        case 2:
        {
            PrintAdmin(Ui::Process);
            break;
        }
    }
}

//При двойном щелчке по таблице для списка процессов
void MainForm::on_table_process_doubleClicked(const QModelIndex &index)
{
    if (ui->table_process->columnCount()==5)
    {
        QString host=ui->table_process->item(index.row(),3)->text();
        if (host=="")
            host=ui->table_process->item(index.row(),4)->text();
        client->connectToHost(host,22079);
        if (client->waitForConnected())
        {
            client->write((char*)&CMD_GET_PROCESS,sizeof(CMD_GET_PROCESS));
            ui->statusBar->showMessage(host);
            ui->actionNewProcess->setEnabled(true);
            ui->actionKillProcess->setEnabled(true);
            ui->actionRefreshProcess->setEnabled(true);

            ui->actionNewProcessMenu->setEnabled(true);
            ui->actionKillProcessMenu->setEnabled(true);
            ui->actionRefreshProcessMenu->setEnabled(true);
        }else
            QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
    }

}

//При создать новый процесс
void MainForm::on_actionNewProcess_triggered()
{
    if (ui->table_process->columnCount()==2)
    {
        new_process_from->exec();
    }
}

//При завершить выделенный процесс
void MainForm::on_actionKillProcess_triggered()
{
    if (ui->table_process->columnCount()==2)
    {
        if (ui->table_process->currentRow()==-1)
        {
            qDebug()<<"No Select Record!";
        }else
        {
            QString host=ui->statusBar->currentMessage();
            int pid=ui->table_process->item(ui->table_process->currentRow(),1)->text().toInt();
            client->connectToHost(host,22079);
            if (client->waitForConnected())
            {
                client->write((char*)&CMD_KILL_PROCESS,sizeof(CMD_GET_PROCESS));
                client->write((char*)&pid,sizeof(pid));
                client->close();
            }else
                QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
        }
    }
}

//При обновить список процессов
void MainForm::on_actionRefreshProcess_triggered()
{
    if (ui->table_process->columnCount()==2)
    {
        QString host=ui->statusBar->currentMessage();
        client->connectToHost(host,22079);
        if (client->waitForConnected())
        {
            client->write((char*)&CMD_GET_PROCESS,sizeof(CMD_GET_PROCESS));
        }else
            QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
    }
}

//При двойном щелчке по таблице для списка файлов
void MainForm::on_table_file_doubleClicked(const QModelIndex &index)
{
    ui->actionRoot->setEnabled(true);
    ui->actionDownload->setEnabled(true);
    ui->actionUpload->setEnabled(true);
    ui->actionDeleteFile->setEnabled(true);

    ui->actionRootMenu->setEnabled(true);
    ui->actionDownloadMenu->setEnabled(true);
    ui->actionUploadMenu->setEnabled(true);
    ui->actionDeleteFileMenu->setEnabled(true);

    if (ui->table_file->columnCount()==5)
    {
        QString host=ui->table_file->item(index.row(),3)->text();
        if (host=="")
            host=ui->table_file->item(index.row(),4)->text();
        client->connectToHost(host,22079);
        if (client->waitForConnected())
        {
            client->write((char*)&CMD_GET_FILE,sizeof(CMD_GET_FILE));
            QByteArray path="/";
            client->write(path);
            ui->current_path->setEnabled(true);
            ui->current_path->setText("/");
            ui->statusBar->showMessage(host);
        }else
            QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
    }else
    {
        QString host=ui->statusBar->currentMessage();
        client->connectToHost(host,22079);
        if (client->waitForConnected())
        {
            client->write((char*)&CMD_GET_FILE,sizeof(CMD_GET_FILE));
            QByteArray path=ui->table_file->item(index.row(),3)->text().toAscii();
            client->write(path);
            ui->current_path->setEnabled(true);
            ui->current_path->setText(path);
        }else
            QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
    }

}

//При изменении текущего пути
void MainForm::on_current_path_returnPressed()
{
    if (ui->table_file->columnCount()!=5)
    {
        QString host=ui->statusBar->currentMessage();
        client->connectToHost(host,22079);
        if (client->waitForConnected())
        {
            client->write((char*)&CMD_GET_FILE,sizeof(CMD_GET_FILE));
            QByteArray path=ui->current_path->text().toAscii();
            client->write(path);
        }else
            QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
    }
}

//При перейти в корень
void MainForm::on_actionRoot_triggered()
{
    if (ui->table_file->columnCount()!=5)
    {
        QString host=ui->statusBar->currentMessage();
        client->connectToHost(host,22079);
        if (client->waitForConnected())
        {
            client->write((char*)&CMD_GET_FILE,sizeof(CMD_GET_FILE));
            QByteArray path="/";
            client->write(path);
            ui->current_path->setText("/");
        }else
            QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
    }
}

//При скачать файл
void MainForm::on_actionDownload_triggered()
{
    if (ui->table_file->selectedItems().isEmpty())
    {
        QMessageBox::information(this,"Скачка файла","Не выделен файл для скачивания!");
    }else
    {
        int type=ui->table_file->item(ui->table_file->currentRow(),1)->text().toInt();
        if (type==2 || type==3)
        {
            //QMessageBox::information(this,"Скачка файла","Идёт скачка файла "+ui->table_file->item(ui->table_file->currentRow(),3)->text());

            QString host=ui->statusBar->currentMessage();
            client->connectToHost(host,22079);
            if (client->waitForConnected())
            {
                client->write((char*)&CMD_DOWNLOAD_FILE,sizeof(CMD_DOWNLOAD_FILE));
                //QByteArray path=ui->table_file->item(ui->table_file->currentRow(),3)->text().toAscii();
                //client->write(path);
                QByteArray buf;
                QDataStream data_c(&buf,QIODevice::WriteOnly);
                data_c<<ui->table_file->item(ui->table_file->currentRow(),3)->text();
                client->write(buf);
                client->waitForBytesWritten();
            }else
                QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
        }
        else
        {
            QMessageBox::information(this,"Скачка файла","Скачивать можно только файл!");
        }

    }
}

//При загрузить файл
void MainForm::on_actionUpload_triggered()
{
    QString path_file=QFileDialog::getOpenFileName(this);
    if (!path_file.isEmpty())
    {
        if (ui->current_path->text()=="/")
        {
            QMessageBox::information(this,"Загрузка файла","Загрузка в корень запрещена!");
        }else
        {
            QFileInfo info(path_file);
            QString path=ui->current_path->text()+info.fileName();
            qDebug()<<"File "<<path;

            QString host=ui->statusBar->currentMessage();

            QFile file(path_file);
            if (file.open(QIODevice::ReadOnly))
            {
                client->connectToHost(host,22079);
                if (client->waitForConnected())
                {
                    client->write((char*)&CMD_UPLOAD_FILE,sizeof(CMD_UPLOAD_FILE));

                    QByteArray buf_c;
                    QDataStream data_c(&buf_c,QIODevice::WriteOnly);
                    data_c<<path;

                    qint64 size_file=file.size();
                    qDebug()<<"Size file "<<size_file;
                    data_c<<size_file;
                    client->write(buf_c);
                    client->waitForBytesWritten();

                    qint64 s=0;
                    while (!file.atEnd())
                    {
                        QByteArray buf;
                        buf=file.readAll();
                        s+=buf.size();
                        client->write(buf);
                        client->waitForBytesWritten();
                        qDebug()<<"Current size="<<s;
                    }
                    file.close();

                    client->close();

                    QMessageBox::information(this,"Загрузка файла","Файл удачно загружен!");
                }else
                    QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
            }else
                QMessageBox::critical(this,"Загрузка файла","Не удалось открыть файл для чтения!");
        }
    }
}

//Сервис - Настройки
void MainForm::on_actionSetting_triggered()
{
    setting_form->exec();
}

//Кнопка Добавить характеристики
void MainForm::on_actionAddDop_clicked()
{
    if (ui->table_device->currentIndex().row()==-1)
    {
        QMessageBox::information(this,"Добаление","Не выбрано устройство");
    }
    else
    {
        model_characteristic->insertRow(model_characteristic->rowCount());
        model_characteristic->setData(model_characteristic->index(model_characteristic->rowCount()-1,3),model_device->record(ui->table_device->currentIndex().row()).value("id"));
    }
}

//Кнопка Сохранить характеристики
void MainForm::on_actionSaveDop_clicked()
{
    model_characteristic->submitAll();
}

//Кнопка Удалить характеристики
void MainForm::on_actionDeleteDop_clicked()
{
    model_characteristic->removeRow(ui->table_characteristic->currentIndex().row());
}

//Кнопка Удалить все характеристики
void MainForm::on_actionDeleteAllDop_clicked()
{
    model_characteristic->removeRows(0,model_characteristic->rowCount());
}

//Кнопка Дублировать характеристики
void MainForm::on_actionCopyDop_clicked()
{
    QSqlRecord rec=model_characteristic->record(ui->table_characteristic->currentIndex().row());
    rec.setValue(0,"");
    model_characteristic->insertRecord(model_characteristic->rowCount(),rec);
}

//Кнопка Добавить ремонты
void MainForm::on_actionAddDop2_clicked()
{
    if (ui->table_device->currentIndex().row()==-1)
    {
        QMessageBox::information(this,"Добаление","Не выбрано устройство");
    }
    else
    {
        model_repair->insertRow(model_repair->rowCount());
        model_repair->setData(model_repair->index(model_repair->rowCount()-1,4),model_device->record(ui->table_device->currentIndex().row()).value("id"));
    }
}

//Кнопка Сохранить ремонты
void MainForm::on_actionSaveDop2_clicked()
{
    model_repair->submitAll();
}

//Кнопка Удалить ремонты
void MainForm::on_actionDeleteDop2_clicked()
{
    model_repair->removeRow(ui->table_repair->currentIndex().row());
}

//Кнопка Удалить все ремонты
void MainForm::on_actionDeleteAllDop2_clicked()
{
    model_repair->removeRows(0,model_repair->rowCount());
}

//Кнопка Дублировать ремонты
void MainForm::on_actionCopyDop2_clicked()
{
    QSqlRecord rec=model_repair->record(ui->table_repair->currentIndex().row());
    rec.setValue(0,"");
    model_repair->insertRecord(model_repair->rowCount(),rec);
}

//При Выключение ПК
void MainForm::on_actionPower_triggered()
{
    if ((ui->table_online->currentRow()==-1))
    {
        QMessageBox::information(this,"Выключение ПК","Не выбран ПК");
    }else
    {
        QString online=ui->table_online->item(ui->table_online->currentRow(),6)->text();
        if (online=="Да")
        {
            QString host=ui->table_online->item(ui->table_online->currentRow(),3)->text();
            if (host=="")
                host=ui->table_online->item(ui->table_online->currentRow(),4)->text();
            ui->statusBar->showMessage(host);
            shutdown_form->exec();
        }else
            QMessageBox::information(this,"Выключение ПК","ПК не готов к администрированию");
    }
}

//При послать сообщение
void MainForm::on_actionMessage_triggered()
{
    if ((ui->table_online->currentRow()==-1))
    {
        QMessageBox::information(this,"Отправка сообщения","Не выбран ПК");
    }else
    {
        QString online=ui->table_online->item(ui->table_online->currentRow(),6)->text();
        if (online=="Да")
        {
            QString host=ui->table_online->item(ui->table_online->currentRow(),3)->text();
            if (host=="")
                host=ui->table_online->item(ui->table_online->currentRow(),4)->text();
            ui->statusBar->showMessage(host);
            message_form->exec();
        }else
            QMessageBox::information(this,"Отправка сообщения","ПК не готов к администрированию");
    }
}

//При Удалить файл
void MainForm::on_actionDeleteFile_triggered()
{
    if (ui->table_file->selectedItems().isEmpty())
    {
        QMessageBox::information(this,"Удаление файла","Не выделен файл для удаления!");
    }else
    {
        int type=ui->table_file->item(ui->table_file->currentRow(),1)->text().toInt();
        if (type==2 || type==3)
        {
            //QMessageBox::information(this,"Скачка файла","Идёт скачка файла "+ui->table_file->item(ui->table_file->currentRow(),3)->text());

            QString host=ui->statusBar->currentMessage();
            client->connectToHost(host,22079);
            if (client->waitForConnected())
            {
                client->write((char*)&CMD_DELETE_FILE,sizeof(CMD_DELETE_FILE));
                QByteArray path=ui->table_file->item(ui->table_file->currentRow(),3)->text().toAscii();
                client->write(path);
                client->close();
            }else
                QMessageBox::information(this,"Подключение","Не удаётся подключится к '"+host+"'");
        }
        else
        {
            QMessageBox::information(this,"Удаление файла","Удалять можно только файл!");
        }

    }
}

//Меню Добавить
void MainForm::on_actionAddMenu_triggered()
{
    on_actionAdd_triggered();
}

//Меню Дублировать
void MainForm::on_actionCopyMenu_triggered()
{
    on_actionCopy_triggered();
}

//Меню Удалить
void MainForm::on_actionDeleteMenu_triggered()
{
    on_actionDelete_triggered();
}

//Меню Удалить все
void MainForm::on_actionDeleteallMenu_triggered()
{
    on_actionDeleteall_triggered();
}

//Меню Сохранить
void MainForm::on_actionSaveMenu_triggered()
{
    on_actionSave_triggered();
}

//Меню Сканировать
void MainForm::on_actionRefreshMenu_triggered()
{
    on_actionRefresh_triggered();
}

//Меню Отправить сообщение
void MainForm::on_actionMessageMenu_triggered()
{
    on_actionMessage_triggered();
}

//Меню Выключить ПК
void MainForm::on_actionPowerMenu_triggered()
{
    on_actionPower_triggered();
}

//Меню Перейти в корень
void MainForm::on_actionRootMenu_triggered()
{
    on_actionRoot_triggered();
}

//Меню Скачать файл
void MainForm::on_actionDownloadMenu_triggered()
{
    on_actionDownload_triggered();
}

//Меню Загрузить файл
void MainForm::on_actionUploadMenu_triggered()
{
    on_actionUpload_triggered();
}

//Меню Удалить файл
void MainForm::on_actionDeleteFileMenu_triggered()
{
    on_actionDeleteFile_triggered();
}

//Меню Запустить процесс
void MainForm::on_actionNewProcessMenu_triggered()
{
    on_actionNewProcess_triggered();
}

//Меню Завершить процесс
void MainForm::on_actionKillProcessMenu_triggered()
{
    on_actionKillProcess_triggered();
}

//Меню Обновить список процессов
void MainForm::on_actionRefreshProcessMenu_triggered()
{
    on_actionRefreshProcess_triggered();
}

//Для отмены подсказок Меню
bool MainForm::eventFilter(QObject *target, QEvent *event)
{
    if (event->type()==QEvent::StatusTip)
    {
        //qDebug()<<"Event StatusTip";
        return true;
    }
    return false;
}

void MainForm::on_actionAbout_triggered()
{
    about_form->exec();
}
