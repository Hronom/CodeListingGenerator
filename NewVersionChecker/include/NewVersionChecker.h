#ifndef NEWVERSIONCHECKER_H
#define NEWVERSIONCHECKER_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;
class QNetworkRequest;

class NewVersionChecker: public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *mNetworkAccessManager;
    bool mCheckLaunched;

public:
    NewVersionChecker(QObject *xParent);
    void checkVersion(QString &xVersionFileLink);

private slots:
    void requestFinished(QNetworkReply *xNetworkReply);

signals:
    void versionChecked(QString xCurrentVersion, QString xDownloadLink);
    void versionNotChecked(QString xError);
};

#endif // NEWVERSIONCHECKER_H
