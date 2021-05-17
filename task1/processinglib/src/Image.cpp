//
// Created by abdallah on 3/31/21.
//

#include "processinglib/Image.h"

#define STB_IMAGE_IMPLEMENTATION

#include "processinglib/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "processinglib/stb_image_write.h"
#include "iostream"
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
    float *min = new float[channels];
    for (int k = 0; k < channels; ++k) {
        max[k] = -1000;
        min[k] = 1000;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                scaleImg(i, j, k) = std::abs((*this)(i, j, k));
                if (scaleImg(i, j, k) > max[k]) {
                    max[k] = scaleImg(i, j, k);
                }else if(scaleImg(i, j, k) < min[k]){
                    min[k] = scaleImg(i, j, k);
                }

            }
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                scaleImg(i, j, k) = roundf(((scaleImg(i, j, k)  - min[k])/ max[k]) * 255);
            }
        }
    }
    std::cout<< "scaling "<< std::endl;
    for(int loop = 0 ; loop < 3; loop++){
        std::cout<< max[loop] << " "<< min[loop]<< std::endl;
    }
    std::cout<< "scaling "<< std::endl;
    delete[] max;
    delete[] min;
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

Image Image::XYZ()  {

    Image XYZ = Image(width, height, channels);
    Image temp = Image(this);
    Image normalizedData = temp.toScale();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {

                normalizedData(i, j, k) =  normalizedData(i, j, k) / (float) 255;

            }
        }
    }
    /*
     * X = 0.412453*R + 0.35758 *G + 0.180423*B
     * Y = 0.212671*R + 0.71516 *G + 0.072169*B
     * Z = 0.019334*R + 0.119193*G + 0.950227*B
     * */
    float parameters[3][3] = {
            {0.412453, 0.357580, 0.180423},
            {0.212671, 0.715160, 0.072169},
            {0.019334, 0.119193, 0.019334}

    };

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < channels; ++k) {
                for( int loop = 0; loop < 3; loop++){
                    XYZ(i, j, k) += (parameters[k][loop] * normalizedData(i, j, loop) ) ;
                }
            }
        }
    }

    return XYZ;
}

Image Image::RGBToLUV() {
    Image XYZ = this->XYZ();

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
     double Yn = (double )1.0;
     float un =  0.19793943;
     float vn =  0.46831096;

     Image u(width, height, channels);
     Image v(width, height, channels);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // (X + 15*Y + 3*Z)
            float temp =  ( XYZ(i, j, 0) +
                    15* XYZ(i, j, 1) +
                    3 * XYZ(i, j, 2));
            // u = 4*X / (X + 15*Y + 3*Z)
            u(i, j, 0)=  (4 * XYZ(i, j, 0)) / temp;
            u(i, j, 1) = (4 * XYZ(i, j, 0)) / temp;
            u(i, j, 2) = (4 * XYZ(i, j, 0)) / temp;
            // v = 9*Y / (X + 15*Y + 3*Z)
            v(i, j, 0) =  (9 * XYZ(i, j, 1)) / temp;
            v(i, j, 1) = (9 * XYZ(i, j, 1)) / temp;
            v(i, j, 2) = (9 * XYZ(i, j, 1)) / temp;
        }
    }
     Image LUVImage(width, height, channels);
     for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
                /**
                 * L = 116 * (Y/Yn)^(1/3) - 16
                 * U = 13*L*(u-un)
                 * V = 13*L*(v-vn)
                 */
                if(XYZ(i, j, 1) > 0.008856){
                    LUVImage( i, j, 0 ) = (116 * pow( XYZ(i, j, 1) , 1/3 ) )- 16;
                }else {
                    LUVImage( i, j, 0 ) =903.3 * XYZ(i, j, 1) ;
                }

                LUVImage( i, j, 1 ) = 13 * LUVImage(i, j, 0) * (u(i, j, 1) - un);
                LUVImage( i, j, 2 ) = 13 * LUVImage(i, j, 0) * (v(i, j, 1) - vn);
         }
     }
    std::cout<<"HELLO"<< std::endl;
     int v_ = LUVImage(5,4,1) ;
    std::cout<< v_;
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
