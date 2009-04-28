#include <QWidget>
#include <QGridLayout>
#include <QDialog>
#include <QEvent>
#include <QMap>

class EmoticonSelector : public QDialog
{
  Q_OBJECT
  public:
   EmoticonSelector(QWidget *parent);
   ~EmoticonSelector();
   void loadSmileys();
   void createMap();
   void alignTo(QWidget* w);
   void changeEvent(QEvent * event);
 
   QGridLayout *mainLayout;   
   QMap <QString,QString> smileyMap;
 
   public slots:
    void addSmiley();

   signals: 
    void smileySelected(QString name,QString code);
};













