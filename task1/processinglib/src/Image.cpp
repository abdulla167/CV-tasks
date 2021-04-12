//
// Created by abdallah on 3/31/21.
//

#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

Image::Image(int width, int height, int channel) : width{width}, height{height}, channels{channel}, data{nullptr} {
    data = new float[height * width * channels];
    init(0.0);
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
    this->data = new float[height * width * channels];
    init(data);
    free(data);
}

Image::Image(const Image &image) : Image{image.width, image.height, image.channels} {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                (*this)(i, j, k) = image(i, j, k);
            }
        }
    }
}


void Image::init(unsigned char *data) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                (*this)[j + i * width + k * height * width] = data[k + channels * j + width * channels * i];
            }
        }
    }
}

void Image::init(float value) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                (*this)[j + i * width + k * height * width] = value;
            }
        }
    }
}


Image Image::toScale() {
    Image scaleImg{width, height, channels};
    float *max = new float[channels];
    for (int k = 0; k < channels; ++k) {
        max[k] = 0;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                scaleImg(i, j, k) = std::abs((*this)(i, j, k));
                if (scaleImg(i, j, k) > max[k])
                    max[k] = scaleImg(i, j, k);
            }
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                scaleImg(i, j, k) = roundf((scaleImg(i, j, k) / max[k]) * 255);
            }
        }
    }
    delete[] max;
    return scaleImg;
}

Image Image::toGrayscale() {
    Image grayImg = Image(width, height, 1);
    if (channels > 1) {
        float avg = 0;
        float weights[] = {0.299, 0.587, 0.114};
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                avg = 0;
                for (int k = 0; k < channels; ++k) {
                    avg += weights[k] * (*this)(i, j, k);
                }
                grayImg(i, j, 0) = (unsigned char) roundf(avg);
            }
        }
    } else {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                grayImg(i, j) = (*this)(i, j);
            }
        }
    }
    return grayImg;
}

int Image::size() {
    return channels * width * height;
}

void Image::saveJPG(std::string filename) {
    char buff[256];
    sprintf(buff, "%s.jpg", filename.c_str());
    unsigned char *data_out = new unsigned char[width * height * channels];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                data_out[k + j * channels + i * width] = (int) roundf((*this)(i, j, k));
            }
        }
    }
//    int success = stbi_write_png(buff, width, _width, channels, data_out, width*channels);
    int success = stbi_write_jpg(buff, width, height, channels, data_out, 100);
    if (!success) fprintf(stderr, "Failed to write image %s\n", buff);
    free(data_out);
}

float &Image::operator[](int index) {
    return data[index];
}

float &Image::operator[](int index) const {
    return data[index];
}


float &Image::operator()(int i, int j) {
    if (channels > 1)
        throw "Image is three channels";
    return data[i * width + j];
}

float &Image::operator()(int i, int j) const {
    if (channels > 1)
        throw "Image is three channels";
    return data[i * width + j];
}

float &Image::operator()(int i, int j, int k) {
    if (channels == 1 && k > 0)
        throw "Image is one channel";
    return data[k * height * width + i * width + j];
}

float &Image::operator()(int i, int j, int k) const {
    if (channels == 1 && k > 0)
        throw "Image is one channel";
    return data[k * height * width + i * width + j];
}

Image::~Image() {
    delete[] data;
}
