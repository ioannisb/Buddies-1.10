#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <QChar>
#include <QDebug>

class fileSend;

class fileSendDialog : public QDialog
{
 Q_OBJECT
 public:
  fileSendDialog(fileSend *p,int mode,qint64 size);
  ~fileSendDialog();
  
  fileSend *parent;

  QPushButton *acceptButton; 
  QPushButton *rejectButton; 
  QPushButton *cancelButton; 
  QLabel *fsLabel;
  QProgressBar *progressBar;

  QString fName;
  void getFileName(QString path);
  
 public slots: 
  void acceptFile();
  void rejectFile();
  void cancelTransaction();
  void updateProgressDialog(int value);
 signals:
  void acceptedFile(QString path);
  void rejectedFile();
  void transactionCancelled();
};
