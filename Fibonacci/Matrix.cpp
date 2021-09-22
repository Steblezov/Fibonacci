#include "Matrix.h"

Matrix Matrix::e() {
    return Matrix(1, 0, 0, 1);
}

Matrix::Matrix (unsigned long long a_, unsigned long long b_, unsigned long long c_, unsigned long long d_) {
    a[0][0] = a_;
    a[0][1] = b_;
    a[1][0] = c_;
    a[1][1] = d_;
}

std::ostream& operator<<(std::ostream& os, const Matrix& a) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            os << a.a[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

Matrix operator*(const Matrix& a, int k) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c.a[i][j] += a.a[i][j] * k;
        }
    }
    return c;
}

Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int h = 0; h < 2; ++h) {
                c.a[i][j] += a.a[i][h] * b.a[h][j];
            }
        }
    }

    return c;
}

Matrix operator*(int k, const Matrix& a) {
    return a * k;
}

Matrix operator+(const Matrix& a, const Matrix& b) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c.a[i][j] = a.a[i][j] + b.a[i][j];
        }
    }
    return c;
}

std::istream& operator>>(std::istream& is, Matrix& a) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            is >> a.a[i][j];
        }
    }
    return is;
}

