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
CMAKE_SOURCE_DIR = /Users/jacklee-kopij/CLionProjects/MachineLearning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jacklee-kopij/CLionProjects/MachineLearning/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MachineLearning.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MachineLearning.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MachineLearning.dir/flags.make

CMakeFiles/MachineLearning.dir/main.cpp.o: CMakeFiles/MachineLearning.dir/flags.make
CMakeFiles/MachineLearning.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacklee-kopij/CLionProjects/MachineLearning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MachineLearning.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MachineLearning.dir/main.cpp.o -c /Users/jacklee-kopij/CLionProjects/MachineLearning/main.cpp

CMakeFiles/MachineLearning.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MachineLearning.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacklee-kopij/CLionProjects/MachineLearning/main.cpp > CMakeFiles/MachineLearning.dir/main.cpp.i

CMakeFiles/MachineLearning.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MachineLearning.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacklee-kopij/CLionProjects/MachineLearning/main.cpp -o CMakeFiles/MachineLearning.dir/main.cpp.s

CMakeFiles/MachineLearning.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MachineLearning.dir/main.cpp.o.requires

CMakeFiles/MachineLearning.dir/main.cpp.o.provides: CMakeFiles/MachineLearning.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MachineLearning.dir/build.make CMakeFiles/MachineLearning.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MachineLearning.dir/main.cpp.o.provides

CMakeFiles/MachineLearning.dir/main.cpp.o.provides.build: CMakeFiles/MachineLearning.dir/main.cpp.o


# Object files for target MachineLearning
MachineLearning_OBJECTS = \
"CMakeFiles/MachineLearning.dir/main.cpp.o"

# External object files for target MachineLearning
MachineLearning_EXTERNAL_OBJECTS =

MachineLearning: CMakeFiles/MachineLearning.dir/main.cpp.o
MachineLearning: CMakeFiles/MachineLearning.dir/build.make
MachineLearning: CMakeFiles/MachineLearning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jacklee-kopij/CLionProjects/MachineLearning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MachineLearning"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MachineLearning.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MachineLearning.dir/build: MachineLearning

.PHONY : CMakeFiles/MachineLearning.dir/build

CMakeFiles/MachineLearning.dir/requires: CMakeFiles/MachineLearning.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MachineLearning.dir/requires

CMakeFiles/MachineLearning.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MachineLearning.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MachineLearning.dir/clean

CMakeFiles/MachineLearning.dir/depend:
	cd /Users/jacklee-kopij/CLionProjects/MachineLearning/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jacklee-kopij/CLionProjects/MachineLearning /Users/jacklee-kopij/CLionProjects/MachineLearning /Users/jacklee-kopij/CLionProjects/MachineLearning/cmake-build-debug /Users/jacklee-kopij/CLionProjects/MachineLearning/cmake-build-debug /Users/jacklee-kopij/CLionProjects/MachineLearning/cmake-build-debug/CMakeFiles/MachineLearning.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MachineLearning.dir/depend

