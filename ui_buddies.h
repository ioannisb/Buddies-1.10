/********************************************************************************
** Form generated from reading ui file 'buddies.ui'
**
** Created: Mon Apr 27 13:59:26 2009
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_BUDDIES_H
#define UI_BUDDIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuddiesClass
{
public:
    QAction *action_Credits;
    QAction *action_Exit;
    QAction *actionChat;
    QAction *action_Exit_2;
    QAction *actionEdit;
    QAction *action_Configure;
    QAction *actionBoard;
    QAction *actionNotes;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *labelLogin;
    QLineEdit *lineEditLogin;
    QLabel *labelPasswd;
    QLineEdit *lineEditPasswd;
    QLabel *StatusLabel;
    QCommandLinkButton *commandLinkButton;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_5;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *labelDuration;
    QSpinBox *durationSpinBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QLabel *labelIP;
    QLineEdit *lineEditIP;
    QLabel *labelHostname;
    QLineEdit *lineEditHost;
    QGroupBox *groupBoxDbStatus;
    QGridLayout *gridLayout_9;
    QLabel *labelDbStatus;
    QLabel *labelimageStatus;
    QLabel *label;
    QComboBox *iconComboBox;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_About;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *BuddiesClass)
    {
    if (BuddiesClass->objectName().isEmpty())
        BuddiesClass->setObjectName(QString::fromUtf8("BuddiesClass"));
    BuddiesClass->resize(299, 535);
    action_Credits = new QAction(BuddiesClass);
    action_Credits->setObjectName(QString::fromUtf8("action_Credits"));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/Welcome.png")), QIcon::Normal, QIcon::Off);
    action_Credits->setIcon(icon);
    action_Exit = new QAction(BuddiesClass);
    action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/Exit.png")), QIcon::Normal, QIcon::Off);
    action_Exit->setIcon(icon1);
    actionChat = new QAction(BuddiesClass);
    actionChat->setObjectName(QString::fromUtf8("actionChat"));
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/Chat.png")), QIcon::Normal, QIcon::Off);
    actionChat->setIcon(icon2);
    action_Exit_2 = new QAction(BuddiesClass);
    action_Exit_2->setObjectName(QString::fromUtf8("action_Exit_2"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/images/Disconnect.png")), QIcon::Normal, QIcon::Off);
    action_Exit_2->setIcon(icon3);
    actionEdit = new QAction(BuddiesClass);
    actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/images/Options.png")), QIcon::Normal, QIcon::Off);
    actionEdit->setIcon(icon4);
    action_Configure = new QAction(BuddiesClass);
    action_Configure->setObjectName(QString::fromUtf8("action_Configure"));
    action_Configure->setIcon(icon4);
    actionBoard = new QAction(BuddiesClass);
    actionBoard->setObjectName(QString::fromUtf8("actionBoard"));
    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/images/Bubbles.png")), QIcon::Normal, QIcon::Off);
    actionBoard->setIcon(icon5);
    actionNotes = new QAction(BuddiesClass);
    actionNotes->setObjectName(QString::fromUtf8("actionNotes"));
    QIcon icon6;
    icon6.addPixmap(QPixmap(QString::fromUtf8(":/images/Pin.png")), QIcon::Normal, QIcon::Off);
    actionNotes->setIcon(icon6);
    centralwidget = new QWidget(BuddiesClass);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setTabPosition(QTabWidget::North);
    tabWidget->setTabShape(QTabWidget::Rounded);
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    gridLayout_4 = new QGridLayout(tab_3);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    label_2 = new QLabel(tab_3);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/Logo.png")));

    gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

    groupBox = new QGroupBox(tab_3);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setAutoFillBackground(true);
    groupBox->setFlat(true);
    groupBox->setCheckable(false);
    gridLayout_3 = new QGridLayout(groupBox);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    labelLogin = new QLabel(groupBox);
    labelLogin->setObjectName(QString::fromUtf8("labelLogin"));

    gridLayout_3->addWidget(labelLogin, 1, 0, 1, 1);

    lineEditLogin = new QLineEdit(groupBox);
    lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));

    gridLayout_3->addWidget(lineEditLogin, 1, 1, 1, 1);

    labelPasswd = new QLabel(groupBox);
    labelPasswd->setObjectName(QString::fromUtf8("labelPasswd"));

    gridLayout_3->addWidget(labelPasswd, 2, 0, 1, 1);

    lineEditPasswd = new QLineEdit(groupBox);
    lineEditPasswd->setObjectName(QString::fromUtf8("lineEditPasswd"));
    lineEditPasswd->setEchoMode(QLineEdit::Password);

    gridLayout_3->addWidget(lineEditPasswd, 2, 1, 1, 1);

    StatusLabel = new QLabel(groupBox);
    StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));
    StatusLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/Error.png")));
    StatusLabel->setAlignment(Qt::AlignCenter);

    gridLayout_3->addWidget(StatusLabel, 3, 0, 1, 1);

    commandLinkButton = new QCommandLinkButton(groupBox);
    commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));

    gridLayout_3->addWidget(commandLinkButton, 3, 1, 1, 1);

    horizontalSpacer = new QSpacerItem(169, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);


    gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

    QIcon icon7;
    icon7.addPixmap(QPixmap(QString::fromUtf8(":/images/Usergroup.png")), QIcon::Normal, QIcon::Off);
    tabWidget->addTab(tab_3, icon7, QString());
    tab_5 = new QWidget();
    tab_5->setObjectName(QString::fromUtf8("tab_5"));
    gridLayout_2 = new QGridLayout(tab_5);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    listWidget = new QListWidget(tab_5);
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

    gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);

    QIcon icon8;
    icon8.addPixmap(QPixmap(QString::fromUtf8(":/images/Man.png")), QIcon::Normal, QIcon::Off);
    tabWidget->addTab(tab_5, icon8, QString());
    tab_4 = new QWidget();
    tab_4->setObjectName(QString::fromUtf8("tab_4"));
    gridLayout_6 = new QGridLayout(tab_4);
    gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
    groupBox_2 = new QGroupBox(tab_4);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout_5 = new QGridLayout(groupBox_2);
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
    labelDuration = new QLabel(groupBox_2);
    labelDuration->setObjectName(QString::fromUtf8("labelDuration"));

    gridLayout_5->addWidget(labelDuration, 0, 0, 1, 1);

    durationSpinBox = new QSpinBox(groupBox_2);
    durationSpinBox->setObjectName(QString::fromUtf8("durationSpinBox"));
    durationSpinBox->setValue(15);

    gridLayout_5->addWidget(durationSpinBox, 0, 1, 1, 1);


    gridLayout_6->addWidget(groupBox_2, 0, 0, 1, 1);

    groupBox_3 = new QGroupBox(tab_4);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    gridLayout_8 = new QGridLayout(groupBox_3);
    gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
    gridLayout_7 = new QGridLayout();
    gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
    labelIP = new QLabel(groupBox_3);
    labelIP->setObjectName(QString::fromUtf8("labelIP"));

    gridLayout_7->addWidget(labelIP, 0, 0, 1, 1);

    lineEditIP = new QLineEdit(groupBox_3);
    lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
    lineEditIP->setReadOnly(true);

    gridLayout_7->addWidget(lineEditIP, 0, 1, 1, 1);

    labelHostname = new QLabel(groupBox_3);
    labelHostname->setObjectName(QString::fromUtf8("labelHostname"));

    gridLayout_7->addWidget(labelHostname, 1, 0, 1, 1);

    lineEditHost = new QLineEdit(groupBox_3);
    lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));
    lineEditHost->setReadOnly(true);

    gridLayout_7->addWidget(lineEditHost, 1, 1, 1, 1);


    gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


    gridLayout_6->addWidget(groupBox_3, 2, 0, 1, 1);

    groupBoxDbStatus = new QGroupBox(tab_4);
    groupBoxDbStatus->setObjectName(QString::fromUtf8("groupBoxDbStatus"));
    gridLayout_9 = new QGridLayout(groupBoxDbStatus);
    gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
    labelDbStatus = new QLabel(groupBoxDbStatus);
    labelDbStatus->setObjectName(QString::fromUtf8("labelDbStatus"));

    gridLayout_9->addWidget(labelDbStatus, 0, 0, 1, 1);

    labelimageStatus = new QLabel(groupBoxDbStatus);
    labelimageStatus->setObjectName(QString::fromUtf8("labelimageStatus"));
    labelimageStatus->setAlignment(Qt::AlignCenter);

    gridLayout_9->addWidget(labelimageStatus, 0, 1, 1, 1);


    gridLayout_6->addWidget(groupBoxDbStatus, 1, 0, 1, 1);

    tabWidget->addTab(tab_4, icon4, QString());

    gridLayout->addWidget(tabWidget, 0, 0, 1, 2);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 1, 0, 1, 1);

    iconComboBox = new QComboBox(centralwidget);
    iconComboBox->setObjectName(QString::fromUtf8("iconComboBox"));

    gridLayout->addWidget(iconComboBox, 1, 1, 1, 1);

    BuddiesClass->setCentralWidget(centralwidget);
    menubar = new QMenuBar(BuddiesClass);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 299, 24));
    menu_File = new QMenu(menubar);
    menu_File->setObjectName(QString::fromUtf8("menu_File"));
    menu_Edit = new QMenu(menubar);
    menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
    menu_About = new QMenu(menubar);
    menu_About->setObjectName(QString::fromUtf8("menu_About"));
    BuddiesClass->setMenuBar(menubar);
    statusbar = new QStatusBar(BuddiesClass);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    BuddiesClass->setStatusBar(statusbar);
    toolBar = new QToolBar(BuddiesClass);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    BuddiesClass->addToolBar(Qt::BottomToolBarArea, toolBar);
    labelLogin->setBuddy(lineEditLogin);
    labelPasswd->setBuddy(lineEditPasswd);
    labelDuration->setBuddy(durationSpinBox);
    labelIP->setBuddy(lineEditIP);
    labelHostname->setBuddy(lineEditHost);
    label->setBuddy(iconComboBox);

    menubar->addAction(menu_File->menuAction());
    menubar->addAction(menu_Edit->menuAction());
    menubar->addAction(menu_About->menuAction());
    menu_File->addAction(action_Exit_2);
    menu_File->addAction(action_Exit);
    menu_Edit->addAction(action_Configure);
    menu_About->addAction(action_Credits);
    toolBar->addAction(actionChat);
    toolBar->addSeparator();
    toolBar->addAction(actionEdit);
    toolBar->addSeparator();
    toolBar->addAction(actionBoard);
    toolBar->addSeparator();
    toolBar->addAction(actionNotes);

    retranslateUi(BuddiesClass);
    QObject::connect(commandLinkButton, SIGNAL(clicked()), BuddiesClass, SLOT(loginUser()));
    QObject::connect(lineEditPasswd, SIGNAL(returnPressed()), BuddiesClass, SLOT(loginUser()));
    QObject::connect(action_Exit, SIGNAL(activated()), BuddiesClass, SLOT(myexit()));
    QObject::connect(action_Exit_2, SIGNAL(activated()), BuddiesClass, SLOT(myexit()));
    QObject::connect(actionEdit, SIGNAL(activated()), BuddiesClass, SLOT(focusTabEdit()));
    QObject::connect(actionChat, SIGNAL(activated()), BuddiesClass, SLOT(startChat()));
    QObject::connect(action_Credits, SIGNAL(activated()), BuddiesClass, SLOT(helpAbout()));
    QObject::connect(action_Configure, SIGNAL(activated()), BuddiesClass, SLOT(focusTabEdit()));
    QObject::connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), BuddiesClass, SLOT(startChat()));
    QObject::connect(actionBoard, SIGNAL(activated()), BuddiesClass, SLOT(WriteOnWall()));
    QObject::connect(actionNotes, SIGNAL(activated()), BuddiesClass, SLOT(openNotes()));

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(BuddiesClass);
    } // setupUi

    void retranslateUi(QMainWindow *BuddiesClass)
    {
    BuddiesClass->setWindowTitle(QApplication::translate("BuddiesClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    action_Credits->setText(QApplication::translate("BuddiesClass", "&Credits", 0, QApplication::UnicodeUTF8));
    action_Exit->setText(QApplication::translate("BuddiesClass", "&Exit", 0, QApplication::UnicodeUTF8));
    actionChat->setText(QApplication::translate("BuddiesClass", "chat", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    actionChat->setToolTip(QApplication::translate("BuddiesClass", "Team Chat", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    action_Exit_2->setText(QApplication::translate("BuddiesClass", "&Disconnect", 0, QApplication::UnicodeUTF8));
    actionEdit->setText(QApplication::translate("BuddiesClass", "Edit", 0, QApplication::UnicodeUTF8));
    action_Configure->setText(QApplication::translate("BuddiesClass", "&Configure", 0, QApplication::UnicodeUTF8));
    actionBoard->setText(QApplication::translate("BuddiesClass", "Board", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    actionBoard->setToolTip(QApplication::translate("BuddiesClass", "Wall", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    actionNotes->setText(QApplication::translate("BuddiesClass", "Notes", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    actionNotes->setToolTip(QApplication::translate("BuddiesClass", "Notes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    label_2->setText(QString());
    groupBox->setTitle(QApplication::translate("BuddiesClass", "Buddies Network", 0, QApplication::UnicodeUTF8));
    labelLogin->setText(QApplication::translate("BuddiesClass", "Login:", 0, QApplication::UnicodeUTF8));
    labelPasswd->setText(QApplication::translate("BuddiesClass", "Password:", 0, QApplication::UnicodeUTF8));
    StatusLabel->setText(QString());
    commandLinkButton->setText(QApplication::translate("BuddiesClass", "Login", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("BuddiesClass", "(B)*", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("BuddiesClass", "Online", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("BuddiesClass", "Baloon Messages", 0, QApplication::UnicodeUTF8));
    labelDuration->setText(QApplication::translate("BuddiesClass", "Choose message duration:", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("BuddiesClass", "Information", 0, QApplication::UnicodeUTF8));
    labelIP->setText(QApplication::translate("BuddiesClass", "IP Address:", 0, QApplication::UnicodeUTF8));
    labelHostname->setText(QApplication::translate("BuddiesClass", "Hostname:", 0, QApplication::UnicodeUTF8));
    groupBoxDbStatus->setTitle(QApplication::translate("BuddiesClass", "Database status", 0, QApplication::UnicodeUTF8));
    labelDbStatus->setText(QApplication::translate("BuddiesClass", "Buddies Database:", 0, QApplication::UnicodeUTF8));
    labelimageStatus->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("BuddiesClass", "Edit", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("BuddiesClass", "Status:", 0, QApplication::UnicodeUTF8));
    menu_File->setTitle(QApplication::translate("BuddiesClass", "&File", 0, QApplication::UnicodeUTF8));
    menu_Edit->setTitle(QApplication::translate("BuddiesClass", "&Edit", 0, QApplication::UnicodeUTF8));
    menu_About->setTitle(QApplication::translate("BuddiesClass", "&About", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("BuddiesClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BuddiesClass: public Ui_BuddiesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDDIES_H
