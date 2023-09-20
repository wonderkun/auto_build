cmake_minimum_required (VERSION 3.7)

PROJECT(hello CXX)
# 将源代码添加到此项目的可执行文件。
add_library(hello SHARED "hello.cpp")
