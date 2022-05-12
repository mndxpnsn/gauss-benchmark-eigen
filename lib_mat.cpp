/*
 * lib_mat.cpp
 *
 *  Created on: May 7, 2022
 *      Author: d-w-h
 */

#include <math.h>
#include <stdio.h>
#include <time.h>

#include "lib_testing.hpp"
#include "lib_testing_ref.hpp"
#include "user_types.hpp"

double rand_num(double min, double max) {

    double val = (double) rand() / (RAND_MAX + 1.0);

    return val * (max - min) - (max - min) / 2;
}

double rand_di(int min, int max) {

    return rand() % (max - min) + min;
}

void init_mat(int n, double ** mat) {

    srand((unsigned) time(NULL));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            double rand_num_loc = rand_num(-25, 25);
            if(fabs(rand_num_loc) <= SMALL_NUM) { rand_num_loc = 0.0; }
            mat[i][j] = rand_num_loc;
        }
    }
}

void init_vec2D(double ** mat, int n, i_real_matrix & mat_inv) {
    for(int i = 0; i < n; ++i) {
        i_real_vector vec_loc;
        for(int j = 0; j < n; ++j) {
            vec_loc.push_back(mat[i][j]);
        }
        mat_inv.push_back(vec_loc);
    }
}

void set_mat_to_matrix(double ** mat, int n, matrix & m) {

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            m(i, j) = mat[i][j];
        }
    }
}

void set_mat_to_matxd(double ** mat, int n, MatrixXd & mat_out) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            mat_out(i, j) = mat[i][j];
        }
    }
}

void set_mat(double ** mat, int n, double ** mat_store) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            mat_store[i][j] = mat[i][j];
        }
    }
}


void print_mat(double ** mat, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%.5f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_matxd(MatrixXd mat, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%.5f ", mat(i, j));
        }
        printf("\n");
    }
    printf("\n");
}

void mat_mult_sq(double ** A, double ** A_inv, int n, double ** mat_res) {

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            double sum_loc = 0;

            for(int k = 0; k < n; ++k) {
                sum_loc = sum_loc + A[i][k] * A_inv[k][j];
            }

            mat_res[i][j] = sum_loc;
        }
    }
}
