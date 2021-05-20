//
// Created by mohamedkamal on ١٦‏/٥‏/٢٠٢١.
//
#include "../MainWindow.h"
#include "../ui_MainWindow.h"
#include <QFileDialog>
#include "processinglib/k_mean_segmentation.h"
#include "processinglib/mean_shift.h"
#include "iostream"
void MainWindow::on_segmentImgBtn_clicked() {

    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    segmentationImage = new Image(filepathStd,3);
    displayRGBImage(segmentationImage, ui->segmentImg);


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

        MeanShift meanShift(segmentationImage, 8, 16, 100);
        Image image = meanShift.run();
        displayRGBImage(&image, ui->segmentOutput);
    }

}

void MainWindow::on_filterSelect_2_currentIndexChanged(QString filterName) {
    startSegmentation();
}