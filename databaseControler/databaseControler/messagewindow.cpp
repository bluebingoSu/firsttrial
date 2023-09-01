#include "messagewindow.h"
#include "ui_messagewindow.h"
#include "serverdatabase.h"

#include <QDebug>
#include <QMessageBox>

MessageWindow::MessageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,500);
    this->setWindowTitle("Database Message");

    //数据库初始化
    serverDataBase = new ServerDataBase();
    serverDataBase->connectDataBase("message");

    //表格初始化
    ui->tableWidget->setFixedSize(800,200);//设置大小
    ui->tableWidget->setColumnCount(5); // 设置列数
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);//固定行高
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);//设置行高50
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//不固定列宽
    //tableWidget->horizontalHeader()->setDefaultSectionSize(50);//设置列宽50
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection); // 设置不选模式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置禁止编辑
    QStringList titleStr={"idSender","idReceiver","timestamp","type","data"};
    ui->tableWidget->setHorizontalHeaderLabels(titleStr);//设置表头名字
    ui->tableWidget->setSortingEnabled(true);  // 允许点击表头进行排序
    showMessage();

    connect(ui->pushButton_return,&QPushButton::clicked,[&]{//发送返回信号
        emit returnMain();
    });

    connect(ui->pushButton_show,&QPushButton::clicked,this,&MessageWindow::showMessage);//展现全部信息

    connect(ui->pushButton_add,&QPushButton::clicked,[&]{//增加消息
        QString idSender = ui->lineEdit_idSender->text();
        QString idReceiver = ui->lineEdit_idReceiver->text();
        QString timestamp = ui->lineEdit_timestamp->text();
        QString type = ui->lineEdit_type->text();
        QString data = ui->lineEdit_data->text();
        if(idSender!=nullptr&&idReceiver!=nullptr&&timestamp!=nullptr&&type!=nullptr&&data!=nullptr){
            QJsonObject jsonMessage;
            serverDataBase->changeMessageIntoJson(idSender,idReceiver,timestamp,type,data,jsonMessage);
            if(serverDataBase->addMessage(jsonMessage)){
                ui->lineEdit_idSender->clear();
                ui->lineEdit_idReceiver->clear();
                ui->lineEdit_timestamp->clear();
                ui->lineEdit_type->clear();
                ui->lineEdit_data->clear();
                showMessageOne(idReceiver);
            }else{
                QMessageBox::warning(this,"The message exists!","The message exists.");
            }
        }
    });

    connect(ui->pushButton_select,&QPushButton::clicked,[&]{//根据内容选择消息
        QString idSender = ui->lineEdit_idSender->text();
        QString idReceiver = ui->lineEdit_idReceiver->text();
        QString dataPart = ui->lineEdit_data->text();
        QList<QJsonObject> jsonMessageList;
        if(idSender!=nullptr&&idReceiver!=nullptr&&dataPart!=nullptr){
            if(serverDataBase->selectMessageByData(idSender,idReceiver,dataPart,jsonMessageList)){
                ui->lineEdit_idSender->clear();
                ui->lineEdit_idReceiver->clear();
                ui->lineEdit_data->clear();
                ui->tableWidget->clearContents();//清空数据
                ui->tableWidget->setRowCount(0);//清空行
                int i=0;
                foreach (QJsonObject jsonMessage, jsonMessageList) {
                    QString idSender,idReceiver,timestamp,type,data;
                    serverDataBase->changeJsonIntoMessage(idSender,idReceiver,timestamp,type,data,jsonMessage);
                    QString titles[]={idSender,idReceiver,timestamp,type,data};
                    ui->tableWidget->insertRow(i);//插入行
                    for(int j=0;j<5;j++){
                        QTableWidgetItem *item=new QTableWidgetItem();
                        item->setText(titles[j]);
                        ui->tableWidget->setItem(i,j,item);
                    }
                    i++;
                }
            }else{
                QMessageBox::warning(this,"Failed to find message.","Failed to find message.");
            }
        }
    });
}

MessageWindow::~MessageWindow()
{
    delete ui;
}

void MessageWindow::showMessage(){
    ui->tableWidget->clearContents();//清空数据
    ui->tableWidget->setRowCount(0);//清空行
    QList<QJsonObject> jsonMessageList;
    serverDataBase->getAllMessage(jsonMessageList);
    int i=0;
    foreach (QJsonObject jsonMessage, jsonMessageList) {
        QString idSender,idReceiver,timestamp,type,data;
        serverDataBase->changeJsonIntoMessage(idSender,idReceiver,timestamp,type,data,jsonMessage);
        QString titles[]={idSender,idReceiver,timestamp,type,data};
        ui->tableWidget->insertRow(i);//插入行
        for(int j=0;j<5;j++){
            QTableWidgetItem *item=new QTableWidgetItem();
            item->setText(titles[j]);
            ui->tableWidget->setItem(i,j,item);
        }
        i++;
    }
}

void MessageWindow::showMessageOne(QString idReceiver){
    ui->tableWidget->clearContents();//清空数据
    ui->tableWidget->setRowCount(0);//清空行
    QList<QJsonObject> jsonMessageList;
    serverDataBase->getMessage(idReceiver, jsonMessageList);
    int i=0;
    foreach (QJsonObject jsonMessage, jsonMessageList) {
        QString idSender,timestamp,type,data;
        serverDataBase->changeJsonIntoMessage(idSender,idReceiver,timestamp,type,data,jsonMessage);
        QString titles[]={idSender,idReceiver,timestamp,type,data};
        ui->tableWidget->insertRow(i);//插入行
        for(int j=0;j<5;j++){
            QTableWidgetItem *item=new QTableWidgetItem();
            item->setText(titles[j]);
            ui->tableWidget->setItem(i,j,item);
        }
        i++;
    }

}
