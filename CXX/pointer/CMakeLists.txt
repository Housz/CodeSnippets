cmake_minimum_required(VERSION 3.15)

project(pointer)
add_executable(test)

file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)

target_sources(test PUBLIC ${sources})