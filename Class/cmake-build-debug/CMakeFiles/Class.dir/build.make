# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "/Users/sam/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4129.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/sam/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4129.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Class.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Class.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Class.dir/flags.make

CMakeFiles/Class.dir/main.cpp.o: CMakeFiles/Class.dir/flags.make
CMakeFiles/Class.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Class.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Class.dir/main.cpp.o -c "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/main.cpp"

CMakeFiles/Class.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Class.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/main.cpp" > CMakeFiles/Class.dir/main.cpp.i

CMakeFiles/Class.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Class.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/main.cpp" -o CMakeFiles/Class.dir/main.cpp.s

# Object files for target Class
Class_OBJECTS = \
"CMakeFiles/Class.dir/main.cpp.o"

# External object files for target Class
Class_EXTERNAL_OBJECTS =

Class: CMakeFiles/Class.dir/main.cpp.o
Class: CMakeFiles/Class.dir/build.make
Class: CMakeFiles/Class.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Class"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Class.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Class.dir/build: Class

.PHONY : CMakeFiles/Class.dir/build

CMakeFiles/Class.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Class.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Class.dir/clean

CMakeFiles/Class.dir/depend:
	cd "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/cmake-build-debug" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/cmake-build-debug" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Class/cmake-build-debug/CMakeFiles/Class.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Class.dir/depend

