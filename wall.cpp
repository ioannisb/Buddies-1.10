#include "wall.h"
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


/*---------------------------------------------------------------------------------------------*/
Wall::Wall(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	QTimer * counter = new QTimer( this );
		    connect( counter, SIGNAL(timeout()),
			             this, SLOT(wallreload()) );
			counter->start( 1000 );


}

/*---------------------------------------------------------------------------------------------*/

Wall::~Wall()
{

}


/*---------------------------------------------------------------------------------------------*/

void Wall::send()
{

	//--get msg

		ui.listWidget->clear();

		QDateTime  dt = QDateTime::currentDateTime();

		QString  datetime = dt.toString("dd/MM/yyyy hh:mm:ss ");



		ui.lineEditWall->text();

		QString wallmsg = ui.lineEditWall->text();

		//--write msg

		QSqlQuery query;

		query.exec("INSERT INTO b_wall(b_id, b_message, b_time)VALUES('', '"+wallmsg+"', '"+datetime+"')");

		ui.lineEditWall->clear();

		if (!query.isActive())
		    QMessageBox::warning(this, tr("Database Error"),
		  		                         query.lastError().text());




}

/*---------------------------------------------------------------------------------------------*/


void Wall::wallreload()
{


	qDebug("=> Wall counter");

		ui.listWidget->clear();

		//ui.listWidget->addItem("Buddies Chat...");

		QString seperator = "=> ";

		QString left = "(";
		QString right = ") ";



		QDateTime  dt = QDateTime::currentDateTime();

		QString  datetime = dt.toString("hh:mm:ss ");

		QSqlQuery query1;

		query1.exec("select b_time, b_message from b_wall ORDER BY b_id DESC LIMIT 15;");


		while (query1.next())
		{

		QString time = query1.value(0).toString();
		QString message = query1.value(1).toString();


		QString hr = "<->";


		QString full = left + time + right + message;

		QListWidgetItem *item = new QListWidgetItem(tr(full));

		ui.listWidget->addItem(hr);
		ui.listWidget->addItem(item);


		}



}

/*---------------------------------------------------------------------------------------------*/

