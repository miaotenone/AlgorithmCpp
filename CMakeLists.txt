cmake_minimum_required(VERSION 3.25)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./output")
include_directories("src/utils")
## 添加子项目
#add_subdirectory(googletest)
## 指定gtest的头文件目录
#include_directories(googletest/googletest/include gtest_demo/lib/googletest)
## 指定gmock的头文件目录
#include_directories(googletest/googlemock/include gtest_demo/lib/googlemock)
#add_executable(${PROJECT_NAME} main.cpp)
## 指定将gtest gtest_main两个链接库，链接到gtest01工程中
#target_link_libraries(${PROJECT_NAME} gtest gtest_main)
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file} src/Binary_Tree/MaxDepth.cpp src/practice/common.cpp src/practice/deep_copy.cpp src/utils/common_ds.h src/Binary_Tree/MaxDepth.cpp)
endforeach ()

