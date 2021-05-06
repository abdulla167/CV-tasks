SET(LIB_NAME processinglib)
include_directories(include/processinglib)

add_library(${LIB_NAME} src/Image.cpp src/filters.cpp src/utilities.cpp src/histogram.cpp src/fourier_transform.cpp src/canny.cpp src/hough.cpp src/greedy_snake.cpp src/harris_corner_detector.cpp include/processinglib/harris_corner_detector.h include/processinglib/imageMatching.h src/imageMatching.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
find_library(FFTW NAMES libfftw3.so.3 libfftw3.a REQUIRED)
target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} ${FFTW})
target_include_directories(${LIB_NAME} PUBLIC include)