cmake_minimum_required(VERSION 3.16)
project(gmd5hash)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_BUILD_TYPE DEBUG)
add_library(gmd5hash STATIC gmd5hash.cpp gmd5hash.h)
target_link_libraries(gmd5hash ssl crypto)