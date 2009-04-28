/********************************************************************************
** Form generated from reading ui file 'wall.ui'
**
** Created: Tue Apr 28 11:17:41 2009
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WALL_H
#define UI_WALL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_WallClass
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEditWall;

    void setupUi(QDialog *WallClass)
    {
    if (WallClass->objectName().isEmpty())
        WallClass->setObjectName(QString::fromUtf8("WallClass"));
    WallClass->resize(470, 360);
    gridLayout = new QGridLayout(WallClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    listWidget = new QListWidget(WallClass);
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setProperty("isWrapping", QVariant(true));
    listWidget->setWordWrap(true);

    gridLayout->addWidget(listWidget, 0, 0, 1, 4);

    label = new QLabel(WallClass);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 1, 0, 1, 1);

    lineEditWall = new QLineEdit(WallClass);
    lineEditWall->setObjectName(QString::fromUtf8("lineEditWall"));

    gridLayout->addWidget(lineEditWall, 1, 1, 1, 3);

    label->setBuddy(lineEditWall);

    retranslateUi(WallClass);
    QObject::connect(lineEditWall, SIGNAL(returnPressed()), WallClass, SLOT(send()));

    QMetaObject::connectSlotsByName(WallClass);
    } // setupUi

    void retranslateUi(QDialog *WallClass)
    {
    WallClass->setWindowTitle(QApplication::translate("WallClass", "Wall", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("WallClass", "Write on the Wall: ", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(WallClass);
    } // retranslateUi

};

namespace Ui {
    class WallClass: public Ui_WallClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WALL_H
