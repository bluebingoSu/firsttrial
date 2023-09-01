#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class TCPClient;
}

class TCPClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit TCPClient(QWidget *parent = 0);
    ~TCPClient();

public slots:
    void slotReadyRead();
    void slotSendMsg();

private:
    Ui::TCPClient *ui;
    QTcpSocket* m_client;
};


#endif // TCPCLIENT_H
