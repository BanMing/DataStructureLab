cmake_minimum_required(VERSION 3.15)
project(DataStructureLab)

#头文件目录
include_directories(include)


#aux_source_directory(. DIR_SRCS)
#设置源文件
#file(GLOB SOURCES "src/*.cpp")
set("src")
add_executable(DataStructureLab main.cpp)