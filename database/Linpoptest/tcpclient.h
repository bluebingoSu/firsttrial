#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QMainWindow>
#include <QTcpSocket>

class ClientDataBase;

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


private slots:
    void on_pushButton_input_clicked();

private:
    Ui::TCPClient *ui;
    QTcpSocket* m_client;
    ClientDataBase *m_database;
};


#endif // TCPCLIENT_H
