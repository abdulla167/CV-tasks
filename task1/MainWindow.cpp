//
// Created by abdallah drwesh on 4/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "processing/filters.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

}


void MainWindow::on_loadImageBtn_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    ui->imageName->setText(QString(filename.c_str()));
    QPixmap pixmap{filePath};
    ui->inputImageLabel->setPixmap(pixmap);
    loadImage(filepathStd);
    std::string imageSize = std::to_string(inputImage->size());
    ui->imageSize->setText(QString(imageSize.c_str()));
}

void MainWindow::on_filterSelect_currentIndexChanged(QString filterName) {
    if (filterName == "Average") {
        auto grayImage = inputImage->toGrayscale();
        auto im = avgFilter(grayImage);
        displayGrayscaleImage(&im);
    } else if (filterName == "Gaussian") {
        auto grayImage = inputImage->toGrayscale();
        auto im = gaussianFilter(grayImage);
        displayGrayscaleImage(&im);
    } else if (filterName == "Median") {
        auto grayImage = inputImage->toGrayscale();
        auto im = medianFilter(grayImage);
        displayGrayscaleImage(&im);
    } else if (filterName == "Prewitt") {
        auto grayImage = inputImage->toGrayscale();
        auto im = perwitEdgeDetector(grayImage);
        displayGrayscaleImage(&im);
    } else if (filterName == "Roberts") {
        auto grayImage = inputImage->toGrayscale();
        auto im = robertsEdgeDetector(grayImage);
        displayGrayscaleImage(&im);
    } else if (filterName == "Sobel") {
        auto grayImage = inputImage->toGrayscale();
        auto im = sobelEdgeDetector(grayImage);
        displayGrayscaleImage(&im);
    }
}

void MainWindow::loadImage(std::string filepath) {
    if (inputImage != nullptr) {
        delete inputImage;
    }
    inputImage = new Image(filepath);
}

void MainWindow::displayRGBImage(Image *image) {
    QImage qImage(image->width, image->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < image->width; ++j) {
        for (int i = 0; i < image->height; ++i) {
            rgb = qRgb(image->data[i][j][0], image->data[i][j][1], image->data[i][j][2]);
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
            qImage.setPixel(j, i, rgb);
        }
    }
    ui->outputImageLabel->setPixmap(QPixmap::fromImage(qImage));
}

void MainWindow::displayGrayscaleImage(Image *image) {
    QImage qImage(image->width, image->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < image->width; ++j) {
        for (int i = 0; i < image->height; ++i) {
            rgb = qRgb(image->data[i][j][0], image->data[i][j][0], image->data[i][j][0]);
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
            qImage.setPixel(j, i, rgb);
        }
    }
    ui->outputImageLabel->setPixmap(QPixmap::fromImage(qImage));
}

MainWindow::~MainWindow() {
    delete ui;
    delete inputImage;
    delete outputImage;
}
