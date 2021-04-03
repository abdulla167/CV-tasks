//
// Created by abdallah on 3/31/21.
//

#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

Image::Image(int width, int height, int channel) : width{width}, height{height}, channels{channel}, data{nullptr} {
    creatImage();
}

Image::Image(std::string filename, int channels) {
    int channelsInImage = 0;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &channelsInImage, channels);
    if (!data) {
        fprintf(stderr, "Cannot load image \"%s\"\nSTB Reason: %s\n",
                filename.c_str(), stbi_failure_reason());
        exit(0);
    }
//    printf("num of channels: %i", channelsInImage);
    if (channels == 0)
        this->channels = channelsInImage;
    else
        this->channels = channels;
    creatImage();
    init(data);
    free(data);
}

Image::Image(const Image &image) : Image{image.width, image.height, image.channels} {
    copyData(image.data);
}

void Image::creatImage() {
    data = new unsigned char **[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new unsigned char *[width];
        for (int j = 0; j < width; ++j) {
            data[i][j] = new unsigned char[channels];
        }
    }
}

void Image::init(unsigned char *data) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                this->data[i][j][k] = data[k + channels * j + width * channels * i];
            }
        }
    }
}

void Image::copyData(unsigned char ***data) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                this->data[i][j][k] = data[i][j][k];
            }
        }
    }
}

unsigned char * Image::flatten() {
    unsigned char *data = new unsigned char[channels * width * height];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                data[k + channels * j + width * channels * i] = this->data[i][j][k];
            }
        }
    }
    return data;
}

Image Image::toGrayscale() {
    Image grayImg = Image(width, height, 1);
    float avg = 0;
    float weights[] = {0.299, 0.587, 0.114};
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            avg = 0;
            for (int k = 0; k < channels; ++k) {
                avg += weights[k] * data[i][j][k];
            }
            grayImg.data[i][j][0] = (unsigned char) roundf(avg);
        }
    }
    return grayImg;
}

int Image::size() {
    return channels*width*height;
}

void Image::saveJPG(std::string filename) {
    char buff[256];
    sprintf(buff, "%s.jpg", filename.c_str());
    unsigned char *data_out = flatten();
//    int success = stbi_write_png(buff, width, height, channels, data_out, width*channels);
    int success = stbi_write_jpg(buff, width, height, channels, data_out, 100);
    if (!success) fprintf(stderr, "Failed to write image %s\n", buff);
    free(data_out);
}

Image::~Image() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            delete[] data[i][j];
        }
        delete[] data[i];
    }
    delete[] data;
}