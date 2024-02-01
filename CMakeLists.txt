cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(
    SimpleC++WebServer
    VERSION 0.0.1
    DESCRIPTION "A Simple C++ Web Server"
    LANGUAGES CXX
)

include(FetchContent)

# 设置FetchContent所下载内容的输出目录
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/_deps)

# 下载并添加fmt库
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_library(
    SimpleServer
    ./src/serverString.cpp
    ./src/serverTime.cpp
)

target_include_directories(
    SimpleServer
    PRIVATE include
)

target_link_libraries(SimpleServer PRIVATE fmt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# 单元测试, 默认为ON, 如果没有网络则设置为OFF避免从Github下载GTest
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if(ENABLE_UNIT_TESTS)
    # 下载GTest
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )

    # 获取GTest模块的属性
    FetchContent_GetProperties(googletest)

    if(NOT googletest_POPULATED)
        FetchContent_Populate(googletest)

        # 防止Gtest中的编译器设置覆盖项目的设置
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

        # 禁止GTest使用PThread
        set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

        # 添加Gtest的目标 targers: gtest, gtest_main, gmock, gmock_main
        add_subdirectory(
            ${googletest_SOURCE_DIR}
            ${googletest_BINARY_DIR}
        )

        # Windows下静默std::tr1报错
        if(MSVC)
            foreach(_tgt gtest gtest_main gmock gmock_main)
                target_compile_definitions(${_tgt}
                    PRIVATE
                    "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
                )
            endforeach()
        endif()
    endif()

    # 测试目标
    add_executable(testServerString test/testServerString.cpp)
    add_executable(testServerTime test/testServerTime.cpp)

    target_include_directories(testServerString PRIVATE include)
    target_include_directories(testServerTime PRIVATE include)

    target_link_libraries(testServerString PRIVATE gtest_main SimpleServer)
    target_link_libraries(testServerTime PRIVATE gtest_main SimpleServer)

    enable_testing()

    add_test(NAME ServerString COMMAND $<TARGET_FILE:testServerString>)
    add_test(NAME ServerTime COMMAND $<TARGET_FILE:testServerTime>)
endif()