#ifndef NOTES_H
#define NOTES_H

#include <QtGui/QDialog>
#include "ui_notes.h"
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QtGui>
#include <QStatusBar>
#include <QMessageBox>
#include <QProcess>
#include <QtSql>
#include <QTimer>
#include <QListWidget>
#include "chat.h"
#include <QHostInfo>
#include <QNetworkInterface>



class Notes : public QDialog
{
    Q_OBJECT

public:
    Notes(QWidget *parent = 0);
    ~Notes();

    Ui::NotesClass ui;


public slots:
	void addNotes();
	void showNotes();
private:

};

#endif // NOTES_H
