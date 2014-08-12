cmake_minimum_required(VERSION 2.6)
project(CXXEXP)
set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CXXEXP_SOURCE_DIR}/binary)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CXXEXP_SOURCE_DIR}/binary)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CXXEXP_SOURCE_DIR}/binary)

include_directories(${CXXEXP_SOURCE_DIR}/third-party/include)
add_subdirectory(topics)
