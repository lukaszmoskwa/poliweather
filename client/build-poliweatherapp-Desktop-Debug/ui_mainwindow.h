/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *centralFrame;
    QGridLayout *layoutInner;
    QLabel *weatherIconMain;
    QLabel *fullPlaceName;
    QFrame *line_3;
    QFrame *line;
    QFrame *line_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Description;
    QLabel *Wind;
    QLabel *Temperature;
    QLabel *Umidity;
    QLineEdit *lineEdit;
    QFrame *bottomFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *filters;
    QLabel *emptyLabel;
    QPushButton *options;
    QPushButton *pushButton;
    QFrame *upperFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logoLabel2;
    QLabel *logoLabel1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 680));
        MainWindow->setMaximumSize(QSize(400, 680));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(51, 73, 95);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        centralFrame = new QFrame(centralWidget);
        centralFrame->setObjectName(QStringLiteral("centralFrame"));
        centralFrame->setStyleSheet(QStringLiteral("background-color: rgba(0, 170, 255, 30);"));
        layoutInner = new QGridLayout(centralFrame);
        layoutInner->setSpacing(6);
        layoutInner->setContentsMargins(11, 11, 11, 11);
        layoutInner->setObjectName(QStringLiteral("layoutInner"));
        weatherIconMain = new QLabel(centralFrame);
        weatherIconMain->setObjectName(QStringLiteral("weatherIconMain"));
        weatherIconMain->setMinimumSize(QSize(100, 100));
        weatherIconMain->setMaximumSize(QSize(100, 100));
        weatherIconMain->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));

        layoutInner->addWidget(weatherIconMain, 2, 0, 1, 1);

        fullPlaceName = new QLabel(centralFrame);
        fullPlaceName->setObjectName(QStringLiteral("fullPlaceName"));
        fullPlaceName->setMinimumSize(QSize(0, 50));
        fullPlaceName->setMaximumSize(QSize(16777215, 50));
        fullPlaceName->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 15pt \"DejaVu Sans\";\n"
"background-color:rgba(0,0,0,0);"));

        layoutInner->addWidget(fullPlaceName, 0, 0, 1, 4);

        line_3 = new QFrame(centralFrame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        layoutInner->addWidget(line_3, 6, 0, 1, 4);

        line = new QFrame(centralFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        layoutInner->addWidget(line, 1, 0, 1, 4);

        line_4 = new QFrame(centralFrame);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        layoutInner->addWidget(line_4, 4, 0, 1, 4);

        scrollArea = new QScrollArea(centralFrame);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(360, 0));
        scrollArea->setMaximumSize(QSize(360, 16777215));
        scrollArea->setStyleSheet(QLatin1String("/*QScrollBar:handle:vertical {\n"
"background: rgb(170, 170, 255);\n"
"}\n"
"QScrollBar:up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"background:rgb(170, 170, 255);\n"
"}*/"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 358, 278));
        listWidget = new QListWidget(scrollAreaWidgetContents);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 1, 361, 291));
        scrollArea->setWidget(scrollAreaWidgetContents);

        layoutInner->addWidget(scrollArea, 5, 0, 1, 4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Description = new QLabel(centralFrame);
        Description->setObjectName(QStringLiteral("Description"));
        Description->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 13pt \"DejaVu Sans\";\n"
"background-color:rgba(0,0,0,0);"));

        verticalLayout->addWidget(Description);

        Wind = new QLabel(centralFrame);
        Wind->setObjectName(QStringLiteral("Wind"));
        Wind->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 13pt \"DejaVu Sans\";\n"
"background-color:rgba(0,0,0,0);"));

        verticalLayout->addWidget(Wind);

        Temperature = new QLabel(centralFrame);
        Temperature->setObjectName(QStringLiteral("Temperature"));
        Temperature->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 13pt \"DejaVu Sans\";\n"
"background-color:rgba(0,0,0,0);"));

        verticalLayout->addWidget(Temperature);

        Umidity = new QLabel(centralFrame);
        Umidity->setObjectName(QStringLiteral("Umidity"));
        Umidity->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 13pt \"DejaVu Sans\";\n"
"background-color:rgba(0,0,0,0);"));

        verticalLayout->addWidget(Umidity);


        layoutInner->addLayout(verticalLayout, 2, 1, 1, 3);


        gridLayout->addWidget(centralFrame, 2, 0, 1, 2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 255);"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        bottomFrame = new QFrame(centralWidget);
        bottomFrame->setObjectName(QStringLiteral("bottomFrame"));
        bottomFrame->setMinimumSize(QSize(0, 40));
        bottomFrame->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(bottomFrame);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        filters = new QPushButton(bottomFrame);
        filters->setObjectName(QStringLiteral("filters"));
        filters->setMinimumSize(QSize(30, 30));
        filters->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/language.png"), QSize(), QIcon::Normal, QIcon::Off);
        filters->setIcon(icon);
        filters->setIconSize(QSize(24, 24));
        filters->setFlat(true);

        horizontalLayout->addWidget(filters);

        emptyLabel = new QLabel(bottomFrame);
        emptyLabel->setObjectName(QStringLiteral("emptyLabel"));
        emptyLabel->setMinimumSize(QSize(0, 30));
        emptyLabel->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(emptyLabel);

        options = new QPushButton(bottomFrame);
        options->setObjectName(QStringLiteral("options"));
        options->setMinimumSize(QSize(30, 30));
        options->setMaximumSize(QSize(30, 30));
        options->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        options->setIcon(icon1);
        options->setIconSize(QSize(24, 24));
        options->setFlat(true);

        horizontalLayout->addWidget(options);


        gridLayout->addWidget(bottomFrame, 3, 0, 1, 2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("font: 10pt \"Abyssinica SIL\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(20, 116, 208);"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        upperFrame = new QFrame(centralWidget);
        upperFrame->setObjectName(QStringLiteral("upperFrame"));
        upperFrame->setMaximumSize(QSize(16777215, 90));
        horizontalLayout_2 = new QHBoxLayout(upperFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        logoLabel2 = new QLabel(upperFrame);
        logoLabel2->setObjectName(QStringLiteral("logoLabel2"));
        logoLabel2->setMinimumSize(QSize(90, 90));
        logoLabel2->setMaximumSize(QSize(90, 90));

        horizontalLayout_2->addWidget(logoLabel2);

        logoLabel1 = new QLabel(upperFrame);
        logoLabel1->setObjectName(QStringLiteral("logoLabel1"));
        logoLabel1->setMinimumSize(QSize(0, 90));
        logoLabel1->setMaximumSize(QSize(16777215, 90));
        logoLabel1->setStyleSheet(QStringLiteral("image: url(:/images/images/logo-scritta.png);"));

        horizontalLayout_2->addWidget(logoLabel1);


        gridLayout->addWidget(upperFrame, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Poli Weather", 0));
        weatherIconMain->setText(QApplication::translate("MainWindow", "text", 0));
        fullPlaceName->setText(QApplication::translate("MainWindow", "No Data Loaded", 0));
        Description->setText(QApplication::translate("MainWindow", "text", 0));
        Wind->setText(QApplication::translate("MainWindow", "text", 0));
        Temperature->setText(QApplication::translate("MainWindow", "text", 0));
        Umidity->setText(QApplication::translate("MainWindow", "text", 0));
        filters->setText(QString());
        emptyLabel->setText(QString());
        options->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Check", 0));
        pushButton->setShortcut(QApplication::translate("MainWindow", "Return", 0));
        logoLabel2->setText(QString());
        logoLabel1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
