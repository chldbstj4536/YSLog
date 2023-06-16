cmake_minimum_required(VERSION 3.25)

project(YSLogTest
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(YSLogTest main.cpp)

# ysLog.hpp 파일 포함
target_include_directories(YSLogTest
    PUBLIC ./..)

# VS 시작프로젝트 설정
if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT YSLogTest)
endif()