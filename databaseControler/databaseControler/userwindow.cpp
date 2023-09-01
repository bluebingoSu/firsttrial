#include "userwindow.h"
#include "ui_userwindow.h"
#include "serverdatabase.h"

#include <QDebug>
#include <QMessageBox>

UserWindow::UserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,500);
    this->setWindowTitle("Database User");

    //数据库初始化
    serverDataBase = new ServerDataBase();
    serverDataBase->connectDataBase("user");

    //表格初始化
    ui->tableWidget->setFixedSize(800,200);//设置大小
    ui->tableWidget->setColumnCount(6); // 设置列数
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);//固定行高
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);//设置行高50
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//不固定列宽
    //tableWidget->horizontalHeader()->setDefaultSectionSize(50);//设置列宽50
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection); // 设置不选模式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置禁止编辑
    QStringList titleStr={"avatar","id","ip","name","department","online"};
    ui->tableWidget->setHorizontalHeaderLabels(titleStr);//设置表头名字
    ui->tableWidget->setSortingEnabled(true);  // 允许点击表头进行排序
    showTable();

    connect(ui->pushButton_show,&QPushButton::clicked,this,&UserWindow::showTable);//显示所有数据

    connect(ui->pushButton_return,&QPushButton::clicked,[&]{//发出返回信号
        emit returnMain();
    });

    connect(ui->pushButton_add,&QPushButton::clicked,[&]{//添加用户
        QString id=ui->lineEdit_id->text();
        QString name=ui->lineEdit_name->text();
        QString password=ui->lineEdit_password->text();
        if(id!=nullptr&&name!=nullptr&&password!=nullptr){
            if(serverDataBase->addUserAccount(id,name,password)){
                ui->lineEdit_id->clear();
                ui->lineEdit_name->clear();
                ui->lineEdit_password->clear();
                showTableOne(id);
            }else{
                QMessageBox::warning(this,"ID exists!","The id exists.");
            }
        }
    });

    connect(ui->pushButton_clear,&QPushButton::clicked,[&]{//删除用户
        QString id=ui->lineEdit_id->text();
        if(id!=nullptr){
            if(serverDataBase->deleteUserAccount(id)){
                ui->lineEdit_id->clear();
                QMessageBox::information(this,"ID deleted.","Succeed to delete user"+id+"!");
                showTable();
            }else{
                QMessageBox::warning(this,"ID doesn't exist!","The id doesn't exist.");
            }
        }
    });

    connect(ui->pushButton_select,&QPushButton::clicked,[&]{//选择用户
        QString id=ui->lineEdit_id->text();
        QJsonObject jsonUserView;
        if(id!=nullptr){
            if(serverDataBase->getUserView(id,jsonUserView)){
                ui->lineEdit_id->clear();
                ui->tableWidget->clearContents();//清空数据
                ui->tableWidget->setRowCount(0);//清空行
                showTableOne(id);
            }else{
                QMessageBox::warning(this,"ID doesn't exist!","The id doesn't exist.");
            }
        }
    });

    connect(ui->pushButton_alterName,&QPushButton::clicked,[&]{//修改用户名字
        QString id=ui->lineEdit_id->text();
        QString name=ui->lineEdit_name->text();
        if(id!=nullptr&&name!=nullptr){
            if(serverDataBase->alterUserName(id,name)){
                ui->lineEdit_id->clear();
                ui->lineEdit_name->clear();
                showTableOne(id);
            }else{
                QMessageBox::warning(this,"ID doesn't exist!","The id doesn't exist.");
            }
        }
    });
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::showTable(){
    ui->tableWidget->clearContents();//清空数据
    ui->tableWidget->setRowCount(0);//清空行
    QList<QJsonObject> jsonUserViewList;
    serverDataBase->getAllUserView(jsonUserViewList);
    int i=0;
    foreach (QJsonObject jsonUserView, jsonUserViewList) {
        QString avatar,id,name,ip,department,isOnline;
        bool online;
        serverDataBase->changeJsonIntoUser(avatar,id,ip,name,department,online,jsonUserView);
        online?isOnline="true":isOnline="false";
        QString titles[]={avatar,id,ip,name,department,isOnline};
        ui->tableWidget->insertRow(i);//插入行
        for(int j=0;j<6;j++){
            QTableWidgetItem *item=new QTableWidgetItem();
            item->setText(titles[j]);
            ui->tableWidget->setItem(i,j,item);
        }
        i++;
    }
}

void UserWindow::showTableOne(QString id){
    ui->tableWidget->clearContents();//清空数据
    ui->tableWidget->setRowCount(0);//清空行
    QJsonObject jsonUserView;
    QString avatar,name,ip,department,isOnline;
    bool online;
    serverDataBase->getUserView(id,jsonUserView);
    serverDataBase->changeJsonIntoUser(avatar,id,ip,name,department,online,jsonUserView);
    online?isOnline="true":isOnline="false";
    QString titles[]={avatar,id,ip,name,department,isOnline};
    ui->tableWidget->insertRow(0);//插入行
    for(int j=0;j<6;j++){
        QTableWidgetItem *item=new QTableWidgetItem();
        item->setText(titles[j]);
        ui->tableWidget->setItem(0,j,item);
    }
}
