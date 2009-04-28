#include "qSslChat.h"
#include <QLayout>
#include <QNetworkInterface>
#include <QScrollBar>
#include <QFileInfoList>
#include <QDir>
#include <QClipboard>
#include <QTextCodec>
#include <QPalette>
//#include <Phonon>


qSslChat :: qSslChat()
{
  setupUi(this);
  messageList -> setDisabled(true);
  messageList -> setAcceptDrops(true);
  msgEdit -> setDisabled(true);
  sendButton -> setDisabled(true);
  smileyButton -> setDisabled(true);
  cinfoButton -> setDisabled(true);
  portBox -> setRange(1024,65535);
  portBox -> setValue(7752);
  setWindowTitle("Buddies SSL Chat");
  setWindowIcon(QIcon(":/icons/Logo.png"));
  mode=0;
  server=0;

  cinfoButton -> setIcon(QIcon(":/icons/encrypted.png"));
  cinfoButton -> setIconSize(QSize(20,20));
  cinfoButton -> setToolTip(tr("Display certificate info"));

  connect(cinfoButton,SIGNAL(clicked()),this,SLOT(displayCertificateInfo()));

  smileyButton -> setIcon(QIcon(":/emoticons/01.gif"));
  smileyButton -> setIconSize(QSize(20,20));
  connect(smileyButton,SIGNAL(clicked()),this,SLOT(selectSmiley()));
  emoSelector = new EmoticonSelector(this);
  emoSelector -> hide();
  emoSelector -> alignTo(smileyButton);
  connect(emoSelector,SIGNAL(smileySelected(QString,QString)),this,SLOT(insertSmiley(QString,QString)));

  tableFormat.setBorder(0);
  //systray = new systemTray(this);
  addAnimations();

  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
  QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));

  connect(hostButton,SIGNAL(clicked()),this,SLOT(hostConnection()));
  connect(connectButton,SIGNAL(clicked()),this,SLOT(connectToHost()));
  connect(disconnectButton,SIGNAL(clicked()),this,SLOT(endConnection()));
  connect(messageList,SIGNAL(fileSendInitiated(QString,int,int)),this,SLOT(sendFile(QString,int,int)));

}

void qSslChat :: hostConnection()
{
  if(nameEdit ->text().isEmpty())
   {
      QMessageBox::critical(0,tr("Error"),tr("Choose a name."),QMessageBox::Ok);
      return;
   }

  connectButton -> setDisabled(true);
  hostButton -> setDisabled(true);
  server = new Server(portBox -> value(),false);

  QList<QHostAddress> ipList;
  ipList = QNetworkInterface :: allAddresses();
  int counter = 0;
  QString localIp("127.0.0.1");
  foreach(QHostAddress ip,ipList)
   {
    QString ipString = ip.toString();
    if(ipString.contains(":")) ipList.removeAt(counter);
     else
      if(ipString=="127.0.0.1") ipList.removeAt(counter);
       else
        if(ipString.contains("192.")&&!ipString.contains(".192"))
         {
           localIp = ipString;
           ipList.removeAt(counter);
         }
         else counter++;
   }

  if(ipList.isEmpty())
   {
     QApplication::clipboard()-> setText(localIp,QClipboard::Clipboard);
     ipEdit -> setText(localIp);
   }
   else
    {
     QApplication::clipboard()-> setText(ipList[ipList.size()-1].toString(),QClipboard::Clipboard);
     ipEdit -> setText(ipList[ipList.size()-1].toString());
    }

  connect(server,SIGNAL(readyToSendData()),this,SLOT(activateMsgSending()));
  connect(server,SIGNAL(serverDisconnected()),this,SLOT(endConnection()));
  mode=1;
}

