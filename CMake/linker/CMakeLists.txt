cmake_minimum_required(VERSION 3.15)
project(helloproj)

add_executable(hello)
set(sources main.cpp foo.cpp)
target_sources(hello PUBLIC ${sources})