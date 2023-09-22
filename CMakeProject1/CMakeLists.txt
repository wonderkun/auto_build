# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.7)
PROJECT(CMakeProject1 CXX)
# 将源代码添加到此项目的可执行文件。
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/hello/)


set(RES_PATH "VersionInfo.rc")
set(ICON_PATH "icon1.ico")
set(COMPANY_NAME "qihu360 kaka kill")
set(FILE_DESC "qihu360 kaka kill browser.exe")
set(FILE_DESC "360browser.exe")
configure_file( "${CMAKE_SOURCE_DIR}/VersionInfo.rc.in" ${RES_PATH} )


add_executable (CMakeProject1 "CMakeProject1.cpp" ${RES_PATH})
TARGET_LINK_LIBRARIES(CMakeProject1 hello)