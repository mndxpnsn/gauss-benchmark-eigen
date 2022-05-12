/*
 * lib_mat.hpp
 *
 *  Created on: May 7, 2022
 *      Author: d-w-h
 */

#ifndef LIB_MAT_HPP_
#define LIB_MAT_HPP_

#include "lib_testing.hpp"
#include "lib_testing_ref.hpp"
#include "user_types.hpp"

void init_mat(int n, double ** mat);
void init_vec2D(double ** mat, int n, i_real_matrix & mat_inv);
void set_mat_to_matrix(double ** mat, int n, matrix & m);
void set_mat_to_matxd(double ** mat, int n, MatrixXd & mat_out);
void set_mat(double ** mat, int n, double ** mat_store);
void print_mat(double ** mat, int n);
void print_matxd(MatrixXd mat, int n);
void mat_mult_sq(double ** A, double ** A_inv, int n, double ** mat_res);


#endif /* LIB_MAT_HPP_ */
