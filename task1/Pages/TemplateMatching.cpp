//
// Created by mohamedkamal on ٥‏/٥‏/٢٠٢١.
//
#include "../MainWindow.h"
#include "../ui_MainWindow.h"
#include <QFileDialog>
#include "processinglib/harris_corner_detector.h"
#include "vector"

void MainWindow::on_loadImageMatchBtn_1_clicked() {

    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    QPixmap pixmap{filePath};

    imageMatch_1 = new Image(filepathStd,3);

    QImage qImage(imageMatch_1->width, imageMatch_1->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < imageMatch_1->width; ++j) {
        for (int i = 0; i < imageMatch_1->height; ++i) {
            rgb = qRgb((*imageMatch_1)(i, j,0), (*imageMatch_1)(i, j,1), (*imageMatch_1)(i, j,2));
            qImage.setPixel(j, i, rgb);
        }
    }
    int width = ui->imageMatch_1->width() ;
    int height = ui->imageMatch_1->height();
    ui->imageMatch_1->setBackground(QPixmap::fromImage(qImage).scaled(width, height,Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->imageMatch_1->setAutoFillBackground(true);
    ui->imageMatch_1->replot();
    Image gray = imageMatch_1->toGrayscale();
   std::vector<std::vector<double>> mat =  getSIFTDescriptor(gray);
}

void MainWindow::on_loadImageMatchBtn_2_clicked() {

    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    QPixmap pixmap{filePath};

    imageMatch_2 = new Image(filepathStd,3);

    QImage qImage(imageMatch_2->width, imageMatch_2->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < imageMatch_2->width; ++j) {
        for (int i = 0; i < imageMatch_2->height; ++i) {
            rgb = qRgb((*imageMatch_2)(i, j,0), (*imageMatch_2)(i, j,1), (*imageMatch_2)(i, j,2));
            qImage.setPixel(j, i, rgb);
        }
    }
    int width = ui->imageMatch_2->width() ;
    int height = ui->imageMatch_2->height();
    ui->imageMatch_2->setBackground(QPixmap::fromImage(qImage).scaled(width, height,Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->imageMatch_2->setAutoFillBackground(true);
    ui->imageMatch_2->replot();

   //std::vector<std::vector<double>> mat =  getSIFTDescriptor(*imageMatch_2);
}