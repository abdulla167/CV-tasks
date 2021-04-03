#pragma once
#include "Image.h"

Image RGB2Gray(Image& colorImg);

Image applyFilter(Image& inputImg, char* filter, int filterDim);


int convolution(Image& inputImg, const char* filter, int filterDim, int x, int y, int channelNo);
