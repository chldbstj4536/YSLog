cmake_minimum_required(VERSION 3.25)

project(YSLog)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(FILES ysLog.hpp DESTINATION ${CMAKE_INSTALL_PREFIX}/inc)