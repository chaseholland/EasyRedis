cmake_minimum_required (VERSION 2.8)
project(EasyRedisTests)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#enable c++ 11
SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

#add gtest
if (NOT TARGET gtest_main)
add_subdirectory(gtest)
endif()

include_directories(${gtest_SOURCE_DIR}/include)

#the actual source directory
include_directories(..)

#add files with new test here
set (test_sources
    test_easyredis.cpp
    test_easyredis_fixture.h
    test_easyredisreply.cpp
)

add_executable(easyredistests ${test_sources})
target_link_libraries(easyredistests gtest_main easyredis hiredis)