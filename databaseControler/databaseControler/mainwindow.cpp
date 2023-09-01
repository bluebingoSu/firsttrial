#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "serverdatabase.h"
#include "userwindow.h"
#include "messagewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(300,150);
    this->setWindowTitle("Database Controller");

    //数据库初始化
//    serverDataBase = new ServerDataBase();
//    serverDataBase->connectDataBase("main");

    //user显示界面初始化
    userWindow = new UserWindow();
    userWindow->setVisible(false);
    connect(ui->pushButton_user,&QPushButton::clicked,[&]{//显示user界面
        userWindow->setVisible(true);
        this->setVisible(false);
    });

    connect(userWindow,&UserWindow::returnMain,[&]{//user界面返回
        this->setVisible(true);
        userWindow->setVisible(false);
    });

    //message显示界面初始化
    messageWindow = new MessageWindow();
    messageWindow->setVisible(false);
    connect(ui->pushButton_message,&QPushButton::clicked,[&]{//显示message界面
        messageWindow->setVisible(true);
        this->setVisible(false);
    });

    connect(messageWindow,&MessageWindow::returnMain,[&]{//message界面返回
        this->setVisible(true);
        messageWindow->setVisible(false);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

