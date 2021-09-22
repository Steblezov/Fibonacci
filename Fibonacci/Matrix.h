#pragma once
#include <iostream>
struct Matrix {
    unsigned long long a[2][2];

    Matrix(unsigned long long a_ = 0, unsigned long long b_ = 0, unsigned long long c_ = 0, unsigned long long d_ = 0);

    static Matrix e();
};

std::ostream& operator<<(std::ostream& os, const Matrix& a);

Matrix operator*(const Matrix& a, int k);

Matrix operator*(const Matrix& a, const Matrix& b);


Matrix operator*(int k, const Matrix& a);

Matrix operator+(const Matrix& a, const Matrix& b);

std::istream& operator>>(std::istream& is, Matrix& a);