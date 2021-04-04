//
// Created by abdallah drwesh on 4/3/21.
//

#ifndef CV_UTILITIES_H
#define CV_UTILITIES_H

#include "Image.h"

void averageGeneration(float *kernel, char dim = 3);

void gaussianGeneration(float *kernel, char dim = 3, float sigma = 1, float mean = 0);

Image applyFilter(Image &inputImg, float *filter, int filterDim = 3);

float convolution(Image &inputImg, const float *filter, int filterDim, int x, int y, int channelNo);

int convSort(Image &inputImg, int filterDim, int x, int y, int channelNo);

void arrayToScale(double * data, int size);

void arrayToScale(float * data, int size);

void fft2dShift(double * data, int width, int height);

#endif //CV_UTILITIES_H
