/********************************************************************************
** Form generated from reading ui file 'chat.ui'
**
** Created: Mon Apr 27 12:46:45 2009
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ChatClass
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLineEdit *NickLineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *ChatClass)
    {
    if (ChatClass->objectName().isEmpty())
        ChatClass->setObjectName(QString::fromUtf8("ChatClass"));
    ChatClass->resize(569, 395);
    gridLayout = new QGridLayout(ChatClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    listWidget = new QListWidget(ChatClass);
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setAutoScroll(true);
    listWidget->setAutoScrollMargin(5);
    listWidget->setProperty("isWrapping", QVariant(false));
    listWidget->setWordWrap(true);
    listWidget->setSortingEnabled(false);

    gridLayout->addWidget(listWidget, 0, 0, 1, 3);

    NickLineEdit = new QLineEdit(ChatClass);
    NickLineEdit->setObjectName(QString::fromUtf8("NickLineEdit"));

    gridLayout->addWidget(NickLineEdit, 1, 1, 1, 1);

    horizontalSpacer = new QSpacerItem(163, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

    lineEdit = new QLineEdit(ChatClass);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 2, 1, 1, 2);

    label_2 = new QLabel(ChatClass);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 2, 0, 1, 1);

    label = new QLabel(ChatClass);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 1, 0, 1, 1);


    retranslateUi(ChatClass);
    QObject::connect(lineEdit, SIGNAL(returnPressed()), ChatClass, SLOT(addMessage()));

    QMetaObject::connectSlotsByName(ChatClass);
    } // setupUi

    void retranslateUi(QDialog *ChatClass)
    {
    ChatClass->setWindowTitle(QApplication::translate("ChatClass", "Team Chat", 0, QApplication::UnicodeUTF8));
    NickLineEdit->setText(QString());
    label_2->setText(QApplication::translate("ChatClass", "Message:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("ChatClass", "Nickname:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ChatClass);
    } // retranslateUi

};

namespace Ui {
    class ChatClass: public Ui_ChatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
