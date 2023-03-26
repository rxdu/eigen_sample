/* 
 * pose_representation.cpp
 *
 * Created on 3/26/23 11:53 PM
 * Description:
 *
 * Copyright (c) 2023 Ruixiang Du (rdu)
 */

#include <iostream>

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

int main(int argc, char *argv[]) {
  Eigen::Vector2d p2d(1.0, 2.0);
  std::cout << "A point in 2d: \n" << p2d << std::endl;

  Eigen::Vector3d p3d(1.0, 2.0, 3.0);
  std::cout << "A point in 3d: \n" << p3d << std::endl;

  Eigen::Matrix3d R;
  R << 0, -1, 0, 1, 0, 0, 0, 0, 1;
  std::cout << "A rotation matrix: \n" << R << std::endl;

  Eigen::Quaterniond q_from_R(R);
  std::cout << "A quaternion from rotation matrix: \n" << q_from_R.coeffs() << std::endl;

  Eigen::Quaterniond q_unit = Eigen::Quaterniond::Identity();
  std::cout << "A unit quaternion: \n" << q_unit.coeffs() << std::endl;

  Eigen::Quaterniond q(2, 0, 1, -3);
  std::cout << "A non-normalized quaternion: \n" << q.coeffs() << std::endl;

  q.normalize();
  std::cout << "A normalized quaternion: \n" << q.w() << std::endl << q.vec() << std::endl;

  Eigen::Matrix3d R_from_q = q.toRotationMatrix();
  std::cout << "A rotation matrix from quaternion: \n" << R_from_q << std::endl;

  Eigen::Matrix3f R_from_angleaxis;
  R_from_angleaxis = Eigen::AngleAxisf(0.25 * M_PI, Eigen::Vector3f::UnitX())
      * Eigen::AngleAxisf(0.5 * M_PI, Eigen::Vector3f::UnitY())
      * Eigen::AngleAxisf(0.33 * M_PI, Eigen::Vector3f::UnitZ());
  std::cout << "A rotation matrix from angle-axis: \n" << R_from_angleaxis << std::endl;

  Eigen::Quaternionf q_from_angleaxis(Eigen::AngleAxisf(0.33 * M_PI, Eigen::Vector3f::UnitZ()));
  std::cout << "A quaternion from angle-axis: \n" << q_from_angleaxis.coeffs() << std::endl;

  return 0;
}