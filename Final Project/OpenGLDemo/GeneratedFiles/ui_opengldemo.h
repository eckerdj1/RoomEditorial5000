/********************************************************************************
** Form generated from reading UI file 'opengldemo.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLDEMO_H
#define UI_OPENGLDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "LoadTextBox.h"
#include "MyGLWidget.h"
#include "RotateDial.h"
#include "RotateSlider.h"
#include "ZoomSlider.h"

QT_BEGIN_NAMESPACE

class Ui_OpenGLDemoClass
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    RotateDial *dial;
    QLabel *label;
    QLabel *label_2;
    ZoomSlider *verticalSlider;
    RotateSlider *verticalSlider_2;
    QLabel *label_3;
    LoadTextBox *lineEdit;
    QPushButton *pushButton;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QSlider *horizontalSlider_2;
    QLabel *label_5;
    QSlider *verticalSlider_3;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenGLDemoClass)
    {
        if (OpenGLDemoClass->objectName().isEmpty())
            OpenGLDemoClass->setObjectName(QStringLiteral("OpenGLDemoClass"));
        OpenGLDemoClass->resize(807, 701);
        centralWidget = new QWidget(OpenGLDemoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 9, 671, 551));
        dial = new RotateDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(700, 60, 101, 81));
        dial->setLayoutDirection(Qt::LeftToRight);
        dial->setMaximum(360);
        dial->setValue(45);
        dial->setSliderPosition(45);
        dial->setOrientation(Qt::Horizontal);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 10, 111, 51));
        QFont font;
        font.setFamily(QStringLiteral("Terminal"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(700, 140, 101, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Terminal"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        verticalSlider = new ZoomSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(700, 190, 22, 181));
        verticalSlider->setMinimum(10);
        verticalSlider->setMaximum(100);
        verticalSlider->setSingleStep(1);
        verticalSlider->setValue(100);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedControls(true);
        verticalSlider_2 = new RotateSlider(centralWidget);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(760, 190, 22, 181));
        verticalSlider_2->setMinimum(-85);
        verticalSlider_2->setMaximum(85);
        verticalSlider_2->setOrientation(Qt::Vertical);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(680, 370, 111, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Terminal"));
        font2.setPointSize(9);
        label_3->setFont(font2);
        lineEdit = new LoadTextBox(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(680, 430, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 460, 111, 31));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 570, 221, 22));
        horizontalSlider->setMinimum(-100);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 600, 141, 31));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(380, 570, 241, 22));
        horizontalSlider_2->setMinimum(-100);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(390, 600, 221, 31));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        verticalSlider_3 = new QSlider(centralWidget);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(770, 509, 22, 131));
        verticalSlider_3->setMinimum(1);
        verticalSlider_3->setMaximum(100);
        verticalSlider_3->setValue(5);
        verticalSlider_3->setOrientation(Qt::Vertical);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(700, 520, 61, 91));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 600, 75, 23));
        OpenGLDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OpenGLDemoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 807, 21));
        OpenGLDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OpenGLDemoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OpenGLDemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OpenGLDemoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OpenGLDemoClass->setStatusBar(statusBar);

        retranslateUi(OpenGLDemoClass);
        QObject::connect(dial, SIGNAL(valueChanged(int)), widget, SLOT(rotateCameraY(int)));
        QObject::connect(verticalSlider, SIGNAL(sliderMoved(int)), widget, SLOT(zoomCamera(int)));
        QObject::connect(verticalSlider_2, SIGNAL(sliderMoved(int)), widget, SLOT(rotateCameraX(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit, SLOT(accept()));
        QObject::connect(lineEdit, SIGNAL(loadFile(string)), widget, SLOT(loadNewScene(string)));
        QObject::connect(horizontalSlider_2, SIGNAL(sliderMoved(int)), widget, SLOT(lightZ(int)));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), widget, SLOT(lightX(int)));
        QObject::connect(verticalSlider_3, SIGNAL(sliderMoved(int)), widget, SLOT(lightY(int)));
        QObject::connect(verticalSlider_2, SIGNAL(valueChanged(int)), widget, SLOT(rotateCameraX(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), widget, SLOT(zoomCamera(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(lightX(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), widget, SLOT(lightZ(int)));
        QObject::connect(verticalSlider_3, SIGNAL(valueChanged(int)), widget, SLOT(lightY(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(nextGeo()));

        QMetaObject::connectSlotsByName(OpenGLDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGLDemoClass)
    {
        OpenGLDemoClass->setWindowTitle(QApplication::translate("OpenGLDemoClass", "OpenGLDemo", 0));
        label->setText(QApplication::translate("OpenGLDemoClass", "Camera Controls", 0));
        label_2->setText(QApplication::translate("OpenGLDemoClass", "Rotate", 0));
        label_3->setText(QApplication::translate("OpenGLDemoClass", " Zoom  Up/Down", 0));
        pushButton->setText(QApplication::translate("OpenGLDemoClass", "Load Config File", 0));
        label_4->setText(QApplication::translate("OpenGLDemoClass", "Light Left/Right", 0));
        label_5->setText(QApplication::translate("OpenGLDemoClass", "Light Forward/Back", 0));
        label_6->setText(QApplication::translate("OpenGLDemoClass", "Light Height", 0));
        pushButton_2->setText(QApplication::translate("OpenGLDemoClass", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenGLDemoClass: public Ui_OpenGLDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLDEMO_H
