1. 配置阶段（configure）

   ```
   cmake -B {DIR}
   ```

   在\build目录下生成本地项目文件（Linux的Makefile、Windows的.sln）
2. 构建阶段（build）

   ```
   cmake --build {DIR}
   ```

   调用编译器编译代码。

配置阶段可通过-D?设置缓存变量。下次配置时缓存变量仍会被保留。

设置安装路径

```
cmake -B {DIR} -DCMAKE_INSTALL_PREFIX=/opt/
```

设置构建模式

```
cmake -B {DIR} -DCAMKE_BUILD_TYPE=Release
```

    Windows

```
cmake --build {DIR} --config Release
```
