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
CMAKE_COMMAND = /snap/clion/145/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/145/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohamedkamal/CLionProjects/CV-tasks/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug

# Utility rule file for processing_autogen.

# Include the progress variables for this target.
include processing/CMakeFiles/processing_autogen.dir/progress.make

processing/CMakeFiles/processing_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target processing"
	cd /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug/processing && /snap/clion/145/bin/cmake/linux/bin/cmake -E cmake_autogen /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug/processing/CMakeFiles/processing_autogen.dir/AutogenInfo.json Debug

processing_autogen: processing/CMakeFiles/processing_autogen
processing_autogen: processing/CMakeFiles/processing_autogen.dir/build.make

.PHONY : processing_autogen

# Rule to build all files generated by this target.
processing/CMakeFiles/processing_autogen.dir/build: processing_autogen

.PHONY : processing/CMakeFiles/processing_autogen.dir/build

processing/CMakeFiles/processing_autogen.dir/clean:
	cd /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug/processing && $(CMAKE_COMMAND) -P CMakeFiles/processing_autogen.dir/cmake_clean.cmake
.PHONY : processing/CMakeFiles/processing_autogen.dir/clean

processing/CMakeFiles/processing_autogen.dir/depend:
	cd /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamedkamal/CLionProjects/CV-tasks/task1 /home/mohamedkamal/CLionProjects/CV-tasks/task1/processing /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug/processing /home/mohamedkamal/CLionProjects/CV-tasks/task1/cmake-build-debug/processing/CMakeFiles/processing_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : processing/CMakeFiles/processing_autogen.dir/depend

