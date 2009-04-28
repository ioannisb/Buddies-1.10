#include "server.h"


//Handle the incoming connections, get a socket and set the right socket descriptor

void SslServer :: incomingConnection(int socketDescriptor)
 { 
   socket = new sslConnection( socketDescriptor, this );
 }

//Returns the socket connection to the client

QSslSocket* SslServer :: getClientConnection()
{
   return socket;
}

//Sets the descriptor and initializing the connection

sslConnection::sslConnection( int socketDescriptor, QObject *parent ) : QSslSocket( parent )
{
  if( !setSocketDescriptor( socketDescriptor ) )
   {
     qDebug() << "Couldn't set socket descriptor";
     deleteLater();
     return;
   }
  
  setPeerVerifyMode(QSslSocket::VerifyPeer);
  setLocalCertificate( "mycert.pem" );
  setPrivateKey("mycert.pem");
  startServerEncryption();
}


Server::Server(long port,bool fs)
{
 sslServer = new SslServer();
 if (!sslServer->listen(QHostAddress::Any,port)) 
  {
   qDebug() << "Couldn't bind server";
   QMessageBox::critical(0,tr("Error"),
                                tr("Could not bind server.Choose other port.")
                                ,QMessageBox::Ok); 
  }
   else qDebug() << "Server running on port:"<< port;
 
 connected=0;  
 fileSend=fs;
 connect(sslServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
   
}

void Server :: acceptConnection()
{
  clientConnection = sslServer -> getClientConnection();
  
  qDebug() << "New connection received from "<< clientConnection->peerAddress().toString();
  connect(clientConnection, SIGNAL(encrypted()), SLOT(connectionAccepted()));  
  connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readDataFromClient()));    
  connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));
  connect(clientConnection, SIGNAL(disconnected()), this, SLOT(notifyDisconnect()));
  connect(clientConnection, SIGNAL(sslErrors(QList<QSslError>)),SLOT(sslErrors(QList<QSslError>)) );

}

QString Server :: peerAddress()
{
 if (clientConnection!=0)
  return clientConnection -> peerAddress().toString();
  else return QString("127.0.0.1");
}


void Server :: notifyDisconnect()
 {
  connected=0;
  emit serverDisconnected();
 }
//Handles SSL errors

void Server::sslErrors( const QList<QSslError> &errors )
{
	foreach( const QSslError &error, errors )
	{
		switch( error.error() )
		{
		 case QSslError::NoPeerCertificate: clientConnection -> ignoreSslErrors(); break;
                 case QSslError::HostNameMismatch: clientConnection -> ignoreSslErrors(); break;
                 case QSslError::SelfSignedCertificate: clientConnection -> ignoreSslErrors(); break;
		 default:
			//qWarning( "CLIENT SSL: error %s", qPrintable(error.errorString()) );
                        qDebug() << error.errorString();
			disconnect(); return;
		}
	}
}

void Server::connectionAccepted()
{ 
 qDebug() << "SERVER: Now connected";
 qDebug() << "SERVER: Connection is encrypted:" << clientConnection -> isEncrypted();
 qDebug() << "SERVER: Socket Descriptor:" << clientConnection -> socketDescriptor();
 QSslCipher ciph = clientConnection->sessionCipher();
 QString cipher = QString("%1, %2 (%3/%4)").arg(ciph.authenticationMethod()).arg(ciph.name()).arg(ciph.usedBits()).arg(ciph.supportedBits());
 qDebug() << "SERVER: Cipher:" << cipher;

 connected=1;
 emit readyToSendData();
}

void Server :: readDataFromClient()
{
 if(!fileSend)
  {
   QString incoming(clientConnection->readAll());
   qDebug() << "Client:" << incoming;
   emit messageReceived(incoming);
  }
   else 
    {
     //emit dataReceived(clientConnection -> readAll()); the Server doesn't receive
    }
}

void  Server :: sendMsg(QString msg)
{
  if(connected)
   if(clientConnection != 0) 
    if(clientConnection -> isOpen())
     clientConnection -> write(msg.toUtf8().constData(), msg.toUtf8().length());
}

void Server :: sendData(QByteArray data)
{
 if(fileSend&&connected&&(clientConnection != 0)&&(clientConnection -> isOpen()))
  {
      if(clientConnection -> write(data) == -1) 
       qDebug() << clientConnection -> errorString();
      else
       clientConnection -> flush();
  }
}

Server :: ~Server()
{
 qDebug() << "SERVER: Connection closed";
 connected=0;
 sslServer->close();
};

QString Server :: getSSLCypher()
{
 QString cipher("");
 if(connected) //I know it's not pretty but it looks a lot better than a segfault :P
  if(clientConnection!=0)
   if(clientConnection -> isOpen())
    {
 	QSslCipher ciph = clientConnection->sessionCipher();
 	cipher = QString("%1, %2 (%3/%4)").arg(ciph.authenticationMethod()).arg(ciph.name()).arg(ciph.usedBits()).arg(ciph.supportedBits());	
    }
 return cipher;

}