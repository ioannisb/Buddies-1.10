/********************************************************************************
** Form generated from reading ui file 'certificateinfo.ui'
**
** Created: Mon Apr 27 15:00:48 2009
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CERTIFICATEINFO_H
#define UI_CERTIFICATEINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CertificateInfo
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QHBoxLayout *hboxLayout;
    QListWidget *certificationPathView;
    QGroupBox *groupBox_2;
    QHBoxLayout *hboxLayout1;
    QListWidget *certificateInfoView;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CertificateInfo)
    {
    if (CertificateInfo->objectName().isEmpty())
        CertificateInfo->setObjectName(QString::fromUtf8("CertificateInfo"));
    CertificateInfo->resize(400, 397);
    vboxLayout = new QVBoxLayout(CertificateInfo);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    groupBox = new QGroupBox(CertificateInfo);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    hboxLayout = new QHBoxLayout(groupBox);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    certificationPathView = new QListWidget(groupBox);
    certificationPathView->setObjectName(QString::fromUtf8("certificationPathView"));

    hboxLayout->addWidget(certificationPathView);


    vboxLayout->addWidget(groupBox);

    groupBox_2 = new QGroupBox(CertificateInfo);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    hboxLayout1 = new QHBoxLayout(groupBox_2);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    certificateInfoView = new QListWidget(groupBox_2);
    certificateInfoView->setObjectName(QString::fromUtf8("certificateInfoView"));

    hboxLayout1->addWidget(certificateInfoView);


    vboxLayout->addWidget(groupBox_2);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem);

    buttonBox = new QDialogButtonBox(CertificateInfo);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setStandardButtons(QDialogButtonBox::Close);

    hboxLayout2->addWidget(buttonBox);


    vboxLayout->addLayout(hboxLayout2);


    retranslateUi(CertificateInfo);
    QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), CertificateInfo, SLOT(accept()));

    QMetaObject::connectSlotsByName(CertificateInfo);
    } // setupUi

    void retranslateUi(QDialog *CertificateInfo)
    {
    CertificateInfo->setWindowTitle(QApplication::translate("CertificateInfo", "Display Certificate Information", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("CertificateInfo", "Certification Path", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("CertificateInfo", "Certificate Information", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CertificateInfo);
    } // retranslateUi

};

namespace Ui {
    class CertificateInfo: public Ui_CertificateInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CERTIFICATEINFO_H
