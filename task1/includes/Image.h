#pragma once
#include "iostream"
using namespace std;


class Image {
public:
    int width=0, height=0, channels =0;
    unsigned char*** data = nullptr;

public:
    Image (const string& imgPath);

    Image (int width, int height, int channels);

    Image(const Image &img1);

    Image copyOfImg()const;

    int* getDimensions();

    void printImage() const;

    static unsigned char*** convertImgData2D(const unsigned char* img1D, int width, int height, int channels){
        auto *** data = new unsigned char**[height];
        for (int y =0 ; y < height ; y++){
            data[y] = new unsigned char* [width];
            for (int x = 0; x < width;x++){
                data[y][x] = new unsigned char[channels];
                for (int z =0 ; z < channels;z++){
                    data[y][x][z] = img1D[z + channels * x + width * channels * y];
                }
            }
        }
        return data;
    }


    static Image RGB2Gray(Image& colorImg){
        Image grayImg{colorImg.width, colorImg.height,1};
        for (int y =0; y < colorImg.height; y++){
            for (int x = 0; x < colorImg.width; x++){
                grayImg.data[y][x][0] = (unsigned char)(0.3 * colorImg.data[y][x][0])
                                        + (0.6 * colorImg.data[y][x][1]) +(0.1* colorImg.data[y][x][2]);
            }
        }
        return grayImg;
    }


    static int* getGlobalHist(Image& inputImg){
        if (inputImg.channels > 1){
        }else{
            int histogram[256] = {0};
            for (int y =1 ; y < inputImg.height-1; y++){
                for (int x = 1; x < inputImg.width-1; x++){
                    int value = inputImg.data[y][x][0];
                    histogram[value] += 1;
                }
            }
            return histogram;
        }
    }

    static Image globalThresholding(Image& inputImg, int thresholdVal){
        if (thresholdVal != 0){
            // apply thresholding on image
        } else{
            // apply otsus algorithm
        }
    }



    ~Image();
};


