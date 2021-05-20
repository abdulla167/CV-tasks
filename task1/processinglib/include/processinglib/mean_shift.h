//
// Created by mohamedkamal on ١٥‏/٥‏/٢٠٢١.
//

#ifndef CV_MEAN_SHIF_H
#define CV_MEAN_SHI_H
#include "vector"
#include "Image.h"
using namespace std;
class MeanShift {
    float hs;
    float hr;
    int maxIterations;
    Image * image;

    float distance(int, int, int, int);
    float distance(vector<float>, vector<float>);
public:
    Image run();
    MeanShift();
    MeanShift(Image *, float, float, int);
//    Image getOutput();
    ~MeanShift();
};
#endif //CV_K_MEAN_SEGMENTATIN_H
