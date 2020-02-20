# 设置 CMake 最低版本需求，若不满足就报告致命错误
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# 设置项目名称和语言
project(HelloCMake LANGUAGES CXX)

add_executable(${PROJECT_NAME} HelloCMake.cpp)