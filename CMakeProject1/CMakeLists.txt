# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.7)
PROJECT(CMakeProject1 CXX)
# 将源代码添加到此项目的可执行文件。
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/hello/)
add_executable (CMakeProject1 "CMakeProject1.cpp")
TARGET_LINK_LIBRARIES(CMakeProject1 hello)