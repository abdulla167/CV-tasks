//
// Created by abdallah drwesh on 4/3/21.
//

#include "filters.h"
#include "utilities.h"
#include <cmath>


Image avgFilter(Image &inputImg, char dim) {
    auto *kernel = new float[dim * dim];
    averageGeneration(kernel, dim);
    Image im = applyFilter(inputImg, kernel, dim);
    delete[] kernel;
    return im;
}

Image gaussianFilter(Image &inputImg, char dim, float mean, float sigma) {
    auto *kernel = new float[dim * dim];
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

Image laplacianFilter(Image &inputImg, int dim) {
    float kernel[] = {
            0, -1, 0,
            -1, 4, -1,
            0, -1, 0
    };
    Image im = applyFilter(inputImg, kernel, dim);
    return im;
}

Image perwitEdgeDetector(Image &inputImg) {
    float xFilter[9] = {
            -1, 0, 1,
            -1, 0, 1,
            -1, 0, 1};
    float yFilter[9] = {
            1, 1, 1,
            0, 0, 0,
            -1, -1, -1};
    Image outputImg{inputImg.width - 2, inputImg.height - 2, inputImg.channels};
    Image imgX = applyFilter(inputImg, xFilter, 3);
    Image imgY = applyFilter(inputImg, yFilter, 3);
    for (int y = 0; y < imgX.height; y++) {
        for (int x = 0; x < imgX.width; x++) {
            for (int z = 0; z < imgX.channels; z++) {
                float xComponent = imgX.data[y][x][z];
                float yComponent = imgY.data[y][x][z];
                outputImg.data[y][x][z] =  sqrt(pow(xComponent, 2) + pow(yComponent, 2));
            }
        }
    }
    return outputImg;
}

Image sobelEdgeDetector(Image &inputImg) {
    float xFilter[9] = {
            -1, 0, 1,
            -2, 0, 2,
            -1, 0, 1};
    float yFilter[9] = {
            1, 2, 1,
            0, 0, 0,
            -1, -2, -1};
    Image outputImg{inputImg.width - 2, inputImg.height -2, inputImg.channels};
    Image imgX = applyFilter(inputImg, xFilter, 3);
    Image imgY = applyFilter(inputImg, yFilter, 3);
    for (int y = 0; y < imgX.height; y++) {
        for (int x = 0; x < imgX.width; x++) {
            for (int z = 0; z < imgX.channels; z++) {
                float xComponent = imgX.data[y][x][z];
                float yComponent = imgY.data[y][x][z];
                outputImg.data[y][x][z] = std::sqrt(pow(xComponent, 2) + pow(yComponent, 2));
            }
        }
    }
    return outputImg;
}

Image robertsEdgeDetector(Image &inputImg) {
    Image outputImg{inputImg.width, inputImg.height, inputImg.channels};
    char xFilter[4] = {
            1, 0,
            0, -1};
    char yFilter[4] = {
            0, 1,
            -1, 0};
    float xValue = 0;
    float yValue = 0;
    float result = 0;
    for (int y = 0; y < inputImg.height - 1; y++) {
        for (int x = 0; x < inputImg.width - 1; x++) {
            for (int z = 0; z < inputImg.channels; z++) {
                xValue = inputImg.data[y][x][z] * xFilter[0] + inputImg.data[y + 1][x + 1][z] * xFilter[3];
                yValue = inputImg.data[y][x + 1][z] * yFilter[1] + inputImg.data[y + 1][x][z] * yFilter[2];
                result = sqrt(pow(xValue, 2) + pow(yValue, 2));
                outputImg.data[y][x][z] = result;
            }
        }
    }
    return outputImg;
}


Image globalThresholding(Image &inputImg, int thresholdVal) {
    if (thresholdVal != 0) {
        return buildSegmentedImg(inputImg, thresholdVal);
    } else {
        int threshold =  otsuAlgorithm(inputImg, 256);
        return buildSegmentedImg(inputImg, threshold);
    }
}

Image localThresholding(Image& inputImg, float k, int r, int dim){
    Image outputImg{inputImg.width, inputImg.height, inputImg.channels};
    int offset = (dim - 1)/2;
    double mean = 0;
    double std = 0;
    for (int y = offset; y < inputImg.height-offset; y++){
        for (int x = offset; x < inputImg.width-offset; x++){
            for (int z=0 ; z < inputImg.channels ; z++){
                mean =0, std=0;
                sauvolaTechnique(inputImg, x,y, dim, mean, std);
                int threshold = mean * (1 + (k * ((std/r)-1)));
                if (inputImg.data[y][x][z] >= threshold){
                    outputImg.data[y][x][z] = 255;
                } else{
                    outputImg.data[y][x][z] = 0;
                }
            }
        }
    }
    return outputImg;
}



