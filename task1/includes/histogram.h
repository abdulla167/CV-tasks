#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include "Image.h"

void im_hist(Image& image, int histogram[], int channel);
void cumulative_hist(int histogram[], int cumulative_histogram[]);
void  hist_eq_formula( Image& image,int cumhistogram[],int histogram[], int histogram_equalization_formula[]);
void equalized_hist(Image& image,int histogram[], int equalized_histogram[], int histogram_equalization_formula[]);
void equalized_image(Image& image, int histogram_equalization_formula[]);
#endif // HISTOGRAM_H_INCLUDED
