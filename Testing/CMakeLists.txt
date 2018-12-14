#cmake_minimum_required(VERSION 3.12)
#project(Testing)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(Testing main.cpp)

cmake_minimum_required(VERSION 3.12)

project(Testing)

message(STATUS "start running cmake...")

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

if(FindGTK)

    message(STATUS "GTK+_INCLUDE_DIRS: ${GTK+_INCLUDE_DIRS}")
    message(STATUS "GTK+_LIBRARIES: ${GTK+_LIBRARIES}")
    message(STATUS "GTK+_VERSION: ${GTK+_VERSION}")

    include_directories(${GTK+_INCLUDE_DIRS})

endif()

add_executable(Testing main.cpp)

if(Boost_FOUND)

target_link_libraries(Testing ${Boost_LIBRARIES})

endif()

if(GTK+_FOUND)

target_link_libraries(Testing ${GTK+_LIBRARIES})

endif()