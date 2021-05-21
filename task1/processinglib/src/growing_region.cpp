//
// Created by abdulla167 on ١٥‏/٥‏/٢٠٢١.
//
#include "Image.h"
#include "stack"
#include "point.h"

Image RGSegmentation(Image & inputImg, std::vector<point> seedPoint){
    point pointArray[8] =
            {
                    point(1, -1),
                    point(1, 0),
                    point(0, -1),
                    point(-1, -1),
                    point(-1, 0),
                    point(-1, 1),
                    point(0, 1),
                    point(1, 1)

            };
    Image outputImg(inputImg.width, inputImg.height, inputImg.channels);
    for (int i = 0; i < seedPoint.size(); ++i) {
        std::stack<point> seedPoints;
        seedPoints.push(seedPoint[i]);
        int  growLable = 0;//Mark whether it has grown
        int  inputValue = 0;//The gray value of the _Point to be grown
        int  outputValue = 0;//Mark the gray value of the growing _Point that meets the conditions in the Image of OutputData
        int initialValue = inputImg(seedPoint[i].y, seedPoint[i].x);
        while(!seedPoints.empty()){
            point  topPoint = seedPoints.top();
            seedPoints.pop();
            point tempPoint;
            for (int i = 0; i < 8; i++)
            {
                //tempPoint is the _Point to grow
                tempPoint = topPoint + pointArray[i];
                int x = tempPoint.x;
                int y = tempPoint.y;
                if (x < 0 || y < 0 || x > (inputImg.width - 1) || y > (inputImg.height - 1))
                {
                    continue;
                }
                growLable = outputImg(y, x);
                inputValue = inputImg(y, x);
                /*The second _Point is not growing and the absolute value of the gray difference between
                 * the _Point to be grown and the first seed _Point is less than 10, then grow
                 */
                if (growLable == 0 && abs(inputValue - initialValue) < 20)
                {
                    //Use gray to indicate growth
                    outputImg(y, x) = initialValue;
                    //Put this _Point on the stack
                    seedPoints.push(tempPoint);
                }
            }
        }
    }
    return outputImg;
}
