#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "jsonreader.h"
#include <sstream>
#include <iomanip>
#include <QMovie>
#include <QIcon>
#include <QListWidgetItem>
#include <QSize>
#include <unistd.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        spazi = new QString("  ");
        ui->setupUi(this);
        ui->logoLabel2->setScaledContents(true);
        QMovie* logoGIF = new QMovie(":/images/images/logobase2.gif");
        ui->logoLabel1->setScaledContents(true);
        ui->logoLabel2->setMovie(logoGIF);
        logoGIF->start();
        //QLabel* labello = new QLabel();
        //labello->setPixmap(getIcona("Clear"));
        //QAction* azione = new QAction(this);
        //QIcon* icona = new QIcon();
        //icona->addPixmap(getIcona("Clear"));
        //azione->setIcon(*icona);
    }

MainWindow::~MainWindow()
{
    delete ui;
}

QPixmap MainWindow::getIcona(QString stringa){

    if(stringa == "Clear"){
        QPixmap pixSunny(":/icons/images/sunny.png");
        return pixSunny;
    }
    if(stringa == "Clouds"){
        QPixmap pixCloudy(":/icons/images/cloudy.png");
        return pixCloudy;
    }
    if(stringa == "Rain"){
        QPixmap pixCloudy(":/icons/images/rainy.png");
        return pixCloudy;
    }
    if(stringa == "Snow"){
        QPixmap pixSnow(":/icons/images/snowy.png");
        return pixSnow;
    }
    else{
        QPixmap noPix(":/images/images/setting.png");
        return noPix;
    }

}

void MainWindow::on_pushButton_clicked()
{
    readerWeather = new JsonReader(this, "http://localhost:5000/app/city/" + ui->lineEdit->text().toStdString());
}

void MainWindow::updateWindow(){

    // Clear the listWidget

    ui->listWidget->clear();

    // Name of the city and country
    ui->fullPlaceName->setText(readerWeather->decode("cityName") + ", " + readerWeather->decode("country"));
    // Icon of the current weather status

    //qDebug() << readerWeather->decodeList("list","dt")[0] << "\n";
    ui->weatherIconMain->setPixmap(getIcona(readerWeather->decodeList("weather",0)));
    ui->weatherIconMain->setScaledContents(true);

    QString description = readerWeather->decodeList("description", 0);
    description[0] = description.at(0).toTitleCase();
    ui->Description->setText(description);
    ui->Umidity->setText("Humidity: " + readerWeather->decode("humidity") + "%");
    std::ostringstream windstream;
    windstream << std::setprecision(3) << readerWeather->decode("wind").toFloat();
    QString windFetched = QString::fromUtf8(windstream.str().c_str());
    ui->Wind->setText("Wind speed: " + windFetched  + " km/h");


    /* Temperature can be in celsius or kelvin
    To chose, press the options button */

    if(true){
        std::ostringstream strs;
        strs << std::setprecision(3) << readerWeather->decodeList("temp", 0).toFloat() - 273.15;
        QString tempFetched = QString::fromUtf8(strs.str().c_str());
        ui->Temperature->setText("Temperature: " + tempFetched + " °C");
    }
    else{
        ///QString tempFetched = readerWeather->fetch("main", "temp");
        ///ui->Temperature->setText("Temperature: " + tempFetched + " °C");
    }

    /*  Function to retrieve the informations about the forecast in next few hours/days
     */
    /*QListWidgetItem* item1 = new QListWidgetItem();
    item1->setIcon(getIcona("Clear"));
    item1->setText("Meteo");
    item1->setSizeHint(QSize((ui->listWidget->width()),(ui->listWidget->height()/4)));
    QListWidgetItem* item2 = new QListWidgetItem();
    QIcon* iconaRed = new QIcon(getIcona("Clouds"));
    iconaRed->pixmap(QSize(80,80));
    item2->setIcon(*iconaRed);
    item2->setText("Meteo2");
    item2->setSizeHint(QSize((ui->listWidget->width()),(ui->listWidget->height()/4)));

    ui->listWidget->addItem(item1);
    ui->listWidget->addItem(item2);

    /****/
    if(true){
        for(int i=0;i<30;i++){
            QListWidgetItem* item = new QListWidgetItem();
            item->setIcon(getIcona(readerWeather->decodeList("weather", i)));
            std::ostringstream temps;
            temps << std::setprecision(3) << readerWeather->decodeList("temp", i).toFloat() - 273.15;
            QString tempFetched = QString::fromUtf8(temps.str().c_str());
            item->setText(readerWeather->decodeList("description", i) + " | " + tempFetched + "°C | " + readerWeather->decodeList("time", i));
            item->setForeground(Qt::blue);
            item->setBackground(Qt::white);
            ui->listWidget->addItem(item);
        }
    }
    else {
        ///alt
    }

    /****/

}
