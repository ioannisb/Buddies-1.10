#include "filesend.h"



fileSendDialog :: fileSendDialog(fileSend *p,int mode,qint64 size)
{
 setModal(false);
 parent=p;
 acceptButton = new QPushButton(tr("Accept"));
 rejectButton = new QPushButton(tr("Reject"));
 
 QHBoxLayout *buttonLayout = new QHBoxLayout();
 buttonLayout -> addWidget(acceptButton);
 buttonLayout -> addWidget(rejectButton);

 getFileName(p -> filePath);
 if(mode==1) 
  {
    fsLabel = new QLabel(tr("Sending file")+QString(" ")+fName+QString("(")+QString::number(size)+QString(" B)"));
    setWindowTitle(tr("Sending file"));
  } 
  else 
   {
     if(mode==2) fsLabel = new QLabel(tr("Receiving file")+QString(" ")+fName+QString("(")+QString::number(size)+QString(" B)"));
     setWindowTitle(tr("Receiving file")); 
   }
 
 progressBar = new QProgressBar();
 progressBar -> setMinimumWidth(150);
 progressBar -> setRange(0,100); 
 progressBar -> setValue(0);

 cancelButton = new QPushButton(tr("Cancel"));

 QHBoxLayout *progressLayout = new QHBoxLayout;
 progressLayout -> addWidget(progressBar);
 progressLayout -> addWidget(cancelButton);
 

 QVBoxLayout *mainLayout = new QVBoxLayout();
 mainLayout -> addWidget(fsLabel);
 mainLayout -> addLayout(progressLayout);
 if(mode==2) mainLayout -> addLayout(buttonLayout);
 
 setLayout(mainLayout);

 connect(acceptButton,SIGNAL(clicked()),this,SLOT(acceptFile()));
 connect(rejectButton,SIGNAL(clicked()),this,SLOT(rejectFile()));
 connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancelTransaction()));


 show();
}

void fileSendDialog :: getFileName(QString path)
{
 QString fileName;
 QString tempName;
 for(int i=path.size()-1;i>=0;i--)
  {
   if(path[i]!=QChar('/'))
    {
     if(path[i]!=QChar('\\'))
      {
       tempName += path[i];
      } 
    }
    else break;
  }

 for(int i=tempName.size()-1;i>=0;i--)
  {
   fileName += tempName[i];
  }
 
 fName = fileName; 

}

void fileSendDialog :: acceptFile()
{
  QString dPath = QFileDialog::getSaveFileName(this, tr("Save File"),fName,"");
  acceptButton -> hide();
  rejectButton -> hide();
  emit acceptedFile(dPath);
}

void fileSendDialog :: rejectFile()
{
 emit rejectedFile();
 close();
}

void fileSendDialog :: cancelTransaction()
{
 emit transactionCancelled();
 close();
}

void  fileSendDialog :: updateProgressDialog(int value)
{
  if(value>100) value=100;
  progressBar -> setValue(value);
  if(value>=100) cancelButton -> hide();
}

fileSendDialog :: ~fileSendDialog()
{
}

