# 设置 CMake 最低版本需求，若不满足就报告致命错误
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# 设置项目名称和语言
project(HelloCMake LANGUAGES CXX)

# 定义默认构建类型为 Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# 打印 CMake 设置的相应编译标志
message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")

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

# 切换构建类型：
# $ cmake -G Ninja -D CMAKE_BUILD_TYPE=Release -H. -Bbuild
# $ cmake --build ./build