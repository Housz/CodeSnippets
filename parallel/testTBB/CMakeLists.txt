find_package(TBB REQUIRED)

add_executable(testparallel test_parallel_for.cpp)
target_link_libraries(testparallel PUBLIC TBB::tbb)

add_executable(testinvoke test_invoke.cpp)
target_link_libraries(testinvoke PUBLIC TBB::tbb)

