//
// Created by abdallah drwesh on 4/3/21.
//

#include "processinglib/utilities.h"
#include "processinglib/histogram.h"
#include <cmath>
#include <vector>
#include <algorithm>

void gaussianGeneration(float *kernel, char dim, float sigma, float mean) {
    double r, s = 2.0 * sigma * sigma;
    int t = dim / 2;
    int t2 = dim % 2 == 0 ? t : t + 1;
    float diff_x = 0;
    float diff_y = 0;
    for (int x = -t; x < t2; x++) {
        for (int y = -t; y < t2; y++) {
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

double imageMax(Image &img) {
    double max = 0;
    for (int i = 0; i < img.height; ++i) {
        for (int j = 0; j < img.width; ++j) {
            if (img(i, j) > max)
                max = img(i, j);
        }
    }
    return max;
}

int approximateAngle(float angle) {
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

Image getDirection(Image &imgX, Image &imgY, bool approximateFour) {
    Image outImage{imgX.width, imgX.height, 1};
    float angel = 0;
    for (int i = 0; i < imgX.height; ++i) {
        for (int j = 0; j < imgX.width; ++j) {
            if (imgX(i, j) == 0) {
                if (imgY(i, j) == 0) {
                    angel = 0;
                } else {
                    if (!approximateFour) {
                        angel = imgY(i, j) > 0 ? 90 : 270;
                    } else {
                        angel = imgY(i, j) > 0 ? 90 : -90;
                    }
                }

            } else {
                angel = atan(imgY(i, j) / imgX(i, j)) * (180 / 3.14159265);
                if (!approximateFour) {
                    if (angel > 0) {
                        if (imgY(i, j) < 0) {
                            angel = angel + 180;
                        }
                    } else {
                        if (imgY(i, j) < 0) {
                            angel = 360 + angel;
                        } else {
                            angel = 180 + angel;
                        }
                    }
                }

            }
            outImage(i, j) = angel;
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


void
getOptimalThresholdsRec(int intThreshold, int histSize, double normalizedHist[], double globalMean, double classMeans[],
                     double classProb[], int currentNumModes,int numClasses,
                     std::vector<int> &thresholds, std::vector<int> &optimalThreshold, double &maxBetweenVar) {
    if (intThreshold < histSize) {
        // base case
        if (currentNumModes == 2) {
            classProb[1] = 0;
            classMeans[1] = 0;
            double tempProb, tempMean,  betweenVar;
            for (int i = intThreshold; i < histSize; ++i) {
                tempProb = 1;
                tempMean = globalMean;
                betweenVar = 0;
                thresholds[thresholds.size() - 1] = i;
                classProb[1] += normalizedHist[i];
                classMeans[1] += i * normalizedHist[i];
                if (classProb[1] != 0) {
                    for (int j = numClasses - 1; j > 0; --j) {
                        tempProb -= classProb[j];
                        tempMean -= classMeans[j];
                    }
                    classProb[0] = tempProb;
                    classMeans[0] = tempMean;
                    for (int j = 0; j < numClasses; ++j) {
                        betweenVar += classProb[j] * (classMeans[j] / classProb[j] - globalMean) *
                                      (classMeans[j] / classProb[j] - globalMean);

                    }
                    if (betweenVar > maxBetweenVar) {
                        maxBetweenVar = betweenVar;
                        for (int j = 0; j < thresholds.size(); ++j) {
                            optimalThreshold[j] = thresholds[j];
                        }
                    }
                }
            }
        } else {
            double tempClassProb = 0;
            double tempClassMean = 0;
            for (int i = intThreshold; i < histSize; ++i) {
                thresholds[thresholds.size() + 1 - currentNumModes] = i;
                tempClassProb += normalizedHist[i];
                tempClassMean += i * normalizedHist[i];
                classProb[currentNumModes - 1] = tempClassProb;
                classMeans[currentNumModes - 1] = tempClassMean;
                if (classProb[currentNumModes - 1] != 0)
                    getOptimalThresholdsRec(i + 1, histSize, normalizedHist, globalMean, classMeans, classProb,
                                            currentNumModes - 1, numClasses,thresholds, optimalThreshold, maxBetweenVar);

            }
        }
    }
}

void
getOptimalThresholds(int intThreshold, int histSize, double normalizedHist[], double globalMean, double classMeans[],
                     double classProb[], int numModes,
                     std::vector<int> &thresholds, std::vector<int> &optimalThreshold, double &maxBetweenVar) {
    getOptimalThresholdsRec(intThreshold, histSize, normalizedHist, globalMean, classMeans, classProb, numModes, numModes,thresholds,
                         optimalThreshold, maxBetweenVar);
}

std::vector<int> otsuAlgorithm(Image &inputImg, int histSize, int numModes) {
    auto hist = new int[histSize];
    auto normalizedHist = new double[histSize];
    int pixelsNo = inputImg.width * inputImg.height;
    double globalMean = 0;
    auto classProbabilities = new double[numModes];
    auto classMeans = new double[numModes];
    auto optimalThreshold = std::vector<int>(numModes - 1);
    auto thresholds = std::vector<int>(numModes - 1);
    double maxBetweenVar = 0;
    for (int i = 0; i < numModes; ++i) {
        classProbabilities[i] = classMeans[i] = 0;
    }
    im_hist(inputImg, hist, 1);
    getNormalizedHist(hist, normalizedHist, histSize, pixelsNo);
    for (int i = 0; i < histSize; i++) {
        globalMean += i * normalizedHist[i];
    }
    getOptimalThresholds(0, histSize, normalizedHist, globalMean, classMeans, classProbabilities, numModes, thresholds,
                         optimalThreshold, maxBetweenVar);
    delete[] hist;
    delete[] normalizedHist;
    delete[] classProbabilities;
    delete[] classMeans;
    return optimalThreshold;
}

Image buildSegmentedImg(Image &inputImg, std::vector<int> thresholds) {
    Image segmentedImg{inputImg.width, inputImg.height, inputImg.channels};
    if (thresholds.size() == 1)
        return buildSegmentedImg(inputImg, thresholds[0]);
    int step = 255 / thresholds.size();
    for (int y = 0; y < inputImg.height - 1; y++) {
        for (int x = 0; x < inputImg.width - 1; x++) {
            for (int i = 1; i < thresholds.size(); ++i) {
                if (inputImg(y, x) >= thresholds[i - 1] && inputImg(y, x) < thresholds[i]) {
                    segmentedImg(y, x) = (i + 1) * step;
                }
            }
        }
    }
    return segmentedImg;
}

Image buildSegmentedImg(Image &inputImg, int thresholdVal) {
    Image segmentedImg{inputImg.width, inputImg.height, inputImg.channels};
    for (int y = 0; y < inputImg.height - 1; y++) {
        for (int x = 0; x < inputImg.width - 1; x++) {
            if (inputImg(y, x) > thresholdVal) {
                segmentedImg(y, x) = 255;
            } else {
                segmentedImg(y, x) = 0;
            }
        }
    }
    return segmentedImg;
}

