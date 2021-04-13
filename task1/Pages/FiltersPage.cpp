//
// Created by abdallah drwesh on 4/4/21.
//
#include "../MainWindow.h"
#include "../ui_MainWindow.h"
#include <QFileDialog>
#include "processinglib/filters.h"
#include "processinglib/utilities.h"
#include "processinglib/canny.h"
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
        auto grayImage = noiseImage->toGrayscale();
        auto im = avgFilter(grayImage, 7);
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_average");
    } else if (filterName == "Gaussian") {
        auto grayImage = noiseImage->toGrayscale();
        auto im = gaussianFilter(grayImage, 7);
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_gaussian");
    } else if (filterName == "Median") {
        auto grayImage = noiseImage->toGrayscale();
        auto im = medianFilter(grayImage, 7);
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_median");
    } else if (filterName == "Prewitt") {
        auto grayImage = inputImage->toGrayscale();
        displayGrayscaleImage(&grayImage, ui->inputImageLabel);
        auto im = perwitEdgeDetector(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_prewitt");
    } else if (filterName == "Roberts") {
        auto grayImage = inputImage->toGrayscale();
        displayGrayscaleImage(&grayImage, ui->inputImageLabel);
        auto im = robertsEdgeDetector(grayImage).toScale();
//        im.saveJPG("out_robot");
        displayGrayscaleImage(&im, ui->outputImageLabel);
    } else if (filterName == "Sobel") {
        auto grayImage = inputImage->toGrayscale();
        displayGrayscaleImage(&grayImage, ui->inputImageLabel);
        auto im = sobelEdgeDetector(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_sobel");
    } else if (filterName == "Salt and Pepper Noise") {
        delete noiseImage;
        noiseImage = new Image(inputImage->width, inputImage->height, inputImage->channels);
        auto grayImage = inputImage->toGrayscale();
        auto im = saltPepper(grayImage, 100, 2);
        for (int i = 0; i < im.height; ++i) {
            for (int j = 0; j < im.width; ++j) {
                for (int k = 0; k < im.channels; ++k) {
                    (*noiseImage)(i, j, k) = im(i, j, k);
                }
            }
        }
        displayGrayscaleImage(&im, ui->inputImageLabel);
//        im.saveJPG("out_salt and pepper");
    } else if (filterName == "Normalize") {
        auto grayImage = inputImage->toGrayscale();
        displayGrayscaleImage(&grayImage, ui->inputImageLabel);
        auto im = minMaxNormalize(grayImage).toScale();
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_normalize");
    } else if (filterName == "Global Thresholding") {
        auto grayImage = inputImage->toGrayscale();
        displayGrayscaleImage(&grayImage, ui->inputImageLabel);
        auto im = globalThresholding(grayImage, 0);
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_global_thresholding");
    } else if (filterName == "Local Thresholding") {
        auto grayImage = inputImage->toGrayscale();
        displayGrayscaleImage(&grayImage, ui->inputImageLabel);
        auto im = localThresholding(grayImage, 0, 128, 15);
        displayGrayscaleImage(&im, ui->outputImageLabel);
//        im.saveJPG("out_local_thresholding");
    } else if(filterName == "Canny"){
        auto grayImage = inputImage->toGrayscale();
        auto im = cannyEdgeDetector(grayImage);
        displayGrayscaleImage(&im, ui->outputImageLabel);
    }
}


