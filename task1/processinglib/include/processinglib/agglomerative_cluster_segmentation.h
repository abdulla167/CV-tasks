//
// Created by abdulla167 on ٢١‏/٥‏/٢٠٢١.
//

#ifndef CV_AGGLOMERATIVE_CLUSTER_SEGMENTATION_H
#define CV_AGGLOMERATIVE_CLUSTER_SEGMENTATION_H
float euclideanDistance(_Point p1, _Point p2);

float clustersDistance(std::vector<_Point> * cluster1, std::vector<_Point> * cluster2);

void initialClusters(Image& img, std::vector<std::vector<_Point>> & clustersList);

int mergeTwoClusters(std::vector<_Point> & cluster1, std::vector<_Point> & cluster2);

Image agglomerativeSeg(Image & img, int numOfClusters, unsigned long initialClustersNum);

#endif //CV_AGGLOMERATIVE_CLUSTER_SEGMENTATION_H
