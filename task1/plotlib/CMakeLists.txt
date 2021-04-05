add_library(plotlib qcustomplot.cpp)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} PrintSupport REQUIRED)

target_link_libraries(plotlib ${REQUIRED_LIBS_QUALIFIED} Qt5::PrintSupport)

