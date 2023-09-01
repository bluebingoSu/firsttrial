#include "mainwindow.h"
#include "tcpserver.h"
#include "tcpclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TCPServer w;
    TCPClient z;
    w.show();
    z.show();
    return a.exec();
}
