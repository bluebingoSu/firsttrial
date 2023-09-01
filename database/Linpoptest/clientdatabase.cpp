#include "clientdatabase.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QJsonObject>

ClientDataBase::ClientDataBase()
{

}

bool ClientDataBase::connectDataBase(){
    // 创建一个QSqlDatabase对象，用于连接数据库
    db = QSqlDatabase::addDatabase("QSQLITE","cdb");

    // 指定数据库路径，如果路径不存在，将会创建一个新数据库
    db.setDatabaseName("../ClientDataBase/ClientDataBase.db");

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
        return false;
    }

    query=QSqlQuery(db);

    /*
    //删除表
    if(!query.exec("DROP TABLE history;")){
        qDebug() << "Failed to drop table history";
    }
    */


    // 创建一个表
    if (!query.exec("CREATE TABLE history (id TEXT, timestamp TEXT PRIMARY KEY, type TEXT, data TEXT, isSender INTEGER)")) {
        qDebug() << "Failed to create table history:" << query.lastError();
    }

    return true;
}

bool ClientDataBase::addMessage(QJsonObject jsonMessage){
    QVariantList id;id << jsonMessage["id"].toVariant();
    QVariantList timestamp;timestamp << jsonMessage["timestamp"].toVariant();
    QVariantList type;type << jsonMessage["type"].toVariant();
    QVariantList data;data << jsonMessage["data"].toVariant();
    QVariantList isSender;id << jsonMessage["isSender"].toVariant();
    query.prepare("INSERT INTO history VALUES (?,?,?,?,?)");
    query.addBindValue(id);
    query.addBindValue(timestamp);
    query.addBindValue(type);
    query.addBindValue(data);
    query.addBindValue(isSender);
    if(!query.execBatch()){
        qDebug() << "Failed to add history: " << query.lastError();
        return false;
    }
    qDebug() << "Succeed to add history!";
    return true;
}

bool ClientDataBase::getMessage(QString id, QList<QJsonObject> &jsonMessageList){
    query.prepare("SELECT * FROM history WHERE id = ? ORDER BY timestamp");
    QVariantList a;
    a << id;
    query.addBindValue(a);
    if(!query.execBatch()){
        qDebug() << "Failed to select the history: " << query.lastError();
        return false;
    }
    while(query.next()){
        QJsonObject jsonMessage;
        jsonMessage["id"] = query.value("id").toString();
        jsonMessage["timestamp"] = query.value("timestamp").toString();
        jsonMessage["type"] = query.value("type").toString();
        jsonMessage["data"] = query.value("data").toString();
        jsonMessage["isSender"] = query.value("isSender").toInt();
        jsonMessageList.append(jsonMessage);
    }
    qDebug() << "Succeed to get the history!";//isSender为true的时候说明发送者是该用户
    return true;
}

bool ClientDataBase::selectHistoryByData(QString id, QString dataPart, QList<QJsonObject> &jsonMessageList){
    query.prepare("SELECT * FROM history WHERE id = ? AND data LIKE ? ORDER BY timestamp");
    QVariantList a,b;
    a << id;
    b << "%" + dataPart + "%";
    query.addBindValue(a);
    query.addBindValue(b);
    if(!query.execBatch()){
        qDebug() << "Failed to select the history by data: " << query.lastError();
        return false;
    }
    while(query.next()){
        QJsonObject jsonMessage;
        jsonMessage["id"] = query.value("id").toString();
        jsonMessage["timestamp"] = query.value("timestamp").toString();
        jsonMessage["type"] = query.value("type").toString();
        jsonMessage["data"] = query.value("data").toString();
        jsonMessage["isSender"] = query.value("isSender").toInt();
        jsonMessageList.append(jsonMessage);
    }
    qDebug() << "Succeed to select the history by data!";
    return true;
}


/*
    //查看消息记录
    QList<QJsonObject> jsonMessageList;
    getMessage("10086",jsonMessageList);
    foreach (QJsonObject jsonMessage, jsonMessageList) {
        qDebug() << "id: " << jsonMessage["id"];
        qDebug() << "timestamp: " << jsonMessage["timestamp"];
        qDebug() << "type: " << jsonMessage["type"];
        qDebug() << "data: " << jsonMessage["data"];
        qDebug() << "isSender: " << jsonMessage["isSender"];
    }
*/
