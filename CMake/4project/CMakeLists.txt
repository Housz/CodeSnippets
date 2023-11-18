cmake_minimum_required(VERSION 3.15)
project(hellocmake)
# project 初始化项目信息，
# 并把当前CMakeLists.txt所在位置作为根目录
# 对于MSVC，会生成 hellocmake.sln 作为VS里的项目

message("PROJECT_NAME": ${PROJECT_NAME})
message("PROJECT_SOURCE_DIR": ${PROJECT_SOURCE_DIR})
message("PROJECT_BINARY_DIR": ${PROJECT_BINARY_DIR})
message("CMAKE_CURRENT_SOURCE_DIR": ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_CURRENT_BINARY_DIR": ${CMAKE_CURRENT_BINARY_DIR})

# 输出：
# PROJECT_NAME:hellocmake

# PROJECT_SOURCE_DIR:D:/Projects/LearnCMake/LearnCMake/4project
# PROJECT_BINARY_DIR:D:/Projects/LearnCMake/LearnCMake/4project/build
# CMAKE_CURRENT_SOURCE_DIR:D:/Projects/LearnCMake/LearnCMake/4project
# CMAKE_CURRENT_BINARY_DIR:D:/Projects/LearnCMake/LearnCMake/4project/build

# 涉及到子模块时，
# PROJECT_SOURCE_DIR，PROJECT_BINARY_DIR 和 
# CMAKE_CURRENT_SOURCE_DIR，CMAKE_CURRENT_BINARY_DIR 不同

# PROJECT_SOURCE_DIR 表示最近一次调用project的CMakeLists.txt所在的源码目录
# （如当前CMakeLists.txt无project指令，当前的上一层有project指令，则输出上一层的目录
# CMAKE_CURRENT_SOURCE_DIR 表示当前CMakeLists.txt所在的源码目录

# CMAKE_SOURCE_DIR 最外层目录，会让该项目无法作为子模块被使用

# PROJECT_IS_TOP_LEVEL BOOL类型，当前项目是否为最顶层

add_executable(main main.cpp)
# hellocmake解决方案（solution） 下的 main 项目（project）
