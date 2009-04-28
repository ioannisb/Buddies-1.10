#include "buddies.h"
#include "wall.h"
#include "notes.h"
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


//- Ioannis A. Bouhras

/*---------------------------------------------------------------------------------------------*/


Buddies::Buddies(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	getSysInfo();
	createIconGroupBox();
	createActions();
	createTrayIcon();
	countOnlineUsers();




    QTimer * counter = new QTimer( this );
    connect( counter, SIGNAL(timeout()),
	             this, SLOT(structUser()) );
	counter->start( 3000 );
	qDebug("=> Starting timer 1sec interval...");






	//connect(ui.sendBtn, SIGNAL(clicked()), this, SLOT(showMessage()));
	// connect(ui.showIconCheckBox, SIGNAL(toggled(bool)), trayIcon, SLOT(setVisible(bool)));
    connect(ui.iconComboBox, SIGNAL(currentIndexChanged(int)),this, SLOT(setIcon(int)));
	connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(messageClicked()));
	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
	           this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

	ui.iconComboBox->setCurrentIndex(1);

	trayIcon->show();

	setWindowTitle(tr("Buddies"));
	//resize(400, 300);


	ui.listWidget->setIconSize(QSize(40, 40));

	//showMessage();

//-- timer 5 min for online Users Baloon

	QTimer * onlinetimer = new QTimer( this );
		    connect( onlinetimer, SIGNAL(timeout()),
			             this, SLOT(onlineNotify()) );
			onlinetimer->start( 300000 );
			qDebug("=> Starting timer 5min interval...");

//-- Information on Edit Tab

			Information();
//-- Database status
			dbstatus();

}
/*---------------------------------------------------------------------------------------------*/
Buddies::~Buddies()
{

}

/*---------------------------------------------------------------------------------------------*/

void Buddies::setVisible(bool visible)
 {
     minimizeAction->setEnabled(visible);
     maximizeAction->setEnabled(!isMaximized());
     restoreAction->setEnabled(isMaximized() || !visible);
     QWidget::setVisible(visible);
 }

/*---------------------------------------------------------------------------------------------*/

void Buddies::closeEvent(QCloseEvent *event)
 {
     if (trayIcon->isVisible()) {
         QMessageBox::information(this, tr("Systray"),
                                  tr("The program will keep running in the "
                                     "system tray. To terminate the program, "
                                	 "<b>Disconnect</b> from <b>Buddies Network</b> first, then "
                                     "choose <b>Quit</b> in the context menu "
                                     "of the system tray entry."));
         hide();
         event->ignore();
     }
 }

/*---------------------------------------------------------------------------------------------*/

void Buddies::messageClicked()
 {
     QMessageBox::information(0, tr("Systray"),
                              tr("Sorry, I already gave what help I could.\n"
                                 "Maybe you should try asking a human?"));
 }

/*---------------------------------------------------------------------------------------------*/

void Buddies::setIcon(int index)
{

	ui.lineEditLogin->text();
	QString Login = ui.lineEditLogin->text();

    QIcon icon = ui.iconComboBox->itemIcon(index);
    trayIcon->setIcon(icon);
    setWindowIcon(icon);

    trayIcon->setToolTip(ui.iconComboBox->itemText(index));

    QString statCur = ui.iconComboBox->currentText();

    qDebug("=> Set icon");

    qDebug("=> "+statCur+"");



//----------- Online


    if(statCur == "Online"){


    QSqlQuery query3;

   	query3.exec("UPDATE b_main SET b_status='Online' WHERE b_username='"+Login+"'and b_login='1'");


   	if (!query3.isActive()){

   		QMessageBox::warning(this, tr("Database Error"),
    	                          query3.lastError().text());



			}

    countOnlineUsers();
    showMessage();

    }

//----------- Offline

    if(statCur == "Offline"){


    QSqlQuery query4;

   	query4.exec("UPDATE b_main SET b_status='Offline' WHERE b_username='"+Login+"' and b_login='1'");


   	if (!query4.isActive()){

      		QMessageBox::warning(this, tr("Database Error"),
       	                          query4.lastError().text());

   			}

   	countOnlineUsers();
   	showMessage();

 }

//---------Invisible


    if(statCur == "Invisible"){


    QSqlQuery query5;

  	query5.exec("UPDATE b_main SET b_status='Invisible' WHERE b_username='"+Login+"'");


   	if (!query5.isActive()){

      		QMessageBox::warning(this, tr("Database Error"),
       	                          query5.lastError().text());



   			}

   	countOnlineUsers();
   	showMessage();

    }



}

