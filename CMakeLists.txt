cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME KINI)
project(${PROJECT_NAME})

include_directories(./)
include_directories(include)
file(GLOB SOURCES "src/*.tpp")

if(test)
 add_subdirectory(libs/gtest-1.6.0)
 enable_testing()
 include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

 file(GLOB SOURCES_TEST "tests/*.cpp") 
 add_executable(RangeMinimumQueryTest ${SOURCES_TEST})
 target_link_libraries(RangeMinimumQueryTest gtest gtest_main)
endif()
