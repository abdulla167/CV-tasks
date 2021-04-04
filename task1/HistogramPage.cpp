//
// Created by abdallah drwesh on 4/4/21.
//
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include "processing/histogram.h"
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


void MainWindow::on_LoadImageBtn_1_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    ui->imageName->setText(QString(filename.c_str()));
    QPixmap pixmap{filePath};
    ui->InputImagLabel_1->setPixmap(pixmap);
    loadImage(filepathStd, inputImage_1);
    std::string imageSize = std::to_string(inputImage_1->size());
    ui->imageSize->setText(QString(imageSize.c_str()));
    if (inputImage_1->channels == 1) {
        ui->imageSelect->setCurrentIndex(0);
    } else {
        ui->imageSelect->setCurrentIndex(1);
    }
}

void MainWindow::on_imageSelect_currentIndexChanged(QString filterName) {
    if (filterName == "GrayImage" || inputImage_1->channels == 1) {
        int histogram[256];
        int cumHist[256];
        Image grayIm = inputImage_1->toGrayscale();
        im_hist(grayIm, histogram, 1);
        cumulative_hist(histogram, cumHist);
        Mat histImage = histDisplay(histogram, 0);
        int label2Width = ui->InputImagLabel_2->width();
        int label2Height = ui->InputImagLabel_2->height();
        ui->InputImagLabel_2->setPixmap(QPixmap::fromImage(
                QImage((unsigned char *) histImage.data, histImage.cols, histImage.rows, QImage::Format_RGB888)).scaled(
                label2Width, label2Height));
        Mat cumHistImage = CDFDisplay(cumHist, 0);
        int label3Width = ui->InputImagLabel_3->width();
        int label3Height = ui->InputImagLabel_3->height();
        ui->InputImagLabel_3->setPixmap(QPixmap::fromImage(
                QImage((unsigned char *) cumHistImage.data, cumHistImage.cols, cumHistImage.rows,
                       QImage::Format_RGB888)).scaled(label3Width, label3Height));

        displayGrayscaleImage(&grayIm, ui->InputImagLabel_1);

        int hist_eq_form[256];
        int eq_hist[256];
        hist_eq_formula(grayIm, cumHist, histogram, hist_eq_form);
        equalized_hist(grayIm, histogram, eq_hist, hist_eq_form);
        equalized_image(grayIm, hist_eq_form);

        Mat EqhistImage = histDisplay(eq_hist, 0);
        int cumEqHist[256];
        cumulative_hist(eq_hist, cumEqHist);
        Mat cumEqHistIMage = CDFDisplay(cumEqHist, 0);
        QImage qImage_1(grayIm.width, grayIm.height, QImage::Format_RGB16);
        displayGrayscaleImage(&grayIm, ui->outpuImageLabel_1);

        int outlabel2Width = ui->outputImageLabel_2->width();
        int outlabel2Height = ui->outputImageLabel_2->height();
        ui->outputImageLabel_2->setPixmap(QPixmap::fromImage(
                QImage((unsigned char *) EqhistImage.data, EqhistImage.cols, EqhistImage.rows,
                       QImage::Format_RGB888)).scaled(outlabel2Width, outlabel2Height));
        int outlabel3Width = ui->outputImageLabel_3->width();
        int outlabel3Height = ui->outputImageLabel_3->height();
        ui->outputImageLabel_3->setPixmap(QPixmap::fromImage(
                QImage((unsigned char *) cumEqHistIMage.data, cumEqHistIMage.cols, cumEqHistIMage.rows,
                       QImage::Format_RGB888)).scaled(outlabel3Width, outlabel3Height));
    } else if (filterName == "RGBImage" & inputImage_1->channels == 3) {
        ui->outpuImageLabel_1->clear();
        ui->outputImageLabel_2->clear();
        ui->outputImageLabel_3->clear();

        int hist_1[256];
        int cumHist_1[256];
        Image *image = new Image(*inputImage_1);
        im_hist(*image, hist_1, 1);
        cumulative_hist(hist_1, cumHist_1);
        Mat histImage_1 = histDisplay(hist_1, 1);
        Mat cumHistImage_1 = CDFDisplay(cumHist_1, 1);

        int hist_2[256];
        int cumHist_2[256];
        im_hist(*image, hist_2, 2);
        cumulative_hist(hist_2, cumHist_2);
        Mat histImage_2 = histDisplay(hist_2, 2);
        Mat cumHistImage_2 = CDFDisplay(cumHist_2, 2);

        int hist_3[256];
        int cumHist_3[256];
        im_hist(*image, hist_3, 3);
        cumulative_hist(hist_3, cumHist_3);
        Mat histImage_3 = histDisplay(hist_3, 3);
        Mat cumHistImage_3 = CDFDisplay(cumHist_3, 3);

        vconcat(histImage_1, histImage_2, histImage_2);
        vconcat(histImage_2, histImage_3, histImage_3);
        cv::resize(histImage_3, histImage_3, cv::Size(histImage_3.cols * 1, histImage_3.rows * 0.3), 0, 0,
                   INTER_LINEAR);
        vconcat(cumHistImage_1, cumHistImage_2, cumHistImage_2);
        vconcat(cumHistImage_2, cumHistImage_3, cumHistImage_3);
        cv::resize(cumHistImage_3, cumHistImage_3, cv::Size(cumHistImage_3.cols * 1, cumHistImage_3.rows * 0.3), 0, 0,
                   INTER_LINEAR);
        ui->InputImagLabel_2->clear();
        ui->InputImagLabel_3->clear();
        ui->InputImagLabel_2->setPixmap(QPixmap::fromImage(
                QImage((unsigned char *) histImage_3.data, histImage_3.cols, histImage_3.rows, QImage::Format_RGB888)));
        ui->InputImagLabel_3->setPixmap(QPixmap::fromImage(
                QImage((unsigned char *) cumHistImage_3.data, cumHistImage_3.cols, cumHistImage_3.rows,
                       QImage::Format_RGB888)));

    }
}


