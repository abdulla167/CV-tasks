# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2020.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abdallah/Documents/Study/CV/CV-tasks/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug

# Include any dependencies generated for this target.
include processing/CMakeFiles/processing.dir/depend.make

# Include the progress variables for this target.
include processing/CMakeFiles/processing.dir/progress.make

# Include the compile flags for this target's objects.
include processing/CMakeFiles/processing.dir/flags.make

processing/CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.o: processing/CMakeFiles/processing.dir/flags.make
processing/CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.o: processing/processing_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object processing/CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.o"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.o -c /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/processing_autogen/mocs_compilation.cpp

processing/CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.i"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/processing_autogen/mocs_compilation.cpp > CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.i

processing/CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.s"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/processing_autogen/mocs_compilation.cpp -o CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.s

processing/CMakeFiles/processing.dir/src/Image.cpp.o: processing/CMakeFiles/processing.dir/flags.make
processing/CMakeFiles/processing.dir/src/Image.cpp.o: ../processing/src/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object processing/CMakeFiles/processing.dir/src/Image.cpp.o"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/processing.dir/src/Image.cpp.o -c /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/Image.cpp

processing/CMakeFiles/processing.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processing.dir/src/Image.cpp.i"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/Image.cpp > CMakeFiles/processing.dir/src/Image.cpp.i

processing/CMakeFiles/processing.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processing.dir/src/Image.cpp.s"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/Image.cpp -o CMakeFiles/processing.dir/src/Image.cpp.s

processing/CMakeFiles/processing.dir/src/filters.cpp.o: processing/CMakeFiles/processing.dir/flags.make
processing/CMakeFiles/processing.dir/src/filters.cpp.o: ../processing/src/filters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object processing/CMakeFiles/processing.dir/src/filters.cpp.o"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/processing.dir/src/filters.cpp.o -c /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/filters.cpp

processing/CMakeFiles/processing.dir/src/filters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processing.dir/src/filters.cpp.i"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/filters.cpp > CMakeFiles/processing.dir/src/filters.cpp.i

processing/CMakeFiles/processing.dir/src/filters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processing.dir/src/filters.cpp.s"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/filters.cpp -o CMakeFiles/processing.dir/src/filters.cpp.s

processing/CMakeFiles/processing.dir/src/utilities.cpp.o: processing/CMakeFiles/processing.dir/flags.make
processing/CMakeFiles/processing.dir/src/utilities.cpp.o: ../processing/src/utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object processing/CMakeFiles/processing.dir/src/utilities.cpp.o"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/processing.dir/src/utilities.cpp.o -c /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/utilities.cpp

processing/CMakeFiles/processing.dir/src/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processing.dir/src/utilities.cpp.i"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/utilities.cpp > CMakeFiles/processing.dir/src/utilities.cpp.i

processing/CMakeFiles/processing.dir/src/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processing.dir/src/utilities.cpp.s"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/utilities.cpp -o CMakeFiles/processing.dir/src/utilities.cpp.s

processing/CMakeFiles/processing.dir/src/histogram.cpp.o: processing/CMakeFiles/processing.dir/flags.make
processing/CMakeFiles/processing.dir/src/histogram.cpp.o: ../processing/src/histogram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object processing/CMakeFiles/processing.dir/src/histogram.cpp.o"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/processing.dir/src/histogram.cpp.o -c /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/histogram.cpp

processing/CMakeFiles/processing.dir/src/histogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processing.dir/src/histogram.cpp.i"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/histogram.cpp > CMakeFiles/processing.dir/src/histogram.cpp.i

processing/CMakeFiles/processing.dir/src/histogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processing.dir/src/histogram.cpp.s"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/src/histogram.cpp -o CMakeFiles/processing.dir/src/histogram.cpp.s

# Object files for target processing
processing_OBJECTS = \
"CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/processing.dir/src/Image.cpp.o" \
"CMakeFiles/processing.dir/src/filters.cpp.o" \
"CMakeFiles/processing.dir/src/utilities.cpp.o" \
"CMakeFiles/processing.dir/src/histogram.cpp.o"

# External object files for target processing
processing_EXTERNAL_OBJECTS =

processing/libprocessing.a: processing/CMakeFiles/processing.dir/processing_autogen/mocs_compilation.cpp.o
processing/libprocessing.a: processing/CMakeFiles/processing.dir/src/Image.cpp.o
processing/libprocessing.a: processing/CMakeFiles/processing.dir/src/filters.cpp.o
processing/libprocessing.a: processing/CMakeFiles/processing.dir/src/utilities.cpp.o
processing/libprocessing.a: processing/CMakeFiles/processing.dir/src/histogram.cpp.o
processing/libprocessing.a: processing/CMakeFiles/processing.dir/build.make
processing/libprocessing.a: processing/CMakeFiles/processing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libprocessing.a"
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && $(CMAKE_COMMAND) -P CMakeFiles/processing.dir/cmake_clean_target.cmake
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E make_directory /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && ln -sf /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/include/Image.h /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E make_directory /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && ln -sf /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/include/filters.h /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E make_directory /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && ln -sf /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/include/histogram.h /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E make_directory /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && ln -sf /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/include/qcustomplot.h /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E make_directory /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && ln -sf /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/include/stb_image.h /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E make_directory /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && ln -sf /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/include/stb_image_write.h /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && /opt/clion-2020.3/bin/cmake/linux/bin/cmake -E make_directory /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && ln -sf /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing/include/utilities.h /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/include/processing
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/processing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
processing/CMakeFiles/processing.dir/build: processing/libprocessing.a

.PHONY : processing/CMakeFiles/processing.dir/build

processing/CMakeFiles/processing.dir/clean:
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing && $(CMAKE_COMMAND) -P CMakeFiles/processing.dir/cmake_clean.cmake
.PHONY : processing/CMakeFiles/processing.dir/clean

processing/CMakeFiles/processing.dir/depend:
	cd /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdallah/Documents/Study/CV/CV-tasks/task1 /home/abdallah/Documents/Study/CV/CV-tasks/task1/processing /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing /home/abdallah/Documents/Study/CV/CV-tasks/task1/cmake-build-debug/processing/CMakeFiles/processing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : processing/CMakeFiles/processing.dir/depend

