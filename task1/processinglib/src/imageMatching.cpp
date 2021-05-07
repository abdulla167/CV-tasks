//
// Created by mohamedkamal on ٦‏/٥‏/٢٠٢١.
//

#include "imageMatching.h"
#include "Image.h"
#include "processinglib/harris_corner_detector.h"
#include "processinglib/hough.h"
#include "vector"
#include "iostream"
#include "math.h"
using namespace std;
vector<double> SSDMatching(Image& image_1, Image& image_2){
    Image gray_1 = image_1.toGrayscale();
    Image gray_2 = image_2.toGrayscale();

    vector<pair<vector<double>, _Point>> imageDescriptor_1 = getSIFTDescriptor(gray_1,0.01);
    vector<pair<vector<double>, _Point>> imageDescriptor_2 = getSIFTDescriptor(gray_2,0.01);

//    for(pair<vector<double>, _Point> p:imageDescriptor_2){
//        cout<< p.second.x << " "<<p.second.y <<endl;
//    }
    int pointCounter=0;
    vector<double> finalPoints = vector<double>(imageDescriptor_1.size()*4) ;
    vector<int> exclude = vector<int>(imageDescriptor_2.size());
    for(pair<vector<double>, _Point> keyPoint_1: imageDescriptor_1){

        vector<double> result = vector<double>(imageDescriptor_2.size());
        int keyPointCount = 0;
        for(pair<vector<double>, _Point> keyPoint_2: imageDescriptor_2){

            result[keyPointCount] = 0;
            for(int count = 0; count< 128; count++){
                result[keyPointCount] += (( keyPoint_1.first[count] - keyPoint_2.first[count]) * (keyPoint_1.first[count] - keyPoint_2.first[count]));
            }
            keyPointCount++;
        }
        int smallestSSDIndex = 0;
        double smallestValue = result[0];
        int smallestSSDIndex_2 = -1;
        double smallestValue_2 = result[0] + (double )1;
        for(int loop=1; loop< result.size(); loop++){
            if (result[loop] < smallestValue ){
                smallestValue_2 = smallestValue;
                smallestSSDIndex_2 = smallestSSDIndex;
                smallestValue = result[loop];
                smallestSSDIndex = loop;
            }else if (result[loop] <  smallestValue_2 && result[loop]> smallestValue){
                smallestValue_2 = result[loop];
                smallestSSDIndex_2 = loop;
            }
        }

        double temp = (smallestValue/smallestValue_2);
        if ( smallestValue < 0.1) {
            cout<< smallestValue << " "<< smallestValue_2 <<endl;
            double xCoordinate_1 = (keyPoint_1.second.x / (double) image_1.width);
            double yCoordinate_1 = (keyPoint_1.second.y / (double) image_1.height);

            double xCoordinate_2 = (imageDescriptor_2[smallestSSDIndex].second.x / (double) image_2.width);
            double yCoordinate_2 = (imageDescriptor_2[smallestSSDIndex].second.y / (double) image_2.height);
            finalPoints[pointCounter * 4] = xCoordinate_1;
            finalPoints[pointCounter * 4 + 1] = yCoordinate_1;
            finalPoints[pointCounter * 4 + 2] = xCoordinate_2;
            finalPoints[pointCounter * 4 + 3] = yCoordinate_2;
        }else {
            finalPoints[pointCounter * 4] = -1;
            finalPoints[pointCounter * 4 + 1] = -1;
            finalPoints[pointCounter * 4 + 2] = -1;
            finalPoints[pointCounter * 4 + 3] = -1;
        }
        pointCounter++;

    }
    std:: cout<< "it is" << pointCounter<< std::endl;
    return finalPoints;

}

