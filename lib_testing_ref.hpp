/*
 * lib_testing_ref.hpp
 *
 *  Created on: May 10, 2022
 *      Author: d-w-h
 */

#ifndef LIB_TESTING_REF_HPP_
#define LIB_TESTING_REF_HPP_

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>

#include "user_types.hpp"

class matrix {
public:
    matrix(size_t rows, size_t columns)
        : rows_(rows), columns_(columns), elements_(rows * columns) {}

    size_t rows() const { return rows_; }
    size_t columns() const { return columns_; }

    double & operator()(size_t row, size_t column) {
        assert(row < rows_);
        assert(column < columns_);
        return elements_[row * columns_ + column];
    }
    const double & operator()(size_t row, size_t column) const {
        assert(row < rows_);
        assert(column < columns_);
        return elements_[row * columns_ + column];
    }
private:
    size_t rows_;
    size_t columns_;
    std::vector<double> elements_;
};

matrix inverse(const matrix & m);

void print(std::ostream & out, const matrix & m);

matrix product(const matrix & a, const matrix & b);


#endif /* LIB_TESTING_REF_HPP_ */
