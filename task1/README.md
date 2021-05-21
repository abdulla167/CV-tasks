# Task 4
### Thresholding
##### Global Atsu
```c++
std::vector<int> globalAtsu(Image &inputImg, int histSize = 256, int numModes = 2);
```
function parameters:
  * inputImg: reference to gray Image
  * histSize: histogram size depending on the number of bits that represent each pixel in the image
  * numModes: number of modes

function return: return array of thresholds depending on number of modes

**Results**:<br>
* global atsu 2 modes
![](images/atsu-global-2-modes.png)
  
* global atsu 3 modes
![](images/atsu-global-3-modes.png)

##### Local Atsu
```c++
Image localAtsu(Image &inputImg, int blockDim, int histSize = 256, int numModes = 2);
```
function parameters:
* inputImg: reference to gray Image
* blockDim: block dimension (eg, 5 means 5 x 5)
* histSize: histogram size depending on the number of bits that represent each pixel in the image
* numModes: number of modes

function return: return the thresholded image

**Results**:<br>
* local atsu 2 modes, blockDim: 5
![](images/atsu-local-2-modes.png)

* local atsu 3 modes, blockDim: 5
![](images/atsu-local-3-modes.png)
##### Global Optimal Iterative Thresholding

```c++
int globalOptimalIterativeThresholding(Image &inputImg);
```
function parameters:
   * inputImg: reference to gray Image 

function return: return threshold

 **Results**:<br>
![](images/global-optimal.png)

##### Local Optimal Iterative Thresholding
```c++
Image localOptimalIterativeThresholding(Image &inputImg, int blockDim);
```
function parameters:
* inputImg: reference to gray Image
* blockDim: block dimension (eg, 5 means 5 x 5)

function return: return threshold

**Results**:<br>
blockDim: 7
![](images/local-optimal.png)
## Requirement packages git
* fftw3
* qt5
* cmake

## How to Run
linux os:
* mkdir build
* cd build 
* cmake ..
* make 

