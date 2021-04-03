//
// Created by abdallah drwesh on 4/3/21.
//

#include "utilities.h"

#include <cmath>
#include <vector>
#include <algorithm>

void gaussianGeneration(double *kernel, char dim, float sigma, float mean) {
    double r, s = 2.0 * sigma * sigma;
    int t = dim / 2;
    float diff_x = 0;
    float diff_y = 0;
    for (int x = -t; x <= t; x++) {
        for (int y = -t; y <= t; y++) {
            diff_x = x - mean;
            diff_y = y - mean;
            r = std::sqrt(diff_x * diff_x + diff_y * diff_y);
            kernel[(x + t) * dim + y + t] = (exp(-(r * r) / s)) / (M_PI * s);
        }
    }
}

void averageGeneration(double *kernel, char dim) {
    int size = dim * dim;
    for (int i = 0; i < size; ++i) {
        kernel[i] = 1.0 / size;
    }
}

int convolution(Image &inputImg, const char *filter, int filterDim, int x, int y, int channelNo) {
    int startX = x - ((filterDim - 1) / 2);
    int startY = y - ((filterDim - 1) / 2);
    int result = 0;
    for (int i = 0; i < filterDim; i++) {
        for (int j = 0; j < filterDim; j++) {
            int dataValue = inputImg.data[i + startY][j + startX][channelNo];
            char filterValue = filter[(i * 3) + j];
            result += dataValue * filterValue;
        }
    }
    if (abs(result) > 255) {
        result = 255;
    }
    return abs(result);
}

double convolution(Image &inputImg, const double *filter, int filterDim, int x, int y, int channelNo) {
    int startX = x - ((filterDim - 1) / 2);
    int startY = y - ((filterDim - 1) / 2);
    double result = 0;
    for (int i = 0; i < filterDim; i++) {
        for (int j = 0; j < filterDim; j++) {
            int dataValue = inputImg.data[i + startY][j + startX][channelNo];
            double filterValue = filter[(i * 3) + j];
            result += dataValue * filterValue;
        }
    }
    if (std::abs(result) > 255) {
        result = 255;
    }
    return std::abs(result);
}

int convSort(Image &inputImg, int filterDim, int x, int y, int channelNo){
    int startX = x - ((filterDim - 1) / 2);
    int startY = y - ((filterDim - 1) / 2);
    std::vector<int> vals;
    for (int i = 0; i < filterDim; i++) {
        for (int j = 0; j < filterDim; j++) {
            int dataValue = inputImg.data[i + startY][j + startX][channelNo];
            vals.push_back(dataValue);
        }
    }
    std::sort(vals.begin(), vals.end());
    return vals[vals.size() / 2];
}


Image applyFilter(Image &inputImg, char *filter, int filterDim) {
    Image outputImg{inputImg.width - filterDim + 1, inputImg.height - filterDim + 1, inputImg.channels};
    int begin = filterDim / 2;
    for (int y = begin; y < inputImg.height - begin; y++) {
        for (int x = begin; x < inputImg.width - begin; x++) {
            for (int z = 0; z < inputImg.channels; z++) {
                int result = convolution(inputImg, filter, filterDim, x, y, z);
                outputImg.data[y - begin][x - begin][z] = result;
            }
        }
    }
    return outputImg;
}

Image applyFilter(Image &inputImg, double *filter, int filterDim) {
    Image outputImg{inputImg.width - filterDim + 1, inputImg.height - filterDim + 1, inputImg.channels};
    int begin = filterDim / 2;
    for (int y = begin; y < inputImg.height - begin; y++) {
        for (int x = begin; x < inputImg.width - begin; x++) {
            for (int z = 0; z < inputImg.channels; z++) {
                double result = convolution(inputImg, filter, filterDim, x, y, z);
                outputImg.data[y-begin][x-begin][z] = (int)result;
            }
        }
    }
    return outputImg;
}
