cmake_minimum_required(VERSION 3.26)
find_package(OpenVDB CONFIG REQUIRED)

add_executable(helloworld 0helloworld.cpp)
target_link_libraries(helloworld PUBLIC OpenVDB::openvdb)