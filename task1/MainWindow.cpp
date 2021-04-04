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
#include "processing/include/filters.h"
#include "processing/include/histogram.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace  cv;

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
void MainWindow::on_LoadImageBtn_1_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    ui->imageName->setText(QString(filename.c_str()));
    QPixmap pixmap{filePath};
    ui->InputImagLabel_1->setPixmap(pixmap);
    loadImage(filepathStd,2);
    std::string imageSize = std::to_string(inputImage_1->size());
    ui->imageSize->setText(QString(imageSize.c_str()));
    if (inputImage_1->channels == 1){
        ui->imageSelect->setCurrentIndex(0);
    }else{
        ui->imageSelect->setCurrentIndex(1);
    }

}


void MainWindow::loadImage(std::string filepath, Image *&image) {
    if (image != nullptr) {
        delete image;
    }
    image = new Image(filepath);
}

void MainWindow::on_imageSelect_currentIndexChanged(QString filterName) {
    if (filterName == "GrayImage" || inputImage_1->channels == 1) {
        int histogram[256];
        int cumHist[256];
        Image grayIm = inputImage_1->toGrayscale();
        im_hist(grayIm,histogram,1);
        cumulative_hist(histogram,cumHist);
        Mat histImage = histDisplay(histogram,0);
        ui->InputImagLabel_2->setPixmap(QPixmap::fromImage(QImage((unsigned char*) histImage.data, histImage.cols, histImage.rows, QImage::Format_RGB888)));
        Mat cumHistImage = CDFDisplay(cumHist,0);
        ui->InputImagLabel_3->setPixmap(QPixmap::fromImage(QImage((unsigned char*) cumHistImage.data, cumHistImage.cols, cumHistImage.rows, QImage::Format_RGB888)));

        QImage qImage(grayIm.width, grayIm.height, QImage::Format_RGB16);
        QRgb rgb;
        for (int j = 0; j < grayIm.width; ++j) {
            for (int i = 0; i < grayIm.height; ++i) {
                rgb = qRgb(grayIm.data[i][j][0], grayIm.data[i][j][0], grayIm.data[i][j][0]);
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
                qImage.setPixel(j, i, rgb);
            }
        }
        ui->InputImagLabel_1->setPixmap(QPixmap::fromImage(qImage));

        int hist_eq_form[256];
        int eq_hist[256];
        hist_eq_formula( grayIm,cumHist,histogram, hist_eq_form);
        equalized_hist(grayIm,histogram,eq_hist, hist_eq_form);
        equalized_image(grayIm, hist_eq_form);

        Mat EqhistImage = histDisplay(eq_hist,0);
        int cumEqHist[256];
        cumulative_hist(eq_hist, cumEqHist);
        Mat cumEqHistIMage = CDFDisplay(cumEqHist,0);
        QImage qImage_1(grayIm.width, grayIm.height, QImage::Format_RGB16);
        QRgb rgb_1;
        for (int j = 0; j < grayIm.width; ++j) {
            for (int i = 0; i < grayIm.height; ++i) {
                rgb = qRgb(grayIm.data[i][j][0], grayIm.data[i][j][0], grayIm.data[i][j][0]);
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
                qImage.setPixel(j, i, rgb);
            }
        }
        ui->outpuImageLabel_1->setPixmap(QPixmap::fromImage(qImage));
        ui->outputImageLabel_2->setPixmap(QPixmap::fromImage(QImage((unsigned char*) EqhistImage.data, EqhistImage.cols, EqhistImage.rows, QImage::Format_RGB888)));
        ui->outputImageLabel_3->setPixmap(QPixmap::fromImage(QImage((unsigned char*) cumEqHistIMage.data, cumEqHistIMage.cols, cumEqHistIMage.rows, QImage::Format_RGB888)));
    } else if (filterName == "RGBImage" & inputImage_1->channels ==3) {
        ui->outpuImageLabel_1->clear();
        ui->outputImageLabel_2->clear();
        ui->outputImageLabel_3->clear();

        int hist_1[256];
        int cumHist_1[256];
        Image *image = new Image(*inputImage_1);
        im_hist(*image,hist_1,1);
        cumulative_hist(hist_1,cumHist_1);
        Mat histImage_1 = histDisplay(hist_1,1);
        Mat cumHistImage_1 = CDFDisplay(cumHist_1,1);

        int hist_2[256];
        int cumHist_2[256];
        im_hist(*image,hist_2,2);
        cumulative_hist(hist_2,cumHist_2);
        Mat histImage_2 = histDisplay(hist_2,2);
        Mat cumHistImage_2 = CDFDisplay(cumHist_2,2);

        int hist_3[256];
        int cumHist_3[256];
        im_hist(*image,hist_3,3);
        cumulative_hist(hist_3,cumHist_3);
        Mat histImage_3 = histDisplay(hist_3,3);
        Mat cumHistImage_3 = CDFDisplay(cumHist_3,3);

        vconcat(histImage_1,histImage_2,histImage_2);
        vconcat(histImage_2,histImage_3,histImage_3);
        cv::resize(histImage_3, histImage_3, cv::Size(histImage_3.cols * 1,histImage_3.rows * 0.3), 0, 0, INTER_LINEAR);
        vconcat(cumHistImage_1,cumHistImage_2,cumHistImage_2);
        vconcat(cumHistImage_2,cumHistImage_3,cumHistImage_3);
        cv::resize(cumHistImage_3, cumHistImage_3, cv::Size(cumHistImage_3.cols * 1,cumHistImage_3.rows * 0.3), 0, 0, INTER_LINEAR);
        ui->InputImagLabel_2->clear();
        ui->InputImagLabel_3->clear();
        ui->InputImagLabel_2->setPixmap(QPixmap::fromImage(QImage((unsigned char*) histImage_3.data, histImage_3.cols, histImage_3.rows, QImage::Format_RGB888)));
        ui->InputImagLabel_3->setPixmap(QPixmap::fromImage(QImage((unsigned char*) cumHistImage_3.data, cumHistImage_3.cols, cumHistImage_3.rows, QImage::Format_RGB888)));

    }
}

