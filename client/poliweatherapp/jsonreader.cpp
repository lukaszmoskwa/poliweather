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

QString JsonReader::decode(std::string request){
    return QString(tree.get<std::string>(request).c_str());
}

QString JsonReader::decodeList(std::string request, int index){
    std::vector<std::string> dataVector = {};
    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, tree.get_child(request)) {
           // The data function is used to access the data stored in a node
        dataVector.push_back(v.second.data());
    }
    return QString(dataVector.at(index).c_str());
    //return QString(tree.get<std::string>(request, index).c_str());
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
