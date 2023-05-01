cmake_minimum_required (VERSION 3.10)

# Set the project name and version
project(CppSample VERSION 0.1)
configure_file(CppSampleConfig.h.in CppSampleConfig.h)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_CXX_CLANG_TIDY clang-tidy)


# Set compiler options
SET(CMAKE_CXX_FLAGS "-Wall")

include_directories("${PROJECT_SOURCE_DIR}/include")

set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/BinaryTree.cpp
    ${PROJECT_SOURCE_DIR}/src/BinarySearchTree.cpp
    ${PROJECT_SOURCE_DIR}/src/Traversal.cpp
)

add_library(CppSample STATIC ${SOURCES})

enable_testing()
add_subdirectory(test)
