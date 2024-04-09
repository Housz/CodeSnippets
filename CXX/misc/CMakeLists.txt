cmake_minimum_required(VERSION 3.15)

project(misc)
add_executable(main)

file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)

target_sources(main PUBLIC ${sources})