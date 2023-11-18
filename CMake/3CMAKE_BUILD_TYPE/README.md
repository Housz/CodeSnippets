set(CMAKE_BUILD_TYPE Debug) # 调试（默认）

相当于 `-O0 -g`

set(CMAKE_BUILD_TYPE Release) # 发布

相当于 `-O3 -DNDEBUG`

set(CMAKE_BUILD_TYPE MinSizeRel) # 最小体积

相当于 `-Os -DNDEBUG`

set(CMAKE_BUILD_TYPE RelWithDebInfo) # 带调试信息发布

相当于 `-O2 -g -DNDEBUG`


不设置CMAKE_BUILD_TYPE，CMake认为CMAKE_BUILD_TYPE为空字符串，默认为Debug模式。

改为默认Release：

```
if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE Release)
endif()
```
