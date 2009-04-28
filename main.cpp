#include "buddies.h"

#include <QtGui>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenuBar>
#include <QtSql>
#include <QPixmap>
#include <QSqlError>
#include <QSqlDatabase>




int createConnection (){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("Buddies");
        db.setUserName("bud");     //αλλάξτε αυτά τα στοιχεία με τα δικά σας!
        db.setPassword("1234567890");
        bool ok = db.open();
        if (!ok) {
                qDebug()<<"Warning. Can't open DB. Aborting...";
                return false;
        }
        return ok;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!createConnection())
                    return 1;


    Buddies w;
    w.show();

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
                QMessageBox::critical(0, QObject::tr("Systray"),
                                      QObject::tr("I couldn't detect any system tray "
                                                  "on this system."));
                return 1;
    }

    return a.exec();
}
