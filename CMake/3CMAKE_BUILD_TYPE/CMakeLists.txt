cmake_minimum_required(VERSION 3.15)
project(helloproj)

# set(CMAKE_BUILD_TYPE Debug) # 调试（默认）
set(CMAKE_BUILD_TYPE Release) # 发布
# set(CMAKE_BUILD_TYPE MinSizeRel) # 最小体积
# set(CMAKE_BUILD_TYPE RelWithDebInfo) # 带调试信息发布

add_executable(hello)

aux_source_directory(. sources) # . 当前目录
aux_source_directory(mylib sources) # mylib目录

target_sources(hello PUBLIC ${sources})

