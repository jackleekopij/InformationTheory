# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jacklee-kopij/CLionProjects/MachineLearningCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jacklee-kopij/CLionProjects/MachineLearningCode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MachineLearningCode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MachineLearningCode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MachineLearningCode.dir/flags.make

CMakeFiles/MachineLearningCode.dir/main.cpp.o: CMakeFiles/MachineLearningCode.dir/flags.make
CMakeFiles/MachineLearningCode.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacklee-kopij/CLionProjects/MachineLearningCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MachineLearningCode.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MachineLearningCode.dir/main.cpp.o -c /Users/jacklee-kopij/CLionProjects/MachineLearningCode/main.cpp

CMakeFiles/MachineLearningCode.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MachineLearningCode.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacklee-kopij/CLionProjects/MachineLearningCode/main.cpp > CMakeFiles/MachineLearningCode.dir/main.cpp.i

CMakeFiles/MachineLearningCode.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MachineLearningCode.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacklee-kopij/CLionProjects/MachineLearningCode/main.cpp -o CMakeFiles/MachineLearningCode.dir/main.cpp.s

CMakeFiles/MachineLearningCode.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MachineLearningCode.dir/main.cpp.o.requires

CMakeFiles/MachineLearningCode.dir/main.cpp.o.provides: CMakeFiles/MachineLearningCode.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MachineLearningCode.dir/build.make CMakeFiles/MachineLearningCode.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MachineLearningCode.dir/main.cpp.o.provides

CMakeFiles/MachineLearningCode.dir/main.cpp.o.provides.build: CMakeFiles/MachineLearningCode.dir/main.cpp.o


# Object files for target MachineLearningCode
MachineLearningCode_OBJECTS = \
"CMakeFiles/MachineLearningCode.dir/main.cpp.o"

# External object files for target MachineLearningCode
MachineLearningCode_EXTERNAL_OBJECTS =

MachineLearningCode: CMakeFiles/MachineLearningCode.dir/main.cpp.o
MachineLearningCode: CMakeFiles/MachineLearningCode.dir/build.make
MachineLearningCode: CMakeFiles/MachineLearningCode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jacklee-kopij/CLionProjects/MachineLearningCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MachineLearningCode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MachineLearningCode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MachineLearningCode.dir/build: MachineLearningCode

.PHONY : CMakeFiles/MachineLearningCode.dir/build

CMakeFiles/MachineLearningCode.dir/requires: CMakeFiles/MachineLearningCode.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MachineLearningCode.dir/requires

CMakeFiles/MachineLearningCode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MachineLearningCode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MachineLearningCode.dir/clean

CMakeFiles/MachineLearningCode.dir/depend:
	cd /Users/jacklee-kopij/CLionProjects/MachineLearningCode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jacklee-kopij/CLionProjects/MachineLearningCode /Users/jacklee-kopij/CLionProjects/MachineLearningCode /Users/jacklee-kopij/CLionProjects/MachineLearningCode/cmake-build-debug /Users/jacklee-kopij/CLionProjects/MachineLearningCode/cmake-build-debug /Users/jacklee-kopij/CLionProjects/MachineLearningCode/cmake-build-debug/CMakeFiles/MachineLearningCode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MachineLearningCode.dir/depend