Mat MainWindow::histDisplay(int histogram[], int color) {
    int hist[256];
    for (int i = 0; i < 256; i++) {
        hist[i] = histogram[i];
    }
    // draw the histograms
    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w / 256);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));


    // find the maximum intensity element from histogram
    int max = hist[0];
    for (int i = 1; i < 256; i++) {
        if (max < hist[i]) {
            max = hist[i];
        }
    }

    // normalize the histogram between 0 and histImage.rows
    for (int i = 0; i < 256; i++) {
        hist[i] = ((double) hist[i] / max) * histImage.rows;
    }

    Scalar scalarArray[4] = {Scalar(0, 0, 0), Scalar(255, 0, 0), Scalar(0, 255, 0), Scalar(0, 0, 255)};
    // draw the intensity line for histogram
    for (int i = 0; i < 256; i++) {
        line(histImage, Point(bin_w * (i), hist_h), Point(bin_w * (i), hist_h - hist[i]), scalarArray[color], 2, 8, 0);
    }

    // display histogram
//    namedWindow(name, WINDOW_AUTOSIZE);
//    imshow(name, histImage);
//    ui->InputImagLabel_2->setPixmap(QPixmap::fromImage(QImage((unsigned char*) histImage.data, histImage.cols, histImage.rows, QImage::Format_RGB888)));
    return histImage;
}

Mat MainWindow::CDFDisplay(int histogram[], int color) {
    int hist[256];
    for (int i = 0; i < 256; i++) {
        hist[i] = histogram[i];
    }
    // draw the histograms
    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w / 256);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
    // find the maximum intensity element from histogram
    int max = hist[0];
    for (int i = 1; i < 256; i++) {
        if (max < hist[i]) {
            max = hist[i];
        }
    }
    // normalize the histogram between 0 and histImage.rows
    for (int i = 0; i < 256; i++) {
        hist[i] = ((double) hist[i] / max) * histImage.rows;
    }
    // draw the intensity line for histogram
    Scalar scalarArray[4] = {Scalar(0, 0, 0), Scalar(255, 0, 0), Scalar(0, 255, 0), Scalar(0, 0, 255)};
    for (int i = 1; i < 256; i++) {
        line(histImage, Point(bin_w * (i - 1), hist_h - hist[i - 1]), Point(bin_w * (i), hist_h - hist[i]),
             scalarArray[color], 2, 8, 0);
    }
    // display histogram

//    ImageLabel->setPixmap(QPixmap::fromImage(QImage((unsigned char*) histImage.data, histImage.cols, histImage.rows, QImage::Format_RGB888)));
    return histImage;
}