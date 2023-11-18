cmake_minimum_required(VERSION 3.15)
project(helloproj)

add_executable(hello)
# set(sources main.cpp foo.cpp foo.h)
file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)
target_sources(hello PUBLIC ${sources})