/* ----------------------------------------------------------------------------
 * Copyright 2022, Tingjun Li, Ross Hartley
 * All Rights Reserved
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 *  @file   base_propagation.h
 *  @author Tingjun Li, Ross Hartley
 *  @brief  Header file for Invariant EKF base propagation method
 *  @date   November 25, 2022
 **/

#ifndef FILTER_BASE_PROPAGATION_H
#define FILTER_BASE_PROPAGATION_H
#include <Eigen/Dense>
#include <algorithm>
#include <boost/circular_buffer.hpp>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include "filter/noise_params.h"
#include "state/robot_state.h"


class Propagation {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  /// @name Constructors
  /// @{
  // ======================================================================
  /**
   * @brief Constructor for the propagation class
   *
   * @param[in] params: The noise parameter for propagation
   * @param[in] error_type: Error type for the propagation. LeftInvariant or
   * RightInvariant
   */
  /// @}
  Propagation(const NoiseParams& params, const bool estimate_bias);

  /// @name Propagation
  /// @{
  // ======================================================================
  /**
   * @brief This is a skeleton for the propagation method. It should be
   * implemented in the child class.
   *
   * @param[in/out] state: The current state of the robot
   * @param[in] dt: The time step for the propagation
   */
  virtual void Propagate(RobotState& state, double dt);
  /// @}

  /// @name Getters
  /// @{
  // ======================================================================
  /**
   * @brief Gets the current noise parameters.
   *
   * @return inekf::NoiseParams: The current noise parameters.
   */
  const NoiseParams get_noise_params() const;
  /// @}

 protected:
  const NoiseParams noise_params_;
  const Eigen::Vector3d g_;    // Gravity vector in world frame (z-up)
  Eigen::Vector3d
      magnetic_field_;          // Magnetic field vector in world frame (z-up)
  const bool estimate_bias_;    // Whether to estimate the gyro and
                                // accelerometer biases
};                              // End of class Propagation


// #include "../src/filter/base_propagation.cpp"
#endif    // FILTER_BASE_PROPAGATION_H