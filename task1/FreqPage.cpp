//
// Created by abdallah drwesh on 4/4/21.
//

#include "MainWindow.h"
#include "processing/Image.h"
#include "processing/histogram.h"
#include <QtCharts>
#include <ui_MainWindow.h>
#include "QChart"
#include "QChartView"
#include "QLineSeries"

void MainWindow::plot() {
    printf("plot\n");
    QLineSeries *series = new QLineSeries();
    int x[256];
    int histogram[256];
    int cumHist[256];
    Image grayIm = inputImage->toGrayscale();
    im_hist(grayIm, histogram, 1);
    for (int i = 0; i < 256; ++i) {
        x[i] = i;
        series->append(i, histogram[i]);
    }
//    cumulative_hist(histogram, cumHist);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->customPlot);
}

