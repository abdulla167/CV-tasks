//
// Created by mohamedkamal on ١٥‏/٥‏/٢٠٢١.
//
#include "k_mean_segmentation.h"
#include "vector"
#include <random>
#include "iostream"
using namespace std;
K_mean::K_mean() {}

K_mean::K_mean(Image * image, int k, int maxIteration) {
    cout<< "in it"<<endl;

    cout<< "in it"<<endl;


    this->image = new Image(image);
    cout<< "in it "<< this->image->channels << " "<< (*(this->image))(5,5,1)<< " end " << image->channels<<endl;
    this->k = k;
    this->clusters = Image(this->image->width, this->image->height, 1);
//    this->centroids = vector<vector<float>>(k);
    this->maxIterations = maxIteration;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> distForI(0, (this->image->height - 1)); // distribution in range [1, 6]
    uniform_int_distribution<std::mt19937::result_type> distForJ(0, (this->image->width - 1)); // distribution in range [1, 6]
    for(int loop = 0; loop < k; loop++){
        int i = (int)distForI(rng);
        int j = (int)distForJ(rng);
        vector<float> temp;
        for(int k_ = 0; k_ < this->image->channels; k_++){
            cout<< "in it v "<<(*(this->image))(i, j, k_)<<endl;
            temp.push_back((*(this->image))(i, j, k_));
        }
        this->centroids.push_back(temp);
    }

}
void K_mean::clusterPixels() {
    cout<<"in cluster" <<endl;
    for (int i = 0; i < this->image->height; ++i) {
        for (int j = 0; j < this->image->width; ++j) {

           int closestCluster = this->closestCluster(i, j);
           this->clusters(i,j) = closestCluster;
        }
    }
}

int K_mean::closestCluster(int i, int j) {
    float closestDistance = 900000;
    int closestClusterIdnex = -1;
    for(int loop =0 ; loop < this->k; loop++){
        float distance_ = distance(i, j, this->centroids[loop]);
        if( distance_< closestDistance){
            closestDistance = distance_;
            closestClusterIdnex = loop;
        }
    }
    return closestClusterIdnex;
}
float K_mean::distance(int i, int j, vector<float> centroid) {
    float sum = 0;
    for(int k = 0; k < this->image->channels; k++) {
        float difference = (*(this->image))(i, j, k) - centroid[k];
        sum += (difference * difference);
    }
    return sqrt(sum);
}

void K_mean::getClustersCentroid() {
    cout<<"in clustercentroid" <<endl;
    vector<vector<double>> sum = vector<vector<double>>(this->k);
    for(int loop=0; loop < this->k; loop++){
        sum[loop] = vector<double>(this->image->channels);
    }
    vector<int> count = vector<int>(this->k);
    for (int i = 0; i < this->image->height; ++i) {
        for (int j = 0; j < this->image->width; ++j) {
            int cluster = this->clusters(i, j);
                for(int k=0; k < this->image->channels; k++) {
                    sum[cluster][k] += (*(this->image))(i, j, k);
//                    cout<< this->image(i, j, k) <<endl;

                }
            count[cluster] += 1;
        }
    }
    for(int loop = 0 ; loop < this->k; loop++){
       for(int k =0; k < this->image->channels; k++){
           centroids[loop][k] = (sum[loop][k] / (double ) count[loop]);
           cout<< sum[loop][k] / (double ) count[loop] <<endl;
       }
    }
}
bool K_mean::centroidsChanged(vector<vector<float>> oldCentroids) {
    cout<< "centroidsChanged "<<endl;
    double sum = 0;
    for(int loop = 0; loop < this->k; loop++){
        for(int k = 0; k < this->image->channels; k++){

            double temp = (double )oldCentroids[loop][k] - (double) centroids[loop][k];
//            cout<< temp << " " << oldCentroids[loop][k] << " " << centroids[loop][k] << endl;
            if (temp < (double) 0){
                sum += (- temp);
            }else {
                sum += temp;
            }

        }
    }
    cout<< "sum "<<sum<<endl;
    if (sum == (double ) 0.0) {
        return false;
    }else {
        return true;
    }
}
void K_mean::run() {
    cout<<"in run" <<endl;
    for(int loop =0 ; loop < this->maxIterations; loop++){
        this->clusterPixels();
        vector<vector<float>> oldCentroids = vector<vector<float>>(this->k);
        for (int loop1 = 0; loop1 < this->k; loop1++ ){
            oldCentroids[loop1] = vector<float>(this->image->channels);
            for (int loop2 = 0; loop2 < this->image->channels; loop2++ ){
                oldCentroids[loop1][loop2] = this->centroids[loop1][loop2];
            }
        }
        this->getClustersCentroid();
        cout<<"in run" <<endl;
        bool changed = this->centroidsChanged(oldCentroids);
        cout<<"in run" <<endl;
        if (changed == false){
            loop = this->maxIterations;
        }
    }
}

Image K_mean::getOutput() {
    cout<<"in out" <<endl;
//    Image output(this->image->width, this->image->height, this->image->channels);
    Image output = Image(this->image);
    this->run();
    for (int i = 0; i < this->image->height; ++i) {
        for (int j = 0; j < this->image->width; ++j) {
            int cluster = this->clusters(i, j);
            for(int k=0; k < this->image->channels; k++) {
                output(i, j, k) = centroids[cluster][k];
//                cout<<(*output)(i, j, k)<<endl;
            }
        }
    }
    cout<<"in out" <<endl;
    return output;
}
K_mean::~K_mean() {
    delete  image;
}

void K_mean::print(char * a){
    cout<< "print" << a << endl;
}
void K_mean::print(int a){
    cout<< "print" << a << endl;
}