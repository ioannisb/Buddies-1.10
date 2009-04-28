#include <QDebug>
#include <QSslSocket>
#include <QSslError>
#include <QSslCipher>
#include <QMessageBox>

class Client: public QSslSocket
{
   Q_OBJECT
   public:
     
    Client(QString host,long port,bool fs);
    ~Client();

    QSslSocket *serverConnection;
    long peerPort;
    bool connected;
    bool fileSend;  
    void sendMsg(QString msg);
    void endConnection();
    QString getSSLCypher();
    QString peerAddress();
   public slots:
    void connectionAccepted();
    void socketStateChanged(QAbstractSocket::SocketState state);
    void readDataFromServer();
    void sslErrors( const QList<QSslError> &err );

   signals:
    void readyToSendData();
    void messageReceived(QString msg);
    void dataReceived(QByteArray data);
    void clientDisconnected();
};


