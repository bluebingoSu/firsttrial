#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "serverdatabase.h"

#include <QtNetwork>
#include <QMessageBox>
#include <QDebug>

TCPServer::TCPServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TCPServer),
    m_server(NULL),
    m_client(NULL)
{
    ui->setupUi(this);

    //创建套接字对象
    m_server = new QTcpServer(this);
    //将套接字设置为监听模式
    m_server->listen(QHostAddress::Any, 9999);
    //连接数据库
    m_database=new ServerDataBase();
    if(!m_database->connectDataBase()){
        qDebug() << "Failed to connect m_database";
    }

    //通过信号接收客户端请求
    connect(m_server, &QTcpServer::newConnection,this, &TCPServer::slotNewConnection);
}

TCPServer::~TCPServer()
{
    delete ui;
}

void TCPServer::slotNewConnection()
{
    if(m_client == NULL)
    {
        //处理客户端的连接请求
        m_client = m_server->nextPendingConnection();
        //发送数据
        m_client->write("服务器连接成功!!!");
        //连接信号, 接收客户端数据
        connect(m_client, &QTcpSocket::readyRead,this, &TCPServer::slotReadyRead);
    }
}

void TCPServer::slotReadyRead()
{
    //接收数据
    QByteArray array = m_client->readLine();
    QMessageBox::information(this, "Client Message", array);
}

