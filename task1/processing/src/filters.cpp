//
// Created by abdallah drwesh on 4/3/21.
//

#include "filters.h"
#include "utilities.h"
#include <cmath>

Image avgFilter(Image &inputImg, char dim) {
    auto *kernel = new double[dim * dim];
    averageGeneration(kernel, dim);
    Image im = applyFilter(inputImg, kernel, dim);
    delete[] kernel;
    return im;
}

Image gaussianFilter(Image &inputImg, char dim, float mean, float sigma) {
    auto *kernel = new double[dim * dim];
    gaussianGeneration(kernel, dim, sigma, mean);
    Image im = applyFilter(inputImg, kernel, dim);
    delete[] kernel;
    return im;
}

Image medianFilter(Image &inputImg, int dim) {
    Image outputImg{inputImg.width - dim + 1, inputImg.height - dim + 1, inputImg.channels};
    int begin = dim / 2;
    for (int i = begin; i < inputImg.height - begin; i++) {
        for (int j = begin; j < inputImg.width - begin; j++) {
            for (int k = 0; k < inputImg.channels; k++) {
                outputImg.data[i - begin][j - begin][k] = convSort(inputImg, dim, j, i, k);
            }
        }
    }
    return outputImg;
}

Image perwitEdgeDetector(Image &inputImg) {
    Image outputImg{inputImg.width, inputImg.height, inputImg.channels};
    char xFilter[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    char yFilter[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    Image imgX = applyFilter(inputImg, xFilter, 3);
    Image imgY = applyFilter(inputImg, yFilter, 3);
    for (int y = 0; y < imgX.height; y++) {
        for (int x = 0; x < imgX.width; x++) {
            for (int z = 0; z < imgX.channels; z++) {
                unsigned char xComponent = imgX.data[y][x][z];
                unsigned char yComponent = imgY.data[y][x][z];
                outputImg.data[y][x][z] = (unsigned char) sqrt(pow(xComponent, 2) + pow(yComponent, 2));
            }
        }
    }
    return outputImg;
}

Image sobelEdgeDetector(Image &inputImg) {
    Image outputImg{inputImg.width, inputImg.height, inputImg.channels};
    char xFilter[9] = {
            -1, 0, 1,
            -2, 0, 2,
            -1, 0, 1};
    char yFilter[9] = {
            1, 2, 1,
            0, 0, 0,
            -1, -2, -1};
    Image imgX = applyFilter(inputImg, xFilter, 3);
    Image imgY = applyFilter(inputImg, yFilter, 3);
    for (int y = 0; y < imgX.height; y++) {
        for (int x = 0; x < imgX.width; x++) {
            for (int z = 0; z < imgX.channels; z++) {
                unsigned char xComponent = imgX.data[y][x][z];
                unsigned char yComponent = imgY.data[y][x][z];
                outputImg.data[y][x][z] = (unsigned char) sqrt(pow(xComponent, 2) + pow(yComponent, 2));
            }
        }
    }
    return outputImg;
}

Image robertsEdgeDetector(Image &inputImg) {
    Image outputImg{inputImg.width, inputImg.height, inputImg.channels};
    char xFilter[4] = {1, 0, 0, -1};
    char yFilter[4] = {0, 1, -1, 0};
    for (int y = 0; y < inputImg.height - 1; y++) {
        for (int x = 0; x < inputImg.width - 1; x++) {
            for (int z = 0; z < inputImg.channels; z++) {
                int xValue = inputImg.data[y][x][z] * xFilter[0] + inputImg.data[y + 1][x][z] * xFilter[3];
                int yValue = inputImg.data[y][x][z] * yFilter[1] + inputImg.data[y + 1][x][z] * yFilter[2];
                int result = sqrt(pow(xValue, 2) + pow(yValue, 2));
                if (abs(result) > 255) {
                    result = 255;
                }
                outputImg.data[y][x][z] = result;
            }
        }
    }
    return outputImg;
}


