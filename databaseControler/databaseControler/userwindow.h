#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>

class ServerDataBase;

namespace Ui {
class UserWindow;
}

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private:
    Ui::UserWindow *ui;
    ServerDataBase *serverDataBase;

signals:
    void returnMain();//返回信号

private slots:
    void showTable();//展示全部用户
    void showTableOne(QString id);//展示一人
};

#endif // USERWINDOW_H
