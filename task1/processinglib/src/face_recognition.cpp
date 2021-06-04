//
// Created by abdulla167 on ٣‏/٦‏/٢٠٢١.
//
#include "iostream"
#include <filesystem>
#include <vector>
#include <Image.h>
#include "utilities.h"
#include "face_recognition.h"

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

void GetCenteredImgs(vector<vector<float>> &TrainingDataset) {
    vector<float> AverageVect = AvgVector(TrainingDataset);
    for (int i = 0; i < TrainingDataset[0].size(); ++i) {
        float temp = 0;
        for (int j = 0; j < TrainingDataset.size(); ++j) {
            TrainingDataset[j][i] = TrainingDataset[j][i] - AverageVect[i];
        }
    }
}

vector<vector<float>> GetCovMatrix(vector<vector<float>>& TrainingDataset){
    vector<vector<float>> CorrMat = std::vector<vector<float>>(TrainingDataset.size(),vector<float>(TrainingDataset.size()));
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

vector<vector<float>> GetEigenFaces(vector<vector<float>>& TrainingDataset){
    GetCenteredImgs(TrainingDataset);
    vector<vector<float>> CovMat = GetCovMatrix(TrainingDataset);
    vector<pair<vector<float>, float>> EigenValuesAndVectors = egienVectorsValues(CovMat);
    vector<vector<float>> EigenFaces;
    vector<float> tempEigenFace;
    float temp = 0;
    for (int eigenValueIndex = 0; eigenValueIndex < EigenValuesAndVectors.size(); ++eigenValueIndex) {
        for (int i = 0; i < CovMat[0].size(); ++i) {
            for (int j = 0; j < CovMat.size(); ++j) {
                temp += TrainingDataset[j][i] * EigenValuesAndVectors[eigenValueIndex].first[j];
            }
            tempEigenFace.push_back(temp);
        }
        EigenFaces.push_back(vector<float>(tempEigenFace));
    }
    return EigenFaces;
}

vector<vector<float>> getProjectedImgs(vector<vector<float>>& TrainingDataset){
    vector<vector<float>> EigenFaces = GetEigenFaces(TrainingDataset);
    vector<vector<float>> CoffMat =  std::vector<vector<float>>(TrainingDataset.size(),vector<float>(TrainingDataset[0].size()));
    float tempCoff = 0;
    for (int imgIndex = 0; imgIndex < TrainingDataset.size(); ++imgIndex) {
        tempCoff = 0;
        for (int eigenFaceIndex = 0; eigenFaceIndex < EigenFaces.size(); ++eigenFaceIndex) {
            for (int i = 0; i < TrainingDataset[0].size(); ++i) {
                tempCoff = tempCoff + (EigenFaces[eigenFaceIndex][i] * TrainingDataset[imgIndex][i]);
            }
            CoffMat[imgIndex][eigenFaceIndex] = tempCoff;
        }
    }
    return CoffMat;
}





