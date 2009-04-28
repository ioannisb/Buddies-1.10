/***************************************************************************
 *   Copyright (C) 2008 by Balázs Béla 					   *
 *   balazsbela@gmail.com 						   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include <QApplication>
#include "qSslChat.h"
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
  Q_INIT_RESOURCE(qSslChat);
  QApplication app(argc,argv);
  QCoreApplication :: addLibraryPath(".");
 /*
  int mode;
  cout << "Mode (1-Server,2-Client,3-Mixed):";
  cin >> mode;
    
  if(mode==1)
   {
    qDebug() << "Running in Server mode";
    Server *server = new Server();
   }
   else
    if(mode==2) 
     {
       qDebug() << "Running in Client mode";
       Client *client=new Client();    
     }
     else
      if(mode==3)
       {
        qDebug() << "Running in Mixed mode";
        Server *server = new Server();
        Client *client = new Client();
       }*/
 
   if (!QSslSocket::supportsSsl()) {
         QMessageBox::information(0, "qSslChat","qSslChat requires OpenSSL to run.Please install it");
         return -1;
     }
   
  QFile file("mycert.pem");
  if(!file.exists())
   {
     QMessageBox::information(0, "qSslChat","qSslChat needs an SSL certificate and an SSL RSA Private key to work.Both of them have to be in the mycert.pem file.You can generate them with the shell script which was provided.");
     return -1;
   }
 
  qSslChat *sslchat = new qSslChat();
  sslchat -> showMaximized();
  return app.exec();
} 
