SET(LIB_NAME processinglib)
include_directories(include/processinglib)

add_library(${LIB_NAME}
        src/Image.cpp
        src/filters.cpp
        src/utilities.cpp
        src/histogram.cpp
        src/fourier_transform.cpp
        src/canny.cpp src/hough.cpp
        src/greedy_snake.cpp
        src/harris_corner_detector.cpp
        src/imageMatching.cpp
        src/k_mean_segmentation.cpp
        src/mean_shift.cpp
        src/thresholding.cpp
        src/growing_region.cpp
        src/point.cpp
        src/agglomerative_cluster_segmentation.cpp
        src/face_detection_opencv.cpp
        )

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
find_library(FFTW NAMES libfftw3.so.3 libfftw3.a REQUIRED)
target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} ${FFTW})
target_include_directories(${LIB_NAME} PUBLIC include)