/*---------------------------------------------------------------------------------------------*/

void Buddies::iconActivated(QSystemTrayIcon::ActivationReason reason)
 {
     switch (reason) {
     case QSystemTrayIcon::Trigger:
     case QSystemTrayIcon::DoubleClick:
         ui.iconComboBox->setCurrentIndex((ui.iconComboBox->currentIndex() + 1)
                                       % ui.iconComboBox->count());
         break;
     case QSystemTrayIcon::MiddleClick:
       //  showMessage();
         break;
     default:
         ;
     }

     qDebug("=> Icon activated");
 }

/*---------------------------------------------------------------------------------------------*/

void Buddies::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    qDebug("=> Tray actions");
}

/*---------------------------------------------------------------------------------------------*/

void Buddies::myexit()
{

	qDebug("=> Disconnecting");

	ui.lineEditLogin->text();

	QString Login = ui.lineEditLogin->text();

	QSqlQuery query6;

	query6.exec("UPDATE b_main SET b_login='0', b_status='Offline' WHERE b_username='"+Login+"'");

	ui.StatusLabel->setPixmap(QPixmap("images/Error.png"));

	ui.lineEditLogin->clear();
	ui.lineEditPasswd->clear();

	QMessageBox::warning(this, tr("Disconnecting from Network"),
		    	   		   			        "Disconnected");



	if (!query6.isActive()){
		    QMessageBox::warning(this, tr("Database Error"),
			                         query6.lastError().text());
	}


}

/*---------------------------------------------------------------------------------------------*/

void Buddies::createTrayIcon()
 {
     trayIconMenu = new QMenu(this);
     trayIconMenu->addAction(minimizeAction);
     trayIconMenu->addAction(maximizeAction);
     trayIconMenu->addAction(restoreAction);
     trayIconMenu->addSeparator();
     trayIconMenu->addAction(quitAction);

     trayIcon = new QSystemTrayIcon(this);
     trayIcon->setContextMenu(trayIconMenu);

     qDebug("=> Tray icon created");
 }

/*---------------------------------------------------------------------------------------------*/

void Buddies::createIconGroupBox()
 {

     ui.iconComboBox->addItem(QIcon(":/images/Online.png"), tr("Online"));
     ui.iconComboBox->addItem(QIcon(":/images/Offline.png"), tr("Offline"));
     ui.iconComboBox->addItem(QIcon(":/images/Invisible.png"), tr("Invisible"));

/*
     ui.typeComboBox->addItem(tr("None"), QSystemTrayIcon::NoIcon);
     ui.typeComboBox->addItem(style()->standardIcon(
            QStyle::SP_MessageBoxInformation), tr("Information"),
            QSystemTrayIcon::Information);
     ui.typeComboBox->addItem(style()->standardIcon(
            QStyle::SP_MessageBoxWarning), tr("Warning"),
            QSystemTrayIcon::Warning);
     ui.typeComboBox->addItem(style()->standardIcon(
            QStyle::SP_MessageBoxCritical), tr("Critical"),
            QSystemTrayIcon::Critical);
     ui.typeComboBox->setCurrentIndex(1);

*/


     ui.durationSpinBox->setRange(5, 60);
     ui.durationSpinBox->setSuffix(" s");
     ui.durationSpinBox->setValue(15);



 }
/*---------------------------------------------------------------------------------------------*/

void Buddies::countOnlineUsers()
{

	QSqlQuery query;


	query.exec("select count(*) from b_main where b_status='Online'");

	if (!query.isActive())
	    QMessageBox::warning(this, tr("Database Error"),
	                         query.lastError().text());
	while (query.next()) {
	QString Penguins = query.value(0).toString();

	qDebug("=> Online users");

	ui.statusbar->showMessage(tr("Currently "+Penguins+" Buddies online"), 2000);

	}

}

/*---------------------------------------------------------------------------------------------*/

void Buddies::showMessage()
 {

	    QSqlQuery query7;

		query7.exec("select count(*) from b_main where b_status='Online'");

		while (query7.next()) {

		QString ST = query7.value(0).toString();
		//qDebug("=> messageX");
		trayIcon->showMessage("Online users:","Number of users Online: "+ST+"",QSystemTrayIcon::NoIcon ,
		ui.durationSpinBox->value() * 1000);
		//qDebug("=> messageX");


		}
/*
	 QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(
	 ui.typeComboBox->itemData(ui.typeComboBox->currentIndex()).toInt());
	 trayIcon->showMessage(ui.titleEdit->text(), ui.bodyEdit->toPlainText(), icon,
	 ui.durationSpinBox->value() * 1000);
*/


 }
