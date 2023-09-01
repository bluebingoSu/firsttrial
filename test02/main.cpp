#include "mainwindow.h"
#include "maindatabase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //mainDataBase *d=new mainDataBase();
    return a.exec();
}
