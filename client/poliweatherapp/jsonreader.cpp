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

QString JsonReader::decode(std::string richiesta){
    return QString(tree.get<std::string>(richiesta).c_str());
}

std::vector<std::string> JsonReader::decodeList(std::string richiestaLista, std::string richiestaStringa){
    std::vector<QString> vettore = {};
    for(boost::property_tree::ptree stringa : tree.get_child(richiestaLista)){
        vettore.push_back(stringa.second.get<std::string>(richiestaStringa));
    }
    return vettore;
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


        std::stringstream stream(((std::string)document.toJson()).c_str());
        boost::property_tree::read_json(stream, tree);

        //qDebug() << map["coord"].toMap()["lat"].toDouble();
        uiWindow->updateWindow();
    }
}
