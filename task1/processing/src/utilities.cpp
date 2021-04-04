//
// Created by abdallah drwesh on 4/3/21.
//

#include "utilities.h"

#include <cmath>
#include <vector>
#include <algorithm>

void gaussianGeneration(float *kernel, char dim, float sigma, float mean) {
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

void averageGeneration(float *kernel, char dim) {
    int size = dim * dim;
    for (int i = 0; i < size; ++i) {
        kernel[i] = 1.0 / size;
    }
}

float convolution(Image &inputImg, const float *filter, int filterDim, int x, int y, int channelNo) {
    int startX = x - ((filterDim - 1) / 2);
    int startY = y - ((filterDim - 1) / 2);
    float result = 0;
    for (int i = 0; i < filterDim; i++) {
        for (int j = 0; j < filterDim; j++) {
            float dataValue = inputImg.data[i + startY][j + startX][channelNo];
            float filterValue = filter[(i * 3) + j];
            result += dataValue * filterValue;
        }
    }
    return result;
}

int convSort(Image &inputImg, int filterDim, int x, int y, int channelNo) {
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
    return vals[vals.size() / 2 + vals.size() % 2];
}

Image applyFilter(Image &inputImg, float *filter, int filterDim) {
    Image outputImg{inputImg.width - filterDim + 1, inputImg.height - filterDim + 1, inputImg.channels};
    int offset = filterDim / 2;
    for (int y = offset; y < inputImg.height - offset; y++) {
        for (int x = offset; x < inputImg.width - offset; x++) {
            for (int z = 0; z < inputImg.channels; z++) {
                float result = convolution(inputImg, filter, filterDim, x, y, z);
                outputImg.data[y - offset][x - offset][z] = result;
            }
        }
    }
    return outputImg;
}

void arrayToScale(double *data, int size) {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        data[i] = std::abs(data[i]);
        if (data[i] > max)
            max = data[i];
    }
    for (int i = 0; i < size; ++i) {
        data[i] = (data[i] / max) * 255;
    }
}

void arrayToScale(float *data, int size) {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        data[i] = std::abs(data[i]);
        if (data[i] > max)
            max = data[i];
    }
    for (int i = 0; i < size; ++i) {
        data[i] = (data[i] / max) * 255;
    }
}

void fft2dShift(double *data, int width, int height) {
    double temp = 0;
    int hWidth = width / 2;
    int hHeight = height / 2;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < hWidth; ++j) {
            temp = data[j + i * width];
            data[j + i * width] = data[width - 1 - j + i * width];
            data[width - 1 - j + i * width] = temp;
        }
    }

    for (int i = 0; i < hHeight / 2; ++i) {
        for (int j = 0; j < width; ++j) {
            temp = data[j + i * width];
            data[j + i * width] = data[j + (hHeight - 1 - i) * width];
            data[j + (hHeight - 1 - i) * width] = temp;
        }
    }
    int h3_4 = hHeight + hHeight / 2;
    for (int i = hHeight, k = 0; i < h3_4; ++i, ++k) {
        for (int j = 0; j < width; ++j) {
            temp = data[j + i * width];
            data[j + i * width] = data[j + (height - 1 - k) * width];
            data[j + (height - 1 - k) * width] = temp;
        }
    }
}
