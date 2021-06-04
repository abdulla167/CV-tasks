/**
 * Created by abdallah drwesh on 6/4/21.
 */
#include "face_detection_opencv.h"
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

Image detectFace(Image &inputImage) {
    cv::CascadeClassifier faceDetection;
    if (!faceDetection.load("../Resources/models/haarcascade_frontalface_default.xml")) {
        std::cout << "model not loaded correctly" << std::endl;
        exit(1);
    }
    if (inputImage.channels > 1) {
        cv::Mat rgbImg(inputImage.height, inputImage.width, CV_8UC3);
        for (int i = 0; i < inputImage.height; ++i) {
            for (int j = 0; j < inputImage.width; ++j) {
                for (int k = 2; k > -1; --k) {
//                    rgbImg.data[i * inputImage.width + j + k*inputImage.width * inputImage.height ] = (unsigned char) inputImage(i, j, k);
                    rgbImg.data[i * inputImage.width * 3 + j * 3 + 2 - k] = (unsigned char) inputImage(i, j, k);
                }
            }
        }
        std::vector<cv::Rect> faces;
        faceDetection.detectMultiScale(rgbImg, faces);
        showDetectedFaceImage(rgbImg.clone(), faces);
        return cropImageToTheDetectedFace(rgbImg, faces[0]);
    } else {
        cv::Mat greyImg = cv::Mat(inputImage.height, inputImage.width, CV_8U);
        for (int i = 0; i < inputImage.height; ++i) {
            for (int j = 0; j < inputImage.width; ++j) {
                greyImg.data[i * inputImage.width + j] = inputImage(i, j);
            }
        }
        std::vector<cv::Rect> faces;
        faceDetection.detectMultiScale(greyImg, faces);
        showDetectedFaceImage(greyImg.clone(), faces);
        return cropImageToTheDetectedFace(greyImg, faces[0]);
    }
}

void showDetectedFaceImage(cv::Mat img, std::vector<cv::Rect> faces) {
    if (!faces.empty()) {
        for (int i = 0; i < faces.size(); ++i) {
            cv::Point pt1(faces[i].x, faces[i].y);
            cv::Point pt2(faces[i].x + faces[i].height, faces[i].y + faces[i].width);
            cv::rectangle(img, pt1, pt2, cv::Scalar(0, 0, 255), 2);
        }
    }
    cv::imshow("face detection", img);
}

Image cropImageToTheDetectedFace(cv::Mat img, cv::Rect face) {
    int maxHeight = 192, maxWeidth = 192;
    int widthDiff = maxWeidth - face.width;
    int heightDiff = maxHeight - face.height;
    int x1 = face.x;
    int y1 = face.y;
    int x2 = face.width + x1;
    int y2 = face.height + y1;
    if (widthDiff == 1) {
        x2 += 1;
    } else if (widthDiff > 1) {
        if (widthDiff % 2 == 0) {
            x1 -= widthDiff / 2;
            x2 += widthDiff / 2;
        } else {
            x1 -= widthDiff / 2;
            x2 += widthDiff / 2 + 1;
        }
    }
    if (x1 < 0) {
        x1 = 0;
        x2 = face.width + widthDiff;
    } else if (x2 > img.cols) {
        x1 = face.x - widthDiff;
        x2 = x1 + maxWeidth;
        if (x1 < 0) {
            x1 = 0;
            x2 += -x1;
        }
    }

    if (heightDiff == 1) {
        y2 += 1;
    } else if (heightDiff > 1) {
        if (heightDiff % 2 == 0) {
            y1 -= heightDiff / 2;
            y2 += heightDiff / 2;
        } else {
            y1 -= heightDiff / 2;
            y2 += heightDiff / 2 + 1;
        }
    }
    if (y1 < 0) {
        y1 = 0;
        y2 = face.height + heightDiff;
    } else if (y2 > img.rows) {
        y1 = face.y - heightDiff;
        y2 = y1 + maxHeight;
        if (y1 < 0) {
            y1 = 0;
            y2 += -y1;
        }
    }
    cv::Rect myROI(x1, y1, x2 - x1, y2 - y1);
    cv::Mat croppedImgMat = img(myROI);
    auto croppedBGR = croppedImgMat.clone();
    croppedImgMat.convertTo(croppedBGR, CV_8UC3);

    Image croppedImage(croppedImgMat.cols, croppedImgMat.rows, croppedImgMat.channels());
    if (croppedImage.channels > 1) {
        auto croppedBGR = croppedImgMat.clone();
        croppedImgMat.convertTo(croppedBGR, CV_8UC3);
//        std::cout << croppedImgMat.rows << ", " << croppedImgMat.cols << ", " << croppedImgMat.channels() << std::endl;
//        cv::imshow("crop.jpg", croppedBGR);
        for (int i = 0; i < croppedImage.height; ++i) {
            for (int j = 0; j < croppedImage.width; ++j) {
                for (int k = 2; k > -1; --k) {
                    croppedImage(i, j, 2 - k) = croppedBGR.data[i * croppedImage.width * 3 + j * 3 + k];
                }
            }
        }
    } else {
        auto croppedGray = croppedImgMat.clone();
        croppedImgMat.convertTo(croppedBGR, CV_8UC1);
        for (int i = 0; i < croppedImage.height; ++i) {
            for (int j = 0; j < croppedImage.height; ++j) {
                croppedImage(i, j, 0) = croppedGray.data[i * croppedImage.width + j];
            }
        }
    }
    return croppedImage;
}
