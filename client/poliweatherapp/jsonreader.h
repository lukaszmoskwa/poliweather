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
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
//#include "mainwindow.h"

class MainWindow;

class JsonReader : public QObject
{
    Q_OBJECT
public:
    JsonReader(MainWindow* uiWindow, std::string url);
    virtual ~JsonReader() {};
    QString decode(std::string request);
    QString decodeList(std::string request, int index);
signals:
public slots:
    void replyFinished(QNetworkReply *reply);
private:
    QNetworkAccessManager *manager;
    QVariantMap map;
    MainWindow* uiWindow;
    boost::property_tree::ptree tree;
};

#endif // JSONREADER_H
