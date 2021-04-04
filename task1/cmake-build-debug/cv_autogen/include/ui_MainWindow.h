/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QWidget *frequencyFilters;
    QPushButton *plotBtn;
    QFrame *customPlot;
    QWidget *hybrid;
    QFrame *frame_4;
    QLabel *label_71;
    QLabel *imageALabel;
    QFrame *frame_5;
    QLabel *label_91;
    QLabel *imageBLabel;
    QPushButton *imageABtn;
    QPushButton *imageBBtn;
    QLabel *imageASize;
    QLabel *imageAName;
    QLabel *label_101;
    QLabel *label_11;
    QLabel *imageBSize;
    QLabel *imageBName;
    QLabel *label_121;
    QLabel *label_13;
    QPushButton *hybridBtn;
    QFrame *frame_6;
    QLabel *label_141;
    QLabel *hybridImageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1383, 935);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        filters = new QWidget();
        filters->setObjectName(QStringLiteral("filters"));
        frame = new QFrame(filters);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(210, 10, 531, 541));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 121, 17));
        inputImageLabel = new QLabel(frame);
        inputImageLabel->setObjectName(QStringLiteral("inputImageLabel"));
        inputImageLabel->setGeometry(QRect(10, 20, 512, 511));
        frame_2 = new QFrame(filters);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(750, 10, 531, 541));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 101, 21));
        outputImageLabel = new QLabel(frame_2);
        outputImageLabel->setObjectName(QStringLiteral("outputImageLabel"));
        outputImageLabel->setGeometry(QRect(10, 20, 511, 512));
        loadImageBtn = new QPushButton(filters);
        loadImageBtn->setObjectName(QStringLiteral("loadImageBtn"));
        loadImageBtn->setGeometry(QRect(10, 50, 131, 51));
        frame_3 = new QFrame(filters);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(200, 650, 1031, 131));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 20, 411, 91));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        filterSelect = new QComboBox(widget);
        filterSelect->setObjectName(QStringLiteral("filterSelect"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filterSelect->sizePolicy().hasHeightForWidth());
        filterSelect->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(filterSelect);

        additionalParmsFrame = new QFrame(frame_3);
        additionalParmsFrame->setObjectName(QStringLiteral("additionalParmsFrame"));
        additionalParmsFrame->setGeometry(QRect(519, 39, 431, 71));
        additionalParmsFrame->setFrameShape(QFrame::StyledPanel);
        additionalParmsFrame->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(520, 20, 161, 17));
        label_3 = new QLabel(filters);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 630, 111, 17));
        label_6 = new QLabel(filters);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 51, 17));
        imageName = new QLabel(filters);
        imageName->setObjectName(QStringLiteral("imageName"));
        imageName->setGeometry(QRect(70, 130, 141, 21));
        label_8 = new QLabel(filters);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 170, 41, 17));
        imageSize = new QLabel(filters);
        imageSize->setObjectName(QStringLiteral("imageSize"));
        imageSize->setGeometry(QRect(40, 170, 161, 17));
        tabWidget->addTab(filters, QString());
        histograms = new QWidget();
        histograms->setObjectName(QStringLiteral("histograms"));
        verticalLayout_13 = new QVBoxLayout(histograms);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        LoadImageBtn_1 = new QPushButton(histograms);
        LoadImageBtn_1->setObjectName(QStringLiteral("LoadImageBtn_1"));

        verticalLayout_6->addWidget(LoadImageBtn_1);

        imageSelect = new QComboBox(histograms);
        imageSelect->setObjectName(QStringLiteral("imageSelect"));

        verticalLayout_6->addWidget(imageSelect);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(histograms);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        InputImagLabel_1 = new QLabel(histograms);
        InputImagLabel_1->setObjectName(QStringLiteral("InputImagLabel_1"));

        verticalLayout_3->addWidget(InputImagLabel_1);

        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_10 = new QLabel(histograms);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_4->addWidget(label_10);

        InputImagLabel_2 = new QLabel(histograms);
        InputImagLabel_2->setObjectName(QStringLiteral("InputImagLabel_2"));

        verticalLayout_4->addWidget(InputImagLabel_2);

        verticalLayout_4->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_12 = new QLabel(histograms);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        InputImagLabel_3 = new QLabel(histograms);
        InputImagLabel_3->setObjectName(QStringLiteral("InputImagLabel_3"));

        verticalLayout_5->addWidget(InputImagLabel_3);

        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayout_2->setStretch(3, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_9 = new QLabel(histograms);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_11->addWidget(label_9);

        outpuImageLabel_1 = new QLabel(histograms);
        outpuImageLabel_1->setObjectName(QStringLiteral("outpuImageLabel_1"));

        verticalLayout_11->addWidget(outpuImageLabel_1);

        verticalLayout_11->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_11);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_14 = new QLabel(histograms);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_9->addWidget(label_14);

        outputImageLabel_2 = new QLabel(histograms);
        outputImageLabel_2->setObjectName(QStringLiteral("outputImageLabel_2"));

        verticalLayout_9->addWidget(outputImageLabel_2);

        verticalLayout_9->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_15 = new QLabel(histograms);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_7->addWidget(label_15);

        outputImageLabel_3 = new QLabel(histograms);
        outputImageLabel_3->setObjectName(QStringLiteral("outputImageLabel_3"));

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
        frequencyFilters = new QWidget();
        frequencyFilters->setObjectName(QStringLiteral("frequencyFilters"));
        plotBtn = new QPushButton(frequencyFilters);
        plotBtn->setObjectName(QStringLiteral("plotBtn"));
        plotBtn->setGeometry(QRect(40, 270, 89, 25));
        customPlot = new QFrame(frequencyFilters);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(280, 60, 581, 531));
        customPlot->setFrameShape(QFrame::StyledPanel);
        customPlot->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(frequencyFilters, QString());
        hybrid = new QWidget();
        hybrid->setObjectName(QStringLiteral("hybrid"));
        frame_4 = new QFrame(hybrid);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(330, 20, 411, 401));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_71 = new QLabel(frame_4);
        label_71->setObjectName(QStringLiteral("label_71"));
        label_71->setGeometry(QRect(0, 0, 121, 17));
        imageALabel = new QLabel(frame_4);
        imageALabel->setObjectName(QStringLiteral("imageALabel"));
        imageALabel->setGeometry(QRect(10, 20, 391, 371));
        frame_5 = new QFrame(hybrid);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(330, 430, 411, 401));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_91 = new QLabel(frame_5);
        label_91->setObjectName(QStringLiteral("label_91"));
        label_91->setGeometry(QRect(0, 0, 121, 17));
        imageBLabel = new QLabel(frame_5);
        imageBLabel->setObjectName(QStringLiteral("imageBLabel"));
        imageBLabel->setGeometry(QRect(10, 20, 391, 371));
        imageABtn = new QPushButton(hybrid);
        imageABtn->setObjectName(QStringLiteral("imageABtn"));
        imageABtn->setGeometry(QRect(20, 60, 151, 61));
        imageBBtn = new QPushButton(hybrid);
        imageBBtn->setObjectName(QStringLiteral("imageBBtn"));
        imageBBtn->setGeometry(QRect(30, 490, 151, 61));
        imageASize = new QLabel(hybrid);
        imageASize->setObjectName(QStringLiteral("imageASize"));
        imageASize->setGeometry(QRect(60, 200, 161, 17));
        imageAName = new QLabel(hybrid);
        imageAName->setObjectName(QStringLiteral("imageAName"));
        imageAName->setGeometry(QRect(90, 160, 141, 21));
        label_101 = new QLabel(hybrid);
        label_101->setObjectName(QStringLiteral("label_101"));
        label_101->setGeometry(QRect(30, 200, 41, 17));
        label_11 = new QLabel(hybrid);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 160, 51, 17));
        imageBSize = new QLabel(hybrid);
        imageBSize->setObjectName(QStringLiteral("imageBSize"));
        imageBSize->setGeometry(QRect(70, 620, 161, 17));
        imageBName = new QLabel(hybrid);
        imageBName->setObjectName(QStringLiteral("imageBName"));
        imageBName->setGeometry(QRect(100, 580, 141, 21));
        label_121 = new QLabel(hybrid);
        label_121->setObjectName(QStringLiteral("label_121"));
        label_121->setGeometry(QRect(40, 620, 41, 17));
        label_13 = new QLabel(hybrid);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 580, 51, 17));
        hybridBtn = new QPushButton(hybrid);
        hybridBtn->setObjectName(QStringLiteral("hybridBtn"));
        hybridBtn->setGeometry(QRect(30, 740, 131, 41));
        frame_6 = new QFrame(hybrid);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(790, 110, 531, 541));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_141 = new QLabel(frame_6);
        label_141->setObjectName(QStringLiteral("label_141"));
        label_141->setGeometry(QRect(0, 0, 121, 17));
        hybridImageLabel = new QLabel(frame_6);
        hybridImageLabel->setObjectName(QStringLiteral("hybridImageLabel"));
        hybridImageLabel->setGeometry(QRect(10, 20, 512, 511));
        tabWidget->addTab(hybrid, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1383, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Input Image", Q_NULLPTR));
        inputImageLabel->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Output Image", Q_NULLPTR));
        outputImageLabel->setText(QString());
        loadImageBtn->setText(QApplication::translate("MainWindow", "Load Image", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Select Filter", Q_NULLPTR));
        filterSelect->clear();
        filterSelect->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Average", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Gaussian", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Median", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sobel", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Prewitt", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Roberts", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "Additional Prameteres", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Filter Settings", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        imageName->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Size:", Q_NULLPTR));
        imageSize->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(filters), QApplication::translate("MainWindow", "Filters", Q_NULLPTR));
        LoadImageBtn_1->setText(QApplication::translate("MainWindow", "Load Image", Q_NULLPTR));
        imageSelect->clear();
        imageSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GrayImage", Q_NULLPTR)
         << QApplication::translate("MainWindow", "RGBImage", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("MainWindow", "Input Image", Q_NULLPTR));
        InputImagLabel_1->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Histogram", Q_NULLPTR));
        InputImagLabel_2->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "CDF", Q_NULLPTR));
        InputImagLabel_3->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "OutputImage", Q_NULLPTR));
        outpuImageLabel_1->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "Histogram", Q_NULLPTR));
        outputImageLabel_2->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "CDF", Q_NULLPTR));
        outputImageLabel_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(histograms), QApplication::translate("MainWindow", "Histograms", Q_NULLPTR));
        plotBtn->setText(QApplication::translate("MainWindow", "plot", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(frequencyFilters), QApplication::translate("MainWindow", "Frequency Filters", Q_NULLPTR));
        label_71->setText(QApplication::translate("MainWindow", "Image A", Q_NULLPTR));
        imageALabel->setText(QString());
        label_91->setText(QApplication::translate("MainWindow", "Image B", Q_NULLPTR));
        imageBLabel->setText(QString());
        imageABtn->setText(QApplication::translate("MainWindow", "Load Image A", Q_NULLPTR));
        imageBBtn->setText(QApplication::translate("MainWindow", "Load Image B", Q_NULLPTR));
        imageASize->setText(QString());
        imageAName->setText(QString());
        label_101->setText(QApplication::translate("MainWindow", "Size:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        imageBSize->setText(QString());
        imageBName->setText(QString());
        label_121->setText(QApplication::translate("MainWindow", "Size:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        hybridBtn->setText(QApplication::translate("MainWindow", "Make Hybrid", Q_NULLPTR));
        label_141->setText(QApplication::translate("MainWindow", "Hybrid Image", Q_NULLPTR));
        hybridImageLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(hybrid), QApplication::translate("MainWindow", "Hybrid", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
