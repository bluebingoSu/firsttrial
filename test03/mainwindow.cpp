#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

#include <QIODevice>
#include <QDateTime>
#include <QDebug>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widget1=new secondWindow(this);
    widget1->setWindowTitle("widget 1");
    widget1->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_send_clicked()
{
    //获取输入
    QString str=ui->plainTextEdit_input->toPlainText();
    if(str.isEmpty()){
        return;
    }

    //获取时间
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    QString timeStr = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间

    //输出文字
    ui->plainTextEdit_input->clear();
    ui->textBrowser_output->insertPlainText(timeStr+"\n");
    ui->textBrowser_output->insertPlainText(str+"\n");

    //打开本地记录
    QFile file("memory.txt");
    if(!file.open(QIODevice::Append)){
        qDebug()<<"open file failed.";
        return;
    }
    QTextStream out(&file);
    out << timeStr+"\n" << str+"\n";
    file.flush();
    file.close();
}

void MainWindow::on_textBrowser_output_textChanged()
{
    ui->textBrowser_output->moveCursor(QTextCursor::End);
}

void MainWindow::on_pushButton_history_clicked()
{
    if(!widget1->isVisible()){
        widget1->show();
        widget1->loadHistory();
    }
}
