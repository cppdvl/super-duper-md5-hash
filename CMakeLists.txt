cmake_minimum_required(VERSION 3.16)
project(gmd5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
add_library(gmd5 STATIC gdm5hash.cpp gdm5hash.h)
target_link_libraries(gmd5 ssl crypto)