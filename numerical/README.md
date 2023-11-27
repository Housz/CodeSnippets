vcpkg install eigen3:x64-windows

cmake -B build -DCMAKE_TOOLCHAIN_FILE=<vcpkg_path>\scripts\buildsystems\vcpkg.cmake
cmake --build .\build\