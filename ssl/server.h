#include <QTcpServer>
#include <QDebug>
#include <QSslSocket>
#include <QSslError>
#include <QWidget>
#include <QSslCipher>
#include <QMessageBox>

class SslServer : public QTcpServer
{
  Q_OBJECT

  public: 
         QSslSocket *socket;
         QSslSocket* getClientConnection();
  protected:
	void incomingConnection( int socketDescriptor );
};

class sslConnection: public QSslSocket
{
  Q_OBJECT
  public:
	sslConnection( int socketDescriptor, QObject *parent );
};


class Server : public QWidget
 {
  Q_OBJECT
  public:
   Server(long port,bool fs);
  ~Server();

   SslServer *sslServer;
   QSslSocket *clientConnection;
   bool connected;
   bool fileSend;
   void sendMsg(QString msg);
   void sendData(QByteArray data);
   QString peerAddress();
   QString getSSLCypher();
   public slots:
    void acceptConnection();
    void connectionAccepted();
    void readDataFromClient();
    void sslErrors( const QList<QSslError> &err );
    void notifyDisconnect();
   signals:
    void readyToSendData();
    void messageReceived(QString msg);
  //  void dataReceived(QByteArray data);
    void serverDisconnected();
 };




