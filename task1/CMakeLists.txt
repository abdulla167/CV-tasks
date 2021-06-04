cmake_minimum_required(VERSION 3.17)
project(cv)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS  Pages)
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

add_executable(${PROJECT_NAME} main.cpp  MainWindow.cpp MainWindow.h MainWindow.ui Pages/FiltersPage.cpp Pages/HistogramPage.cpp Pages/HybridPage.cpp Pages/FreqPage.cpp Pages/SnakePage.cpp Pages/TemplateMatching.cpp Pages/SegmentationPage.cpp)
if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
add_subdirectory(processinglib)

add_subdirectory(plotlib)
target_link_libraries(${PROJECT_NAME} processinglib plotlib)
target_link_libraries(${PROJECT_NAME}  ${REQUIRED_LIBS_QUALIFIED})
