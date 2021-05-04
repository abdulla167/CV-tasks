//
// Created by abdulla167 on ٣‏/٥‏/٢٠٢١.
//
#include "Image.h"
#include "filters.h"
#include <math.h>
#include <iostream>
#include <utilities.h>
#include "hough.h"
#include "vector"
#include "utilities.h"

void getHarrisCorner(Image& pointsStrength, std::vector<_Point>& cornerPoints, double threshold){
    for (int y = 4; y < pointsStrength.height -4 ; ++y) {
        for (int x = 4; x < pointsStrength.width -4; ++x) {
            bool cornerPoint = true;
            if (pointsStrength(y,x) < threshold)
                continue;
            for (int i = -4; i < 5 ; ++i) {
                for (int j = -4; j < 5 ; ++j) {
                    if (pointsStrength(y + i, x + j) > pointsStrength(y, x)){
                        i = 5;
                        j = 5;
                        cornerPoint = false;
                    }
                }
            }
            if (cornerPoint)
                cornerPoints.push_back({x + 3, y + 3});
        }
    }
}

std::vector<_Point> cornerHarris(Image& grayImg, double threshold, int patchDim =3){
    double det,trace, strength;
    float xFilter[9] = {-1, 0, 1,-2, 0, 2, -1, 0, 1};
    float yFilter[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
    auto *kernel = new float[9 * 9];
    gaussianGeneration(kernel, 9, 0.5, 1);
    std::vector<_Point> cornerPoints;
    Image bluredImg = gaussianFilter(grayImg);
    Image Ix = applyFilter(bluredImg, xFilter, 3);
    Image Iy = applyFilter(bluredImg, yFilter, 3);
    Image pointsStrength{Ix.width - (patchDim-1), Ix.height - (patchDim-1), 1};
    int patchOffset = (patchDim - 1) / 2;
    for (int y = patchOffset;y < Ix.height - patchOffset; ++y){
        for(int x = patchOffset; x < Ix.width - patchOffset; ++x){
            double Ixp2 =0;
            double Ixyp=0;
            double Iyp2=0;
            for (int i = - patchOffset; i < (patchOffset + 1) ; ++i) {
                for (int j = - patchOffset; j < (patchOffset + 1); ++j) {
                    Ixp2 += Ix(y + i,x + j) * Ix(y + i,x + j) * kernel[(j + 5) + ((i+5)*9)];
                    Iyp2 += Iy(y + i,x + j) * Iy(y + i,x + j) * kernel[(j + 5) + ((i+5)*9)];
                    Ixyp += Ix(y + i,x + j) * Iy(y + i,x + j) * kernel[(j + 5) + ((i+5)*9)];
                }
            }
            det = (Ixp2 * Iyp2) - pow(Ixyp,2);
            trace = Ixp2 + Iyp2;
            strength = det - (0.1 * trace * trace);
            pointsStrength(y - patchOffset, x - patchOffset) = strength;
        }
    }
    double max = imageMax(pointsStrength);
    std::cout << max;
    getHarrisCorner(pointsStrength, cornerPoints, max * threshold);
    return cornerPoints;
}

void drawCornerPoints(Image& img, std::vector<_Point>& cornerPoints){
    int x,y;
    for (int pointNum = 0; pointNum < cornerPoints.size() ; ++pointNum) {
        x = cornerPoints[pointNum].x;
        y = cornerPoints[pointNum].y;
        for (int j = -2; j < 3; ++j) {
            for (int i = -2; i < 3; ++i) {
                if (x != 0 && y != 0){
                    img(y + j, x + i, 1) = 255;
                }
            }
        }
    }
}

