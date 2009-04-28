/********************************************************************************
** Form generated from reading ui file 'qSslChat.ui'
**
** Created: Mon Apr 27 15:00:48 2009
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QSSLCHAT_H
#define UI_QSSLCHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "cqtextedit.h"

QT_BEGIN_NAMESPACE

class Ui_qSslChat
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *hostLabel;
    QLineEdit *ipEdit;
    QLabel *portLabel;
    QSpinBox *portBox;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QPushButton *connectButton;
    QPushButton *hostButton;
    QPushButton *disconnectButton;
    cqtextedit *messageList;
    QHBoxLayout *horizontalLayout_2;
    QLabel *messageLabel;
    QLineEdit *msgEdit;
    QToolButton *cinfoButton;
    QToolButton *smileyButton;
    QPushButton *sendButton;

    void setupUi(QWidget *qSslChat)
    {
    if (qSslChat->objectName().isEmpty())
        qSslChat->setObjectName(QString::fromUtf8("qSslChat"));
    qSslChat->resize(1016, 688);
    verticalLayout_2 = new QVBoxLayout(qSslChat);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    hostLabel = new QLabel(qSslChat);
    hostLabel->setObjectName(QString::fromUtf8("hostLabel"));

    horizontalLayout->addWidget(hostLabel);

    ipEdit = new QLineEdit(qSslChat);
    ipEdit->setObjectName(QString::fromUtf8("ipEdit"));

    horizontalLayout->addWidget(ipEdit);

    portLabel = new QLabel(qSslChat);
    portLabel->setObjectName(QString::fromUtf8("portLabel"));

    horizontalLayout->addWidget(portLabel);

    portBox = new QSpinBox(qSslChat);
    portBox->setObjectName(QString::fromUtf8("portBox"));

    horizontalLayout->addWidget(portBox);

    nameLabel = new QLabel(qSslChat);
    nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

    horizontalLayout->addWidget(nameLabel);

    nameEdit = new QLineEdit(qSslChat);
    nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

    horizontalLayout->addWidget(nameEdit);

    connectButton = new QPushButton(qSslChat);
    connectButton->setObjectName(QString::fromUtf8("connectButton"));

    horizontalLayout->addWidget(connectButton);

    hostButton = new QPushButton(qSslChat);
    hostButton->setObjectName(QString::fromUtf8("hostButton"));

    horizontalLayout->addWidget(hostButton);

    disconnectButton = new QPushButton(qSslChat);
    disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));

    horizontalLayout->addWidget(disconnectButton);


    verticalLayout->addLayout(horizontalLayout);

    messageList = new cqtextedit(qSslChat);
    messageList->setObjectName(QString::fromUtf8("messageList"));

    verticalLayout->addWidget(messageList);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    messageLabel = new QLabel(qSslChat);
    messageLabel->setObjectName(QString::fromUtf8("messageLabel"));

    horizontalLayout_2->addWidget(messageLabel);

    msgEdit = new QLineEdit(qSslChat);
    msgEdit->setObjectName(QString::fromUtf8("msgEdit"));

    horizontalLayout_2->addWidget(msgEdit);

    cinfoButton = new QToolButton(qSslChat);
    cinfoButton->setObjectName(QString::fromUtf8("cinfoButton"));

    horizontalLayout_2->addWidget(cinfoButton);

    smileyButton = new QToolButton(qSslChat);
    smileyButton->setObjectName(QString::fromUtf8("smileyButton"));

    horizontalLayout_2->addWidget(smileyButton);

    sendButton = new QPushButton(qSslChat);
    sendButton->setObjectName(QString::fromUtf8("sendButton"));

    horizontalLayout_2->addWidget(sendButton);


    verticalLayout->addLayout(horizontalLayout_2);


    verticalLayout_2->addLayout(verticalLayout);


    retranslateUi(qSslChat);

    QMetaObject::connectSlotsByName(qSslChat);
    } // setupUi

    void retranslateUi(QWidget *qSslChat)
    {
    qSslChat->setWindowTitle(QApplication::translate("qSslChat", "Buddies SSL", 0, QApplication::UnicodeUTF8));
    hostLabel->setText(QApplication::translate("qSslChat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Host:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    portLabel->setText(QApplication::translate("qSslChat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Port:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    nameLabel->setText(QApplication::translate("qSslChat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Name:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    connectButton->setText(QApplication::translate("qSslChat", "Connect to host", 0, QApplication::UnicodeUTF8));
    hostButton->setText(QApplication::translate("qSslChat", "Host conversation", 0, QApplication::UnicodeUTF8));
    disconnectButton->setText(QApplication::translate("qSslChat", "Disconnect", 0, QApplication::UnicodeUTF8));
    messageLabel->setText(QApplication::translate("qSslChat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Message:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    cinfoButton->setText(QApplication::translate("qSslChat", "...", 0, QApplication::UnicodeUTF8));
    smileyButton->setText(QApplication::translate("qSslChat", "...", 0, QApplication::UnicodeUTF8));
    sendButton->setText(QApplication::translate("qSslChat", "Send", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(qSslChat);
    } // retranslateUi

};

namespace Ui {
    class qSslChat: public Ui_qSslChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSSLCHAT_H
