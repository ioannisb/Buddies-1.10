#ifndef CHAT_H
#define CHAT_H

#include <QtGui/QDialog>
#include "ui_chat.h"
#include <QtSql>


class Buddies;

class Chat : public QDialog
{
    Q_OBJECT

public:
    Chat(QWidget *parent = 0);
    ~Chat();

    Ui::ChatClass ui;


public slots:
	void addMessage();
	void messageboard();


private:

    QSqlQuery query;




};

#endif // CHAT_H
