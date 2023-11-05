/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openFileButton;
    QSpacerItem *horizontalSpacer;
    QOpenGLWidget *openGLWidget;
    QLabel *label_4;
    QLabel *label_fileName;
    QLabel *label_5;
    QLabel *label_numberVertices;
    QLabel *label_6;
    QLabel *label_numberPolygons;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *enlargeButton;
    QPushButton *moveZRightButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *moveZLeftButton;
    QDoubleSpinBox *moveSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_3;
    QPushButton *rotateXRightButton;
    QLineEdit *lineEdit;
    QPushButton *rotateYRightButton;
    QPushButton *rotateZRightButton;
    QPushButton *moveYRightButton;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *rotateXLeftButton;
    QDoubleSpinBox *scaleSpinBox;
    QPushButton *moveYLeftButton;
    QPushButton *shrinkButton;
    QPushButton *rotateZLeftButton;
    QPushButton *rotateYLeftButton;
    QDoubleSpinBox *rotateSpinBox;
    QSpacerItem *verticalSpacer;
    QPushButton *moveXLeftButton;
    QPushButton *moveXRightButton;
    QLabel *label_7;
    QLabel *errorDescription;
    QComboBox *projecttionComboBox;
    QPushButton *dotColorButton;
    QPushButton *lineColorButton;
    QPushButton *applySettingButton;
    QDoubleSpinBox *dotSizeSpinBox;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *lineSizeSpinBox;
    QComboBox *dotTypeComboBox;
    QComboBox *lineTypeComboBox;
    QPushButton *backColorButton;
    QPushButton *screenshotButton;
    QPushButton *recordGifButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1350, 930);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1350, 930));
        MainWindow->setMaximumSize(QSize(1350, 930));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 511, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        openFileButton = new QPushButton(horizontalLayoutWidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        horizontalLayout_2->addWidget(openFileButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 60, 800, 800));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(820, 500, 61, 20));
        label_fileName = new QLabel(centralwidget);
        label_fileName->setObjectName(QString::fromUtf8("label_fileName"));
        label_fileName->setGeometry(QRect(890, 500, 331, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(820, 520, 121, 20));
        label_numberVertices = new QLabel(centralwidget);
        label_numberVertices->setObjectName(QString::fromUtf8("label_numberVertices"));
        label_numberVertices->setGeometry(QRect(950, 520, 131, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(820, 540, 131, 20));
        label_numberPolygons = new QLabel(centralwidget);
        label_numberPolygons->setObjectName(QString::fromUtf8("label_numberPolygons"));
        label_numberPolygons->setGeometry(QRect(960, 540, 131, 21));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(820, 70, 511, 423));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        enlargeButton = new QPushButton(layoutWidget);
        enlargeButton->setObjectName(QString::fromUtf8("enlargeButton"));

        gridLayout->addWidget(enlargeButton, 14, 0, 1, 2);

        moveZRightButton = new QPushButton(layoutWidget);
        moveZRightButton->setObjectName(QString::fromUtf8("moveZRightButton"));

        gridLayout->addWidget(moveZRightButton, 11, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        moveZLeftButton = new QPushButton(layoutWidget);
        moveZLeftButton->setObjectName(QString::fromUtf8("moveZLeftButton"));

        gridLayout->addWidget(moveZLeftButton, 11, 0, 1, 2);

        moveSpinBox = new QDoubleSpinBox(layoutWidget);
        moveSpinBox->setObjectName(QString::fromUtf8("moveSpinBox"));

        gridLayout->addWidget(moveSpinBox, 6, 3, 6, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 1, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFrame(false);
        lineEdit_3->setReadOnly(true);

        gridLayout->addWidget(lineEdit_3, 13, 0, 1, 2);

        rotateXRightButton = new QPushButton(layoutWidget);
        rotateXRightButton->setObjectName(QString::fromUtf8("rotateXRightButton"));

        gridLayout->addWidget(rotateXRightButton, 1, 2, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFrame(false);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 2);

        rotateYRightButton = new QPushButton(layoutWidget);
        rotateYRightButton->setObjectName(QString::fromUtf8("rotateYRightButton"));

        gridLayout->addWidget(rotateYRightButton, 2, 2, 1, 1);

        rotateZRightButton = new QPushButton(layoutWidget);
        rotateZRightButton->setObjectName(QString::fromUtf8("rotateZRightButton"));

        gridLayout->addWidget(rotateZRightButton, 3, 2, 1, 1);

        moveYRightButton = new QPushButton(layoutWidget);
        moveYRightButton->setObjectName(QString::fromUtf8("moveYRightButton"));

        gridLayout->addWidget(moveYRightButton, 10, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 2, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFrame(false);
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 5, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 12, 0, 1, 1);

        rotateXLeftButton = new QPushButton(layoutWidget);
        rotateXLeftButton->setObjectName(QString::fromUtf8("rotateXLeftButton"));

        gridLayout->addWidget(rotateXLeftButton, 1, 0, 1, 2);

        scaleSpinBox = new QDoubleSpinBox(layoutWidget);
        scaleSpinBox->setObjectName(QString::fromUtf8("scaleSpinBox"));

        gridLayout->addWidget(scaleSpinBox, 14, 3, 1, 1);

        moveYLeftButton = new QPushButton(layoutWidget);
        moveYLeftButton->setObjectName(QString::fromUtf8("moveYLeftButton"));

        gridLayout->addWidget(moveYLeftButton, 10, 0, 1, 2);

        shrinkButton = new QPushButton(layoutWidget);
        shrinkButton->setObjectName(QString::fromUtf8("shrinkButton"));

        gridLayout->addWidget(shrinkButton, 14, 2, 1, 1);

        rotateZLeftButton = new QPushButton(layoutWidget);
        rotateZLeftButton->setObjectName(QString::fromUtf8("rotateZLeftButton"));

        gridLayout->addWidget(rotateZLeftButton, 3, 0, 1, 2);

        rotateYLeftButton = new QPushButton(layoutWidget);
        rotateYLeftButton->setObjectName(QString::fromUtf8("rotateYLeftButton"));

        gridLayout->addWidget(rotateYLeftButton, 2, 0, 1, 2);

        rotateSpinBox = new QDoubleSpinBox(layoutWidget);
        rotateSpinBox->setObjectName(QString::fromUtf8("rotateSpinBox"));

        gridLayout->addWidget(rotateSpinBox, 1, 3, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        moveXLeftButton = new QPushButton(layoutWidget);
        moveXLeftButton->setObjectName(QString::fromUtf8("moveXLeftButton"));

        gridLayout->addWidget(moveXLeftButton, 7, 2, 3, 1);

        moveXRightButton = new QPushButton(layoutWidget);
        moveXRightButton->setObjectName(QString::fromUtf8("moveXRightButton"));

        gridLayout->addWidget(moveXRightButton, 7, 0, 3, 2);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(820, 580, 61, 20));
        errorDescription = new QLabel(centralwidget);
        errorDescription->setObjectName(QString::fromUtf8("errorDescription"));
        errorDescription->setGeometry(QRect(870, 580, 331, 21));
        projecttionComboBox = new QComboBox(centralwidget);
        projecttionComboBox->setObjectName(QString::fromUtf8("projecttionComboBox"));
        projecttionComboBox->setGeometry(QRect(810, 610, 201, 32));
        dotColorButton = new QPushButton(centralwidget);
        dotColorButton->setObjectName(QString::fromUtf8("dotColorButton"));
        dotColorButton->setGeometry(QRect(820, 640, 100, 32));
        lineColorButton = new QPushButton(centralwidget);
        lineColorButton->setObjectName(QString::fromUtf8("lineColorButton"));
        lineColorButton->setGeometry(QRect(820, 670, 100, 32));
        applySettingButton = new QPushButton(centralwidget);
        applySettingButton->setObjectName(QString::fromUtf8("applySettingButton"));
        applySettingButton->setGeometry(QRect(830, 710, 100, 32));
        dotSizeSpinBox = new QDoubleSpinBox(centralwidget);
        dotSizeSpinBox->setObjectName(QString::fromUtf8("dotSizeSpinBox"));
        dotSizeSpinBox->setGeometry(QRect(990, 650, 71, 21));
        dotSizeSpinBox->setMinimum(1.000000000000000);
        dotSizeSpinBox->setMaximum(10.000000000000000);
        dotSizeSpinBox->setValue(5.000000000000000);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(930, 650, 58, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(930, 680, 58, 16));
        lineSizeSpinBox = new QDoubleSpinBox(centralwidget);
        lineSizeSpinBox->setObjectName(QString::fromUtf8("lineSizeSpinBox"));
        lineSizeSpinBox->setGeometry(QRect(990, 680, 71, 21));
        lineSizeSpinBox->setMinimum(1.000000000000000);
        lineSizeSpinBox->setMaximum(10.000000000000000);
        lineSizeSpinBox->setValue(1.000000000000000);
        dotTypeComboBox = new QComboBox(centralwidget);
        dotTypeComboBox->setObjectName(QString::fromUtf8("dotTypeComboBox"));
        dotTypeComboBox->setGeometry(QRect(1070, 641, 201, 41));
        lineTypeComboBox = new QComboBox(centralwidget);
        lineTypeComboBox->setObjectName(QString::fromUtf8("lineTypeComboBox"));
        lineTypeComboBox->setGeometry(QRect(1070, 670, 201, 41));
        backColorButton = new QPushButton(centralwidget);
        backColorButton->setObjectName(QString::fromUtf8("backColorButton"));
        backColorButton->setGeometry(QRect(1020, 610, 141, 32));
        screenshotButton = new QPushButton(centralwidget);
        screenshotButton->setObjectName(QString::fromUtf8("screenshotButton"));
        screenshotButton->setGeometry(QRect(820, 760, 181, 61));
        recordGifButton = new QPushButton(centralwidget);
        recordGifButton->setObjectName(QString::fromUtf8("recordGifButton"));
        recordGifButton->setGeometry(QRect(1020, 760, 181, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1350, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "File name:", nullptr));
        label_fileName->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Number of vertices:", nullptr));
        label_numberVertices->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Number of polygons:", nullptr));
        label_numberPolygons->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        enlargeButton->setText(QCoreApplication::translate("MainWindow", "Enlarge", nullptr));
        moveZRightButton->setText(QCoreApplication::translate("MainWindow", "Move Z Right", nullptr));
        moveZLeftButton->setText(QCoreApplication::translate("MainWindow", "Move Z Left", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Scale:", nullptr));
        rotateXRightButton->setText(QCoreApplication::translate("MainWindow", "X Down", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "Rotate:", nullptr));
        rotateYRightButton->setText(QCoreApplication::translate("MainWindow", "Y Left", nullptr));
        rotateZRightButton->setText(QCoreApplication::translate("MainWindow", "Z Counterclockwise", nullptr));
        moveYRightButton->setText(QCoreApplication::translate("MainWindow", "Move Y Down", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "Move:", nullptr));
        rotateXLeftButton->setText(QCoreApplication::translate("MainWindow", "X Up", nullptr));
        moveYLeftButton->setText(QCoreApplication::translate("MainWindow", "Move Y Up", nullptr));
        shrinkButton->setText(QCoreApplication::translate("MainWindow", "Shrink", nullptr));
        rotateZLeftButton->setText(QCoreApplication::translate("MainWindow", "Z Clockwise", nullptr));
        rotateYLeftButton->setText(QCoreApplication::translate("MainWindow", "Y Right", nullptr));
        moveXLeftButton->setText(QCoreApplication::translate("MainWindow", "Move X Right", nullptr));
        moveXRightButton->setText(QCoreApplication::translate("MainWindow", "Move X Left", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        errorDescription->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        projecttionComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\241hoose projection", nullptr));
        dotColorButton->setText(QCoreApplication::translate("MainWindow", "Dot color", nullptr));
        lineColorButton->setText(QCoreApplication::translate("MainWindow", "Line color", nullptr));
        applySettingButton->setText(QCoreApplication::translate("MainWindow", "Apply Settings", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Dot size:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "line size:", nullptr));
        dotTypeComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\241hoose dot type", nullptr));
        lineTypeComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\241hoose line type", nullptr));
        backColorButton->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        screenshotButton->setText(QCoreApplication::translate("MainWindow", "Take a screenshot", nullptr));
        recordGifButton->setText(QCoreApplication::translate("MainWindow", "Record GIF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
