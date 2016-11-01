#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QString>

//#include "jsonreader.h"

class JsonReader;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateWindow();
    QPixmap getIcona(QString stringa);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    JsonReader* readerWeather;
    JsonReader* readerForecast;
    QString* spazi;
};

#endif // MAINWINDOW_H