/*---------------------------------------------------------------------------------------------*/

void Buddies::setUserStatus()
{

	QSqlQuery query1;


	query1.exec("select count(*) from b_main where b_status='Online'");

	if (!query1.isActive())
	QMessageBox::warning(this, tr("Database Error"),
		                         query1.lastError().text());
	while (query1.next()) {
	QString Penguins = query.value(0).toString();

	qDebug("=> query1");

	ui.statusbar->showMessage(tr("Currently "+Penguins+" Buddies online"), 2000);

	}



}
/*---------------------------------------------------------------------------------------------*/

void Buddies::loginUser()
{

	stopifNotConnected();

	validateUser();



	ui.lineEditLogin->text();
	QString Login = ui.lineEditLogin->text();
	ui.lineEditPasswd->text();
	QString Passwd = ui.lineEditPasswd->text();

	QSqlQuery query;

	query.exec("SELECT b_username,b_password from b_main where b_username='"+Login+"'");

   	if (!query.isActive())
   	    QMessageBox::warning(this, tr("Database Error"),
	    		                         query.lastError().text());
	   	while (query.next()) {

   	QString vLogin = query.value(0).toString();
   	QString vPasswd = query.value(1).toString();

	   	if(Passwd == vPasswd){

	QSqlQuery query2;

	query2.exec("UPDATE b_main SET b_login='1' WHERE b_username='"+Login+"'");


	if (!query2.isActive())
		    QMessageBox::warning(this, tr("Database Error"),
			                         query2.lastError().text());


	qDebug("=> update - login ok");

#if debug
	   		qDebug("login ok");
#endif


	   	}
	   	else {

	   		ui.StatusLabel->setPixmap(QPixmap("images/Error.png"));
	   		   	QMessageBox::warning(this, tr("Database Error"),
	   		   			                         "Login incorect");
	   	return;
	   	}

   	}


	loginCurrentStatus();
}

/*---------------------------------------------------------------------------------------------*/


void Buddies::loginCurrentStatus()
{

	QSqlQuery query1;

	QString Username = ui.lineEditLogin->text();


	query1.exec("SELECT b_login from b_main where b_username='"+Username+"'");

	if (!query1.isActive())
	    QMessageBox::warning(this, tr("Database Error"),
		                         query1.lastError().text());
	while (query1.next()) {

	QString Status = query1.value(0).toString();

	qDebug("=> query1 get status");

	if(Status == "1" ){

		ui.StatusLabel->setPixmap(QPixmap("images/Ok.png"));

	}
	else
	{
		ui.StatusLabel->setPixmap(QPixmap("images/Error.png"));
		return;
	}

	}

}


/*---------------------------------------------------------------------------------------------*/


void Buddies::validateUser()
{
	ui.lineEditLogin->text();
	QString Lenter = ui.lineEditLogin->text();

	if(ui.lineEditLogin->text().isEmpty()){
		ui.StatusLabel->setPixmap(QPixmap("images/Error.png"));
		    	   		   	QMessageBox::warning(this, tr("Login"),
		    	   		   			                         "User field is empty");
		    	   		   	return;
	}

	if(ui.lineEditPasswd->text().isEmpty()){
			ui.StatusLabel->setPixmap(QPixmap("images/Error.png"));
			    	   		   	QMessageBox::warning(this, tr("Login"),
			    	   		   			                         "Password field is empty");
			    	   		   	return;
		}


	QSqlQuery query;

	query.exec("SELECT b_username from b_main where b_username='"+Lenter+"'");

    if(!query.next()){

    	ui.StatusLabel->setPixmap(QPixmap("images/Error.png"));
    	   		   	QMessageBox::warning(this, tr("Login"),
    	   		   			                         "User does not exist");

    }
    else
    {

    QString Validate = query.value(0).toString();

#if debug
    qDebug(Validate);
#endif

	 }

}
/*---------------------------------------------------------------------------------------------*/


