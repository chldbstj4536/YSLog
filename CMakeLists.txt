cmake_minimum_required(VERSION 3.25)

project(YSLog
    LANGUAGES CXX)

# 외부 프로젝트 설치
execute_process(COMMAND ${CMAKE_COMMAND} -S ${CMAKE_CURRENT_SOURCE_DIR}/submodules/YSDefine -B ${CMAKE_CURRENT_BINARY_DIR}/build -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
execute_process(COMMAND ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR}/build --target install)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(ysLog ysLog.cpp)

target_include_directories(ysLog
    PUBLIC ./out/inc)

# 설치 관련 설정
install(FILES       ysLog.hpp
    DESTINATION ${CMAKE_INSTALL_PREFIX}/inc)
install(TARGETS     ysLog
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)