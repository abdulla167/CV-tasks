//
// Created by mohamedkamal on ١٣‏/٤‏/٢٠٢١.
//

#include "../MainWindow.h"
#include "../ui_MainWindow.h"
#include <QFileDialog>
#include <iostream>
# include "processinglib/greedy_snake.h"

using namespace std;
using namespace cv;
void MainWindow::on_start_clicked(){


    qDebug() << "started";
    for(int j =0; j<5 ; j++){
        float alpha = 2, beta = 1.7, gamma = 2.5, sigma = 9 -2*j, maxIt = 10000;

        for (int i = 0; i < 5-j; i++) {
            Image image = snakeImage->toGrayscale();
            greedySnake(image, maxIt, 50, arrayOfPointsX, arrayOfPointsY, sigma, alpha, beta, gamma);

                sigma = sigma - 2;

        }
    }
    qDebug() << "ended";
    xData->clear();
    yData->clear();
    for (int i=0; i<50; i++){
        int xCoordinate = (arrayOfPointsX[i]/(float )snakeImage->width)*ui->snake->background().rect().width();
        int yCoordinate = (arrayOfPointsY[i]/(float )snakeImage->height)*ui->snake->background().rect().height();

        xData->append(ui->snake->xAxis->pixelToCoord( xCoordinate) );
        yData->append(ui->snake->yAxis->pixelToCoord( yCoordinate) );
    }
//    points->data()->clear();
    points->setData(*xData, *yData);
    ui->snake->replot();

}
void MainWindow::on_loadSnake_clicked() {

    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    QPixmap pixmap{filePath};
    snakeImage = new Image(filepathStd,3);
    qDebug() <<"hellp";
    std::string imageHeight = std::to_string(snakeImage->height);
    std::string imageWidth = std::to_string(snakeImage->width);
    ui->imageSize->setText(QString(imageHeight.c_str()));
    ui->imageName->setText(QString(imageWidth.c_str()));

    QImage qImage(snakeImage->width, snakeImage->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < snakeImage->width; ++j) {
        for (int i = 0; i < snakeImage->height; ++i) {
            rgb = qRgb((*snakeImage)(i, j,0), (*snakeImage)(i, j,1), (*snakeImage)(i, j,2));
            qImage.setPixel(j, i, rgb);
        }
    }
    int width = ui->snake->width() ;
    int height = ui->snake->height();
    ui->snake->setBackground(QPixmap::fromImage(qImage).scaled(width, height,Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->snake->setAutoFillBackground(true);
    ui->snake->replot();



}



