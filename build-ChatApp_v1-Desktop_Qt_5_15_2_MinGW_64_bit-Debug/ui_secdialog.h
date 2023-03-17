/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *clock_label;
    QLabel *dateTime_label;
    QTextBrowser *messageBrowser;
    QTextEdit *messageBox;
    QPushButton *sendButton;
    QLabel *label_off_or_online;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(927, 507);
        layoutWidget = new QWidget(SecDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 410, 161, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        clock_label = new QLabel(layoutWidget);
        clock_label->setObjectName(QString::fromUtf8("clock_label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        clock_label->setFont(font);

        verticalLayout->addWidget(clock_label);

        dateTime_label = new QLabel(layoutWidget);
        dateTime_label->setObjectName(QString::fromUtf8("dateTime_label"));
        dateTime_label->setFont(font);

        verticalLayout->addWidget(dateTime_label);

        messageBrowser = new QTextBrowser(SecDialog);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));
        messageBrowser->setGeometry(QRect(270, 20, 611, 371));
        messageBox = new QTextEdit(SecDialog);
        messageBox->setObjectName(QString::fromUtf8("messageBox"));
        messageBox->setGeometry(QRect(270, 400, 511, 70));
        sendButton = new QPushButton(SecDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(790, 400, 91, 71));
        label_off_or_online = new QLabel(SecDialog);
        label_off_or_online->setObjectName(QString::fromUtf8("label_off_or_online"));
        label_off_or_online->setGeometry(QRect(60, 340, 159, 62));
        label_off_or_online->setFont(font);

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        clock_label->setText(QCoreApplication::translate("SecDialog", "Clock", nullptr));
        dateTime_label->setText(QCoreApplication::translate("SecDialog", "DateTime", nullptr));
        sendButton->setText(QCoreApplication::translate("SecDialog", "Send", nullptr));
        label_off_or_online->setText(QCoreApplication::translate("SecDialog", "Clock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
