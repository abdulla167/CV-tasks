//
// Created by abdulla167 on ٣‏/٦‏/٢٠٢١.
//

#ifndef CV_FACE_RECOGNITION_H
#define CV_FACE_RECOGNITION_H
#include "vector"

using std::vector; using std::pair;

std::vector<std::string> loadImgsDataset(std::string DirPath, std::vector<std::vector<float>> &Dataset);
std::vector<float> AvgVector(std::vector<std::vector<float>>& TrainingDataset);

vector<vector<float>>  GetCenteredImgs(vector<vector<float>> TrainingDataset);

float VectorsDotProduct(std::vector<float> v1, std::vector<float> v2);

std::vector<std::vector<float>> GetCovMatrix(std::vector<std::vector<float>>& TrainingDataset);

vector<vector<float>> GetEigenVectorsOfUpperCorr(vector<vector<float>>& TrainingDataset);

vector<vector<float>> getImagesCoeff(vector<vector<float>>& TrainingDataset, vector<vector<float>> & EigenVectors);

pair<int, float> PredictImg(vector<float> testImg, vector<vector<float>> EigenVectors, vector<vector<float>> ImgsCoffMat);

void WriteVectorToFile(std::string filename, vector<vector<float>> Mat);

void ReadFileToVector(std::string filename, vector<vector<float>>& Mat);

#endif //CV_FACE_RECOGNITION_H
