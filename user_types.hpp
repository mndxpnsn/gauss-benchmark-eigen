/*
 * user_types.hpp
 *
 *  Created on: May 7, 2022
 *      Author: d-w-h
 */

#ifndef USER_TYPES_HPP_
#define USER_TYPES_HPP_

#include <vector>

#include "Eigen/LU"

const int MAX_INT = 1215752192;
const double SMALL_NUM = 1e-10;

using Eigen::Inverse;
using Eigen::MatrixXd;

typedef struct order_array_elem {
    int old_row;
    double val;
} oa_elem_t;

using i_float_t = double; // using i_float_t = float; // Notice: Do NOT use int type!
using i_real_vector = std::vector<i_float_t>;
using i_real_matrix = std::vector<i_real_vector>;


#endif /* USER_TYPES_HPP_ */
