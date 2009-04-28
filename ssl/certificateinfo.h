#ifndef CERTIFICATEINFO_H
#define CERTIFICATEINFO_H

#include <QtGui/QDialog>
#include <QtNetwork/QSslCertificate>

QT_BEGIN_NAMESPACE
class Ui_CertificateInfo;
QT_END_NAMESPACE

class CertificateInfo : public QDialog
{
    Q_OBJECT
public:
    CertificateInfo(QWidget *parent = 0);
    ~CertificateInfo();

    void setCertificateChain(const QList<QSslCertificate> &chain);

private slots:
    void updateCertificateInfo(int index);

private:
    Ui_CertificateInfo *form;
    QList<QSslCertificate> chain;
};

#endif
