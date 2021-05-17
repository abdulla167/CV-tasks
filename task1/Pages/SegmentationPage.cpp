//
// Created by mohamedkamal on ١٦‏/٥‏/٢٠٢١.
//
#include "../MainWindow.h"
#include "../ui_MainWindow.h"
#include <QFileDialog>
#include "processinglib/k_mean_segmentation.h"
#include "iostream"
void MainWindow::on_segmentImgBtn_clicked() {

    QString filePath = QFileDialog::getOpenFileName(this, "load image", "../");
    std::string filepathStd = filePath.toStdString();
    auto filename = filepathStd.substr(filepathStd.find_last_of("/") + 1);
    segmentationImage = new Image(filepathStd,3);
    displayRGBImage(segmentationImage, ui->segmentImg);


}

void MainWindow::on_startSegmentationBtn_clicked() {

    K_mean kMean( segmentationImage, 3, 200);
    Image image = kMean.getOutput();

    for (int j = 0; j < image.width; j++) {
        for (int i = 0; i < image.height; i++) {
            for (int k =0; k < image.channels; k++){
                image(i, j, k) = abs(image(i, j, k));
            }
        }
    }

    displayRGBImage(&image, ui->segmentOutput);

}
