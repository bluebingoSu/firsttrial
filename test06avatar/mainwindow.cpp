#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QTableWidget>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString name="苏为";
    QString firstChar=name.left(1);
    qDebug() << firstChar;
    QSize size(200,200);
    QImage image(size,QImage::Format_ARGB32);
    image.fill(qRgba(0,0,0,100));//设置图片背景颜色
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);//设置画出的图片在上方
    QPen pen = painter.pen();
    pen.setColor(Qt::red);//设置颜色
    QFont font = painter.font();
    font.setBold(true);//加粗
    font.setPixelSize(50);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(image.rect(),Qt::AlignCenter,firstChar);


    //图片的显示（建议换了）
    QTableWidget *table=new QTableWidget();
    table->setFixedSize(200,200);
    table->setRowCount(1); // 设置行数
    table->setColumnCount(1); // 设置列数
    QPixmap pixmap;
    pixmap.convertFromImage(image);
    //QLabel *label=new QLabel();
    ui->label->setPixmap(pixmap);
    ui->label->setFixedSize(200,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

