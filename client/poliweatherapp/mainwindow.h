#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QMenuBar>
#include <QMenu>

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
    void on_filters_clicked();
    void set_celsius();
    void set_kelvin();

private:
    Ui::MainWindow* ui;
    JsonReader* readerWeather;
    JsonReader* readerForecast;
    QString spacing;
    int tempUnit;
    QMenu* menuSettings;

};

#endif // MAINWINDOW_H
