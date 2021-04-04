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
    data = new float **[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new float *[width];
        for (int j = 0; j < width; ++j) {
            data[i][j] = new float[channels];
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

void Image::copyData(float ***data) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                this->data[i][j][k] = data[i][j][k];
            }
        }
    }
}

float *Image::flatten() {
    float *data = new float[channels * width * height];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                data[k + channels * j + width * channels * i] = this->data[i][j][k];
            }
        }
    }
    return data;
}

double *Image::flattenDouble() {
    double *data = new double[channels * width * height];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                data[k + channels * j + width * channels * i] = this->data[i][j][k];
            }
        }
    }
    return data;
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
                scaleImg.data[i][j][k] = std::abs(data[i][j][k]);
                if (scaleImg.data[i][j][k] > max[k])
                    max[k] = scaleImg.data[i][j][k];
            }
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                scaleImg.data[i][j][k] = roundf((scaleImg.data[i][j][k] / max[k]) * 255);
            }
        }
    }
    return scaleImg;
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
    return channels * width * height;
}

void Image::saveJPG(std::string filename) {
    char buff[256];
    sprintf(buff, "%s.jpg", filename.c_str());
    unsigned char *data_out = new unsigned char[width * height * channels];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                data_out[k + j * channels + i * width] = (int) roundf(data[i][j][k]);
            }
        }
    }
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