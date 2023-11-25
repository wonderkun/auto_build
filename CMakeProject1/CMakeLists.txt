# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.7)
PROJECT(CMakeProject1 CXX)
# 将源代码添加到此项目的可执行文件。
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/hello/ ${CMAKE_CURRENT_SOURCE_DIR})


# 添加变量支持
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_env/")
include(res_var)

set(RES_PATH "${CMAKE_BINARY_DIR}/VersionInfo.rc")
configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.rc.in" ${RES_PATH} )


add_executable (CMakeProject1 "CMakeProject1.cpp" ${RES_PATH})
# TARGET_LINK_LIBRARIES(CMakeProject1 hello)