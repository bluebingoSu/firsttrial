#include "maindatabase.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>

mainDataBase::mainDataBase()
{
    // 创建一个QSqlDatabase对象，用于连接数据库
    QSqlDatabase db;
    QSqlQuery query;
    db = QSqlDatabase::addDatabase("QSQLITE");

    // 指定数据库路径，如果路径不存在，将会创建一个新数据库
    db.setHostName("host");
    db.setDatabaseName("dbname");
    db.setUserName("username");
    db.setPassword("password");

    db.setDatabaseName(":memory:");
    // 尝试建立到数据库的连接
    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError();
    }
    query=QSqlQuery(db);
    // 创建一个表
    if (!query.exec("CREATE TABLE student (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)")) {
        qDebug() << "Failed to create table:" << query.lastError();
    }
    db.close();
}
