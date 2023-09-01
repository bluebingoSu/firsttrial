#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QApplication>
#include <QStandardPaths>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建一个QSqlDatabase对象，用于连接数据库
    db = QSqlDatabase::addDatabase("QSQLITE");

    // 指定数据库路径，如果路径不存在，将会创建一个新数据库
    /*
    db.setHostName("host");
    db.setDatabaseName("dbname");
    db.setUserName("username");
    db.setPassword("password");

*/

    db.setDatabaseName("myDataBase");
    //查找数据库在本地的位置
    /*QString databasePath = QCoreApplication::applicationDirPath() + "/:memory:.db";
    QString newDatabasePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/:memory:.db";
    qDebug() << databasePath;
    qDebug() << newDatabasePath;
    //QFile::copy(databasePath, newDatabasePath);
*/

    // 尝试建立到数据库的连接
    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError();
    }
    query=QSqlQuery(db);
    // 创建一个表（如果表不存在）
    query.exec(QString("select count(*) from sqlite_master where type='table' and name='%student'"));
    if(!query.next()){
        qDebug() << "The query doesn't exist.";
        if (!query.exec("CREATE TABLE student (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)")) {
            qDebug() << "Failed to create table:" << query.lastError();
        }
    }else{
        qDebug() << "The query exists.";
    }

    // 将表显示
    qmodel=new QSqlQueryModel();
    query.exec("SELECT * FROM student");
    qmodel->setQuery(query);
    ui->tableView->setModel(qmodel);
    ui->tableView->scrollToBottom();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // 插入一些数据
    QVariantList names,ages;
    names << ui->lineEdit_name->text();
    ages << ui->lineEdit_age->text().toInt();
    if(ui->lineEdit_name->text().isEmpty()||ui->lineEdit_age->text().toInt()==0){
        return;
    }
    ui->lineEdit_name->clear();
    ui->lineEdit_age->clear();
    if(!query.prepare("INSERT INTO student (name, age) VALUES (?, ?)")){
        qDebug() << "Failed to prepare:" << query.lastError();
    }
    query.addBindValue(names);
    query.addBindValue(ages);
    if (!query.execBatch()) {
        qDebug() << "Failed to execBatch:" << query.lastError();
    }


    // 执行查询并输出结果
    query.exec("SELECT * FROM student");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "ID:" << id << ", Name:" << name << ", Age:" << age;
    }

    qmodel->setQuery(query);
    ui->tableView->setModel(qmodel);
    ui->tableView->scrollToBottom();
    // 关闭数据库连接
    //db.close();

}

void MainWindow::on_pushButton_clear_clicked()
{
    if(!query.exec("DELETE FROM student")){
        qDebug() << "Failed to delete." << query.lastError();
    }
    query.exec("SELECT * FROM student");
    qmodel->setQuery(query);
    ui->tableView->setModel(qmodel);
}
