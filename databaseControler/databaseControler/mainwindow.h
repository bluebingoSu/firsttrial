#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ServerDataBase;
class UserWindow;
class MessageWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    ServerDataBase *serverDataBase;
    UserWindow *userWindow;
    MessageWindow *messageWindow;
};
#endif // MAINWINDOW_H
