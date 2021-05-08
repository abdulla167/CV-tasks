# Task 3
### Haris Operator
```c++
std::vector<_Point> cornerHarris(Image& grayImg, double threshold, int patchDim = 3)
```
Parameters:
* Grayscale image
* Threshold(0 -> 1) which is percentage of max of haris operator
* Patch dimension to construct hessian matrix at each pixel<br>
it uses internally ```void getHarrisCorner(Image &pointsStrength, std::vector<_Point> &cornerPoints, double threshold) ```
which get the points that greater than threshold
<br>
Complexity: O(imgWidth x imgHeight)
![](./images/harris_image.png)

### SIFT Descriptor
```c++
std::vector<std::pair<std::vector<double>, _Point>> getSIFTDescriptor(Image &inputImg, float threshold = 0.01)
```
Parameters: 
* Grayscale image
* Threshold(0 -> 1) which passed to `cornerHarris`

Returns: 
vector of pair, each pair if 128-length vector and its associated point

Steps:
* get main orientation of pixel `std::vector<double>
  getMainOrientation(Image &dir, Image &magnitude, std::pair<int, int> iRange, std::pair<int, int> jRange)` 
  construct histogram of 36 bin in neighborhood of the pixel and take all orientations that greater than 0.8 * (max orientation)
* for each main orientation construct 16 x 16 neighborhood for each 4 x 4 region make histogram of 8 bin (of relative orientations) and store this histogram in the feature vector
 `void featureHistogram(Image &dir, Image &magnitude, double mainOrientation, std::pair<int, int> iRange, std::pair<int, int> jRange, std::vector<double> &v)`
* normalize the feature vector

Complexity: O(n^2)

## Requirement packages 
* fftw3
* qt5
* cmake

## How to Run
linux os:
* mkdir build
* cd build 
* cmake ..
* make 

