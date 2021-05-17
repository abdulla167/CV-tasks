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
    QPixmap pixmap{filePath};
    segmentationImage = new Image(filepathStd,3);
    displayRGBImage(segmentationImage, ui->segmentImg);


}

void MainWindow::on_startSegmentationBtn_clicked() {

    K_mean kMean( segmentationImage, 3, 100);
    Image image1 = kMean.getOutput();

    Image *image = new Image(image1.width, image1.height, image1.channels);
    for (int j = 0; j < image1.width; j++) {
        for (int i = 0; i < image1.height; i++) {
            for (int k =0; k < image1.channels; k++){
                (*image)(i, j, k) = abs(image1(i, j, k));
            }
        }
    }
    kMean.print(image->width);
    kMean.print(image->height);
    kMean.print(image->channels);
    displayRGBImage(image, ui->segmentOutput);

}
