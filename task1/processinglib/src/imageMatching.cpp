//
// Created by mohamedkamal on ٦‏/٥‏/٢٠٢١.
//

#include "imageMatching.h"
#include "Image.h"
#include "processinglib/harris_corner_detector.h"
#include "vector"

using namespace std;
void SSDMatching(Image& image_1, Image& image_2){
    Image gray_1 = image_1.toGrayscale();
    Image gray_2 = image_2.toGrayscale();
    vector<vector<double>> imageDescriptor_1 = getSIFTDescriptor(gray_1);
    vector<vector<double>> imageDescriptor_2 = getSIFTDescriptor(gray_2);
    for(vector<double> keyPoint_1: imageDescriptor_1){
        double *result ;
        result = new double [imageDescriptor_2.size()];
        int keyPointCount = 0;
        for(vector<double> keyPoint_2: imageDescriptor_2){
            for(int count = 0; count< 128; count++){
                result[keyPointCount] += ((keyPoint_1[count] - keyPoint_2[count]) * (keyPoint_1[count] - keyPoint_2[count]));
            }
            keyPointCount++;
        }
        int smallestSSDIndex = 0;
        double smallestValue = result[0];
        for(int loop=1; loop<imageDescriptor_1.size(); loop++){
            if (result[loop] < smallestValue){
                smallestValue = result[loop];
                smallestSSDIndex = loop;
            }
        }
        int xCoordinate_1 = ceil(
                (imageDescriptor_1[0] / (float) snakeImage->width) * ui->snake->background().rect().width());
        int yCoordinate = ceil(
                (arrayOfPointsY[i] / (float) snakeImage->height) * ui->snake->background().rect().height());

    }


}

void normalizedCorrelation(Image& image_1, Image& image_2){

}