//
// Created by abdallah drwesh on 4/3/21.
//

#include "processinglib/utilities.h"
#include "processinglib/histogram.h"
#include <cmath>
#include <vector>
#include <list>
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
            float dataValue = inputImg(i + startY, j + startX, channelNo);
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
            int dataValue = inputImg(i + startY, j + startX, channelNo);
            vals.push_back(dataValue);
        }
    }
    std::sort(vals.begin(), vals.end());
    return vals[vals.size() / 2 + vals.size() % 2];
}

void lpfGeneration(float *kernel, int width, int height, float pWidth, float pHeight) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            kernel[j + i * width] = 0;
        }
    }
    int xi = width / 2 - roundf((pWidth / 2) * width);
    int xf = width / 2 + roundf((pWidth / 2) * width);
    int yi = height / 2 - roundf((pHeight / 2) * height);
    int yf = height / 2 + roundf((pHeight / 2) * height);
    printf("%i, %i, %i, %i\n", xi, xf, yi, yf);
    for (int i = yi; i < yf; ++i) {
        for (int j = xi; j < xf; ++j) {
            kernel[j + i * width] = 1;
        }
    }
}

void hpfGeneration(float *kernel, int width, int height, float pWidth, float pHeight) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            kernel[j + i * width] = 1;
        }
    }
    int xi = width / 2 - roundf((pWidth / 2) * width);
    int xf = width / 2 + roundf((pWidth / 2) * width);
    int yi = height / 2 - roundf((pHeight / 2) * height);
    int yf = height / 2 + roundf((pHeight / 2) * height);
    printf("%i, %i, %i, %i\n", xi, xf, yi, yf);
    for (int i = yi; i < yf; ++i) {
        for (int j = xi; j < xf; ++j) {
            kernel[j + i * width] = 0;
        }
    }
}

Image applyFilter(Image &inputImg, float *filter, int filterDim) {
    Image outputImg{inputImg.width - filterDim + 1, inputImg.height - filterDim + 1, inputImg.channels};
    int offset = filterDim / 2;
    for (int y = offset; y < inputImg.height - offset; y++) {
        for (int x = offset; x < inputImg.width - offset; x++) {
            for (int z = 0; z < inputImg.channels; z++) {
                float result = convolution(inputImg, filter, filterDim, x, y, z);
                outputImg(y - offset, x - offset, z) = result;
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

Image saltPepper(Image &image, int count, int sizePixel) {
    Image out = image;
    int xPosition;
    int yPosition;
    int saltPepperNoise;
    while (count) {
        xPosition = rand() % (image.width - sizePixel + 1);
        yPosition = rand() % (image.height - sizePixel + 1);
        saltPepperNoise = rand() % 2;
        for (int i = 0; i < sizePixel; i++) {
            for (int j = 0; j < sizePixel; j++) {
                for (int k = 0; k < image.channels; ++k) {
                    out(i + yPosition, j + xPosition, k) = saltPepperNoise * 255;
                }
            }
        }
        count--;
    }
    return out;
}

Image minMaxNormalize(Image &image) {
    Image normalizedImage{image.width, image.height, image.channels};
    float *max = new float[image.channels];
    float *min = new float[image.channels];
    for (int k = 0; k < image.channels; ++k) {
        max[k] = 0;
        min[k] = 0;
    }

    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                if (image(i, j, k) > max[k])
                    max[k] = image(i, j, k);
                if (image(i, j, k) < min[k])
                    min[k] = image(i, j, k);
            }
        }
    }
    for (int k = 0; k < image.channels; ++k) {
        printf("%f, %f -", min[k], max[k]);
    }
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                normalizedImage(i, j, k) = (image(i, j, k) - min[k]) / (max[k] - min[k]);
            }
        }
    }
    return normalizedImage;
}

int approximateAngle(float x, float y) {
    auto angle = atan(y / x) * (180 / 3.14159265);
    if (angle > -22.5 && angle <= 22.5) {
        return 0;
    } else if (angle > 22.5 && angle <= 67.5) {
        return 45;
    } else if ((angle > 67.5 && angle <= 90) || (angle > -90 && angle <= -67.5)) {
        return 90;
    } else if (angle > -67.5 && angle <= -22.5) {
        return 135;
    }
}


Image getMagnitude(Image &imgX, Image &imgY) {
    Image outImage{imgX.width, imgX.height, 1};
    for (int i = 0; i < imgX.height; ++i) {
        for (int j = 0; j < imgX.width; ++j) {
            outImage(i, j) = sqrt(imgX(i, j) * imgX(i, j) + imgY(i, j) * imgY(i, j));
        }
    }
    return outImage;
}

Image getDirection(Image &imgX, Image &imgY) {
    Image outImage{imgX.width, imgX.height, 1};
    for (int i = 0; i < imgX.height; ++i) {
        for (int j = 0; j < imgX.width; ++j) {
            outImage(i, j) = approximateAngle(imgX(i, j), imgY(i, j));
        }
    }
    return outImage;
}


void sauvolaTechnique(Image &inputImg, int x, int y, int filterDim, double &mean, double &std) {
    int offset = (filterDim - 1) / 2;
    int startX = x - offset;
    int startY = y - offset;
    int N = filterDim * filterDim;
    for (int i = 0; i < filterDim; i++) {
        for (int j = 0; j < filterDim; j++) {
            mean += inputImg(i + startY, j + startX);
        }
    }
    mean = mean / N;
    for (int i = 0; i < filterDim; i++) {
        for (int j = 0; j < filterDim; j++) {
            std += pow(inputImg(i + startY, j + startX) - mean, 2);
        }
    }
    std = sqrt(std / (N - 1));
}

int otsuAlgorithm(Image &inputImg, int histSize) {
    int hist[256];
    double normalizedHist[256];
    int pixelsNo = inputImg.width * inputImg.height;
    int threshold = 0;
    double globalMean = 0, firstProbabilitySum = 0;
    double firstClassProbability = 0, secondClassProbability = 0, firstClassMean = 0, secondClassMean = 0;
    double variance = 0, maxVariance = 0;
    im_hist(inputImg, hist, 1);
    getNormalizedHist(hist, normalizedHist, histSize, pixelsNo);
    for (int i = 0; i < 256; i++) {
        globalMean += i * normalizedHist[i];
    }
    for (int t = 0; t < 256; t++) {
        firstClassProbability += normalizedHist[t];
        if (firstClassProbability == 0)
            continue;
        secondClassProbability = 1 - firstClassProbability;
        firstProbabilitySum += t * normalizedHist[t];
        firstClassMean = (double) firstProbabilitySum / (double) firstClassProbability;
        secondClassMean = (double) (globalMean - firstProbabilitySum) / (double) secondClassProbability;
        variance = firstClassProbability * secondClassProbability * pow((firstClassMean - secondClassMean), 2);
        if (variance > maxVariance) {
            threshold = t;
            maxVariance = variance;
        }
    }
    return threshold;
}

Image buildSegmentedImg(Image &inputImg, int threshold) {
    Image segmentedImg{inputImg.width, inputImg.height, inputImg.channels};
    for (int y = 0; y < inputImg.height - 1; y++) {
        for (int x = 0; x < inputImg.width - 1; x++) {
            if (inputImg(y, x) > threshold) {
                segmentedImg(y, x) = 255;
            } else {
                segmentedImg(y, x) = 0;
            }
        }
    }
    return segmentedImg;
}

