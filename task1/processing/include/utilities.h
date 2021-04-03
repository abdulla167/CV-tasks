//
// Created by abdallah drwesh on 4/3/21.
//

#ifndef CV_UTILITIES_H
#define CV_UTILITIES_H

#include "Image.h"

void averageGeneration(double *kernel, char dim = 3);

void gaussianGeneration(double *kernel, char dim = 3, float sigma = 1, float mean = 0);

Image applyFilter(Image &inputImg, char *filter, int filterDim = 3);

Image applyFilter(Image &inputImg, double *filter, int filterDim = 3);

int convolution(Image &inputImg, const char *filter, int filterDim, int x, int y, int channelNo);

double convolution(Image &inputImg, const double *filter, int filterDim, int x, int y, int channelNo);

int convSort(Image &inputImg, int filterDim, int x, int y, int channelNo);

#endif //CV_UTILITIES_H
