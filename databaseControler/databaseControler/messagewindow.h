#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QWidget>

class ServerDataBase;

namespace Ui {
class MessageWindow;
}

class MessageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MessageWindow(QWidget *parent = nullptr);
    ~MessageWindow();

private:
    Ui::MessageWindow *ui;
    ServerDataBase *serverDataBase;

signals:
    void returnMain();//返回信号

private slots:
    void showMessage();//展示全部消息
    void showMessageOne(QString idReceiver);//展示一人消息
};

#endif // MESSAGEWINDOW_H
