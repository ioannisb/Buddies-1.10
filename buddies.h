#ifndef BUDDIES_H
#define BUDDIES_H

#include <QtGui/QMainWindow>
#include "ui_buddies.h"
#include "chat.h"

#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QtSql>
#include <QStatusBar>


class QAction;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;
class QSpinBox;
class QTextEdit;

#include "ui_chat.h"

class Chat;

class Buddies : public QMainWindow
{
    Q_OBJECT

public:
    Buddies(QWidget *parent = 0);
    ~Buddies();

    void setVisible(bool visible);
    bool initDB ();
    void initModel( QSqlTableModel *model, QString);

    Ui::BuddiesClass ui;

public slots:
	void countOnlineUsers();
	void setUserStatus();
	void loginUser();
	void loginCurrentStatus();
	void validateUser();
	void stopifNotConnected();
	void myexit();
	void focusTabEdit();
	void structUser();
	void startChat();
	void helpAbout();
	void getSysInfo();
	void onlineNotify();
	void WriteOnWall();
	void Information();
	void dbstatus();
	void openNotes();


protected:
     void closeEvent(QCloseEvent *event);

private slots:

    void setIcon(int index);
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void messageClicked();
    void showMessage();

private:
    QStatusBar *statusbar;
    QLabel *labelimagestatus;
    QLineEdit *lineEditLogin;

    void createIconGroupBox();
    // void createMessageGroupBox();
    void createTrayIcon();
    void createActions();


//  QGroupBox *messageGroupBox;
    QComboBox *iconComboBox;
//  QComboBox *typeComboBox;
//  QLabel *iconLabel;
//  QLineEdit *titleEdit;
//  QTextEdit *bodyEdit;
//  QSpinBox *durationSpinBox;
//  QGroupBox *iconGroupBox;
//  QCheckBox *showIconCheckBox;

    QLineEdit *lineEditIP;
    QLineEdit *lineEditHost;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;


    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    QSqlTableModel model;
    QString filter;
    QSqlQuery query;
    QListWidget *listWidget;
    QListWidgetItem *item;

};

#endif // BUDDIES_H
