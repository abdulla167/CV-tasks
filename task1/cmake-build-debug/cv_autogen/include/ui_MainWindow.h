/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *filters;
    QFrame *frame;
    QLabel *label;
    QLabel *inputImageLabel;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *outputImageLabel;
    QPushButton *loadImageBtn;
    QFrame *frame_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QComboBox *filterSelect;
    QFrame *additionalParmsFrame;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *imageName;
    QLabel *label_8;
    QLabel *imageSize;
    QWidget *histograms;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QPushButton *LoadImageBtn_1;
    QComboBox *imageSelect;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *InputImagLabel_1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QLabel *InputImagLabel_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QLabel *InputImagLabel_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_9;
    QLabel *outpuImageLabel_1;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_14;
    QLabel *outputImageLabel_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QLabel *outputImageLabel_3;
    QWidget *hybrid;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1083, 711);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        filters = new QWidget();
        filters->setObjectName(QString::fromUtf8("filters"));
        frame = new QFrame(filters);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(220, 30, 431, 401));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 121, 17));
        inputImageLabel = new QLabel(frame);
        inputImageLabel->setObjectName(QString::fromUtf8("inputImageLabel"));
        inputImageLabel->setGeometry(QRect(0, 20, 431, 381));
        frame_2 = new QFrame(filters);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(660, 30, 451, 401));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 101, 21));
        outputImageLabel = new QLabel(frame_2);
        outputImageLabel->setObjectName(QString::fromUtf8("outputImageLabel"));
        outputImageLabel->setGeometry(QRect(0, 20, 451, 381));
        loadImageBtn = new QPushButton(filters);
        loadImageBtn->setObjectName(QString::fromUtf8("loadImageBtn"));
        loadImageBtn->setGeometry(QRect(10, 50, 131, 51));
        frame_3 = new QFrame(filters);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(70, 480, 1031, 131));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 411, 91));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        filterSelect = new QComboBox(widget);
        filterSelect->addItem(QString());
        filterSelect->addItem(QString());
        filterSelect->addItem(QString());
        filterSelect->addItem(QString());
        filterSelect->addItem(QString());
        filterSelect->addItem(QString());
        filterSelect->addItem(QString());
        filterSelect->setObjectName(QString::fromUtf8("filterSelect"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filterSelect->sizePolicy().hasHeightForWidth());
        filterSelect->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(filterSelect);

        additionalParmsFrame = new QFrame(frame_3);
        additionalParmsFrame->setObjectName(QString::fromUtf8("additionalParmsFrame"));
        additionalParmsFrame->setGeometry(QRect(519, 39, 431, 71));
        additionalParmsFrame->setFrameShape(QFrame::StyledPanel);
        additionalParmsFrame->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 20, 161, 17));
        label_3 = new QLabel(filters);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 460, 111, 17));
        label_6 = new QLabel(filters);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 130, 51, 17));
        imageName = new QLabel(filters);
        imageName->setObjectName(QString::fromUtf8("imageName"));
        imageName->setGeometry(QRect(70, 130, 141, 21));
        label_8 = new QLabel(filters);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 210, 41, 17));
        imageSize = new QLabel(filters);
        imageSize->setObjectName(QString::fromUtf8("imageSize"));
        imageSize->setGeometry(QRect(50, 210, 161, 17));
        tabWidget->addTab(filters, QString());
        histograms = new QWidget();
        histograms->setObjectName(QString::fromUtf8("histograms"));
        verticalLayout_13 = new QVBoxLayout(histograms);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        LoadImageBtn_1 = new QPushButton(histograms);
        LoadImageBtn_1->setObjectName(QString::fromUtf8("LoadImageBtn_1"));

        verticalLayout_6->addWidget(LoadImageBtn_1);

        imageSelect = new QComboBox(histograms);
        imageSelect->addItem(QString());
        imageSelect->addItem(QString());
        imageSelect->setObjectName(QString::fromUtf8("imageSelect"));

        verticalLayout_6->addWidget(imageSelect);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(histograms);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        InputImagLabel_1 = new QLabel(histograms);
        InputImagLabel_1->setObjectName(QString::fromUtf8("InputImagLabel_1"));

        verticalLayout_3->addWidget(InputImagLabel_1);

        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_10 = new QLabel(histograms);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        InputImagLabel_2 = new QLabel(histograms);
        InputImagLabel_2->setObjectName(QString::fromUtf8("InputImagLabel_2"));

        verticalLayout_4->addWidget(InputImagLabel_2);

        verticalLayout_4->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_12 = new QLabel(histograms);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_5->addWidget(label_12);

        InputImagLabel_3 = new QLabel(histograms);
        InputImagLabel_3->setObjectName(QString::fromUtf8("InputImagLabel_3"));

        verticalLayout_5->addWidget(InputImagLabel_3);

        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayout_2->setStretch(3, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_9 = new QLabel(histograms);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_11->addWidget(label_9);

        outpuImageLabel_1 = new QLabel(histograms);
        outpuImageLabel_1->setObjectName(QString::fromUtf8("outpuImageLabel_1"));

        verticalLayout_11->addWidget(outpuImageLabel_1);

        verticalLayout_11->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_11);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_14 = new QLabel(histograms);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_9->addWidget(label_14);

        outputImageLabel_2 = new QLabel(histograms);
        outputImageLabel_2->setObjectName(QString::fromUtf8("outputImageLabel_2"));

        verticalLayout_9->addWidget(outputImageLabel_2);

        verticalLayout_9->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_15 = new QLabel(histograms);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_7->addWidget(label_15);

        outputImageLabel_3 = new QLabel(histograms);
        outputImageLabel_3->setObjectName(QString::fromUtf8("outputImageLabel_3"));

        verticalLayout_7->addWidget(outputImageLabel_3);

        verticalLayout_7->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_7);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 3);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_13->addLayout(verticalLayout_2);

        tabWidget->addTab(histograms, QString());
        hybrid = new QWidget();
        hybrid->setObjectName(QString::fromUtf8("hybrid"));
        tabWidget->addTab(hybrid, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1083, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Input Image", nullptr));
        inputImageLabel->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Output Image", nullptr));
        outputImageLabel->setText(QString());
        loadImageBtn->setText(QApplication::translate("MainWindow", "Load Image", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Select Filter", nullptr));
        filterSelect->setItemText(0, QString());
        filterSelect->setItemText(1, QApplication::translate("MainWindow", "Average", nullptr));
        filterSelect->setItemText(2, QApplication::translate("MainWindow", "Gaussian", nullptr));
        filterSelect->setItemText(3, QApplication::translate("MainWindow", "Median", nullptr));
        filterSelect->setItemText(4, QApplication::translate("MainWindow", "Sobel", nullptr));
        filterSelect->setItemText(5, QApplication::translate("MainWindow", "Prewitt", nullptr));
        filterSelect->setItemText(6, QApplication::translate("MainWindow", "Roberts", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "Additional Prameteres", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Filter Settings", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Name:", nullptr));
        imageName->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Size:", nullptr));
        imageSize->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(filters), QApplication::translate("MainWindow", "Filters", nullptr));
        LoadImageBtn_1->setText(QApplication::translate("MainWindow", "Load Image", nullptr));
        imageSelect->setItemText(0, QApplication::translate("MainWindow", "GrayImage", nullptr));
        imageSelect->setItemText(1, QApplication::translate("MainWindow", "RGBImage", nullptr));

        label_7->setText(QApplication::translate("MainWindow", "Input Image", nullptr));
        InputImagLabel_1->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Histogram", nullptr));
        InputImagLabel_2->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "CDF", nullptr));
        InputImagLabel_3->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "OutputImage", nullptr));
        outpuImageLabel_1->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "Histogram", nullptr));
        outputImageLabel_2->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "CDF", nullptr));
        outputImageLabel_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(histograms), QApplication::translate("MainWindow", "Histograms", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(hybrid), QApplication::translate("MainWindow", "Hybrid", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