void qSslChat :: connectToHost()
{
  if(nameEdit ->text().isEmpty())
   {
      QMessageBox::critical(0,tr("Error"),tr("Choose a name."),QMessageBox::Ok);
      return;
   }
  if(ipEdit -> text().isEmpty())
   {
     QMessageBox::critical(0,tr("Error"),tr("Give the ip address(or hostname) of the conversation host."),QMessageBox::Ok);
     return;
   }

  client = new Client(ipEdit -> text(),portBox -> value(),false);
  connect(client,SIGNAL(readyToSendData()),this,SLOT(activateMsgSending()));
  connect(client,SIGNAL(clientDisconnected()),this,SLOT(endConnection()));

  mode=2;
}

void qSslChat :: sendMsg(QString s)
{

 if(mode==1) server -> sendMsg(s);
  else
   if(mode==2) client -> sendMsg(s);

}

void qSslChat :: activateMsgSending()
{
 msgEdit -> setDisabled(false);
 sendButton -> setDisabled(false);
 messageList -> setDisabled(false);
 smileyButton -> setDisabled(false);
 if(mode==2) cinfoButton -> setDisabled(false); //Can only display the server certificate
 msgEdit -> setFocus();
 connectButton -> setDisabled(true);
 hostButton -> setDisabled(true);
 portBox -> setDisabled(true);
 ipEdit -> setDisabled(true);
 nameEdit -> setDisabled(true);
 QPalette palette;
 palette.setColor(QPalette::Base, QColor(255, 255, 192));
 ipEdit->setPalette(palette);

 messageList -> clear();


 QString cypher="";
 if(mode == 1) cypher = server -> getSSLCypher();
 if(mode == 2) cypher = client -> getSSLCypher();
 appendMessage("*",tr("Connection now encrypted.Session Cypher:")+cypher);
 sendMsg(QString("<SETNICK>"+nameEdit -> text()));
 connect(msgEdit,SIGNAL(returnPressed()),this,SLOT(displayMsg()));
 connect(sendButton,SIGNAL(clicked()),this,SLOT(displayMsg()));
 connect(msgEdit,SIGNAL(textEdited(QString)),this,SLOT(sendAnticipation()));

 if(mode == 1) //If server
  {
   connect(server,SIGNAL(messageReceived(QString)),this,SLOT(receiveMessage(QString)));
  }
  else //if client
   if (mode == 2) connect(client,SIGNAL(messageReceived(QString)),this,SLOT(receiveMessage(QString)));

}

void qSslChat :: appendMessage(const QString from, QString message)
{
 if (from.isEmpty() || message.isEmpty())
         return;

     QTextCursor cursor(messageList->textCursor());
     cursor.movePosition(QTextCursor::End);
     QTextTable *table = cursor.insertTable(1, 2, tableFormat);
     if (from == QString("*")) table->cellAt(0, 0).firstCursorPosition().insertHtml(from+" ");
      else
       table->cellAt(0, 0).firstCursorPosition().insertText("<" + from + ">: ");

     filterEmoticons(&message);
     table->cellAt(0, 1).firstCursorPosition().insertHtml(message);

     QScrollBar *bar = messageList->verticalScrollBar();
     bar->setValue(bar->maximum());


}


