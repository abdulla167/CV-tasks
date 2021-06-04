//
// Created by abdulla167 on ٣‏/٦‏/٢٠٢١.
//

#ifndef CV_FACE_RECOGNITION_H
#define CV_FACE_RECOGNITION_H
#include "vector"

using std::vector; using std::pair;

void loadImgsDataset(std::string DirPath, std::vector<std::vector<float>>& TrainingDataset);

std::vector<float> AvgVector(std::vector<std::vector<float>>& TrainingDataset);

void GetCenteredImgs(std::vector<std::vector<float>>& TrainingDataset);

float VectorsDotProduct(std::vector<float> v1, std::vector<float> v2);

std::vector<std::vector<float>> GetCovMatrix(std::vector<std::vector<float>>& TrainingDataset);

vector<vector<float>> GetEigenFaces(vector<vector<float>>& TrainingDataset);

vector<vector<float>> getProjectedImgs(vector<vector<float>>& TrainingDataset);

#endif //CV_FACE_RECOGNITION_H
