#include <cmath>
#include "../includes/Image.h"



int convolution(Image& inputImg, const char* filter, int filterDim, int x, int y, int channelNo){
    int startX = x - ((filterDim - 1) / 2);
    int startY = y - ((filterDim - 1) / 2);
    int result = 0;
    for (int i = 0; i < filterDim ; i++){
        for (int j = 0; j < filterDim; j++){
            int dataValue = inputImg.data[i + startY][j + startX][channelNo];
            char filterValue =  filter[(i*3) + j];
            result += dataValue  * filterValue;
        }
    }
    if (abs(result) > 255){
        result =255;
    }
    return abs(result);
}


Image applyFilter(Image& inputImg, char* filter, int filterDim){
    Image outputImg{inputImg.width, inputImg.height, inputImg.channels};
    for (int y =1 ; y < inputImg.height-1; y++){
        for (int x = 1; x < inputImg.width-1; x++){
            for (int z=0 ; z < inputImg.channels ; z++){
                int result = convolution(inputImg, filter,filterDim, x, y, z);
                outputImg.data[y][x][z] = result;
            }
        }
    }
    return outputImg;
}

