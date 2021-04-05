//
// Created by abdallah drwesh on 4/3/21.
//

#include "histogram.h"

#include <iostream>

using namespace std;

#include <cmath>

void im_hist(Image &image, int histogram[], int channel) {
    float ***image_pixels = image.data;

    // initialize all intensity values to 0
    for (int i = 0; i < 256; i++) {
        histogram[i] = 0;
    }

    // calculate the histgram
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            histogram[(int) image_pixels[y][x][channel - 1]]++;
        }
    }
}

void cumulative_hist(int histogram[], int cumulative_histogram[]) {
    cumulative_histogram[0] = histogram[0];

    for (int i = 1; i < 256; i++) {
        cumulative_histogram[i] = histogram[i] + cumulative_histogram[i - 1];
    }
}

void hist_eq_formula(Image &image, int cumhistogram[], int histogram_equalization_formula[]) {
    // Caluculate the size of image
    int image_size = image.height * image.width;


    // smallest non zero vale of cumulative histogram
//    int smallest_cdf = cumhistogram[0];
//    for (int i = 1; i < 256; i++) {
//        if (cumhistogram[i] < smallest_cdf) {
//            smallest_cdf = cumhistogram[i];
//        }
//    }
    float alpha = (255.0 / (image_size ));
    // Scale the histogram
    for (int i = 0; i < 256; i++) {
        histogram_equalization_formula[i] = (unsigned char) round(((double) cumhistogram[i] ) * alpha);
    }

}


void equalized_image(Image &inImage, int histogram_equalization_formula[]) {
    float ***inImgPixels = inImage.data;
    Image outImage{inImage.width, inImage.height, inImage.channels};
    cout << inImgPixels[0][0][0];
    for (int y = 0; y < inImage.height; y++) {
        for (int x = 0; x < inImage.width; x++) {
            inImgPixels[y][x][0] = (unsigned char) histogram_equalization_formula[(int) inImgPixels[y][x][0]];
        }
    }
}

void getNormalizedHist(int *hist,double *normalizedHist, int histSize, int pixelsNo) {
    for (int i = 0; i < histSize; i++) {
        normalizedHist[i] = (double) hist[i] / (double) pixelsNo;
    }
}
