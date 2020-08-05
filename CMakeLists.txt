cmake_minimum_required(VERSION 3.15)
project(data_structure)

#头文件目录 include省去路径
include_directories(include)

set(CMAKE_CXX_STANDARD 14)

#设置源文件
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/*/*cpp)

add_library(data_structure_src SHARED ${SOURCE_FILES})
add_executable(data_structure main.cpp)

target_link_libraries(data_structure
data_structure_src
)