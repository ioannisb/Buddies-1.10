#include "filesenddialog.h"
#include "client.h"
#include "server.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QTimer>

class fileSend : public QWidget
{
 Q_OBJECT
 public: 
  fileSend();
  ~fileSend();
  
  Server *server;
  Client *client;
  fileSendDialog *fsDialog;
  QString filePath;  
  QString destinationPath;
  QTimer *dsTimer; //dataSendTimer
  int mode;
  int port;
  bool fileReject;
  qint64 fsize;
  qint64 transferred;
  QString mateName;
  QString hostIp;
  QFile *file;
 
 public slots:
  void sendFile(QString f,int p,qint64 size);
  void receiveFile(QString f,int p,qint64 size,QString host);
  void receiveData(QByteArray data);
  void initiateTransaction();
  void endConnection();
  void disconnectClient();
  void acceptFile(QString dp);
  void rejectFile();
  void actOnReject();
  void actOnComplete();
  void cancelTransaction(); 
 // void notifyFinished();
  void updateProgressBar();
  void sendAChunk();
  signals: 
   void finished();
   void successful();
   void fileRejected();
};


