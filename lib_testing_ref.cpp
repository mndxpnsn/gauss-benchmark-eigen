/*
 * lib_testing_ref.cpp
 *
 * The code below was obtained from:
 * https://rosettacode.org/wiki/Gauss-Jordan_matrix_inversion#C.2B.2B
 */

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>

#include "lib_testing_ref.hpp"

matrix product(const matrix& a, const matrix& b) {
    assert(a.columns() == b.rows());
    size_t arows = a.rows();
    size_t bcolumns = b.columns();
    size_t n = a.columns();
    matrix c(arows, bcolumns);
    for (size_t i = 0; i < arows; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < bcolumns; ++k)
                c(i, k) += a(i, j) * b(j, k);
        }
    }
    return c;
}

void swap_rows(matrix & m, size_t i, size_t j) {
    size_t columns = m.columns();
    for (size_t column = 0; column < columns; ++column) {
        double tmp = m(i, column);
        m(i, column) = m(j, column);
        m(j, column) = tmp;
    }
}

// Convert matrix to reduced row echelon form
void rref(matrix & m) {
    size_t rows = m.rows();
    size_t columns = m.columns();
    for (size_t row = 0, lead = 0; row < rows && lead < columns; ++row, ++lead) {
        size_t i = row;
        while (m(i, lead) == 0) {
            if (++i == rows) {
                i = row;
                if (++lead == columns)
                    return;
            }
        }
        swap_rows(m, i, row);
        if (m(row, lead) != 0) {
            double f = m(row, lead);
            for (size_t column = 0; column < columns; ++column)
                m(row, column) /= f;
        }
        for (size_t j = 0; j < rows; ++j) {
            if (j == row)
                continue;
            double f = m(j, lead);
            for (size_t column = 0; column < columns; ++column)
                m(j, column) -= f * m(row, column);
        }
    }
}

matrix inverse(const matrix & m) {
    assert(m.rows() == m.columns());
    size_t rows = m.rows();
    matrix tmp(rows, 2 * rows);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < rows; ++column)
            tmp(row, column) = m(row, column);
        tmp(row, row + rows) = 1;
    }
    rref(tmp);
    matrix inv(rows, rows);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < rows; ++column)
            inv(row, column) = tmp(row, column + rows);
    }
    return inv;
}

void print(std::ostream& out, const matrix & m) {
    size_t rows = m.rows(), columns = m.columns();
    out << std::fixed << std::setprecision(4);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            if (column > 0)
                out << ' ';
            out << std::setw(7) << m(row, column);
        }
        out << '\n';
    }
    out << '\n';
}


