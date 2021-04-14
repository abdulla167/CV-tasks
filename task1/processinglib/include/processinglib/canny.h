//
// Created by abdallah drwesh on 4/13/21.
//

#ifndef CV_CANNY_H
#define CV_CANNY_H

#include "Image.h"

Image cannyNonMaxSuppression(Image &mag, Image& dir);

Image cannyEdgeDetector(Image &image, float sigma = 1, float thHigh = 0.9, float thLow=0.3);

Image edgeLink(int tHigh, int tLow, Image& image);

#endif //CV_CANNY_H
