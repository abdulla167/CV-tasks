//
// Created by mohamedkamal on ٦‏/٥‏/٢٠٢١.
//

#include "imageMatching.h"
#include "Image.h"
#include "processinglib/harris_corner_detector.h"
#include "processinglib/hough.h"
#include "vector"

using namespace std;
void SSDMatching(Image& image_1, Image& image_2, int* finalPoints){
    Image gray_1 = image_1.toGrayscale();
    Image gray_2 = image_2.toGrayscale();
    vector<pair<vector<double>, _Point>> imageDescriptor_1 = getSIFTDescriptor(gray_1);
    vector<pair<vector<double>, _Point>> imageDescriptor_2 = getSIFTDescriptor(gray_2);
    int pointCounter=0;
    finalPoints = new int[imageDescriptor_1.size()*4];

    for(pair<vector<double>, _Point> keyPoint_1: imageDescriptor_1){
        double *result ;
        result = new double [imageDescriptor_2.size()];
        int keyPointCount = 0;
        for(pair<vector<double>, _Point> keyPoint_2: imageDescriptor_2){
            for(int count = 0; count< 128; count++){
                result[keyPointCount] += ((keyPoint_1.first[count] - keyPoint_2.first[count]) * (keyPoint_1.first[count] - keyPoint_2.first[count]));
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
        int xCoordinate_1 = (imageDescriptor_1[pointCounter].second.x / (float) image_1.width);
        int yCoordinate_1 =  (imageDescriptor_1[pointCounter].second.y / (float) image_1.height) ;

        int xCoordinate_2 = (imageDescriptor_2[smallestSSDIndex].second.x / (float) image_2.width) ;
        int yCoordinate_2 =  (imageDescriptor_2[smallestSSDIndex].second.y / (float) image_2.height) ;
        finalPoints[pointCounter*4] = xCoordinate_1;
        finalPoints[pointCounter*4 + 1] = yCoordinate_1;
        finalPoints[pointCounter*4 + 2] = xCoordinate_2;
        finalPoints[pointCounter*4 + 3] = yCoordinate_2;

        pointCounter++;

    }

}

void normalizedCorrelation(Image& image_1, Image& image_2){

}