add_library(plotlib qcustomplot.cpp)
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts PrintSupport)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts Qt5::PrintSupport)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} PrintSupport REQUIRED)
target_link_libraries(plotlib ${REQUIRED_LIBS_QUALIFIED})
target_include_directories(plotlib PUBLIC .)

