# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.17
cmake_policy(SET CMP0009 NEW)

# EXPORT_HEADERS at processing/export_header.cmake:3 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false RELATIVE "/home/mohamedkamal/CLionProjects/CV-tasks/task1/processing" "/home/mohamedkamal/CLionProjects/CV-tasks/task1/processing/*.h")
set(OLD_GLOB
  "include/Image.h"
  "include/filters.h"
  "include/histogram.h"
  "include/stb_image.h"
  "include/stb_image_write.h"
  "include/utilities.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()
