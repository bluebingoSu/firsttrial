#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QMainWindow>
#include <QTcpServer>

namespace Ui {
class TCPServer;
}

class TCPServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TCPServer(QWidget *parent = nullptr);
    ~TCPServer();

public slots:
    void slotNewConnection();
    void slotReadyRead();

private:
    Ui::TCPServer *ui;
    // 负责监听的套接字
    QTcpServer* m_server;
    // 负责通信的套接字
    QTcpSocket* m_client;

};

#endif // TCPSERVER_H
