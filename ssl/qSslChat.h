#include "filesend.h"
#include "ui_qSslChat.h"
#include "emoticonselector.h"
#include "certificateinfo.h"
#include <QCloseEvent>
#include <QShowEvent>
#include <QTextTable>
#include <QFocusEvent>

class fileSend;

class qSslChat : public QWidget,public Ui::qSslChat
{
  Q_OBJECT

  public:
   qSslChat();
   ~qSslChat();

   Server *server;
   Client *client;
//   systemTray *systray;

   int mode;
   QString mateName;

  // void closeEvent(QCloseEvent *e);
   //void showEvent(QShowEvent *event);
   void appendMessage(const QString from, QString message);
   void filterEmoticons(QString *message);
   void addAnimations();

  private:
   QTextTableFormat tableFormat;
   EmoticonSelector *emoSelector;

  public slots:
   void hostConnection();
   void connectToHost();
   void activateMsgSending();
   void sendMsg(QString s);
   void receiveMessage(QString msg);
   void displayMsg();
   void endConnection();
   void sendAnticipation();
   void sendFile(QString path,int source,int size);
   void notifyServer(); //about file reject
   void completeFileSend();
   void selectSmiley();
   void insertSmiley(QString name,QString code);
   void displayCertificateInfo();
  signals:
   void peerRejectedFileSend();
   void fsCompleted();
};




