//
// Created by abdallah drwesh on 4/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include <QGraphicsPixmapItem>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QtCharts>
#include <QChart>
#include <QChartView>
#include <QLineSeries>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}


void MainWindow::loadImage(std::string filepath, Image *&image) {
    if (image != nullptr) {
        delete image;
    }
    image = new Image(filepath);
}


void MainWindow::displayRGBImage(Image *image, QLabel *label) {
    QImage qImage(image->width, image->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < image->width; ++j) {
        for (int i = 0; i < image->height; ++i) {
            rgb = qRgb(image->data[i][j][0], image->data[i][j][1], image->data[i][j][2]);
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
            qImage.setPixel(j, i, rgb);
        }
    }
    label->setPixmap(QPixmap::fromImage(qImage));
}

void MainWindow::displayGrayscaleImage(Image *image, QLabel *label) {
    QImage qImage(image->width, image->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < image->width; ++j) {
        for (int i = 0; i < image->height; ++i) {
            rgb = qRgb(image->data[i][j][0], image->data[i][j][0], image->data[i][j][0]);
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
            qImage.setPixel(j, i, rgb);
        }
    }
    int width = label->width();
    int height = label->height();
    label->clear();
    label->setPixmap(QPixmap::fromImage(qImage).scaled(width, height));
}

MainWindow::~MainWindow() {
    delete ui;
    delete inputImage;
    delete noiseImage;
    delete imageA;
    delete imageB;
    delete inputImage_1;
    delete outputImage;
    delete outputImage_1;
    delete inputFreqImage;
}
