//
// Created by abdallah drwesh on 4/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include <QGraphicsPixmapItem>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QChart>
#include <QChartView>
#include <QLineSeries>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
//    ImageDisplay = new QCPItemPixmap( ui->snake);
    points = ui->snake->addGraph();
    ui->snake->xAxis->setVisible(false);
    ui->snake->yAxis->setVisible(false);
    ui->snake->xAxis->setRange(0.0, 5.0);
    ui->snake->yAxis->setRange(0.0, 5.0);
    ui->snake->setAutoFillBackground(true);
    ui->snake->replot();
    ui->snake->installEventFilter(this);
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
            rgb = qRgb((*image)(i, j, 0), (*image)(i, j, 1), (*image)(i, j, 2));
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
            qImage.setPixel(j, i, rgb);
        }
    }
    int width = label->width();
    int height = label->height();
    label->setPixmap(QPixmap::fromImage(qImage).scaled(width, height));
}

void MainWindow::displayGrayscaleImage(Image *image, QLabel *label) {
    QImage qImage(image->width, image->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < image->width; ++j) {
        for (int i = 0; i < image->height; ++i) {
            rgb = qRgb((*image)(i, j), (*image)(i, j), (*image)(i, j));
//            printf("%i %i %i \n",inputImage->data[i][j][0],inputImage->data[i][j][1],inputImage->data[i][j][2]);
            qImage.setPixel(j, i, rgb);
        }
    }
    int width = label->width();
    int height = label->height();
    label->clear();
    label->setPixmap(QPixmap::fromImage(qImage).scaled(width, height));
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {

    if (obj == ui->snake && snakeImage != nullptr) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

            int x = ceil(((float) mouseEvent->x() / ui->snake->background().rect().width()) * snakeImage->width);
            int y = ceil(((float) mouseEvent->y() / ui->snake->background().rect().height()) *
                         snakeImage->height); //qDebug()
            if (centerX == 0) {
                centerX = x;
                centerY = y;
            } else if (raduis == 0) {
                raduis = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));

            }


            if (raduis != 0) {
                qDebug() << "start drawing";
                float step = 2 * 3.14 / pointsCount;
                for (int i = 0; i < pointsCount; i++) {
                    arrayOfPointsX[i] = centerX + cos(step * i) * raduis;
                    arrayOfPointsY[i] = centerY + sin(step * i) * raduis;
                    int xCoordinate = ceil(
                            (arrayOfPointsX[i] / (float) snakeImage->width) * ui->snake->background().rect().width());
                    int yCoordinate = ceil(
                            (arrayOfPointsY[i] / (float) snakeImage->height) * ui->snake->background().rect().height());
                    xData->append(ui->snake->xAxis->pixelToCoord(xCoordinate));
                    yData->append(ui->snake->yAxis->pixelToCoord(yCoordinate));
                }
                qDebug() << "start drawing";
                points->setData(*xData, *yData);
                qDebug() << "start drawing";
                points->setLineStyle((QCPGraph::LineStyle) QCPGraph::lsNone);
                points->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));
                points->setPen(QPen(QColor(0, 0, 255), 2));
//                points->setLayer("points");
//                ui->snake->moveLayer(points->layer(), ImageDisplay->layer(), QCustomPlot::limAbove);
                ui->snake->replot();
            }
            return QObject::eventFilter(obj, event);
        }
    }
    return QObject::eventFilter(obj, event);
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
    delete snakeImage;
    delete ImageDisplay;
    delete points;
    delete xData;
    delete yData;

}
