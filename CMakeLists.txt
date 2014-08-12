cmake_minimum_required (VERSION 2.8.4)
project (CXXEXP CXX C)
set (CMAKE_VERBOSE_MAKEFILE true)

set (CXXEXP_OUT_DIR ${CXXEXP_SOURCE_DIR}/binary)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CXXEXP_OUT_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CXXEXP_OUT_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CXXEXP_OUT_DIR}/lib)

set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

add_subdirectory (third-party)

set (CXXEXP_THIRD_PARTY_DIR ${CXXEXP_SOURCE_DIR}/third-party)
include_directories (${CXXEXP_THIRD_PARTY_DIR}/src/boost_1_56_0)
include_directories (${CXXEXP_THIRD_PARTY_DIR}/src/libevent-2.0.21-stable/include)
include_directories (${CXXEXP_THIRD_PARTY_DIR}/src/gflags-2.1.1/include)
include_directories (${CXXEXP_THIRD_PARTY_DIR}/src/glog-0.3.3/include)
include_directories (${CXXEXP_THIRD_PARTY_DIR}/src/gtest-1.7.0/include)

link_directories (${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
link_directories (${CXXEXP_THIRD_PARTY_DIR}/lib)
add_subdirectory (topics)