void MainWindow::loadImage(std::string filepath, int tabNo) {
    if (tabNo == 1){
        if (inputImage != nullptr) {
            delete inputImage;
        }
        inputImage = new Image(filepath);
    } else if (tabNo == 2){
        if (inputImage_1 != nullptr) {
            delete inputImage_1;
        }
        inputImage_1 = new Image(filepath);
    }
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
Mat MainWindow::histDisplay(int histogram[], int color)
{
    int hist[256];
    for(int i = 0; i < 256; i++)
    {
        hist[i]=histogram[i];
    }
    // draw the histograms
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double) hist_w/256);

     Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));


    // find the maximum intensity element from histogram
    int max = hist[0];
    for(int i = 1; i < 256; i++){
        if(max < hist[i]){
            max = hist[i];
        }
    }

    // normalize the histogram between 0 and histImage.rows
    for(int i = 0; i < 256; i++)
    {
        hist[i] = ((double)hist[i]/max)*histImage.rows;
    }

    Scalar scalarArray[4] = {Scalar(0, 0, 0),Scalar(255, 0, 0),Scalar(0, 255, 0), Scalar(0, 0, 255) };
    // draw the intensity line for histogram
    for(int i = 0; i < 256; i++)
    {
        line(histImage, Point(bin_w*(i), hist_h), Point(bin_w*(i), hist_h - hist[i]),scalarArray[color], 2, 8, 0);
    }

    // display histogram
//    namedWindow(name, WINDOW_AUTOSIZE);
//    imshow(name, histImage);
//    ui->InputImagLabel_2->setPixmap(QPixmap::fromImage(QImage((unsigned char*) histImage.data, histImage.cols, histImage.rows, QImage::Format_RGB888)));
    return histImage;
}

Mat MainWindow::CDFDisplay(int histogram[], int color)
{
    int hist[256];
    for(int i = 0; i < 256; i++)
    {
        hist[i]=histogram[i];
    }
    // draw the histograms
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double) hist_w/256);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
    // find the maximum intensity element from histogram
    int max = hist[0];
    for(int i = 1; i < 256; i++){
        if(max < hist[i]){
            max = hist[i];
        }
    }
    // normalize the histogram between 0 and histImage.rows
    for(int i = 0; i < 256; i++)
    {
        hist[i] = ((double)hist[i]/max)*histImage.rows;
    }
    // draw the intensity line for histogram
    Scalar scalarArray[4] = {Scalar(0, 0, 0),Scalar(255, 0, 0),Scalar(0, 255, 0), Scalar(0, 0, 255) };
    for(int i = 1; i < 256; i++)
    {
        line(histImage, Point(bin_w*(i-1), hist_h - hist[i-1]), Point(bin_w*(i), hist_h - hist[i]),scalarArray[color], 2, 8, 0);
    }
    // display histogram

//    ImageLabel->setPixmap(QPixmap::fromImage(QImage((unsigned char*) histImage.data, histImage.cols, histImage.rows, QImage::Format_RGB888)));
    return histImage;
}
MainWindow::~MainWindow() {
    delete ui;
    delete inputImage;
    delete inputImage_1;
    delete outputImage;
    delete outputImage_1;
}
