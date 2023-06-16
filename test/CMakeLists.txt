cmake_minimum_required(VERSION 3.25)

project(YSLogTest
    LANGUAGES CXX)

# 외부 프로젝트 설치
execute_process(COMMAND ${CMAKE_COMMAND} -S ./.. -B ./../build -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
execute_process(COMMAND ${CMAKE_COMMAND} --build ./../build --target install)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ysLogTest main.cpp)

# 타겟에 설치된 라이브러리 추가
target_include_directories(ysLogTest
    PUBLIC ${CMAKE_INSTALL_PREFIX}/inc)
target_link_libraries(ysLogTest
    PUBLIC ${CMAKE_INSTALL_PREFIX}/lib/ysLog.lib)

# VS 시작프로젝트 설정
if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ysLogTest)
endif()