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
CMAKE_SOURCE_DIR = /Users/jacklee-kopij/CLionProjects/ID3_algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jacklee-kopij/CLionProjects/ID3_algorithm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ID3_algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ID3_algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ID3_algorithm.dir/flags.make

CMakeFiles/ID3_algorithm.dir/main.cpp.o: CMakeFiles/ID3_algorithm.dir/flags.make
CMakeFiles/ID3_algorithm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacklee-kopij/CLionProjects/ID3_algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ID3_algorithm.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ID3_algorithm.dir/main.cpp.o -c /Users/jacklee-kopij/CLionProjects/ID3_algorithm/main.cpp

CMakeFiles/ID3_algorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ID3_algorithm.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacklee-kopij/CLionProjects/ID3_algorithm/main.cpp > CMakeFiles/ID3_algorithm.dir/main.cpp.i

CMakeFiles/ID3_algorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ID3_algorithm.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacklee-kopij/CLionProjects/ID3_algorithm/main.cpp -o CMakeFiles/ID3_algorithm.dir/main.cpp.s

CMakeFiles/ID3_algorithm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ID3_algorithm.dir/main.cpp.o.requires

CMakeFiles/ID3_algorithm.dir/main.cpp.o.provides: CMakeFiles/ID3_algorithm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ID3_algorithm.dir/build.make CMakeFiles/ID3_algorithm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ID3_algorithm.dir/main.cpp.o.provides

CMakeFiles/ID3_algorithm.dir/main.cpp.o.provides.build: CMakeFiles/ID3_algorithm.dir/main.cpp.o


# Object files for target ID3_algorithm
ID3_algorithm_OBJECTS = \
"CMakeFiles/ID3_algorithm.dir/main.cpp.o"

# External object files for target ID3_algorithm
ID3_algorithm_EXTERNAL_OBJECTS =

ID3_algorithm: CMakeFiles/ID3_algorithm.dir/main.cpp.o
ID3_algorithm: CMakeFiles/ID3_algorithm.dir/build.make
ID3_algorithm: CMakeFiles/ID3_algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jacklee-kopij/CLionProjects/ID3_algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ID3_algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ID3_algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ID3_algorithm.dir/build: ID3_algorithm

.PHONY : CMakeFiles/ID3_algorithm.dir/build

CMakeFiles/ID3_algorithm.dir/requires: CMakeFiles/ID3_algorithm.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ID3_algorithm.dir/requires

CMakeFiles/ID3_algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ID3_algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ID3_algorithm.dir/clean

CMakeFiles/ID3_algorithm.dir/depend:
	cd /Users/jacklee-kopij/CLionProjects/ID3_algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jacklee-kopij/CLionProjects/ID3_algorithm /Users/jacklee-kopij/CLionProjects/ID3_algorithm /Users/jacklee-kopij/CLionProjects/ID3_algorithm/cmake-build-debug /Users/jacklee-kopij/CLionProjects/ID3_algorithm/cmake-build-debug /Users/jacklee-kopij/CLionProjects/ID3_algorithm/cmake-build-debug/CMakeFiles/ID3_algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ID3_algorithm.dir/depend
