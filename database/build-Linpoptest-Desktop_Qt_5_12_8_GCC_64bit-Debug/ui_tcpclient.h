/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPClient
{
public:
    QPushButton *pushButton_input;
    QTextEdit *textEdit_input;
    QPushButton *pushButton_close;
    QTextBrowser *textBrowser_output;

    void setupUi(QWidget *TCPClient)
    {
        if (TCPClient->objectName().isEmpty())
            TCPClient->setObjectName(QString::fromUtf8("TCPClient"));
        TCPClient->resize(789, 563);
        pushButton_input = new QPushButton(TCPClient);
        pushButton_input->setObjectName(QString::fromUtf8("pushButton_input"));
        pushButton_input->setGeometry(QRect(380, 420, 89, 25));
        textEdit_input = new QTextEdit(TCPClient);
        textEdit_input->setObjectName(QString::fromUtf8("textEdit_input"));
        textEdit_input->setGeometry(QRect(140, 270, 331, 91));
        pushButton_close = new QPushButton(TCPClient);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(140, 420, 89, 25));
        textBrowser_output = new QTextBrowser(TCPClient);
        textBrowser_output->setObjectName(QString::fromUtf8("textBrowser_output"));
        textBrowser_output->setGeometry(QRect(140, 30, 331, 192));

        retranslateUi(TCPClient);

        QMetaObject::connectSlotsByName(TCPClient);
    } // setupUi

    void retranslateUi(QWidget *TCPClient)
    {
        TCPClient->setWindowTitle(QApplication::translate("TCPClient", "Form", nullptr));
        pushButton_input->setText(QApplication::translate("TCPClient", "send", nullptr));
        pushButton_close->setText(QApplication::translate("TCPClient", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPClient: public Ui_TCPClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
