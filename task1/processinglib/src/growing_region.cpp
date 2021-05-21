//
// Created by abdulla167 on ١٥‏/٥‏/٢٠٢١.
//
#include "Image.h"
#include "stack"
#include "_Point.h"

Image RGSegmentation(Image & inputImg, _Point seedPoint){
    _Point pointArray[8] =
            {
                    _Point(1, -1),
                    _Point(1, 0),
                    _Point(0, -1),
                    _Point(-1, -1),
                    _Point(-1, 0),
                    _Point(-1, 1),
                    _Point(0, 1),
                    _Point(1, 1)

            };
    Image outputImg(inputImg.width, inputImg.height, inputImg.channels);
    std::stack<_Point> seedPoints;
    seedPoints.push(seedPoint);
    int  growLable = 0;//Mark whether it has grown
    int  inputValue = 0;//The gray value of the point to be grown
    int  outputValue = 0;//Mark the gray value of the growing point that meets the conditions in the Image of OutputData
    int initialValue = inputImg(seedPoint.y, seedPoint.x);
    while(!seedPoints.empty()){
        _Point  topPoint = seedPoints.top();
        seedPoints.pop();
        _Point tempPoint;
        for (int i = 0; i < 8; i++)
        {
            //tempPoint is the point to grow
            tempPoint = topPoint + pointArray[i];
            int x = tempPoint.x;
            int y = tempPoint.y;
            if (x < 0 || y < 0 || x > (inputImg.width - 1) || y > (inputImg.height - 1))
            {
                continue;
            }
            growLable = outputImg(y, x);
            inputValue = inputImg(y, x);
            /*The second point is not growing and the absolute value of the gray difference between
             * the point to be grown and the first seed point is less than 10, then grow
             */
            if (growLable == 0 && abs(inputValue - initialValue) < 30)
            {
                //Use gray to indicate growth
                outputImg(y, x) = 255;
                //Put this point on the stack
                seedPoints.push(tempPoint);
            }
        }
    }
    return outputImg;
}
