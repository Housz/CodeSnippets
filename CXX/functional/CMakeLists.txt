cmake_minimum_required(VERSION 3.26)

project(functional)
add_executable(main)

file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)

target_sources(main PUBLIC ${sources})