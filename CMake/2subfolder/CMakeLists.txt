cmake_minimum_required(VERSION 3.15)
project(helloproj)

add_executable(hello)

aux_source_directory(. sources) # . 当前目录
aux_source_directory(mylib sources) # mylib目录
# aux_source_directory({dir}, {Source variable})
# aux_source_directory 会根据当前语言自动匹配源码

target_sources(hello PUBLIC ${sources})
