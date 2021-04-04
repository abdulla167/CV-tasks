//
// Created by abdallah drwesh on 4/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <iostream>
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
    loadImage(filepathStd, inputImage);
    auto grayImage = inputImage->toGrayscale();
    displayGrayscaleImage(&grayImage, ui->inputImageLabel);
    std::string imageSize = std::to_string(inputImage->size());
    ui->imageSize->setText(QString(imageSize.c_str()));
}

void MainWindow::on_imageABtn_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    ui->imageAName->setText(QString(filename.c_str()));
    loadImage(filepathStd, imageA);
    auto grayImage = imageA->toGrayscale();
    displayGrayscaleImage(&grayImage, ui->imageALabel);
    std::string imageSize = std::to_string(imageA->size());
    ui->imageASize->setText(QString(imageSize.c_str()));
}

void MainWindow::on_imageBBtn_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    ui->imageBName->setText(QString(filename.c_str()));
    loadImage(filepathStd, imageB);
    auto grayImage = imageB->toGrayscale();
    displayGrayscaleImage(&grayImage, ui->imageBLabel);
    std::string imageSize = std::to_string(imageB->size());
    ui->imageBSize->setText(QString(imageSize.c_str()));
}

void MainWindow::on_hybridBtn_clicked() {
    auto grayImage1 = imageA->toGrayscale();
    auto im1 = gaussianFilter(grayImage1);
    auto grayImage2 = imageB->toGrayscale();
    auto im2 = laplacianFilter(grayImage2);
    Image hybrid {im1.width, im1.height, 1};
    for (int i = 0; i < im1.height; ++i) {
        for (int j = 0; j < im1.width; ++j) {
            hybrid.data[i][j][0] = im1.data[i][j][0] + im2.data[i][j][0];
        }
    }
    auto displayImg = hybrid.toScale();
    displayGrayscaleImage(&displayImg, ui->hybridImageLabel);
}

void MainWindow::on_filterSelect_currentIndexChanged(QString filterName) {
    std::cout << filterName.toStdString() << std::endl;
    if (filterName == "Average") {
        auto grayImage = inputImage->toGrayscale();
        auto im = avgFilter(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
    } else if (filterName == "Gaussian") {
        auto grayImage = inputImage->toGrayscale();
        auto im = gaussianFilter(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
    } else if (filterName == "Median") {
        auto grayImage = inputImage->toGrayscale();
        auto im = medianFilter(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
    } else if (filterName == "Prewitt") {
        auto grayImage = inputImage->toGrayscale();
        auto im = perwitEdgeDetector(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
    } else if (filterName == "Roberts") {
        auto grayImage = inputImage->toGrayscale();
        auto im = robertsEdgeDetector(grayImage).toScale();
        for (int i = 0; i < 10000000; ++i);
        displayGrayscaleImage(&im, ui->outputImageLabel);
    } else if (filterName == "Sobel") {
        auto grayImage = inputImage->toGrayscale();
        auto im = sobelEdgeDetector(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
    }
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
    delete outputImage;
}
