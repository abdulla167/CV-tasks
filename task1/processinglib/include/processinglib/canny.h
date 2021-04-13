//
// Created by abdallah drwesh on 4/13/21.
//

#ifndef CV_CANNY_H
#define CV_CANNY_H

#include "Image.h"

Image cannyNonMaxSuppression(Image &mag, Image& dir);

Image cannyEdgeDetector(Image &image);

Image edgeLink(int tHigh, int tLow, Image& image);

#endif //CV_CANNY_H
