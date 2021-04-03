
#include <iostream>
using namespace std;
#include <cmath>
#include "../includes/Image.h"
#include "../includes/histogram.h"

void im_hist(Image& image, int histogram[], int channel)
{
    // initialize all intensity values to 0
    for(int i = 0; i < 256; i++)
    {
        histogram[i] = 0;
    }

    // calculate the no of pixels for each intensity values
    for(int y = 0; y < image.height; y++){
        for(int x = 0; x < image.width; x++){
                histogram[ (int)image.data[y][x][channel - 1]]++;
    }
    }
}
void cumulative_hist(int histogram[], int cumulative_histogram[])
{
    cumulative_histogram[0] = histogram[0];

    for(int i = 1; i < 256; i++)
    {
        cumulative_histogram[i] = histogram[i] + cumulative_histogram[i-1];

    }
}

void  hist_eq_formula(Image& image, int cumhistogram[],int histogram[], int histogram_equalization_formula[]) {
    // Caluculate the size of image
    int image_size = image.height * image.width;


    // smallest non zero vale of cumulative histogram
    int smallest_cdf = cumhistogram[0];
    for (int i = 1 ; i< 256 ; i++){
        if (cumhistogram[i] < smallest_cdf){
            smallest_cdf = cumhistogram[i];
        }
    }
    cout << smallest_cdf;
    float alpha = (255.0/(image_size - smallest_cdf)) ;
    // Scale the histogram
    for(int i = 0; i < 256; i++)
    {
        histogram_equalization_formula[i] = (unsigned char) round(((double)cumhistogram[i] - smallest_cdf )  * alpha);
    }

}
void equalized_hist(Image& image, int histogram[], int equalized_histogram[], int histogram_equalization_formula[]){
    // Calculate the probability of each intensity
    float PrRk[256];
    int image_size = image.height * image.width;
    for(int i = 0; i < 256; i++)
    {
        PrRk[i] = (double)histogram[i] / image_size;
    }
    // Generate the equlized histogram
    float PsSk[256];
    for(int i = 0; i < 256; i++)
    {
        PsSk[i] = 0;
    }

    for(int i = 0; i < 256; i++)
    {
        PsSk[histogram_equalization_formula[i]] += PrRk[i];
    }

    for(int i = 0; i < 256; i++){
       equalized_histogram[i] = (int)round(PsSk[i]*255);
    }
}
void equalized_image(Image& image, int histogram_equalization_formula[]){
    for(int y = 0; y < image.height; y++){
        for(int x = 0; x < image.width; x++){

                image.data[y][x][0] = (unsigned char) histogram_equalization_formula[image.data[y][x][0]];
        }
    }
//    image.saveJPG("D:/cv_task1/hello");
}
