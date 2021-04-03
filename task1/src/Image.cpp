#include "../includes/Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../includes/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../includes//stb_image_write.h"

Image::Image (const string& imgPath){
    unsigned char *img = stbi_load("../resources/lenna.png", &width, &height, &channels, 0);
    if (img == nullptr){
        exit(1);
    } else{
        data = convertImgData2D(img, width, height, channels);
    }
}

Image::Image (int width, int height, int channels){
    this->width = width;
    this->height= height;
    this->channels = channels;
    data = new unsigned char** [height];
    for (int y =0 ; y < height ; y++){
        data[y] = new unsigned char* [width];
        for (int x = 0; x < width;x++){
            data[y][x] = new unsigned char[channels];
        }
    }
}

// Copy constructor
Image::Image(const Image &img1) {
    width = img1.width;
    height = img1.height;
    channels = img1.channels;
    data = new unsigned char** [height];
    for (int y =0 ; y < height ; y++){
        data[y] = new unsigned char* [width];
        for (int x = 0; x < width;x++){
            data[y][x] = new unsigned char[channels];
            for(int z =0 ; z < channels; z++){
                data[y][x][z] = img1.data[y][x][z];
            }
        }
    }
}


// MAKE COPY OF THE IMAGE
Image Image::copyOfImg()const {
    Image copyImg{this->width, this->height, this->channels};
    for (int y =0 ; y < height ; y++){
        for (int x = 0; x < width;x++){
            for (int z =0 ; z < channels; z++){
                copyImg.data[y][x][z] = data[y][x][z];
            }
        }
    }
    return copyImg;
}

//GET IMAGE DIMENSIONS
int* Image::getDimensions(){
    int dim[3] = {width, height, channels};
    return dim;
}

//PRINTING IMAGE DATA
void Image::printImage() const{
    for (int x=0 ; x < height ; x++){
        for (int y = 0; y < width ;y++){
            for (int z =0 ; z < channels; z++){
                std::cout << (int) data[x][y][z] << ", ";
            }
        }
    }
}

Image::~Image() {
    for (int y =0 ; y < height ; y++){
        for (int x = 0; x < width;x++){
            delete[] data[y][x];
        }
        delete[] data[y];
    }
    delete[] data;
}