/********************************************************************************
** Form generated from reading ui file 'notes.ui'
**
** Created: Mon Apr 27 12:46:45 2009
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NOTES_H
#define UI_NOTES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NotesClass
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonView;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *labelUser;
    QPushButton *pushButtonNew;

    void setupUi(QDialog *NotesClass)
    {
    if (NotesClass->objectName().isEmpty())
        NotesClass->setObjectName(QString::fromUtf8("NotesClass"));
    NotesClass->resize(400, 300);
    QPalette palette;
    QBrush brush(QColor(255, 232, 101, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush);
    QBrush brush1(QColor(255, 255, 255, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette.setBrush(QPalette::Active, QPalette::Window, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
    NotesClass->setPalette(palette);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/Pin.png")), QIcon::Normal, QIcon::Off);
    NotesClass->setWindowIcon(icon);
    gridLayout = new QGridLayout(NotesClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    textEdit = new QTextEdit(NotesClass);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    QPalette palette1;
    palette1.setBrush(QPalette::Active, QPalette::Base, brush);
    palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
    QBrush brush2(QColor(246, 246, 246, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
    textEdit->setPalette(palette1);
    textEdit->setFrameShape(QFrame::HLine);

    gridLayout->addWidget(textEdit, 1, 0, 1, 5);

    horizontalSpacer = new QSpacerItem(121, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 2, 0, 1, 2);

    pushButtonView = new QPushButton(NotesClass);
    pushButtonView->setObjectName(QString::fromUtf8("pushButtonView"));

    gridLayout->addWidget(pushButtonView, 2, 2, 1, 1);

    pushButton = new QPushButton(NotesClass);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout->addWidget(pushButton, 2, 4, 1, 1);

    label = new QLabel(NotesClass);
    label->setObjectName(QString::fromUtf8("label"));
    label->setPixmap(QPixmap(QString::fromUtf8(":/images/Pin.png")));

    gridLayout->addWidget(label, 0, 4, 1, 1);

    label_2 = new QLabel(NotesClass);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 0, 0, 1, 1);

    labelUser = new QLabel(NotesClass);
    labelUser->setObjectName(QString::fromUtf8("labelUser"));
    labelUser->setFrameShape(QFrame::NoFrame);

    gridLayout->addWidget(labelUser, 0, 1, 1, 3);

    pushButtonNew = new QPushButton(NotesClass);
    pushButtonNew->setObjectName(QString::fromUtf8("pushButtonNew"));

    gridLayout->addWidget(pushButtonNew, 2, 3, 1, 1);


    retranslateUi(NotesClass);
    QObject::connect(pushButton, SIGNAL(clicked()), NotesClass, SLOT(addNotes()));
    QObject::connect(pushButtonView, SIGNAL(clicked()), NotesClass, SLOT(showNotes()));
    QObject::connect(pushButtonNew, SIGNAL(clicked()), textEdit, SLOT(clear()));

    QMetaObject::connectSlotsByName(NotesClass);
    } // setupUi

    void retranslateUi(QDialog *NotesClass)
    {
    NotesClass->setWindowTitle(QApplication::translate("NotesClass", "Notes", 0, QApplication::UnicodeUTF8));
    pushButtonView->setText(QApplication::translate("NotesClass", "View Notes", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("NotesClass", "Add note", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("NotesClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/Pin.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("NotesClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#ce481f;\">My Notes:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    labelUser->setText(QString());
    pushButtonNew->setText(QApplication::translate("NotesClass", "New Note", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(NotesClass);
    } // retranslateUi

};

namespace Ui {
    class NotesClass: public Ui_NotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTES_H
