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
CMAKE_SOURCE_DIR = "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Recitation10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Recitation10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Recitation10.dir/flags.make

CMakeFiles/Recitation10.dir/main.cpp.o: CMakeFiles/Recitation10.dir/flags.make
CMakeFiles/Recitation10.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Recitation10.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Recitation10.dir/main.cpp.o -c "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/main.cpp"

CMakeFiles/Recitation10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Recitation10.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/main.cpp" > CMakeFiles/Recitation10.dir/main.cpp.i

CMakeFiles/Recitation10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Recitation10.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/main.cpp" -o CMakeFiles/Recitation10.dir/main.cpp.s

CMakeFiles/Recitation10.dir/trie.cpp.o: CMakeFiles/Recitation10.dir/flags.make
CMakeFiles/Recitation10.dir/trie.cpp.o: ../trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Recitation10.dir/trie.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Recitation10.dir/trie.cpp.o -c "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/trie.cpp"

CMakeFiles/Recitation10.dir/trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Recitation10.dir/trie.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/trie.cpp" > CMakeFiles/Recitation10.dir/trie.cpp.i

CMakeFiles/Recitation10.dir/trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Recitation10.dir/trie.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/trie.cpp" -o CMakeFiles/Recitation10.dir/trie.cpp.s

# Object files for target Recitation10
Recitation10_OBJECTS = \
"CMakeFiles/Recitation10.dir/main.cpp.o" \
"CMakeFiles/Recitation10.dir/trie.cpp.o"

# External object files for target Recitation10
Recitation10_EXTERNAL_OBJECTS =

Recitation10: CMakeFiles/Recitation10.dir/main.cpp.o
Recitation10: CMakeFiles/Recitation10.dir/trie.cpp.o
Recitation10: CMakeFiles/Recitation10.dir/build.make
Recitation10: CMakeFiles/Recitation10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Recitation10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Recitation10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Recitation10.dir/build: Recitation10

.PHONY : CMakeFiles/Recitation10.dir/build

CMakeFiles/Recitation10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Recitation10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Recitation10.dir/clean

CMakeFiles/Recitation10.dir/depend:
	cd "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug" "/Users/sam/Desktop/CU Boulder/2018:2019/CSCI 2275/Assignments/Recitation10/cmake-build-debug/CMakeFiles/Recitation10.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Recitation10.dir/depend

