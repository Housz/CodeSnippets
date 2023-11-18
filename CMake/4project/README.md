# project

```
project(hellocmake)
```

project 初始化项目信息，

并把当前CMakeLists.txt所在位置作为根目录

对于MSVC，会生成 hellocmake.sln 作为VS里的项目

```
message("PROJECT_NAME": ${PROJECT_NAME})message("PROJECT_SOURCE_DIR": ${PROJECT_SOURCE_DIR})message("PROJECT_BINARY_DIR": ${PROJECT_BINARY_DIR})message("CMAKE_CURRENT_SOURCE_DIR": ${CMAKE_CURRENT_SOURCE_DIR})message("CMAKE_CURRENT_BINARY_DIR": ${CMAKE_CURRENT_BINARY_DIR})
```

输出：

PROJECT_NAME:hellocmake

PROJECT_SOURCE_DIR:D:/Projects/LearnCMake/LearnCMake/4project

PROJECT_BINARY_DIR:D:/Projects/LearnCMake/LearnCMake/4project/build

CMAKE_CURRENT_SOURCE_DIR:D:/Projects/LearnCMake/LearnCMake/4project

CMAKE_CURRENT_BINARY_DIR:D:/Projects/LearnCMake/LearnCMake/4project/build


涉及到子模块时，

`PROJECT_SOURCE_DIR`，`PROJECT_BINARY_DIR `和

`CMAKE_CURRENT_SOURCE_DIR`，`CMAKE_CURRENT_BINARY_DIR `不同

`PROJECT_SOURCE_DIR `表示最近一次调用project的CMakeLists.txt所在的源码目录

（如当前CMakeLists.txt无`project`指令，当前的上一层有`project`指令，则输出上一层的目录

`CMAKE_CURRENT_SOURCE_DIR `表示当前CMakeLists.txt所在的源码目录

`CMAKE_SOURCE_DIR `最外层目录，会让该项目无法作为子模块被使用

---

`PROJECT_IS_TOP_LEVEL `BOOL类型，当前项目是否为最顶层

---

```
add_executable(main main.cpp)
```

hellocmake解决方案（solution） 下的 main 项目（project）

---

# project的`LANGUAGES`字段

project(项目名 `LANGUAGES` `语言` )

C语言：`C`，C++：`CXX`

使用混合C/C++：`project( myproj LANGUAGES C CXX )`

可先设为NONE：`project( myproj LANGUAGES NONE )`

然后用根据情况启用某种语言：`enable_language(CXX)`

---

# project的 `VERSION`字段

project(项目名 `VERSION` `x.y.z` )

主版本号.次版本号.补丁版本号

获取：

${PROJECT_VERSION_MAJOR}

${PROJECT_VERSION_MINOR}

${PROJECT_VERSION_PATCH}

---



# C++标准版本

版本为整数，11，17，23

```
set (CMAKE_CXX_STANDARD 17)
```

`CMAKE_CXX_STANDARD_REQUIRED` 默认为`OFF`，表示CMake检测到编译器不支持该版本C++，自动调低到低版本。`ON`表示不支持则报错。

```
set (CMAKE_CXX_STANDARD_REQUIRED ON)
```

`CMAKE_CXX_EXTENSIONS` ON表示使用编译器特有的特性，通用跨平台代码则用OFF

```
set (CMAKE_CXX_EXTENSIONS ON)
```

这些版本设置一般写在project命令之前，先让CMake进行检测

---

注意不要直接改`CMAKE_CXX_FLAGS`添加`-std=c++17`，这种方法仅用于GCC环境，MSVC不适用。版本要通过CMake封装好的`CMAKE_CXX_STANDARD`来设置。


[CMake常见变量——Project和CMake相关信息 - luoganttcc - 博客园 (cnblogs.com)](https://www.cnblogs.com/luoganttcc/p/16604036.html)
