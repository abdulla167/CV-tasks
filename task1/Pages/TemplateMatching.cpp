//
// Created by mohamedkamal on ٥‏/٥‏/٢٠٢١.
//
#include "../MainWindow.h"
#include "../ui_MainWindow.h"
#include <QFileDialog>
#include "processinglib/harris_corner_detector.h"
#include "processinglib/imageMatching.h"
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
    int * result;

    SSDMatching(*imageMatch_1,*imageMatch_2, result);
    int elementCount = (sizeof(result)  / sizeof(result[0]))/4;
    for(int loop = 0 ; loop < elementCount; loop++) {
        int xCoord_1 = result[loop*4 ] * ui->imageMatch_1->background().rect().width();
        int yCoord_1 = result[loop*4 + 1] * ui->imageMatch_1->background().rect().height();
        int xCoord_2 = result[loop*4 + 2] * ui->imageMatch_2->background().rect().width();
        int yCoord_2 = result[loop*4 + 3] * ui->imageMatch_2->background().rect().height();
//        xDataMatching_1->append(ui->imageMatch_1->xAxis->pixelToCoord(xCoord_1));
//        yDataMatching_1->append(ui->imageMatch_1->yAxis->pixelToCoord(yCoord_1));
//        xDataMatching_2->append(ui->imageMatch_2->xAxis->pixelToCoord(xCoord_2));
//        yDataMatching_2->append(ui->imageMatch_2->yAxis->pixelToCoord(yCoord_2));
        QCPItemText *textLabel = new QCPItemText(ui->imageMatch_1);
//        textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
        textLabel->position->setCoords(xCoord_1, yCoord_1); // place position at center/top of axis rect
        textLabel->setText( "" + loop);
        textLabel->setFont(QFont(font().family(), 3)); // make font a bit larger
        textLabel->setPen(QPen(Qt::blue)); // show black border around text
        QCPItemText *textLabel_2 = new QCPItemText(ui->imageMatch_2);
//        textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        textLabel_2->position->setType(QCPItemPosition::ptAxisRectRatio);
        textLabel_2->position->setCoords(xCoord_2, yCoord_2); // place position at center/top of axis rect
        textLabel_2->setText( "" + loop);
        textLabel_2->setFont(QFont(font().family(), 3)); // make font a bit larger
        textLabel_2->setPen(QPen(Qt::blue)); // show black border around text

        qDebug()<< loop << "  "<< xCoord_1;

    }
    ui->imageMatch_1->replot();
    ui->imageMatch_2->replot();
}