//
// Created by abdallah drwesh on 4/3/21.
//

#ifndef CV_UTILITIES_H
#define CV_UTILITIES_H

#include "Image.h"

void averageGeneration(float *kernel, char dim = 3);

void gaussianGeneration(float *kernel, char dim = 3, float sigma = 1, float mean = 0);

void lpfGeneration(float *kernel, int width, int height, float pWidth = 0.08, float pHeight = 0.08);

void hpfGeneration(float *kernel, int width, int height, float pWidth = 0.05, float pHeight = 0.05);

Image applyFilter(Image &inputImg, float *filter, int filterDim = 3);

float convolution(Image &inputImg, const float *filter, int filterDim, int x, int y, int channelNo);

int convSort(Image &inputImg, int filterDim, int x, int y, int channelNo);

void arrayToScale(double *data, int size);

void arrayToScale(float *data, int size);

Image saltPepper(Image & image, int count, int pixelSize);

Image minMaxNormalize(Image & image);


void sauvolaTechnique(Image& inputImg, int x, int y, int filterDim, double & mean, double & std);

int otsuAlgorithm(Image &inputImg, int histSize);

Image buildSegmentedImg(Image &inputImg, int threshold);

void sauvolaTechnique(Image& inputImg, int x, int y, int filterDim, double & mean, double & std);

int otsuAlgorithm(Image &inputImg, int histSize);

Image buildSegmentedImg(Image &inputImg, int threshold);


#endif //CV_UTILITIES_H
