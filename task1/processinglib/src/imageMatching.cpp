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

    vector<pair<vector<double>, _Point>> imageDescriptor_1 = getSIFTDescriptor(gray_1,0.001);
    vector<pair<vector<double>, _Point>> imageDescriptor_2 = getSIFTDescriptor(gray_2,0.001);

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
        for(int loop=1; loop< result.size(); loop++){
            if (result[loop] < smallestValue){
                smallestValue = result[loop];
                smallestSSDIndex = loop;
            }
        }

        if ( smallestValue <(double ) 0.09) {
            double xCoordinate_1 = (imageDescriptor_1[pointCounter].second.x / (double) image_1.width);
            double yCoordinate_1 = (imageDescriptor_1[pointCounter].second.y / (double) image_1.height);

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
    cout<< "start ttt"<< endl;
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
        for(int loop=1; loop< result.size(); loop++){
            if (result[loop] > largestValue){
                largestValue = result[loop];
                largetCorrIndex = loop;
            }
        }
        cout<< "largest " << largestValue <<  endl;
        if (largestValue> (double ) 0.85) {

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