void qSslChat :: receiveMessage(QString msg)
{
 if (msg.indexOf("<SETNICK>")!=-1)
  {
   mateName = msg.replace(QString("<SETNICK>"),QString("")) ;
   QString ip="127.0.0.1";
   if(mode==1) ip=server -> peerAddress();
   if(mode==2) ip=client -> peerAddress();

   appendMessage(QString("*"),mateName+QString(" (")+ip+QString(") ")+QString(tr(" has joined the conversation")));
    //ListWidget: addItem(QString("* ")+mateName+QString(tr(" has joined the conversation")));
  }
  else
   if (msg.indexOf("<CLOSE>")!= -1)
    {
     endConnection();
    }
    else
     if (msg.indexOf("<ANTICIPATE>")!= -1)
      {
       messageLabel -> setText(QString("<font color=green><b>")+tr("Message")+QString(":</b></font>"));
      }
     else
      if (msg.indexOf("<FILESENDEVENT>")!= -1)
       {
         QString sizeString = msg;
         QString str = msg.replace(QString("<FILESENDEVENT>"),QString(""));
         sizeString.truncate(sizeString.indexOf("<"));
         str.replace(sizeString,QString(""));
         sendFile(str,1,sizeString.toInt());
       }
       else
        if (msg.indexOf("<FILESENDREJECT>")!= -1)
         {
          emit peerRejectedFileSend();
          appendMessage("*",mateName+QString(tr(" has rejected the file")));
         }
        else
         if (msg.indexOf("<FILESENDCOMPLETED>")!= -1)
          {
           emit fsCompleted();
           appendMessage("*",tr("File sending completed"));
          }
        /*
	else //Maybe some other time, like when they make Phonon work with Qt4 in Ubuntu
         if (msg.indexOf("<BUZZ>")!= -1)
          {
            Phonon::MediaObject *music =Phonon::createPlayer(Phonon::MusicCategory,                        Phonon::MediaSource(":/sounds/buzz.wav"));
            music->play();
            appendMessage("*",mateName+tr("has buzzed you."));
          }*/
    else
    {
      activateWindow();
      raise();
     // if(!isVisible()) systray -> blink();
     // messageList -> addItem(QString("<")+mateName+QString(">: ")+msg);
      appendMessage(mateName,msg);
      //messageList -> scrollToBottom();
      connect(msgEdit,SIGNAL(textEdited(QString)),this,SLOT(sendAnticipation()));
      messageLabel -> setText(QString("<b>")+tr("Message")+QString(":</b>"));
    }
}

void qSslChat :: displayMsg()
{
 QString s = msgEdit -> text();
 if(!s.isEmpty())
  {
    if(s == QString("/clear"))
     {
       messageList -> clear();
       msgEdit -> setText(QString(""));
       msgEdit -> setFocus();
      // systray -> stopBlinking();
     }
     else
      {
        appendMessage(nameEdit->text(),s);
        sendMsg(s);
        msgEdit -> setText(QString(""));
        msgEdit -> setFocus();
       // systray -> stopBlinking();
      }
  }
}

void qSslChat :: endConnection()
{
  sendMsg("<CLOSE>");
  connectButton -> setDisabled(false);
  hostButton -> setDisabled(false);
  portBox -> setDisabled(false);
  ipEdit -> setDisabled(false);
  nameEdit -> setDisabled(false);
  QPalette palette;
  palette.setColor(QPalette::Base, QColor(255, 255, 255));
  ipEdit->setPalette(palette);

  msgEdit -> setDisabled(true);
  sendButton -> setDisabled(true);
  messageList -> setDisabled(true);
  smileyButton -> setDisabled(true);
  cinfoButton -> setDisabled(true);

  appendMessage(QString("*"),QString(tr("Disconnected")));
  disconnect(msgEdit,SIGNAL(returnPressed()),this,SLOT(displayMsg()));
  disconnect(sendButton,SIGNAL(clicked()),this,SLOT(displayMsg()));
  if(mode==1) disconnect(server,SIGNAL(messageReceived(QString)),this,SLOT(receiveMessage(QString)));
  if(mode==2) disconnect(client,SIGNAL(messageReceived(QString)),this,SLOT(receiveMessage(QString)));
  if(mode==1) server -> deleteLater();qDebug() << "Server closed";
  if(mode==2) client -> deleteLater();qDebug() << "Client closed";

  mode=0;

}


void qSslChat :: sendAnticipation()
{
 sendMsg(QString("<ANTICIPATE>"));
 disconnect(msgEdit,SIGNAL(textEdited(QString)),this,SLOT(sendAnticipation()));

}

//This catches minimize events when the window gets minimized and also hides
//the window entry in the taskbar so the program sits in the system tray
/*void qSslChat::closeEvent(QCloseEvent *e)
{
  e->ignore();
  hide();
}

*/

/*
void qSslChat :: showEvent ( QShowEvent * event )
{
 //systray -> stopBlinking();
 return QWidget :: showEvent(event);
}
*/

