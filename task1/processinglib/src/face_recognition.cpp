//
// Created by abdulla167 on ٣‏/٦‏/٢٠٢١.
//
#include "iostream"
#include <filesystem>
#include <vector>
#include <Image.h>
#include <fstream>
#include "utilities.h"
#include "face_recognition.h"
#include "math.h"
#include "algorithm"

using std::filesystem::recursive_directory_iterator;

void loadImgsDataset(std::string DirPath, std::vector<std::vector<float>>& Dataset, int numImgs){
    vector<std::string> TempPaths;
    for (const auto & file : recursive_directory_iterator(DirPath)){
        TempPaths.push_back(file.path());
    }
    std::sort(TempPaths.begin(), TempPaths.end());
    for (int i = 0; i < TempPaths.size(); ++i) {
        Dataset.push_back(Image(TempPaths[i], 3).ImageAsVector());
        if (i > numImgs)
            break;
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

vector<vector<float>>  GetCenteredImgs(vector<vector<float>> TrainingDataset) {
    vector<float> AverageVect = AvgVector(TrainingDataset);
    for (int i = 0; i < TrainingDataset[0].size(); ++i) {
        for (int j = 0; j < TrainingDataset.size(); ++j) {
            TrainingDataset[j][i] = TrainingDataset[j][i] - AverageVect[i];
        }
    }
    return TrainingDataset;
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
            CorrMat[j][i] = result / (M);
        }
    }
    return CorrMat;
}

vector<vector<float>> GetEigenFaces(vector<vector<float>>& TrainingDataset){
    vector<vector<float>> CovMat = GetCovMatrix(TrainingDataset);
    vector<pair<vector<float>, float>> EigenValuesAndVectors = egienVectorsValues(CovMat);
    vector<vector<float>> EigenFaces;
    float temp = 0;
    for (int eigenValueIndex = 0; eigenValueIndex < EigenValuesAndVectors.size(); ++eigenValueIndex) {
        vector<float> tempEigenFace;
        for (int i = 0; i < TrainingDataset[0].size(); ++i) {
            temp = 0;
            for (int j = 0; j < TrainingDataset.size(); ++j) {
                temp += TrainingDataset[j][i] * EigenValuesAndVectors[eigenValueIndex].first[j];
            }
            tempEigenFace.push_back(temp);
        }
        EigenFaces.push_back(vector<float>(tempEigenFace));
    }
    WriteVectorToFile("../Eigen_Faces_Matrix.txt", EigenFaces);
    return EigenFaces;
}

vector<vector<float>> getProjectedImgs(vector<vector<float>>& TrainingDataset, vector<vector<float>> & EigenFaces){
    vector<vector<float>> CoffMat =  std::vector<vector<float>>(TrainingDataset.size(),vector<float>(EigenFaces.size()));
    float tempCoff = 0;
    for (int imgIndex = 0; imgIndex < TrainingDataset.size(); ++imgIndex) {
        for (int eigenFaceIndex = 0; eigenFaceIndex < EigenFaces.size(); ++eigenFaceIndex) {
            tempCoff = 0;
            for (int i = 0; i < TrainingDataset[0].size(); ++i) {
                tempCoff = tempCoff + (EigenFaces[eigenFaceIndex][i] * TrainingDataset[imgIndex][i]);
            }
            CoffMat[imgIndex][eigenFaceIndex] = tempCoff;
        }
    }
    WriteVectorToFile("../Coefficient_Matrix.txt", CoffMat);
    return CoffMat;
}


vector<float> GetImgCoff( vector<vector<float>> EigenFaces , vector<float> ImgVector){
    vector<float> ImgCoff;
    float tempCoff = 0;
    for (int eigenFaceIndex = 0; eigenFaceIndex < EigenFaces.size(); ++eigenFaceIndex) {
        tempCoff = 0;
        for (int i = 0; i < ImgVector.size(); ++i) {
            tempCoff = tempCoff + (EigenFaces[eigenFaceIndex][i] * ImgVector[i]);
        }
        ImgCoff.push_back(tempCoff);
    }
    return ImgCoff;
}

float GetImgError(vector<float> TestImgCoff, vector<float> TrainImgCoff){
    float error = 0;
    for (int i = 0; i < TestImgCoff.size(); ++i) {
        error = error + abs(TestImgCoff[i] - TrainImgCoff[i]);
    }
    return error;
}

pair<int, float> GetSimilarImg(vector<vector<float>> CoffMatrix, vector<float> ImgCoff)
{
    pair<int, float> MinError{0,INFINITY};
    float TempError = 0;
    for (int i = 0; i < CoffMatrix.size(); ++i) {
        TempError = GetImgError(ImgCoff, CoffMatrix[i]);
        if (TempError < MinError.second){
            MinError.first = i;
            MinError.second = TempError;
        }
    }
    return MinError;
}

pair<int, float> TestImg(vector<float> testImg, vector<vector<float>> EigenFaces,  vector<vector<float>> CoffMat){
    vector<float> imgCoff = GetImgCoff(EigenFaces, testImg);
    pair<int, float> MinError = GetSimilarImg(CoffMat, imgCoff);
    return MinError;
}

void WriteVectorToFile(std::string filename, vector<vector<float>> Mat){
    std::ofstream outFile(filename);
    for (int i = 0; i < Mat.size(); ++i) {
        for (int j = 0; j < Mat[0].size(); ++j) {
            outFile << Mat[i][j] << " ";
        }
        outFile << std::endl;
    }
}

void ReadFileToVector(std::string filename, vector<vector<float>>& Mat){
    std::string str;
    std::ifstream in(filename);
    while (std::getline(in, str))
    {
        if (str.size() > 0){
            std::stringstream ss(str);
            std::string word;
            vector<float> temp;
            while (ss >> word) {
                temp.push_back(std::stof(word));
            }
            Mat.push_back(temp);
        }
    }
}
