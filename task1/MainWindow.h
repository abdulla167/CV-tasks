//
// Created by abdallah drwesh on 4/3/21.
//

#ifndef CV_MAINWINDOW_H
#define CV_MAINWINDOW_H

#include <QMainWindow>
#include "processing/Image.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

    Image *inputImage = nullptr;
    Image *outputImage = nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:

    void on_loadImageBtn_clicked();

    void on_filterSelect_currentIndexChanged(QString);

private:
    Ui::MainWindow *ui;
    void loadImage(std::string filepath);
    void displayRGBImage(Image *image);
    void displayGrayscaleImage(Image *image);
};

#endif //CV_MAINWINDOW_H
