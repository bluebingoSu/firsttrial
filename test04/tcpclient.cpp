#include "tcpclient.h"
#include "ui_tcpclient.h"

#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

TCPClient::TCPClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TCPClient)
{
    ui->setupUi(this);
    //创建套接字
    m_client = new QTcpSocket(this);
    //连接服务器
    m_client->connectToHost(QHostAddress("127.0.0.1"), 9999);

    //通过信号接收服务器数据
    connect(m_client, &QTcpSocket::readyRead,
this, &TCPClient::slotReadyRead);
    //发送按钮
    connect(ui->btnSend, &QPushButton::clicked,
this, &TCPClient::slotSendMsg);
}

TCPClient::~TCPClient()
{
    delete ui;
}

void TCPClient::slotReadyRead()
{
     //接收数据
    QByteArray array = m_client->readAll();
    QMessageBox::information(this, "Server Message", array);
}

void TCPClient::slotSendMsg()
{
    QString text = ui->textEdit->toPlainText();
     //发送数据
    m_client->write(text.toUtf8());
    ui->textEdit->clear();
}
