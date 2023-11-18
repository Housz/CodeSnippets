cmake_minimum_required(VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project( myproj LANGUAGES C CXX )

# 如果build目录和源码目录一样
if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
	message(WARNING "The binary directory of CMake cannot be the same as source directory!")
endif()

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)	
endif()

# win平台防止std::min std::max被覆盖
if (WIN32)
	add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

# 编译缓存，加速编译
if (NOT MSVC)
	find_program(CCACHE_PROGRAM ccache)
	if (CCACHE PROGRAM)
		message(STATUS "Found CCache: sCCACHE_PROGRAM]")
		set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
		set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
	endif()
endif()

# #############################################

# 静态库（win：main.exe + mylib.lib）（Linux：main + mylib.a）

# add_library(mylib STATIC foo.cpp)

# add_executable(main main.cpp)

# target_link_libraries(main PUBLIC mylib)（Linux：main + mylib.so）

# #############################################


# #############################################

# 动态库（win：main.exe + mylib.dll）

# add_library(mylib SHARED foo.cpp)

# add_executable(main main.cpp)

# target_link_libraries(main PUBLIC mylib)

# #############################################



# #############################################

# 对象库（只有main.exe）

add_library(mylib OBJECT foo.cpp)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC mylib)

# #############################################
