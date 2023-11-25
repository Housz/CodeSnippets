cmake_minimum_required(VERSION 3.15)

add_executable(testThread)

file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)

target_sources(testThread PUBLIC ${sources})