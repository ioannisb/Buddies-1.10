#include "chat.h"
#include "buddies.h"
#include "ui_buddies.h"
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
#include <QTextStream>
#include <QFile>
#include <QDateTime>

using namespace std;


/*---------------------------------------------------------------------------------------------*/

Chat::Chat(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	QTimer * counter = new QTimer( this );
	    connect( counter, SIGNAL(timeout()),
		             this, SLOT(messageboard()) );
		counter->start( 1000 );

#if debug
		qDebug("Starting timer 5sec interval...");
#endif

}

/*---------------------------------------------------------------------------------------------*/


Chat::~Chat()
{

}


/*---------------------------------------------------------------------------------------------*/

void Chat::addMessage()
{
	//--get msg

	ui.listWidget->clear();

	QDateTime  dt = QDateTime::currentDateTime();

	QString  datetime = dt.toString("hh:mm:ss ");


	ui.NickLineEdit->text();

	QString nic = ui.NickLineEdit->text();

	if (ui.NickLineEdit->text().isEmpty()){

			QMessageBox::warning(this, tr("Nickname field"),
				  		                         "Please fill up a nickname");
			return;
	}

	//QString lastnic = datetime + nic + seperator ;

	ui.lineEdit->text();

	QString msg = ui.lineEdit->text();

	//--write msg

	QSqlQuery query;

	query.exec("INSERT INTO b_chat(b_id, b_user, b_time, b_message)VALUES('', '"+nic+"', '"+datetime+"', '"+msg+"')");

	ui.lineEdit->clear();

	if (!query.isActive())
	    QMessageBox::warning(this, tr("Database Error"),
	  		                         query.lastError().text());


}

/*---------------------------------------------------------------------------------------------*/

void Chat::messageboard()
{

	qDebug("=> Chat counter");

	ui.listWidget->clear();

	//ui.listWidget->addItem("Buddies Chat...");

	QString seperator = "=> ";

	QString left = "(";
	QString right = ") ";



	QDateTime  dt = QDateTime::currentDateTime();

	QString  datetime = dt.toString("hh:mm:ss ");

	QSqlQuery query1;

	query1.exec("select b_user, b_message, b_time from b_chat ORDER BY b_id DESC LIMIT 15;");


	while (query1.next())
	{

	QString nicchat = query1.value(0).toString();
	QString msgchat = query1.value(1).toString();
	QString time = query1.value(2).toString();


	QString full = left + time + right + nicchat + seperator + msgchat;

	QListWidgetItem *item = new QListWidgetItem(tr(full));


	ui.listWidget->addItem(item);


	}



}
/*---------------------------------------------------------------------------------------------*/
