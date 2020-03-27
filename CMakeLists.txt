cmake_minimum_required(VERSION 3.15)
project(data_structure)

#头文件目录 include省去路径
include_directories(include)

set(CMAKE_CXX_STANDARD 14)

#设置源文件
file(GLOB SOURCES "src/*.cpp")
#aux_source_directory(. SOURCES)



#add_library(dome ${SOURCES})
add_executable(data_structure main.cpp ${SOURCES})