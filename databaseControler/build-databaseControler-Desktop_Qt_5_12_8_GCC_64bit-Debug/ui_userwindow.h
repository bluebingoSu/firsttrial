/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton_show;
    QPushButton *pushButton_return;
    QLabel *label_id;
    QLabel *label_name;
    QLabel *label_password;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_add;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_select;
    QPushButton *pushButton_alterName;

    void setupUi(QWidget *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(1106, 520);
        tableWidget = new QTableWidget(UserWindow);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(90, 50, 871, 192));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        pushButton_show = new QPushButton(UserWindow);
        pushButton_show->setObjectName(QString::fromUtf8("pushButton_show"));
        pushButton_show->setGeometry(QRect(90, 260, 89, 25));
        pushButton_return = new QPushButton(UserWindow);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(90, 20, 89, 25));
        label_id = new QLabel(UserWindow);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setGeometry(QRect(100, 320, 67, 17));
        label_name = new QLabel(UserWindow);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(100, 350, 67, 17));
        label_password = new QLabel(UserWindow);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(100, 380, 67, 17));
        lineEdit_id = new QLineEdit(UserWindow);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(190, 320, 113, 25));
        lineEdit_name = new QLineEdit(UserWindow);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(190, 350, 113, 25));
        lineEdit_password = new QLineEdit(UserWindow);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(190, 380, 113, 25));
        pushButton_add = new QPushButton(UserWindow);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(90, 430, 89, 25));
        pushButton_clear = new QPushButton(UserWindow);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(260, 430, 89, 25));
        pushButton_select = new QPushButton(UserWindow);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));
        pushButton_select->setGeometry(QRect(440, 430, 89, 25));
        pushButton_alterName = new QPushButton(UserWindow);
        pushButton_alterName->setObjectName(QString::fromUtf8("pushButton_alterName"));
        pushButton_alterName->setGeometry(QRect(620, 430, 89, 25));
#ifndef QT_NO_SHORTCUT
        label_id->setBuddy(lineEdit_id);
        label_name->setBuddy(lineEdit_name);
        label_password->setBuddy(lineEdit_password);
#endif // QT_NO_SHORTCUT

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QWidget *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "Form", nullptr));
        pushButton_show->setText(QApplication::translate("UserWindow", "show", nullptr));
        pushButton_return->setText(QApplication::translate("UserWindow", "return", nullptr));
        label_id->setText(QApplication::translate("UserWindow", "id", nullptr));
        label_name->setText(QApplication::translate("UserWindow", "name", nullptr));
        label_password->setText(QApplication::translate("UserWindow", "password", nullptr));
        pushButton_add->setText(QApplication::translate("UserWindow", "add", nullptr));
        pushButton_clear->setText(QApplication::translate("UserWindow", "clear", nullptr));
        pushButton_select->setText(QApplication::translate("UserWindow", "select", nullptr));
        pushButton_alterName->setText(QApplication::translate("UserWindow", "alter name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
