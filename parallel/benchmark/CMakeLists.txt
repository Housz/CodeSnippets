cmake_minimum_required(VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)

find_package(TBB REQUIRED)

add_executable(testfor test_for.cpp)
target_link_libraries(testfor PUBLIC TBB::tbb)