/*
 * lib_testing.hpp
 *
 *  Created on: May 9, 2022
 *      Author: d-w-h
 */

#ifndef LIB_TESTING_HPP_
#define LIB_TESTING_HPP_


#include "user_types.hpp"

i_real_matrix inv_ref(const i_real_matrix &matG, const bool usePermute);

void showMatrix(const i_real_matrix &matG, const char *describe, bool matlabFormat);


#endif /* LIB_TESTING_HPP_ */
