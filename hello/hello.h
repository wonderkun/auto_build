#ifndef HELLO_H
#define HELLO_H

#include <iostream>

#define MY_LIB_API __declspec(dllexport)

extern "C" MY_LIB_API void SayHello();
#endif
