# 设置 CMake 最低版本需求，若不满足就报告致命错误
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# 设置项目名称和语言
project(AnimalFarm LANGUAGES CXX)

# 打印当前编译器标志。CMake 将对所有 C++ 目标使用这些
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# 为目标准备了了标志列表，其中一些将无法在 Windows 上使用
list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

# 在 Windows 上导出所有库符号：
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

###########################################################
# 创建一个动态库
###########################################################
add_library(animals SHARED
    src/Animal.cpp
    src/Cat.cpp
    src/Dog.cpp
)

target_include_directories(animals
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

set_target_properties(animals
    PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1
)

# 为这个库目标设置编译选项
target_compile_options(animals
    PRIVATE
        ${flags}
)

###########################################################
# 创建一个可执行文件
###########################################################
add_executable(${PROJECT_NAME} src/AnimalFarm.cpp)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

# 设置编译选项
target_compile_options(${PROJECT_NAME}
    PRIVATE
        "-fPIC"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        animals
)