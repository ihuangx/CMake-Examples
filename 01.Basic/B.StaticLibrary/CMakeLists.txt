# 设置 CMake 最低版本需求，若不满足就报告致命错误
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# 设置项目名称和语言
project(HelloCMake LANGUAGES CXX)

###########################################################
# 创建一个静态库
###########################################################
add_library(message STATIC
    src/Message.cpp
)

target_include_directories(message
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

###########################################################
# 创建一个可执行文件
###########################################################
add_executable(${PROJECT_NAME} src/HelloCMake.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        message
)