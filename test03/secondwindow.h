#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class secondWindow; }
QT_END_NAMESPACE

class secondWindow : public QMainWindow
{
    Q_OBJECT
public:
    secondWindow(QWidget *parent = nullptr);
    ~secondWindow();
    void loadHistory();

private slots:
    void on_textBrowser_historyout_textChanged();

private:
    Ui::secondWindow *ui;
};

#endif // SECONDWINDOW_H
