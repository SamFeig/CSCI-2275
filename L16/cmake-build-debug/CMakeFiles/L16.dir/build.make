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
CMAKE_SOURCE_DIR = "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/L16.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/L16.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/L16.dir/flags.make

CMakeFiles/L16.dir/main.cpp.o: CMakeFiles/L16.dir/flags.make
CMakeFiles/L16.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/L16.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/L16.dir/main.cpp.o -c "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/main.cpp"

CMakeFiles/L16.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L16.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/main.cpp" > CMakeFiles/L16.dir/main.cpp.i

CMakeFiles/L16.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L16.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/main.cpp" -o CMakeFiles/L16.dir/main.cpp.s

CMakeFiles/L16.dir/Stack.cpp.o: CMakeFiles/L16.dir/flags.make
CMakeFiles/L16.dir/Stack.cpp.o: ../Stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/L16.dir/Stack.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/L16.dir/Stack.cpp.o -c "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/Stack.cpp"

CMakeFiles/L16.dir/Stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L16.dir/Stack.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/Stack.cpp" > CMakeFiles/L16.dir/Stack.cpp.i

CMakeFiles/L16.dir/Stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L16.dir/Stack.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/Stack.cpp" -o CMakeFiles/L16.dir/Stack.cpp.s

# Object files for target L16
L16_OBJECTS = \
"CMakeFiles/L16.dir/main.cpp.o" \
"CMakeFiles/L16.dir/Stack.cpp.o"

# External object files for target L16
L16_EXTERNAL_OBJECTS =

L16: CMakeFiles/L16.dir/main.cpp.o
L16: CMakeFiles/L16.dir/Stack.cpp.o
L16: CMakeFiles/L16.dir/build.make
L16: CMakeFiles/L16.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable L16"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/L16.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/L16.dir/build: L16

.PHONY : CMakeFiles/L16.dir/build

CMakeFiles/L16.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/L16.dir/cmake_clean.cmake
.PHONY : CMakeFiles/L16.dir/clean

CMakeFiles/L16.dir/depend:
	cd "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/L16/cmake-build-debug/CMakeFiles/L16.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/L16.dir/depend

