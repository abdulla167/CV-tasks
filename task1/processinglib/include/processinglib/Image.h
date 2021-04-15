//
// Created by abdallah on 3/31/21.
//

#ifndef IMAGE_PROCESSING_IMAGE_H
#define IMAGE_PROCESSING_IMAGE_H

#include "string"

class Image {
    float *data;

public:
    int width, height, channels;

    Image(int width, int height, int channel);

    Image(const Image* image);

    Image(std::string filename, int num_channels = 1);

    Image(const Image &image);

    Image toGrayscale();

    int size();

    template<class T>
    T *copyData(){
        T *data = new T[channels * width * height];
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                for (int k = 0; k < channels; ++k) {
                    data[k + channels * j + width * channels * i] = (*this)(i, j, k);
                }
            }
        }
        return data;
    }

    Image toScale();

    void saveJPG(std::string filename);


    ~Image();

    float &operator[](int index);

    float &operator[](int index) const;

    float &operator()(int i, int j);

    float &operator()(int i, int j) const;

    float &operator()(int i, int j, int k);

    float &operator()(int i, int j, int k) const;


private:
    template<class T>
    void init(T *data){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                for (int k = 0; k < channels; ++k) {
                    (*this)(i, j, k) = data[k + channels * j + width * channels * i];
                }
            }
        }
    }
    void init(float value);
};


#endif //IMAGE_PROCESSING_IMAGE_H
