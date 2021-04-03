//
// Created by abdallah on 3/31/21.
//

#ifndef IMAGE_PROCESSING_IMAGE_H
#define IMAGE_PROCESSING_IMAGE_H

#include "string"

class Image {
public:
    unsigned char ***data;
    int width, height, channels;

    Image(int width, int height, int channel);

    Image(std::string filename, int num_channels = 0);

    Image(const Image &image);

    Image toGrayscale();

    int size();

    unsigned char *flatten();

    void saveJPG(std::string filename);

    ~Image();

private:
    void creatImage();

    void init(unsigned char *data);

    void copyData(unsigned char ***data);
};


#endif //IMAGE_PROCESSING_IMAGE_H