void qSslChat :: filterEmoticons(QString *msg)
{

        msg->replace(QRegExp(">:[dD]<"), "<img src=\"06\">");
        //msg->replace(QRegExp("8-?>"), "<img src=\"105\">");


        msg->replace(QString(":)>-"),"<img src=\"67\">");
	msg->replace(QString(":)]"), "<img src=\"100\">");
	msg->replace(QString(":(("), "<img src=\"20\">");
	msg->replace(QString(":))"), "<img src=\"21\">");
	msg->replace(QString(">:)"), "<img src=\"19\">");

	msg->replace(QString(";))"), "<img src=\"71\">");
	msg->replace(QString(";;)"), "<img src=\"05\">");
	msg->replace(QString(";)"), "<img src=\"03\">");
	msg->replace(QString(":-/"), "<img src=\"07\">");
	msg->replace(QString("=(("), "<img src=\"12\">");
	msg->replace(QString("/:)"), "<img src=\"23\">");
	msg->replace(QString("=))"), "<img src=\"24\">");
	msg->replace(QString("=;"), "<img src=\"27\">");
	msg->replace(QString("(:|"), "<img src=\"37\">");
	msg->replace(QString(":-??"), "<img src=\"106\">");
	msg->replace(QString("@:)"), "<img src=\"43\">");
	msg->replace(QString(">-)"), "<img src=\"61\">");
	msg->replace(QString(":-@"), "<img src=\"76\">");
	msg->replace(QString("^:)^"), "<img src=\"77\">");
        msg->replace(QString("~x("), "<img src=\"102\">");
	msg->replace(QString(":-h"), "<img src=\"103\">");
	msg->replace(QString(":-t"), "<img src=\"104\">");
 	msg->replace(QString(">:/"), "<img src=\"70\">");
	msg->replace(QString(":\">"), "<img src=\"09\">");



	msg->replace(QRegExp(":-?[bB]"), "<img src=\"26\">");
	//msg->replace(QRegExp("=[pP]~"), "<img src=\"38\">");
	//msg->replace(QRegExp("#-?[oO]"), "<img src=\"40\">");
	//msg->replace(QRegExp("=[dD]>"), "<img src=\"41\">");
	msg->replace(QRegExp("[lL]-?[)]"), "<img src=\"30\">");
	msg->replace(QRegExp(":-?&"), "<img src=\"31\">");
	msg->replace(QRegExp(":-?[$]"), "<img src=\"32\">");
	msg->replace(QRegExp("[[]-?[(]"), "<img src=\"33\">");
	msg->replace(QRegExp(">:-?[pP]"), "<img src=\"47\">");
	msg->replace(QRegExp("<:-?[pP]"), "<img src=\"36\">");
	msg->replace(QRegExp(":-?[wW]"), "<img src=\"45\">");
	//msg->replace(QRegExp(":-?>"), "<img src=\"46\">");
	msg->replace(QRegExp("8-?[xX]"), "<img src=\"59\">");
	msg->replace(QRegExp("[[]-?[oO]>"), "<img src=\"63\">");
	msg->replace(QRegExp("[Bb]-?[(]"), "<img src=\"66\">");
	msg->replace(QRegExp(":-?[Jj]"), "<img src=\"78\">");
	msg->replace(QRegExp(":-?<"), "<img src=\"15\">");
  	//msg->replace(QRegExp("#:-?[sS]"), "<img src=\"18\">");
	msg->replace(QRegExp(":-?[sS][sS]"), "<img src=\"42\">");
        msg->replace(QRegExp(":-?[sS]"), "<img src=\"17\">");
        msg->replace(QRegExp("[xX]-?[(]"), "<img src=\"14\">");
        msg->replace(QRegExp(":-?[xX]"), "<img src=\"08\">");
	msg->replace(QRegExp(":-?[pP]"), "<img src=\"10\">");
	msg->replace(QRegExp(":-?[*]"), "<img src=\"11\">");
        msg->replace(QRegExp(":-?[Dd]"), "<img src=\"04\">");

        msg->replace(QString(":)"), "<img src=\"01\">");
	msg->replace(QString(":("), "<img src=\"02\">");
       	msg->replace(QString(":|"), "<img src=\"22\">");
	msg->replace(QString(":-?"), "<img src=\"39\">");

}

