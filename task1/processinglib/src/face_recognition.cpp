//
// Created by abdulla167 on ٣‏/٦‏/٢٠٢١.
//
#include "iostream"
#include <filesystem>
#include <vector>
#include <Image.h>

using std::filesystem::recursive_directory_iterator;

void loadImgsDataset(std::string DirPath, std::vector<std::vector<float>>& TrainingDataset){
    for (const auto & file : recursive_directory_iterator(DirPath)){
        std::cout << Image(file.path(), 3).width << "," << Image(file.path(), 3).height<< std::endl;
        TrainingDataset.push_back(Image(file.path(), 3).ImageAsVector());
    }
}

std::vector<float> AvgVector(std::vector<std::vector<float>>& TrainingDataset){
    std::vector<float> AverageVect;
    int numOfVectors = TrainingDataset.size();
    for (int i = 0; i < TrainingDataset[0].size(); ++i) {
        float temp = 0;
        for (int j = 0; j < numOfVectors; ++j) {
            temp += TrainingDataset[j][i];
        }
        AverageVect.push_back(temp / numOfVectors);
    }
    return AverageVect;
}

void GetImgsMatrix(std::vector<std::vector<float>>& TrainingDataset) {
    std::vector<float> AverageVect = AvgVector(TrainingDataset);
    for (int i = 0; i < TrainingDataset[0].size(); ++i) {
        float temp = 0;
        for (int j = 0; j < TrainingDataset.size(); ++j) {
            TrainingDataset[j][i] = TrainingDataset[j][i] - AverageVect[i];
        }
    }
}

std::vector<std::vector<float>> GetCovMatrix(std::vector<std::vector<float>>& TrainingDataset){
    GetImgsMatrix(TrainingDataset);
    std::vector<std::vector<float>> CorrMat = std::vector<std::vector<float>>(TrainingDataset.size(),
            std::vector<float>(TrainingDataset.size()));
    int M = TrainingDataset[0].size();
    float result = 0;
    for (int i = 0; i < TrainingDataset.size(); ++i) {
        for (int j = 0; j < TrainingDataset.size(); ++j) {
            result = 0;
            for (int k = 0; k < TrainingDataset[0].size(); ++k) {
                result += TrainingDataset[i][k] * TrainingDataset[j][k];
            }
            CorrMat[j][i] = result / (M );
        }
    }
    return CorrMat;
}


