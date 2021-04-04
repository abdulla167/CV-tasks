//
// Created by abdallah drwesh on 4/3/21.
//

#ifndef CV_MAINWINDOW_H
#define CV_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "processing/Image.h"
#include <opencv2/imgproc/imgproc.hpp>

using namespace  cv;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

    Image *inputImage = nullptr;
    Image *outputImage = nullptr;

    Image *imageA = nullptr;
    Image *imageB = nullptr;

    Image *inputImage_1 = nullptr;
    Image *outputImage_1 = nullptr;


public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;
private slots:
    void on_loadImageBtn_clicked();
    void on_imageABtn_clicked();

    void on_imageBBtn_clicked();

    void on_hybridBtn_clicked();

    void on_plotBtn_clicked(){
        plot();
    }

    void on_LoadImageBtn_1_clicked();
    void on_filterSelect_currentIndexChanged(QString);
    void on_imageSelect_currentIndexChanged(QString);

private:
    Ui::MainWindow *ui;

    void loadImage(std::string filepath, Image *&image);

    void plot();

    void displayRGBImage(Image *image, QLabel *label);

    void displayGrayscaleImage(Image *image, QLabel *label);

    Mat histDisplay(int histogram[], int color);
    Mat CDFDisplay(int histogram[], int color);
};

#endif //CV_MAINWINDOW_H
