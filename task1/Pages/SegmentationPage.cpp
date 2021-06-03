//
// Created by mohamedkamal on ١٦‏/٥‏/٢٠٢١.
//
#include "../MainWindow.h"
#include "../ui_MainWindow.h"
#include <QFileDialog>
#include "processinglib/utilities.h"
#include "processinglib/k_mean_segmentation.h"
#include "processinglib/mean_shift.h"
#include "processinglib/growing_region.h"
#include "processinglib/agglomerative_cluster_segmentation.h"

void MainWindow::on_segmentImgBtn_clicked() {
    bool  first = false;
    if(segmentationImage == nullptr){
        first = true;
    }
    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    segmentationImage = new Image(filepathStd,3);
    
    QImage qImage(segmentationImage->width, segmentationImage->height, QImage::Format_RGB16);
    QRgb rgb;
    for (int j = 0; j < segmentationImage->width; ++j) {
        for (int i = 0; i < segmentationImage->height; ++i) {
            rgb = qRgb((*segmentationImage)(i, j,0), (*segmentationImage)(i, j,1), (*segmentationImage)(i, j,2));
            qImage.setPixel(j, i, rgb);
        }
    }
    int width = ui->segmentImg->width() ;
    int height = ui->segmentImg->height();
    ui->segmentImg->setBackground(QPixmap::fromImage(qImage).scaled(width, height,Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->segmentImg->setAutoFillBackground(true);
    ui->segmentImg->replot();
    std::vector<std::vector<float>> mat {
            { 1.2f, 2.5f, 5.6f, -2.5f },
            { -3.6f, 9.2f, 0.5f, 7.2f },
            { 4.3f, 1.3f, 9.4f, -3.4f } };


    std::vector<std::vector<float>> result;

    result = covarMatrix(mat);

    for(int i = 0; i < 3; i++){

           qDebug()<<  result[i][0]<< " " << result[i][1]  << " " << result[i][2];

    }
}

void MainWindow::startSegmentation() {
    if (ui->filterSelect_2->currentIndex() == 1){
        int k = 3;
        k = ui->KBox->value();
        qDebug() << k;
        K_mean kMean( segmentationImage, k, 200);
        Image image = kMean.getOutput();
        displayRGBImage(&image, ui->segmentOutput);

    } else if (ui->filterSelect_2->currentIndex() == 2) {

        MeanShift meanShift(segmentationImage, 8, 16);
        Image image = meanShift.run();
        displayRGBImage(&image, ui->segmentOutput);
    }  else if (ui->filterSelect_2->currentIndex() == 3) {
        auto outputImg = RGSegmentation((*segmentationImage), DataRG);
        displayRGBImage(&outputImg, ui->segmentOutput);
    }  else if (ui->filterSelect_2->currentIndex() == 4) {
        auto grayImage = segmentationImage->toGrayscale();
        auto outputImg = agglomerativeSeg(grayImage, 9, 25);
        displayGrayscaleImage(&outputImg, ui->segmentOutput);
    }

}
void MainWindow::on_reRunBtn_clicked() {
    startSegmentation();
}
void MainWindow::on_clearSegmentBtn_clicked() {
    regionGrowing->data()->clear();
    DataRG.clear();
    ui->segmentImg->replot();
}

void MainWindow::on_filterSelect_2_currentIndexChanged(QString filterName) {
    startSegmentation();
}