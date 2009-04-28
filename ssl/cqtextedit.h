#include <QTextEdit>
#include <QMimeData>
#include <QTextCursor>
#include <QString>
#include <QList>
#include <QUrl>
#include <QHash>
#include <QMovie>
#include <QFocusEvent>
#include <QTimer>

class QWidget;

class cqtextedit : public QTextEdit
{
 Q_OBJECT
 
 public:
   cqtextedit(QWidget *parent);
   
   QTimer *timer;
   void addAnimation(const QUrl& url, const QString& fileName)
	{
		QMovie* movie = new QMovie(this);
		movie->setFileName(fileName);
		urls.insert(movie, url);
		connect(movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
		movie->start();
	}
  

 protected:
 //void dragEnterEvent(QDragEnterEvent *event);
 //void dropEvent(QDropEvent *e);
 void insertFromMimeData( const QMimeData *source );
 bool canInsertFromMimeData( const QMimeData *source ) const;
 void focusOutEvent( QFocusEvent * event );

 public slots: 
    void enableCopyPaste();
    void enableDragnDrop();
    void reload();

  signals: 
    void focusLost(); 
    void fileSendInitiated(QString origin,int source,int dummy);

 private:
  
  QHash<QMovie*, QUrl> urls;

 private slots:
  void animate()
	{
                
		if (QMovie* movie = qobject_cast<QMovie*>(sender()))
		{
			document()->addResource(QTextDocument::ImageResource,
				urls.value(movie), movie->currentPixmap());
			//setLineWrapColumnOrWidth(lineWrapColumnOrWidth()); // causes reload      			
                }
	}

 
};


