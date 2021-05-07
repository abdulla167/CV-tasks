//
// Created by mohamedkamal on ٦‏/٥‏/٢٠٢١.
//

#ifndef CV_IMAGEMATCHING_H
#define CV_IMAGEMATCHING_H
#include "Image.h"
#include "vector"
std::vector<double> SSDMatching(Image&, Image&);
std::vector<double> normalizedCorrelation(Image&, Image&);

#endif //CV_IMAGEMATCHING_H