vector<double> normalizedCorrelation(Image& image_1, Image& image_2){
    Image gray_1 = image_1.toGrayscale();
    Image gray_2 = image_2.toGrayscale();

    vector<pair<vector<double>, _Point>> imageDescriptor_1 = getSIFTDescriptor(gray_1);
    vector<pair<vector<double>, _Point>> imageDescriptor_2 = getSIFTDescriptor(gray_2);

    vector<double> descriptorAverage_1 =vector<double>(imageDescriptor_1.size());
    for(int imageDescriptorLoop_1 = 0; imageDescriptorLoop_1 < imageDescriptor_1.size(); imageDescriptorLoop_1++){
        double average = 0;
        for ( double pointInVector: imageDescriptor_1[imageDescriptorLoop_1].first) {
            average += pointInVector;
        }
        descriptorAverage_1[imageDescriptorLoop_1] = average/128;
    }

    vector<double> descriptorAverage_2 = vector<double>(imageDescriptor_2.size());
    for(int imageDescriptorLoop_2 = 0; imageDescriptorLoop_2 < imageDescriptor_2.size(); imageDescriptorLoop_2++) {
        double average = 0;
        for(double pointInVector: imageDescriptor_2[imageDescriptorLoop_2].first){
            average += pointInVector;
        }
        descriptorAverage_2[imageDescriptorLoop_2] = average/128;
    }

    vector<double> finalPoints = vector<double>(imageDescriptor_1.size()*4) ;
    for(int descriptorCount_1 = 0; descriptorCount_1 < imageDescriptor_1.size(); descriptorCount_1++){

        vector<double> result = vector<double>(imageDescriptor_2.size());
        for (int descriptorCount_2 = 0; descriptorCount_2< imageDescriptor_2.size(); descriptorCount_2++) {
            result[descriptorCount_2] = 0;
            for(int loop = 0; loop < 128 ; loop++){
                result[descriptorCount_2] += ((imageDescriptor_1[descriptorCount_1].first[loop] -
                        descriptorAverage_1[descriptorCount_1]) * (imageDescriptor_2[descriptorCount_2].first[loop] - descriptorAverage_2[descriptorCount_2]));
            }
            double firstTerm = 0;
            double secondTerm = 0;
            for(int loop = 0; loop < 128 ; loop++){
                firstTerm += ( (imageDescriptor_1[descriptorCount_1].first[loop] - descriptorAverage_1[descriptorCount_1]) *
                        (imageDescriptor_1[descriptorCount_1].first[loop] - descriptorAverage_1[descriptorCount_1]) );
                secondTerm += ((imageDescriptor_2[descriptorCount_2].first[loop] - descriptorAverage_2[descriptorCount_2]) *
                        (imageDescriptor_2[descriptorCount_2].first[loop] - descriptorAverage_2[descriptorCount_2]));
            }
            double makam = sqrt((firstTerm * secondTerm));
            result[descriptorCount_2] = result[descriptorCount_2] / makam;

        }

        int largetCorrIndex = 0;
        double largestValue = result[0];
        int largetCorrIndex_2 = 0;
        double largestValue_2 = result[0] - 0.1;
        for(int loop=1; loop< result.size(); loop++){
            if (result[loop] > largestValue){
                largestValue_2 = largestValue;
                largetCorrIndex_2 = largetCorrIndex;
                largestValue = result[loop];
                largetCorrIndex = loop;
            } else if (result[loop] > largestValue_2 && result[loop] < largestValue){
                largestValue_2 = result[loop];
                largetCorrIndex_2 = loop;
            }
        }
        double temp = largestValue_2/largestValue;
        if (largestValue> (double ) 0.8) {

            double xCoordinate_1 = (imageDescriptor_1[descriptorCount_1].second.x / (double) image_1.width);
            double yCoordinate_1 = (imageDescriptor_1[descriptorCount_1].second.y / (double) image_1.height);

            double xCoordinate_2 = (imageDescriptor_2[largetCorrIndex].second.x / (double) image_2.width);
            double yCoordinate_2 = (imageDescriptor_2[largetCorrIndex].second.y / (double) image_2.height);
            finalPoints[descriptorCount_1 * 4] = xCoordinate_1;
            finalPoints[descriptorCount_1 * 4 + 1] = yCoordinate_1;
            finalPoints[descriptorCount_1 * 4 + 2] = xCoordinate_2;
            finalPoints[descriptorCount_1 * 4 + 3] = yCoordinate_2;
        }else {
            finalPoints[descriptorCount_1 * 4] = -1;
            finalPoints[descriptorCount_1 * 4 + 1] = -1;
            finalPoints[descriptorCount_1 * 4 + 2] = -1;
            finalPoints[descriptorCount_1 * 4 + 3] = -1;
        }


    }
    return finalPoints;
}