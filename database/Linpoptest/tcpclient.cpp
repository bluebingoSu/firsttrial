#include "tcpclient.h"
#include "ui_tcpclient.h"
#include "clientdatabase.h"

#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QIODevice>
#include <QDateTime>
#include <QDebug>
#include <QWidget>

TCPClient::TCPClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TCPClient)
{
    ui->setupUi(this);
    //创建套接字
    m_client = new QTcpSocket(this);
    //连接服务器
    m_client->connectToHost(QHostAddress("127.0.0.1"), 9999);

    //连接数据库
    m_database=new ClientDataBase();
    if(!m_database->connectDataBase()){
        qDebug() << "Failed to connect m_database";
    }

    //通过信号接收服务器数据
    connect(m_client, &QTcpSocket::readyRead,this, &TCPClient::slotReadyRead);
    //发送按钮
    //connect(ui->pushButton_input, &QPushButton::clicked,this, &TCPClient::slotSendMsg);
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
    QString text = ui->textEdit_input->toPlainText();
     //发送数据
    m_client->write(text.toUtf8());
}

void TCPClient::on_pushButton_input_clicked()
{

    //数据传输到服务端
    TCPClient::slotSendMsg();

    //获取输入
    QString str=ui->textEdit_input->toPlainText();
    if(str.isEmpty()){
        return;
    }

    //获取时间
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    QString timeStr = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间

    //输出文字
    ui->textEdit_input->clear();
    ui->textBrowser_output->insertPlainText(timeStr+"\n");
    ui->textBrowser_output->insertPlainText(str+"\n");

    //存入本地数据库
}
