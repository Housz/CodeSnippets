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

