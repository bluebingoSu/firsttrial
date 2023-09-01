/********************************************************************************
** Form generated from reading UI file 'messagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEWINDOW_H
#define UI_MESSAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageWindow
{
public:
    QLabel *label_idReceiver;
    QLineEdit *lineEdit_idSender;
    QPushButton *pushButton_return;
    QPushButton *pushButton_select;
    QPushButton *pushButton_add;
    QTableWidget *tableWidget;
    QPushButton *pushButton_show;
    QLabel *label_timestamp;
    QLineEdit *lineEdit_timestamp;
    QLineEdit *lineEdit_idReceiver;
    QLabel *label_idSender;
    QLabel *label_type;
    QLabel *label_data;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_data;

    void setupUi(QWidget *MessageWindow)
    {
        if (MessageWindow->objectName().isEmpty())
            MessageWindow->setObjectName(QString::fromUtf8("MessageWindow"));
        MessageWindow->resize(1077, 568);
        label_idReceiver = new QLabel(MessageWindow);
        label_idReceiver->setObjectName(QString::fromUtf8("label_idReceiver"));
        label_idReceiver->setGeometry(QRect(100, 350, 81, 17));
        lineEdit_idSender = new QLineEdit(MessageWindow);
        lineEdit_idSender->setObjectName(QString::fromUtf8("lineEdit_idSender"));
        lineEdit_idSender->setGeometry(QRect(190, 320, 113, 25));
        pushButton_return = new QPushButton(MessageWindow);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(90, 20, 89, 25));
        pushButton_select = new QPushButton(MessageWindow);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));
        pushButton_select->setGeometry(QRect(440, 430, 89, 25));
        pushButton_add = new QPushButton(MessageWindow);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(90, 430, 89, 25));
        tableWidget = new QTableWidget(MessageWindow);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(90, 50, 871, 192));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        pushButton_show = new QPushButton(MessageWindow);
        pushButton_show->setObjectName(QString::fromUtf8("pushButton_show"));
        pushButton_show->setGeometry(QRect(90, 260, 89, 25));
        label_timestamp = new QLabel(MessageWindow);
        label_timestamp->setObjectName(QString::fromUtf8("label_timestamp"));
        label_timestamp->setGeometry(QRect(100, 380, 81, 17));
        lineEdit_timestamp = new QLineEdit(MessageWindow);
        lineEdit_timestamp->setObjectName(QString::fromUtf8("lineEdit_timestamp"));
        lineEdit_timestamp->setGeometry(QRect(190, 380, 113, 25));
        lineEdit_idReceiver = new QLineEdit(MessageWindow);
        lineEdit_idReceiver->setObjectName(QString::fromUtf8("lineEdit_idReceiver"));
        lineEdit_idReceiver->setGeometry(QRect(190, 350, 113, 25));
        label_idSender = new QLabel(MessageWindow);
        label_idSender->setObjectName(QString::fromUtf8("label_idSender"));
        label_idSender->setGeometry(QRect(100, 320, 67, 17));
        label_type = new QLabel(MessageWindow);
        label_type->setObjectName(QString::fromUtf8("label_type"));
        label_type->setGeometry(QRect(380, 320, 67, 17));
        label_data = new QLabel(MessageWindow);
        label_data->setObjectName(QString::fromUtf8("label_data"));
        label_data->setGeometry(QRect(380, 350, 81, 17));
        lineEdit_type = new QLineEdit(MessageWindow);
        lineEdit_type->setObjectName(QString::fromUtf8("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(470, 320, 113, 25));
        lineEdit_data = new QLineEdit(MessageWindow);
        lineEdit_data->setObjectName(QString::fromUtf8("lineEdit_data"));
        lineEdit_data->setGeometry(QRect(470, 350, 113, 25));
#ifndef QT_NO_SHORTCUT
        label_idReceiver->setBuddy(lineEdit_idReceiver);
        label_timestamp->setBuddy(lineEdit_timestamp);
        label_idSender->setBuddy(lineEdit_idSender);
        label_type->setBuddy(lineEdit_type);
        label_data->setBuddy(lineEdit_data);
#endif // QT_NO_SHORTCUT

        retranslateUi(MessageWindow);

        QMetaObject::connectSlotsByName(MessageWindow);
    } // setupUi

    void retranslateUi(QWidget *MessageWindow)
    {
        MessageWindow->setWindowTitle(QApplication::translate("MessageWindow", "Form", nullptr));
        label_idReceiver->setText(QApplication::translate("MessageWindow", "idReceiver", nullptr));
        pushButton_return->setText(QApplication::translate("MessageWindow", "return", nullptr));
        pushButton_select->setText(QApplication::translate("MessageWindow", "select", nullptr));
        pushButton_add->setText(QApplication::translate("MessageWindow", "add", nullptr));
        pushButton_show->setText(QApplication::translate("MessageWindow", "show", nullptr));
        label_timestamp->setText(QApplication::translate("MessageWindow", "timestamp", nullptr));
        label_idSender->setText(QApplication::translate("MessageWindow", "idSender", nullptr));
        label_type->setText(QApplication::translate("MessageWindow", "type", nullptr));
        label_data->setText(QApplication::translate("MessageWindow", "data", nullptr));
        lineEdit_type->setText(QString());
        lineEdit_data->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MessageWindow: public Ui_MessageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEWINDOW_H
