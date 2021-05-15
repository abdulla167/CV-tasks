//
// Created by abdallah on 3/31/21.
//

#include "processinglib/Image.h"

#define STB_IMAGE_IMPLEMENTATION

#include "processinglib/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "processinglib/stb_image_write.h"

Image::Image() {};

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


Image::Image(const Image *image) : Image{image->width, image->height, image->channels} {
    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            for (int k = 0; k < image->channels; ++k) {
                (*this)(i, j, k) = (*image)(i, j, k);
            }
        }
    }
}


void Image::init(float value) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                (*this)(i, j, k) = value;
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


double* Image::XYZ()  {
    float *max = new float[channels];
    for (int k = 0; k < channels; ++k) {
        max[k] = 0;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                if ((*this)(i, j, k) > max[k])
                    max[k] = (*this)(i, j, k);
            }
        }
    }
    double *XYZ = new double[this->height * this->width * this->channels];
    double *normalizedData = new double[this->height * this->width * this->channels];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {

                normalizedData[k * height * width + i * width + j] = (double) 0;
                XYZ[k * height * width + i * width + j] = (double) 0;
            }
        }
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {

                normalizedData[k * height * width + i * width + j] = (double) (*this)(i, j, k) / (double) max[k];
            }
        }
    }
    /*
     * X = 0.412453*R + 0.35758 *G + 0.180423*B
     * Y = 0.212671*R + 0.71516 *G + 0.072169*B
     * Z = 0.019334*R + 0.119193*G + 0.950227*B
     * */
    double parameters[3][3] = {
            {(double )0.412453,  (double )0.35758, (double )0.180423},
            {(double )0.212671,  (double )0.71516, (double )0.072169},
            {(double )0.019334, (double )0.019334, (double )0.019334}
    };

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                for( int loop = 0; loop < 3; loop++){
                    XYZ[k * height * width + i * width + j] += parameters[k][loop] * normalizedData[loop * height * width + i * width + j]  ;
                }

            }
        }
    }
    delete[] normalizedData;
    delete[] max;
    return XYZ;
}

Image Image::RGBToLUV() {
    double * XYZ = this->XYZ();
    /**
     * CIE chromaticity coordinates:
     * xn = 0.312713
     * yn = 0.329016
     * CIE luminance:
     * Yn = 1.0
     * un = 4*xn / (-2*xn + 12*yn + 3)
     * vn = 9*yn / (-2*xn + 12*yn + 3)
     * u = 4*X / (X + 15*Y + 3*Z)
     * v = 9*Y / (X + 15*Y + 3*Z)
     * L = 116 * (Y/Yn)^(1/3) - 16
     * U = 13*L*(u-un)
     * V = 13*L*(v-vn)
     */
     double xn = (double )0.312713, yn = (double )0.329016, Yn = (double )1.0;
     double un = 4*xn / (-2*xn + 12*yn + 3);
     double vn = 9*yn / (-2*xn + 12*yn + 3);

     double * u = new double [this->height * this->width * this->channels];
     double * v = new double [this->height * this->width * this->channels];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // (X + 15*Y + 3*Z)
            double temp =  ( XYZ[0 * height * width + i * width + j] +
                    15* XYZ[1 * height * width + i * width + j] +
                    3 * XYZ[2 * height * width + i * width + j]);
            // u = 4*X / (X + 15*Y + 3*Z)
            u[0 + j * channels + i * width] =  (4 * XYZ[0 * height * width + i * width + j]) / temp;
            u[1 + j * channels + i * width] = (4 * XYZ[0 * height * width + i * width + j]) / temp;
            u[2 + j * channels + i * width] = (4 * XYZ[0 * height * width + i * width + j]) / temp;
            // v = 9*Y / (X + 15*Y + 3*Z)
            v[0 + j * channels + i * width] =  (9 * XYZ[1 * height * width + i * width + j]) / temp;
            v[1 + j * channels + i * width] = (9 * XYZ[1 * height * width + i * width + j]) / temp;
            v[2 + j * channels + i * width] = (9 * XYZ[1 * height * width + i * width + j]) / temp;
        }
    }
     Image LUVImage(width, height, channels);
     for (int i = 0; i < height; ++i) {
         for (int j = 0; j < width; ++j) {
                /**
                 * L = 116 * (Y/Yn)^(1/3) - 16
                 * U = 13*L*(u-un)
                 * V = 13*L*(v-vn)
                 */

                LUVImage( i, j, 0 ) = 116 * pow( (XYZ[1 * height * width + i * width + j] / Yn), 1/3 ) - 16;
                LUVImage( i, j, 1 ) = 13 * LUVImage(i, j, 0) * (u[1 + j * channels + i * width] - un);
                LUVImage( i, j, 2 ) = 13 * LUVImage(i, j, 0) * (v[1 + j * channels + i * width] - vn);
         }
     }
     delete[] XYZ;
     delete[] u;
     delete[] v;
    return LUVImage;
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


float &Image::operator[](int index) const {
    return data[index];
}


float &Image::operator()(int i, int j) const {
    if (channels > 1)
        throw "Image is three channels";
    return data[i * width + j];
}


float &Image::operator()(int i, int j, int k) const {
    if (channels == 1 && k > 0)
        throw "Image is one channel";
    return data[k * height * width + i * width + j];
}

Image::~Image() {
    delete[] data;
}
