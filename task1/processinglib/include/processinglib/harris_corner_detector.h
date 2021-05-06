//
// Created by abdulla167 on ٤‏/٥‏/٢٠٢١.
//

#ifndef CV_HARRIS_CORNER_DETECTOR_H
#define CV_HARRIS_CORNER_DETECTOR_H
#include "hough.h"
void getHarrisCorner(Image& pointsStrength, std::vector<_Point>& cornerPoints, int threshold);

std::vector<_Point> cornerHarris(Image& grayImg, double threshold, int patchDim);

void drawCornerPoints(Image& img, std::vector<_Point>& cornerPoints);

std::vector<std::vector<double>> getSIFTDescriptor(Image& inputImg);
#endif //CV_HARRIS_CORNER_DETECTOR_H
