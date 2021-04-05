//
// Created by abdallah drwesh on 4/3/21.
//

#ifndef CV_HISTOGRAM_H
#define CV_HISTOGRAM_H

#include "Image.h"

void im_hist(Image &image, int histogram[], int channel);

void cumulative_hist(int histogram[], int cumulative_histogram[]);

void hist_eq_formula(Image &image, int cumhistogram[], int histogram[], int histogram_equalization_formula[]);

void equalized_hist(Image &image, int histogram[], int equalized_histogram[], int histogram_equalization_formula[]);

void equalized_image(Image &inImage, int histogram_equalization_formula[]);

void getNormalizedHist(int *hist,double *normalizedHist, int histSize, int pixelsNo);

#endif //CV_HISTOGRAM_H
