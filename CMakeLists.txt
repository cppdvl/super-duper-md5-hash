cmake_minimum_required(VERSION 3.16)
project(gmd5hash)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_BUILD_TYPE DEBUG)
add_library(gmd5hash STATIC gmd5hash.cpp gmd5hash.h)
include(FetchContent)
if (WIN32)
    message(STATUS "Extracting mingw32 specific libs")
    FetchContent_Declare(mman
            GIT_REPOSITORY https://github.com/cppdvl/mman-win32.git
            GIT_TAG 0.0.1)
    FetchContent_GetProperties(mman)

    if(NOT mman_POPULATED)
        FetchContent_Populate(mman)
        add_subdirectory(${mman_SOURCE_DIR} ${mman_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()



target_link_libraries(gmd5hash ssl crypto)
if (WIN32)
	target_include_directories(gmd5hash PUBLIC ${mman_SOURCE_DIR})
	target_link_libraries(gmd5hash ${mman_BINARY_DIR}/mman)
endif()

