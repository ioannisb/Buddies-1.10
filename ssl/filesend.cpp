#include "filesend.h"

fileSend :: fileSend()
{
  mode = 0; //disconnected
  destinationPath = QDir::homePath ();
  transferred=0;
  fileReject=false;
}

fileSend :: ~fileSend()
{
  //fsDialog -> close();
  qDebug() << "File sending ended";
}

void fileSend :: sendFile(QString f,int p,qint64 size)
{
  filePath = f;
  fsize=size;
  fsDialog = new fileSendDialog(this,1,fsize);
  port=p;

  server = new Server(port+5,true);
  connect(server,SIGNAL(readyToSendData()),this,SLOT(initiateTransaction()));
  connect(server,SIGNAL(serverDisconnected()),this,SLOT(endConnection()));
  connect(this,SIGNAL(finished()),server,SLOT(deleteLater()));
  connect(fsDialog,SIGNAL(transactionCancelled()),this,SLOT(cancelTransaction()));

  qDebug() << "Sending file:"<<f;

  mode = 1; //sender(server) 
}



void fileSend :: receiveFile(QString f,int p,qint64 size,QString host)
{ 
  filePath = f;
  port=p;
  fsize = size;
  hostIp = host;
  fsDialog = new fileSendDialog(this,2,fsize);
  connect(fsDialog,SIGNAL(acceptedFile(QString)),this,SLOT(acceptFile(QString)));
  connect(fsDialog,SIGNAL(rejectedFile()),this,SLOT(rejectFile()));
  connect(fsDialog,SIGNAL(transactionCancelled()),this,SLOT(cancelTransaction()));

} 

//this is called when acceptedFile is emitted
void fileSend :: acceptFile(QString dp) 
{
  destinationPath = dp;
  
  qDebug() << "Accepted file, now connecting";
  qDebug() << "Will save to:"<<dp;

  QFile file(dp);
  if(file.exists())
   {
     qDebug() << "File existed, overwriting";
     if(file.remove()) qDebug() << "File removed";
      else qDebug() << "Couldn't remove file";
   }

  client = new Client(hostIp,port+5,true);
  connect(client,SIGNAL(readyToSendData()),this,SLOT(initiateTransaction()));
  connect(client,SIGNAL(clientDisconnected()),this,SLOT(endConnection()));
  connect(this,SIGNAL(finished()),this,SLOT(disconnectClient()));

  qDebug() << "Receiving file:"<<filePath;
  mode = 2; //client(receiver)
}

/* The client emits the rejectedFile signal,it's connected to this slot,it uses the parent object 
 to notify the server about the reject, the parent emits the peerRejectedFileSend() signal,which is
 connected to actOnReject.I know, I know, now you're wondering what have I smoked.*/
void fileSend :: rejectFile() 
{
 fileReject = true;
 qDebug() << "File rejected";
 emit fileRejected();
 emit finished();
}

void fileSend :: actOnReject()
{
 qDebug() << "Acting on reject";
 fileReject = true;
 fsDialog -> close();
 emit finished();
}

void fileSend :: actOnComplete()
{
 qDebug() << "File send was successful";

 dsTimer -> stop();
 disconnect(dsTimer, SIGNAL(timeout()), this, SLOT(sendAChunk()));
 dsTimer -> deleteLater();
 file -> close(); 
 file -> deleteLater();
 emit finished();
}

void fileSend :: cancelTransaction()
{
 if(mode==2)
 {
   QFile file(destinationPath);
   file.remove();
   fileReject = true;
   emit fileRejected();
 }
 else 
  if(mode==1) 
   {
     fileReject=true;
     emit fileRejected();
     emit finished();
   }
}


void fileSend :: initiateTransaction()
{
  if (mode == 2) connect(client,SIGNAL(dataReceived(QByteArray)),this,SLOT(receiveData(QByteArray)));
   else
    if (mode == 1) 
     {
       qDebug() << "Connected, proceeding to send data";
       file=new QFile(filePath);
       if(file -> open(QIODevice::ReadOnly))
        {
          dsTimer = new QTimer();
          connect(dsTimer, SIGNAL(timeout()), this, SLOT(sendAChunk()));
          dsTimer->start(3);
        }
    }
 
}

void fileSend :: sendAChunk()
{
 QByteArray data;
 if(!fileReject)
  {
    data = file -> read(4096);
    if(data.size()>0)
     {
      transferred += data.size();
      server -> sendData(data); 
      qDebug() << "Sending "<<data.size()<<" bytes from file:"<<filePath;
      updateProgressBar();
     }
     else 
      {         
        if(transferred == file->size())
         {
          /* dsTimer -> stop();
           disconnect(dsTimer, SIGNAL(timeout()), this, SLOT(sendAChunk()));
           dsTimer -> deleteLater();
           file -> close(); 
           file -> deleteLater();*/
         }
      }
  }
  else 
   {
    qDebug() << "File sending cancelled";
    dsTimer -> stop();
    disconnect(dsTimer, SIGNAL(timeout()), this, SLOT(sendAChunk()));
    dsTimer -> deleteLater();
    file -> close();
    file -> deleteLater();
   }
}

void fileSend :: updateProgressBar()
{
  qDebug() << transferred <<" bytes transferred";
  int percent = (transferred*100)/fsize;
  if(percent>100) percent=100;
  fsDialog -> updateProgressDialog(percent);
}

/*
void fileSend :: notifyFinished()
{
 emit finished();
}*/

void fileSend :: receiveData(QByteArray data)
{ 
 if(!fileReject)
  {
    qDebug() << "Writing "<<data.size()<<" bytes of received data to "<<destinationPath;
    QFile file(destinationPath);
    if(file.open(QIODevice::Append))
     {
      file.write(data);
     } else qDebug() << "Could not save file";
    transferred = file.size(); 
    qDebug() << transferred <<" bytes transferred out of" << fsize;
    fsDialog -> updateProgressDialog((transferred*100)/fsize);
    file.close(); 
    if(transferred == fsize) 
     {
       qDebug() << "File receive was successful";
       emit successful(); 
       emit finished();
     }
  }
  else
   {
    disconnectClient();
   }
}

void fileSend :: disconnectClient()
{
 client -> endConnection();
 client -> deleteLater();
 this -> deleteLater();
}

void fileSend :: endConnection()
{
 qDebug() << "Client disconnected!";
}



