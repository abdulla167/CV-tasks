//
// Created by mohamedkamal on ١٥‏/٥‏/٢٠٢١.
//

#ifndef CV_K_MEAN_SEGMENTATIN_H
#define CV_K_MEAN_SEGMENTATIN_H
#include "vector"
#include "Image.h"
using namespace std;
class K_mean {
    int k;
    int maxIterations;
    vector<vector<int>> clusters;
    vector<int> centroids;
    Image image;
    void run();
    void clusterPixels();
    int closestCluster();
    void getClustersCentroid();
    bool centroidsChanged();
    double distance();
public:
    K_mean();
    K_mean(int, int);
    Image getOutput();
    ~K_mean();
};
#endif //CV_K_MEAN_SEGMENTATIN_H