void qSslChat :: addAnimations()
{
 messageList -> addAnimation(QUrl("06"), ":/emoticons/06.gif");
 //messageList -> addAnimation(QUrl("105"), ":/emoticons/105.gif");
 messageList -> addAnimation(QUrl("67"), ":/emoticons/67.gif");
 messageList -> addAnimation(QUrl("100"), ":/emoticons/100.gif");
 messageList -> addAnimation(QUrl("20"), ":/emoticons/20.gif");
 messageList -> addAnimation(QUrl("21"), ":/emoticons/21.gif");
 messageList -> addAnimation(QUrl("19"), ":/emoticons/19.gif");
 messageList -> addAnimation(QUrl("71"), ":/emoticons/71.gif");
 messageList -> addAnimation(QUrl("05"), ":/emoticons/05.gif");
 messageList -> addAnimation(QUrl("03"), ":/emoticons/03.gif");
 messageList -> addAnimation(QUrl("07"), ":/emoticons/07.gif");
 messageList -> addAnimation(QUrl("12"), ":/emoticons/12.gif");
 messageList -> addAnimation(QUrl("23"), ":/emoticons/23.gif");
 messageList -> addAnimation(QUrl("24"), ":/emoticons/24.gif");
 messageList -> addAnimation(QUrl("27"), ":/emoticons/27.gif");
 messageList -> addAnimation(QUrl("37"), ":/emoticons/37.gif");
 messageList -> addAnimation(QUrl("106"),":/emoticons/106.gif");
 messageList -> addAnimation(QUrl("43"), ":/emoticons/43.gif");
 messageList -> addAnimation(QUrl("61"), ":/emoticons/61.gif");
 messageList -> addAnimation(QUrl("76"), ":/emoticons/76.gif");
 messageList -> addAnimation(QUrl("77"), ":/emoticons/77.gif");
 messageList -> addAnimation(QUrl("102"), ":/emoticons/102.gif");
 messageList -> addAnimation(QUrl("103"), ":/emoticons/103.gif");
 messageList -> addAnimation(QUrl("104"), ":/emoticons/104.gif");
 messageList -> addAnimation(QUrl("70"), ":/emoticons/70.gif");
 messageList -> addAnimation(QUrl("09"), ":/emoticons/09.gif");
 messageList -> addAnimation(QUrl("26"), ":/emoticons/26.gif");
 /*messageList -> addAnimation(QUrl("38"), ":/emoticons/38.gif");
 messageList -> addAnimation(QUrl("40"), ":/emoticons/40.gif");
 messageList -> addAnimation(QUrl("41"), ":/emoticons/41.gif");*/
 messageList -> addAnimation(QUrl("30"), ":/emoticons/30.gif");
 messageList -> addAnimation(QUrl("31"), ":/emoticons/31.gif");
 messageList -> addAnimation(QUrl("32"), ":/emoticons/32.gif");
 messageList -> addAnimation(QUrl("33"), ":/emoticons/33.gif");
 messageList -> addAnimation(QUrl("47"), ":/emoticons/47.gif");
 messageList -> addAnimation(QUrl("36"), ":/emoticons/36.gif");
 messageList -> addAnimation(QUrl("45"), ":/emoticons/45.gif");
 messageList -> addAnimation(QUrl("59"), ":/emoticons/59.gif");
 messageList -> addAnimation(QUrl("63"), ":/emoticons/63.gif");
 messageList -> addAnimation(QUrl("66"), ":/emoticons/66.gif");
 messageList -> addAnimation(QUrl("78"), ":/emoticons/78.gif");
 messageList -> addAnimation(QUrl("15"), ":/emoticons/15.gif");
 //messageList -> addAnimation(QUrl("18"), ":/emoticons/18.gif");
 messageList -> addAnimation(QUrl("42"), ":/emoticons/42.gif");
 messageList -> addAnimation(QUrl("17"), ":/emoticons/17.gif");
 messageList -> addAnimation(QUrl("14"), ":/emoticons/14.gif");
 messageList -> addAnimation(QUrl("08"), ":/emoticons/08.gif");
 messageList -> addAnimation(QUrl("10"), ":/emoticons/10.gif");
 messageList -> addAnimation(QUrl("11"), ":/emoticons/11.gif");
 messageList -> addAnimation(QUrl("04"), ":/emoticons/04.gif");
 messageList -> addAnimation(QUrl("01"), ":/emoticons/01.gif");
 messageList -> addAnimation(QUrl("02"), ":/emoticons/02.gif");
 messageList -> addAnimation(QUrl("22"), ":/emoticons/22.gif");
 messageList -> addAnimation(QUrl("39"), ":/emoticons/39.gif");


 messageList -> hide();
 messageList -> show();
}


