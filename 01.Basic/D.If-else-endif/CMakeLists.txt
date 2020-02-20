# 设置 CMake 最低版本需求，若不满足就报告致命错误
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# 设置项目名称和语言
project(HelloCMake LANGUAGES CXX)

message(STATUS "Is the C++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")
if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
  message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()

# 暴露选项给用户
option(USE_LIBRARY "Compile sources into a library?" OFF)

message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

include(CMakeDependentOption)

# 定义一个有依赖的选项
# 在 USE_LIBRARY 为 ON 的情况下，MAKE_STATIC_LIBRARY 初始值为 OFF
cmake_dependent_option(
    MAKE_STATIC_LIBRARY "Compile sources into a static library?" OFF
    "USE_LIBRARY" ON
)

cmake_dependent_option(
    MAKE_SHARED_LIBRARY "Compile sources into a shared library?" ON
    "USE_LIBRARY" ON
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

list(APPEND _sources src/Message.cpp)

if(USE_LIBRARY)
    message(STATUS "Compile sources into a STATIC library?" ${MAKE_STATIC_LIBRARY})
    message(STATUS "Compile sources into a SHARED library?" ${MAKE_SHARED_LIBRARY})

    if(MAKE_SHARED_LIBRARY)
        add_library(message SHARED ${_sources})

        target_include_directories(message
            PUBLIC
                ${PROJECT_SOURCE_DIR}/include
        )

        add_executable(${PROJECT_NAME} src/HelloCMake.cpp)

        target_link_libraries(${PROJECT_NAME} PRIVATE message)
    endif()

    if(MAKE_STATIC_LIBRARY)
        add_library(message STATIC ${_sources})

        target_include_directories(message
            PUBLIC
                ${PROJECT_SOURCE_DIR}/include
        )

        add_executable(${PROJECT_NAME} src/HelloCMake.cpp)

        target_link_libraries(${PROJECT_NAME} PRIVATE message)
    endif()
else()
    add_executable(${PROJECT_NAME} src/HelloCMake.cpp ${_sources})

    target_include_directories(${PROJECT_NAME}
        PRIVATE
            ${PROJECT_SOURCE_DIR}/include
    )
endif()

# 使用方法
# $ cmake -G Ninja -D USE_LIBRARY=ON -D MAKE_STATIC_LIBRARY=ON -H. -Bbuild
# $ cmake --build ./build
# -D 开关用于为 CMake 设置任何类型的变量：逻辑变量、路径等等。