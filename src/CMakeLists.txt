find_package(Eigen3 REQUIRED NO_MODULE)

add_executable(pose_representation pose_representation.cpp)
target_link_libraries(pose_representation Eigen3::Eigen)