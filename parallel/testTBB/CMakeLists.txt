find_package(TBB REQUIRED)

add_executable(testparallel test_parallel_for.cpp)
target_link_libraries(testparallel PUBLIC TBB::tbb)

add_executable(testinvoke test_invoke.cpp)
target_link_libraries(testinvoke PUBLIC TBB::tbb)

add_executable(testparallelforeach test_parallel_for_each.cpp)
target_link_libraries(testparallelforeach PUBLIC TBB::tbb)

add_executable(testparallelreduce test_parallel_reduce.cpp)
target_link_libraries(testparallelreduce PUBLIC TBB::tbb)