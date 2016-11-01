#include "jsonreader.h"
#include "mainwindow.h"
#include <QDebug>

JsonReader::JsonReader(MainWindow* uiWindow, std::string url)
{
    this->uiWindow =uiWindow;
    manager = new QNetworkAccessManager();

    connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl(url.c_str())));
}

QString JsonReader::fetch(QString key){
    return map[key].toString();
}

QString JsonReader::fetch(QString key1, QString key2, int index){
    return map[key1].toList()[index].toMap()[key2].toString();
}


/*Funzione utile*/
QString JsonReader::fetch(QString key1, QString key2, QString key3, int index){
    qDebug() << map[key1].toList()[index].toMap()[key2].toList()[0].toMap()[key3].toString();
    //return "Clear";
    return map[key1].toList()[index].toMap()[key2].toList()[0].toMap()[key3].toString();
}

QString JsonReader::fetchOther(QString key1, QString key2, QString key3, int index){
    qDebug() << map[key1].toList()[index].toMap()[key2].toMap()[key3].toString();
    //return "Clear";
    return map[key1].toList()[index].toMap()[key2].toList()[0].toMap()[key3].toString();
}

QString JsonReader::fetch(QString key1, QString key2){
    return map[key1].toMap()[key2].toString();
}

double JsonReader::fetchDouble(QString key1, QString key2){
    return map[key1].toMap()[key2].toDouble();
}

void JsonReader::replyFinished(QNetworkReply *reply){
    if(reply->error())
        {
            qDebug() << "ERROR!";
            qDebug() << reply->errorString();
        }
    else{
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject object = document.object();
        map = object.toVariantMap();

        //qDebug() << map["coord"].toMap()["lat"].toDouble();
        uiWindow->updateWindow();
    }
}
