//
// Created by abdallah drwesh on 4/3/21.
//

#ifndef CV_FILTERS_H
#define CV_FILTERS_H

#include "Image.h"

Image avgFilter(Image &inputImg, char dim = 3);

Image gaussianFilter(Image &inputImg, char dim = 3, float mean = 0, float sigma = 1);

Image medianFilter(Image &inputImg, int dim = 3);

Image perwitEdgeDetector(Image &inputImg);

Image sobelEdgeDetector(Image &inputImg);

Image robertsEdgeDetector(Image &inputImg);

#endif //CV_FILTERS_H
