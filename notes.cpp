#include "notes.h"
#include "buddies.h"
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



Notes::Notes(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

Notes::~Notes()
{

}

void Notes::addNotes()
{

	qDebug("=> Add Notes");

	QDateTime  dt2 = QDateTime::currentDateTime();
	QString  bdate = dt2.toString("dd/MM/yyyy hh:mm:ss");

	QString bnote = ui.textEdit->text();

	QSqlQuery query;



	QString buser = ui.labelUser->text();


	if (ui.labelUser->text().isEmpty())
	{
		QMessageBox::warning(this, tr("Login to Network"),
				    	   		             "Please login to Network first. ");
		return;
	}


	if (ui.textEdit->text().isEmpty())
		{
			QMessageBox::warning(this, tr("Empty Note"),
					    	   		             "Please add some content first. ");
			return;
		}

	QMessageBox msgBox;

	msgBox.setText("Do you relaly want to add this note?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	        switch (msgBox.exec()) {
	        case QMessageBox::Yes:
	        // yes was clicked
	        qDebug("=> Note accepted");
	        break;
	        case QMessageBox::No:
	        // no was clicked
	        return;
	        break;
	        default:
	        // should never be reached
	        break;
	        }

	query.exec("INSERT INTO b_notes(b_id, b_user, b_notes, b_date)VALUES('', '"+buser+"', '"+bnote+"', '"+bdate+"')");

	ui.textEdit->clear();

	if (!query.isActive())
	    QMessageBox::warning(this, tr("Database Error"),
		  		                         query.lastError().text());


}


void Notes::showNotes()
{
	qDebug("=> View Notes");

	ui.textEdit->clear();

	QString seperator = " ";
	QString numsep = ")";

	QSqlQuery query2;

	QString authuser = ui.labelUser->text();

	QDateTime  dt3 = QDateTime::currentDateTime();
	QString  bdate2 = dt3.toString("dd/MM/yyyy hh:mm:ss");




	query2.exec("SELECT b_id, b_user, b_notes, b_date from b_notes where b_user='"+authuser+"'");

	if (!query2.isActive())
		    QMessageBox::warning(this, tr("Database Error"),
			  		                         query2.lastError().text());



	while (query2.next()){

		 {

		 QString result0 = query2.value(0).toString();
		 QString result1 = query2.value(1).toString();
		 QString result2 = query2.value(2).toString();
		 QString result3 = query2.value(3).toString();

		 QString sum = result0 + numsep + seperator + result2 + seperator + result3;

		 qDebug(sum);


		 ui.textEdit->append(sum);



		 }
	}



}
