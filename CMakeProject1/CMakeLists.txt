# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.7)
PROJECT(CMakeProject1 CXX)
# 将源代码添加到此项目的可执行文件。
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/hello/ ${CMAKE_CURRENT_SOURCE_DIR})

set(RES_PATH "${CMAKE_BINARY_DIR}/VersionInfo.rc")

set(ICON_PATH "svip.ico")

set(COMPANY_NAME "qihu360 Protecter")
set(FILE_DESC "qihu360 windows 360manageer.exe")
set(FiLE_NAME "360manageer.exe")
set(PRODUCT_NAME "qihu360 Microsoft Windows Operating System")
configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.rc.in" ${RES_PATH} )

add_executable (CMakeProject1 "CMakeProject1.cpp" ${RES_PATH})
# TARGET_LINK_LIBRARIES(CMakeProject1 hello)