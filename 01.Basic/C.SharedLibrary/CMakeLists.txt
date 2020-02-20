# 设置 CMake 最低版本需求，若不满足就报告致命错误
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# 设置项目名称和语言
project(HelloCMake LANGUAGES CXX)

###########################################################
# 创建一个 OBJECT 库
###########################################################
add_library(message-objs OBJECT
    src/Message.cpp
)

# 设置编译的目标文件与生成位置无关（可能在某些平台需要显式设置）
set_target_properties(message-objs
    PROPERTIES
        POSITION_INDEPENDENT_CODE 1
)

target_include_directories(message-objs
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

###########################################################
# 创建一个 STATIC 库
###########################################################
add_library(message-static
    STATIC
        $<TARGET_OBJECTS:message-objs>
)

target_include_directories(message-static
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

###########################################################
# 创建一个 SHARED 库
###########################################################
add_library(message-shared
    SHARED
        $<TARGET_OBJECTS:message-objs>
)

set_target_properties(message-shared
    PROPERTIES
        OUTPUT_NAME "message"
)

target_include_directories(message-shared
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

###########################################################
# 创建一个可执行文件
###########################################################
add_executable(${PROJECT_NAME} src/HelloCMake.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        message-static
)