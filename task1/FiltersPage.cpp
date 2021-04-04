//
// Created by abdallah drwesh on 4/4/21.
//
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include "processing/filters.h"
#include <iostream>

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