void Buddies::stopifNotConnected()
{

	QSqlQuery query1;

	QString Username = ui.lineEditLogin->text();


	query1.exec("SELECT b_login from b_main where b_username='"+Username+"'");

    if (!query1.isActive())
		    QMessageBox::warning(this, tr("Database Error"),
			                         query1.lastError().text());
	while (query1.next()) {

	QString Status = query1.value(0).toString();


	if(Status == "1" ){


	ui.StatusLabel->setPixmap(QPixmap("images/Ok.png"));
	    	   		   	QMessageBox::warning(this, tr("Login"),
	    	   		   			                         "User already connected");
	return;
		}

	}



}
/*---------------------------------------------------------------------------------------------*/

void Buddies::focusTabEdit()
{


	ui.tabWidget->setCurrentIndex(2);


}






/*---------------------------------------------------------------------------------------------*/


void Buddies::structUser()
{
	ui.listWidget->clear();
	QSqlQuery q;

	if ( !q.exec( "select b_image, b_username from b_main where b_status='Online'and b_login='1'" ) ) {
	         qWarning( "Unable to execute query - exiting" );
		       }
		           qWarning( "\nQSqlQuery:" );
	while ( q.next() ) {

	QByteArray ba = q.value( 0 ).toByteArray();

	QString user = q.value( 1 ).toString();

	QPixmap pic;

	pic.loadFromData( ba);

	//ui.Pic->setPixmap(pic);



	QListWidgetItem *item = new QListWidgetItem(tr(user));
	item->setIcon(QIcon(pic));
	//ui.listWidget->clear();
	ui.listWidget->addItem(item);


	}




	qDebug("=> Adding image");


}

/*---------------------------------------------------------------------------------------------*/

void Buddies::startChat()
{

	QString login = ui.lineEditLogin->text();

	Chat dialog(this);
	dialog.ui.NickLineEdit->setText(login);
	dialog.exec();

}

/*---------------------------------------------------------------------------------------------*/

void Buddies::helpAbout()
{
 QMessageBox::about(this, tr("Zeus Linux Registration"),
         tr("<h2>Buddies Network</h2>"
         "<p>CopyLeft  2009 Zeus-linux GR,"
         "<p>Developer <b>Ioannis A. Bouhras</b>,"
         "<p><b>email: ioannis_bouhras@zeuslinux.gr</b>, "
         "<p><b>ATHENS</b>, <b>HELLAS</b> "
         "<p><b>Date: 21-04-2009</b> "));

}
/*---------------------------------------------------------------------------------------------*/

void Buddies::getSysInfo()
{

	QString hostname = QHostInfo::localHostName()+ "";

	qDebug() << "=> Hostname=" << hostname;

	QList <QHostAddress> list = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
	   for (int i = 0; i < list.size(); i++)
	      qDebug() << "=> IP Address="<< list.at(i).toString();

}



/*---------------------------------------------------------------------------------------------*/


void Buddies::onlineNotify()

{

	QDateTime  dt2 = QDateTime::currentDateTime();
	QString  datetime2 = dt2.toString("hh:mm:ss");

	qDebug("=> 5 minutes online notification Time: "+datetime2+"");
	showMessage();



}

/*---------------------------------------------------------------------------------------------*/


void Buddies::WriteOnWall()
{

	Wall dialog(this);
	dialog.exec();

}
/*---------------------------------------------------------------------------------------------*/


void Buddies::Information()
{




	QList <QHostAddress> lista = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
	   for (int i = 0; i < lista.size(); i++)
	   {

		   QString ip = lista.at(i).toString();

		   ui.lineEditIP->setText(ip);

		   //qDebug() << "=> IP Address="<< lista.at(i).toString();

	   }

	   QString hostname = QHostInfo::localHostName()+ "";

	   ui.lineEditHost->setText(hostname);

}



/*---------------------------------------------------------------------------------------------*/

void Buddies::dbstatus()
{
	QSqlQuery query;
	query.exec("SELECT b_id from b_main where id=1");

	if (query.isActive()) {

	ui.labelimageStatus->setPixmap(QPixmap("images/DBerr.png"));
	}
	else

	ui.labelimageStatus->setPixmap(QPixmap("images/DBok.png"));

}

/*---------------------------------------------------------------------------------------------*/


void Buddies::openNotes()
{


	Notes dialog(this);

	QString buser = ui.lineEditLogin->text();

	dialog.ui.labelUser->setText(buser);

	dialog.exec();

}
/*---------------------------------------------------------------------------------------------*/

void Buddies::startSSL()
{

	qDebug("=> Starting SSL chat");

	QProcess *app = new QProcess();

	app->start("./qSslChat");

}

/*---------------------------------------------------------------------------------------------*/
