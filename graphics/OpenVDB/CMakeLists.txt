cmake_minimum_required(VERSION 3.26)
find_package(OpenVDB CONFIG REQUIRED)

add_executable(helloworld 0helloworld.cpp)
target_link_libraries(helloworld PUBLIC OpenVDB::openvdb)

add_executable(grid 1grid.cpp)
target_link_libraries(grid PUBLIC OpenVDB::openvdb)

add_executable(mygrid 2mygrid.cpp)
target_link_libraries(mygrid PUBLIC OpenVDB::openvdb)