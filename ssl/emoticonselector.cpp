#include "emoticonselector.h"
#include <QDir>
#include <QFileInfo>
#include <QToolButton>
#include <QApplication>
#include <QDesktopWidget>


EmoticonSelector :: EmoticonSelector(QWidget *parent)
{
  //setParent(parent);
  Q_UNUSED(parent);
  setWindowFlags(Qt::FramelessWindowHint);
  mainLayout = new QGridLayout(this);
  mainLayout -> setSpacing(0);
  createMap();
  loadSmileys();
}

void EmoticonSelector :: loadSmileys()
{
  QDir dir = QDir(":/emoticons");
  QString filter = "*.gif";
  QFileInfoList entries = dir.entryInfoList();
  int row=0;
  int column=0;
  foreach (QFileInfo file, entries)
   {
     QToolButton *smileyButton = new QToolButton();
     if (column>=7)  
      {   
        column=0;
        row ++;
      }
     smileyButton -> setIcon(QIcon(QString(":/emoticons/")+file.baseName()+QString(".gif")));
     smileyButton -> setIconSize(QSize(20,20)); 
     smileyButton -> setObjectName(file.baseName());
     smileyButton -> setToolTip(smileyMap[file.baseName()]);
     mainLayout -> addWidget(smileyButton,row,column,Qt::AlignHCenter);
     mainLayout -> setColumnMinimumWidth(column,20);
     mainLayout -> setColumnStretch(column,0);
     column++;
     
     connect(smileyButton,SIGNAL(clicked()),this,SLOT(addSmiley())); 
   }

}

void EmoticonSelector :: addSmiley()
{
  QToolButton *sender = qobject_cast<QToolButton *>(QObject::sender() );
  QString name = sender -> objectName(); 
  QString code = smileyMap[name];
  emit smileySelected(name,code);
  hide();
}


void EmoticonSelector::alignTo(QWidget* w)
{
  QPoint w_pos = w->mapToGlobal(QPoint(0,0));
  QSize e_size = sizeHint();
  QSize s_size = QApplication::desktop()->size();
  int l_dist = w_pos.x();
  int r_dist = s_size.width() - (w_pos.x() + w->width());
  int x;
  if (l_dist >= r_dist)
  	x = w_pos.x() - e_size.width();
    else
	x = w_pos.x() + w->width();
  int y = w_pos.y() + w->height()/2 - e_size.height()/2;
  if (y + e_size.height() > s_size.height())
 	y = s_size.height() - e_size.height();
  if (y < 0) y = 0;
  move(x+105, y-70);
}

void EmoticonSelector :: changeEvent(QEvent * event)
{
  if(event -> type() == QEvent::ActivationChange)
   {
    if(!isActiveWindow()) hide();
   }
  QDialog :: changeEvent(event);
}

void EmoticonSelector :: createMap()
{
  smileyMap.insert(QString("06"),QString(">:D<"));
  smileyMap.insert(QString("67"),QString(":)>-"));
  smileyMap.insert(QString("100"),QString(":)]"));
  smileyMap.insert(QString("20"),QString(":(("));
  smileyMap.insert(QString("21"),QString(":))"));
  smileyMap.insert(QString("19"),QString(">:)"));
  smileyMap.insert(QString("71"),QString(";))"));
  smileyMap.insert(QString("05"),QString(";;)"));
  smileyMap.insert(QString("03"),QString(";)"));
  smileyMap.insert(QString("07"),QString(":-/"));
  smileyMap.insert(QString("12"),QString("=(("));
  smileyMap.insert(QString("23"),QString("/:)"));
  smileyMap.insert(QString("24"),QString("=))"));
  smileyMap.insert(QString("27"),QString("=;"));
  smileyMap.insert(QString("37"),QString("(:|"));
  smileyMap.insert(QString("106"),QString(":-??"));
  smileyMap.insert(QString("43"),QString("@:)"));
  smileyMap.insert(QString("61"),QString(">-)"));
  smileyMap.insert(QString("76"),QString(":-@"));
  smileyMap.insert(QString("77"),QString("^:)^"));
  smileyMap.insert(QString("102"),QString("~x("));
  smileyMap.insert(QString("103"),QString(":-h"));
  smileyMap.insert(QString("104"),QString(":-t"));
  smileyMap.insert(QString("70"),QString(">:/"));
  smileyMap.insert(QString("09"),QString(":\">"));
  smileyMap.insert(QString("26"),QString(":-B"));
  smileyMap.insert(QString("30"),QString("l-)"));
  smileyMap.insert(QString("31"),QString(":-&"));
  smileyMap.insert(QString("32"),QString(":-$"));
  smileyMap.insert(QString("33"),QString("[-("));
  smileyMap.insert(QString("47"),QString(">:P"));
  smileyMap.insert(QString("36"),QString("<:P"));
  smileyMap.insert(QString("45"),QString(":-w"));
  smileyMap.insert(QString("59"),QString("8-X"));
  smileyMap.insert(QString("63"),QString("[-O>"));
  smileyMap.insert(QString("66"),QString("B-("));
  smileyMap.insert(QString("78"),QString(":-j"));
  smileyMap.insert(QString("15"),QString(":-<"));
  smileyMap.insert(QString("42"),QString(":-SS"));
  smileyMap.insert(QString("17"),QString(":-S"));
  smileyMap.insert(QString("14"),QString("x-("));
  smileyMap.insert(QString("08"),QString(":-x"));
  smileyMap.insert(QString("10"),QString(":P"));
  smileyMap.insert(QString("11"),QString(":-*"));
  smileyMap.insert(QString("04"),QString(":D"));
  smileyMap.insert(QString("01"),QString(":)"));
  smileyMap.insert(QString("02"),QString(":("));
  smileyMap.insert(QString("22"),QString(":|"));
  smileyMap.insert(QString("39"),QString(":-?"));

}

EmoticonSelector :: ~EmoticonSelector()
{
}



