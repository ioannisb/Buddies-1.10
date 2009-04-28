#include "cqtextedit.h"
#include <QDebug>

cqtextedit :: cqtextedit(QWidget *parent)
{ 
 setParent(parent);
 setAcceptRichText(true);
 setFocusPolicy(Qt::NoFocus);
 connect(this,SIGNAL(selectionChanged()),this,SLOT(enableCopyPaste()));
 connect(this,SIGNAL(focusLost()),this,SLOT(enableDragnDrop()));
 timer = new QTimer();
 connect(timer, SIGNAL(timeout()), this, SLOT(reload()));
 timer->start(100);
 

}

void cqtextedit :: enableCopyPaste()
{
  setFocusPolicy(Qt::StrongFocus);
  setReadOnly(true);
}

void cqtextedit :: enableDragnDrop()
{
  //qDebug() << "Focus lost";
  setFocusPolicy(Qt::NoFocus);
  setReadOnly(false);
}

void cqtextedit :: reload()
{
 setLineWrapColumnOrWidth(lineWrapColumnOrWidth()); // causes reload
}


void cqtextedit::focusOutEvent( QFocusEvent * event )
{
 if((event->reason()==Qt::MouseFocusReason) ||      
    (event->reason()==Qt::TabFocusReason) ||
    (event->reason()==Qt::ActiveWindowFocusReason))
 {
  emit focusLost();
 }
 QTextEdit :: focusOutEvent(event);
}

bool cqtextedit::canInsertFromMimeData( const QMimeData *source ) const
 {
    if (source->hasFormat("text/uri-list"))
        { 
          return true;
        }
     else
         return QTextEdit::canInsertFromMimeData(source);
 }

void cqtextedit::insertFromMimeData( const QMimeData *source )
 {
     setReadOnly(true);
     if (source->hasFormat("text/uri-list"))
     {
         QTextCursor cursor = this->textCursor();
         QString origin = source->urls()[0].toLocalFile();
         #ifdef Q_OS_LINUX  //toLocalFile() doesn't work
          origin = source->urls()[0].toString();
          origin.remove("file://");
         #endif
         #ifdef Q_OS_WIN32
          origin = source->urls()[0].toString();
          origin.remove("file:///");
         #endif
         emit fileSendInitiated(origin,0,0);
     } else QTextEdit::insertFromMimeData(source);
 }





