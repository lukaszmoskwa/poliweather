#ifndef JSONREADER_H
#define JSONREADER_H

#include <string>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QString>
//#include "mainwindow.h"

class MainWindow;

class JsonReader : public QObject
{
    Q_OBJECT
public:
    JsonReader(MainWindow* uiWindow, std::string url);
    virtual ~JsonReader() {};
    QString fetch(QString key);
    QString fetch(QString key1, QString key2);
    QString fetch(QString key1, QString key2, int index);
    QString fetch(QString key1, QString key2, QString key3, int index);
    QString fetchOther(QString key1, QString key2, QString key3, int index);
    double fetchDouble(QString key1, QString key2);
signals:
public slots:
    void replyFinished(QNetworkReply *reply);
private:
    QNetworkAccessManager *manager;
    QVariantMap map;
    MainWindow* uiWindow;
};

#endif // JSONREADER_H
