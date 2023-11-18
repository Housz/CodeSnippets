静态库（win：main.exe + mylib.lib）（Linux：main + mylib.a）

```
add_library(mylib STATIC foo.cpp)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC mylib)
```

动态库（win：main.exe + mylib.dll）（Linux：main + mylib.so）

```
add_library(mylib SHARED foo.cpp)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC mylib)
```

对象库（只有main.exe）

```
add_library(mylib OBJECT foo.cpp)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC mylib)
```


add_library(mylib 参数 foo.cpp)

参数不设置，根据 set(BUILD_SHARED_LIBS ON) 确定，不设置默认为OFF
