cmake_minimum_required(VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)

find_package(TBB REQUIRED)
find_package(benchmark REQUIRED)

add_executable(testfor test_for.cpp)
target_link_libraries(testfor PUBLIC TBB::tbb)


add_executable(bmfor bm_for.cpp)
target_link_libraries(bmfor PUBLIC TBB::tbb benchmark::benchmark)

add_executable(bmfornd bm_for_nd.cpp)
target_link_libraries(bmfornd PUBLIC TBB::tbb benchmark::benchmark)

add_executable(bmfor3d bm_for_3d.cpp)
target_link_libraries(bmfor3d PUBLIC TBB::tbb benchmark::benchmark)

add_executable(bmfor2d bm_for_2d.cpp)
target_link_libraries(bmfor2d PUBLIC TBB::tbb benchmark::benchmark)