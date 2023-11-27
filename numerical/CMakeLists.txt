find_package(Eigen3 REQUIRED)

add_executable(testeigen test_eigen.cpp)
target_link_libraries(testeigen PUBLIC Eigen3::Eigen)


