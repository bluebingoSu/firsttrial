#include "secondwindow.h"
#include "ui_secondwindow.h"

#include "QFile"
#include "QDebug"

secondWindow::secondWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::secondWindow)
{
    ui->setupUi(this);
}

secondWindow::~secondWindow()
{
    delete ui;
}

void secondWindow::loadHistory(){
    //打开本地记录
    QFile file("memory.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"open file failed.";
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString str;
    while(!(str=in.readLine()).isEmpty()){
        ui->textBrowser_historyout->insertPlainText(str+"\n");
    }
    file.close();
}

void secondWindow::on_textBrowser_historyout_textChanged()
{
    ui->textBrowser_historyout->moveCursor(QTextCursor::End);
}