void qSslChat :: notifyServer()
{
 appendMessage("*",tr("You have rejected the file"));
 sendMsg("<FILESENDREJECT>");
}

void qSslChat :: completeFileSend()
{
 appendMessage("*",tr("File receive completed"));
 sendMsg("<FILESENDCOMPLETED>");
}

void qSslChat :: sendFile(QString path,int source,int size)
{
 fileSend *fs = new fileSend();
 connect(fs,SIGNAL(fileRejected()),this,SLOT(notifyServer()),Qt::QueuedConnection);
 connect(fs,SIGNAL(successful()),this,SLOT(completeFileSend()),Qt::QueuedConnection);
 connect(this,SIGNAL(peerRejectedFileSend()),fs,SLOT(actOnReject()),Qt::QueuedConnection);
 connect(this,SIGNAL(fsCompleted()),fs,SLOT(actOnComplete()),Qt::QueuedConnection);
 if (source==0) //Sending
  {
   QFile file(path);
   fs -> sendFile(path,portBox -> value(),file.size());
   sendMsg(QString(QString::number(file.size())+"<FILESENDEVENT>"+path));
  }
  else
   if (source==1) //Receiving
    {
      if(mode==1) //Server mode
       {
         fs -> receiveFile(path,portBox -> value(),size,server->peerAddress()); //If the client sends the file
         qDebug() << "Client sends, server receives."<<"FileServer:"<<server->peerAddress();
       }
       else
        if (mode==2) //Client mode
         {
           fs -> receiveFile(path,portBox -> value(),size,ipEdit->text()); //if the client sends the file
           qDebug() << "Server sends, client receives."<<"FileServer:"<<ipEdit->text();
         }
    }

 connect(fs,SIGNAL(finished()),fs,SLOT(deleteLater()),Qt::QueuedConnection);
 messageList -> enableDragnDrop();

}

void qSslChat :: selectSmiley()
{
  emoSelector -> alignTo(smileyButton);
  emoSelector -> show();
}

void qSslChat :: insertSmiley(QString name,QString code)
{
 Q_UNUSED(name);
 // msgEdit -> insert(QString("<img src=\"")+name+QString("\">"));
  msgEdit -> insert(QString(" ")+code+QString(" "));
}

void qSslChat :: displayCertificateInfo()
{
  CertificateInfo *info = new CertificateInfo(this);
  QSslSocket *socket;
  if(mode==1)
   {
    if(server!=0)
     if(server->clientConnection != 0)
      socket = server -> clientConnection;
   }
   else
    if(mode==2)
     {
      if(client!=0)
       if(client->serverConnection != 0)
        socket = client -> serverConnection;
     }
  if((mode!=0)&&(socket!=0))
   {
     info->setCertificateChain(socket -> peerCertificateChain());
     info->exec();
     info->deleteLater();
   }
}

qSslChat :: ~qSslChat()
{

}



