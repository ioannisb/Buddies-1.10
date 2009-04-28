#include <client.h>
#include <QHostAddress>

Client::Client(QString host,long port,bool fs) 
{
   /*if(!serverConnection)*/ serverConnection = new QSslSocket(this);
     
   serverConnection -> setPeerVerifyMode(QSslSocket::QueryPeer);
   serverConnection -> setLocalCertificate("mycert.pem");
   serverConnection -> setPrivateKey("mycert.pem");
   serverConnection -> connectToHostEncrypted( host, port);
   peerPort = port;
   connected=0;
   fileSend=fs;
   connect(serverConnection, SIGNAL(encrypted()), SLOT(connectionAccepted()));  
   connect(serverConnection,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
   connect(serverConnection, SIGNAL(readyRead()), this, SLOT(readDataFromServer()));    
   connect(serverConnection, SIGNAL(disconnected()), serverConnection, SLOT(deleteLater()));
   connect(serverConnection, SIGNAL(sslErrors(QList<QSslError>)),SLOT(sslErrors(QList<QSslError>)) );
}

void Client::socketStateChanged(QAbstractSocket::SocketState state)
{
 if(state == QAbstractSocket::UnconnectedState)
  { 
   qDebug() << "CLIENT:Connection lost";
   //serverConnection -> connectToHostEncrypted( "localhost", 31337 );
   emit clientDisconnected();
   if((!fileSend)&&(!connected)) QMessageBox::critical(0,tr("Error"),tr("Connection failed!"),QMessageBox::Ok); 
   if((fileSend)&&(!connected)) QMessageBox::critical(0,tr("Error"),tr("Could not receive file!Please make sure that the other party has %1 port open and not blocked by a firewall.").arg(QString::number(peerPort)),QMessageBox::Ok); 
   connected=0;
  }
  else 
   if(state == QAbstractSocket::ConnectingState )
    {
     qDebug() << "CLIENT:Connecting";
    }
    else 
     if(state == QAbstractSocket::ConnectedState)
      {
       qDebug() << "CLIENT:Connected";       
      }
      else 
       if(state == QAbstractSocket::HostLookupState)
        {
         qDebug() << "CLIENT:Performing host lookup";
        }
        else
         if(state == QAbstractSocket::ClosingState)
          {
           qDebug() << "CLIENT:Socket about to close";
          } 
}

void Client :: connectionAccepted()
{
  qDebug() << "CLIENT: Now connected";
  qDebug() << "CLIENT: Connection is encrypted:" << serverConnection -> isEncrypted();
  qDebug() << "CLIENT: Socket Descriptor:" << serverConnection -> socketDescriptor();
  
  QSslCipher ciph = serverConnection->sessionCipher();
  QString cipher = QString("%1, %2 (%3/%4)").arg(ciph.authenticationMethod()).arg(ciph.name()).arg(ciph.usedBits()).arg(ciph.supportedBits());
  qDebug() << "CLIENT: Cipher:" << cipher;
  connected=1;

  emit readyToSendData();
}


void Client::sslErrors( const QList<QSslError> &errors )
{
	foreach( const QSslError &error, errors )
	{
		switch( error.error() )
		{
		 case QSslError::NoPeerCertificate: serverConnection -> ignoreSslErrors(); break;
                 case QSslError::HostNameMismatch: serverConnection -> ignoreSslErrors(); break;
                 case QSslError::SelfSignedCertificate: serverConnection -> ignoreSslErrors(); break;
		 default:
			//qWarning( "CLIENT SSL: error %s", qPrintable(error.errorString()) );
                        qDebug() << error.errorString();
			disconnect(); return;
		}
	}
}

void Client :: readDataFromServer()
{
  if(!fileSend)
   {
     QString incoming(serverConnection->readAll());
     qDebug() << "Server:" << incoming;
     emit messageReceived(incoming);
   }
   else
    {
      qDebug() <<"Bytes available to read:"<< serverConnection -> bytesAvailable();
      while(serverConnection -> bytesAvailable()) 
       {
        emit dataReceived(serverConnection -> readAll());   
       }
    }
}

void  Client :: sendMsg(QString msg)
{
 if(connected)
  if(serverConnection != 0) 
   if(serverConnection -> isOpen())
    serverConnection -> write(msg.toUtf8().constData(), msg.toUtf8().length());
}

void Client :: endConnection()
{
 if(connected)
  if(serverConnection != 0) 
   if(serverConnection -> isOpen())
    serverConnection -> close();
}

Client :: ~Client()
{
 qDebug()<<"CLIENT: Connection closed";
 connected=0;
 if(serverConnection -> isOpen()) serverConnection -> close();
 emit clientDisconnected();
}

QString Client :: getSSLCypher()
{
 QString cipher("");
 if(connected) //I know it's not pretty but it looks a lot better than a segfault :P
  if(serverConnection!=0)
   if(serverConnection -> isOpen())
    {
 	QSslCipher ciph = serverConnection->sessionCipher();
 	cipher = QString("%1, %2 (%3/%4)").arg(ciph.authenticationMethod()).arg(ciph.name()).arg(ciph.usedBits()).arg(ciph.supportedBits());	
    }
 return cipher;

}

QString Client :: peerAddress()
{
 if (serverConnection!=0)
  return serverConnection -> peerAddress().toString();
  else return QString("127.0.0.1");
}

