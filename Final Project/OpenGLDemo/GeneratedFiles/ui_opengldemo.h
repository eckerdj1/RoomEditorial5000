/********************************************************************************
** Form generated from reading UI file 'opengldemo.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLDEMO_H
#define UI_OPENGLDEMO_H

#include <NextLabel.h>
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
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    NextLabel *label_10;
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
        widget->setGeometry(QRect(10, 9, 661, 541));
        dial = new RotateDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(700, 60, 101, 81));
        dial->setLayoutDirection(Qt::LeftToRight);
        dial->setMaximum(360);
        dial->setValue(0);
        dial->setSliderPosition(0);
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
        verticalSlider->setGeometry(QRect(700, 190, 22, 141));
        verticalSlider->setMinimum(10);
        verticalSlider->setMaximum(100);
        verticalSlider->setSingleStep(1);
        verticalSlider->setValue(100);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedControls(true);
        verticalSlider_2 = new RotateSlider(centralWidget);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(760, 190, 22, 141));
        verticalSlider_2->setMinimum(-85);
        verticalSlider_2->setMaximum(85);
        verticalSlider_2->setOrientation(Qt::Vertical);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(680, 330, 111, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Terminal"));
        font2.setPointSize(9);
        label_3->setFont(font2);
        lineEdit = new LoadTextBox(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(680, 360, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 390, 111, 31));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(380, 570, 201, 22));
        horizontalSlider->setMinimum(-100);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(410, 600, 141, 31));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(590, 570, 211, 22));
        horizontalSlider_2->setMinimum(-100);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setSliderPosition(55);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(600, 600, 201, 31));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        verticalSlider_3 = new QSlider(centralWidget);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(760, 430, 22, 131));
        verticalSlider_3->setMinimum(1);
        verticalSlider_3->setMaximum(100);
        verticalSlider_3->setValue(80);
        verticalSlider_3->setSliderPosition(80);
        verticalSlider_3->setOrientation(Qt::Vertical);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(690, 430, 61, 91));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 620, 61, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 600, 31, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 610, 31, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 600, 31, 23));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(110, 590, 31, 23));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(80, 620, 31, 23));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(140, 580, 31, 23));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 560, 61, 23));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(290, 580, 75, 23));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(290, 600, 75, 23));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(200, 600, 31, 23));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(230, 620, 31, 23));
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(200, 620, 31, 23));
        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(230, 580, 31, 23));
        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(230, 600, 31, 23));
        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(200, 580, 31, 23));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 560, 101, 20));
        label_7->setFont(font2);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 560, 61, 20));
        label_8->setFont(font2);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(290, 560, 71, 20));
        label_9->setFont(font2);
        label_10 = new NextLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 580, 61, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Old English Text MT"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferDefault);
        label_10->setFont(font3);
        label_10->setFrameShape(QFrame::WinPanel);
        label_10->setFrameShadow(QFrame::Sunken);
        label_10->setLineWidth(1);
        label_10->setAlignment(Qt::AlignCenter);
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
        QObject::connect(verticalSlider_3, SIGNAL(sliderMoved(int)), widget, SLOT(lightY(int)));
        QObject::connect(verticalSlider_2, SIGNAL(valueChanged(int)), widget, SLOT(rotateCameraX(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), widget, SLOT(zoomCamera(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), widget, SLOT(lightZ(int)));
        QObject::connect(verticalSlider_3, SIGNAL(valueChanged(int)), widget, SLOT(lightY(int)));
        QObject::connect(pushButton_9, SIGNAL(clicked()), widget, SLOT(prevGeo()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(nextGeo()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(moveYNeg()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget, SLOT(moveXNeg()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(moveZPos()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(moveXPos()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), widget, SLOT(moveYPos()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(moveZNeg()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), widget, SLOT(scaleYDown()));
        QObject::connect(pushButton_17, SIGNAL(clicked()), widget, SLOT(scaleXDown()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), widget, SLOT(scaleZUp()));
        QObject::connect(pushButton_14, SIGNAL(clicked()), widget, SLOT(scaleZDown()));
        QObject::connect(pushButton_16, SIGNAL(clicked()), widget, SLOT(scaleYUp()));
        QObject::connect(pushButton_15, SIGNAL(clicked()), widget, SLOT(scaleXUp()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), widget, SLOT(rotateLeft()));
        QObject::connect(pushButton_13, SIGNAL(clicked()), widget, SLOT(rotateRight()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(lightX(int)));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), widget, SLOT(lightX(int)));
        QObject::connect(widget, SIGNAL(sendInt(int)), label_10, SLOT(setNum(int)));

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
        pushButton_3->setText(QApplication::translate("OpenGLDemoClass", "X++", 0));
        pushButton_4->setText(QApplication::translate("OpenGLDemoClass", "Z++", 0));
        pushButton_5->setText(QApplication::translate("OpenGLDemoClass", "X--", 0));
        pushButton_6->setText(QApplication::translate("OpenGLDemoClass", "Z--", 0));
        pushButton_7->setText(QApplication::translate("OpenGLDemoClass", "Y--", 0));
        pushButton_8->setText(QApplication::translate("OpenGLDemoClass", "Y++", 0));
        pushButton_9->setText(QApplication::translate("OpenGLDemoClass", "Previous", 0));
        pushButton_12->setText(QApplication::translate("OpenGLDemoClass", "Rotate Left", 0));
        pushButton_13->setText(QApplication::translate("OpenGLDemoClass", "Rotate Right", 0));
        pushButton_10->setText(QApplication::translate("OpenGLDemoClass", "Y--", 0));
        pushButton_11->setText(QApplication::translate("OpenGLDemoClass", "Z++", 0));
        pushButton_14->setText(QApplication::translate("OpenGLDemoClass", "Z--", 0));
        pushButton_15->setText(QApplication::translate("OpenGLDemoClass", "X++", 0));
        pushButton_16->setText(QApplication::translate("OpenGLDemoClass", "Y++", 0));
        pushButton_17->setText(QApplication::translate("OpenGLDemoClass", "X--", 0));
        label_7->setText(QApplication::translate("OpenGLDemoClass", "Translation", 0));
        label_8->setText(QApplication::translate("OpenGLDemoClass", "Scaling", 0));
        label_9->setText(QApplication::translate("OpenGLDemoClass", "Rotation", 0));
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenGLDemoClass: public Ui_OpenGLDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLDEMO_H
