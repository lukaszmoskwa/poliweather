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
#include <QPoint>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ui->logoLabel2->setScaledContents(true);
        QMovie* logoGIF = new QMovie(":/images/images/logobase2.gif");
        ui->logoLabel1->setScaledContents(true);
        ui->logoLabel2->setMovie(logoGIF);
        logoGIF->start();
        setContextMenuPolicy(Qt::CustomContextMenu);

        //Default temperature unit is Celsius
        tempUnit = 0;

        // Creation of the QMenu that will show the choice between Kelvin and Celsius
        menuSettings = new QMenu();
        QAction* setkelvin_menu = menuSettings->addAction("Set to Kelvin");
        QAction* setcelsius_menu = menuSettings->addAction("Set to Celsius");
        connect(setkelvin_menu, SIGNAL(triggered()), this, SLOT(set_kelvin()));
        connect(setcelsius_menu, SIGNAL(triggered()), this, SLOT(set_celsius()));

    }

MainWindow::~MainWindow()
{
    delete ui;
}


//Function used to popup the window for temperature settings
void MainWindow::on_filters_clicked(){
    QPoint point = ui->bottomWidget->pos();
    menuSettings->popup(mapToGlobal(point));
}

void MainWindow::set_celsius(){
    tempUnit = 0;
}

void MainWindow::set_kelvin(){
    tempUnit = 1;
}

//Function that retrieve the correct weather image for every string
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
// Function executed when the Check button is pushed
void MainWindow::on_pushButton_clicked()
{
    readerWeather = new JsonReader(this, "http://poliweather.tk/app/city/" + ui->lineEdit->text().toStdString());
}

// Main update function called to display informations retrieved
void MainWindow::updateWindow(){

    // Clear the listWidged
    ui->listWidget->clear();

    // Name of the city and country
    ui->fullPlaceName->setText(readerWeather->decode("cityName") + ", " + readerWeather->decode("country"));
    ui->fullPlaceName->setAlignment(Qt::AlignCenter);

    spacing =  "   ";

    // Icon of the current weather status
    ui->weatherIconMain->setPixmap(getIcona(readerWeather->decodeList("weather",0)));
    ui->weatherIconMain->setScaledContents(true);

    // Description, Humidity, Temperature and Wind Speed of the current weather
    QString description = readerWeather->decodeList("description", 0);
    description[0] = description.at(0).toTitleCase();
    ui->Description->setText(spacing + description);
    ui->Umidity->setText(spacing + "Humidity: " + readerWeather->decode("humidity") + "%");
    std::ostringstream windstream;
    windstream << std::setprecision(3) << readerWeather->decode("wind").toFloat();
    QString windFetched = QString::fromUtf8(windstream.str().c_str());
    ui->Wind->setText(spacing + "Wind speed: " + windFetched  + " km/h");


    /* Temperature can be in celsius or kelvin
    To chose, press the options button. tempUnit = 0 is for Celsius, tempUnit = 1 for Kelvin */
    QString tempFetched;
    if(tempUnit == 0){
        std::ostringstream strs;
        strs << std::setprecision(3) << readerWeather->decodeList("temp", 0).toFloat() - 273.15;
        tempFetched = QString::fromUtf8(strs.str().c_str());
        ui->Temperature->setText(spacing + "Temperature: " + tempFetched + " °C");
    }
    else{
        std::ostringstream strs;
        strs << std::setprecision(3) << readerWeather->decodeList("temp", 0).toFloat();
        tempFetched =  QString::fromUtf8(strs.str().c_str());
        ui->Temperature->setText(spacing + "Temperature: " + tempFetched + " K");
    }

    /*  Function to retrieve the informations about the forecast in next few hours/days
     */
    for(int i=0;i<30;i++){
        QListWidgetItem* item = new QListWidgetItem();
        item->setIcon(getIcona(readerWeather->decodeList("weather", i)));
        QString tempFetched;
        if(tempUnit == 0){
            std::ostringstream temps;
            temps << std::setprecision(3) << readerWeather->decodeList("temp", i).toFloat() - 273.15;
            tempFetched = QString::fromUtf8(temps.str().c_str()) + "°C | ";
        }
        else {
            std::ostringstream temps;
            temps << std::setprecision(3) << readerWeather->decodeList("temp", i).toFloat();
            tempFetched = QString::fromUtf8(temps.str().c_str()) + "K | ";
        }
        item->setText(readerWeather->decodeList("description", i) + " | " + tempFetched + readerWeather->decodeList("time", i));
        item->setForeground(Qt::black);
        item->setBackground(Qt::white);
        ui->listWidget->addItem(item);
    }

}
