# 设置 CMake 最低版本需求，若不满足就报告致命错误
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# 设置项目名称和语言
project(ComputeAreas LANGUAGES CXX)

###########################################################
# 创建一个静态库
###########################################################
add_library(geometry STATIC
    src/GeometryCircle.cpp
    src/GeometryPolygon.cpp
    src/GeometryRhombus.cpp
    src/GeometrySquare.cpp
)

target_include_directories(geometry
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# 为这个库目标设置私有编译优化选项：-O3
target_compile_options(geometry
    PRIVATE
        -O3
)

# 生成一个源文件列表
list(
    APPEND sources_with_lower_optimization
        src/GeometryCircle.cpp
        src/GeometryRhombus.cpp
)

# 循环这些源文件，将它们的优化级别调到 -O2
message(STATUS "Setting source properties using IN LISTS syntax:")
foreach(_source IN LISTS sources_with_lower_optimization)
    set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O2)
    message(STATUS "Appending -O2 flag for ${_source}")
endforeach()

# 打印每个源文件的 COMPILE_FLAGS 属性，确保设置正确
message(STATUS "Querying sources properties using plain syntax:")
foreach(_source ${sources_with_lower_optimization})
    get_source_file_property(_flags ${_source} COMPILE_FLAGS)
    message(STATUS "Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach()

###########################################################
# 创建一个可执行文件
###########################################################
add_executable(${PROJECT_NAME} src/ComputeAreas.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        geometry
)

# 使用 VERBOSE=1 检查构建步骤：
# $ cmake --VERBOSE=1 --build ./build