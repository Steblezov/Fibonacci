#include "Vector.h"

Vector::Vector (unsigned long long x_, unsigned long long y_) {
    a[0] = x_;
    a[1] = y_;
}
Vector::Vector(Matrix& b) {
    a[0] = b.a[0][0];
    a[1] = b.a[1][0];
}

Vector Vector::i() {
    return Vector(1, 0);
}

std::ostream& operator<<(std::ostream& os, const Vector& a) {
    for (int i = 0; i < 2; ++i) {
        os << a.a[i] << " ";
    }
    return os;
}

Vector operator*(const Matrix& a, const Vector& b) {
    Vector c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int h = 0; h < 2; ++h) {
                c.a[i] += a.a[i][h] * b.a[h];
            }
        }
    }
    return c;
}

std::istream& operator>>(std::istream& is, Vector& a) {
    for (int i = 0; i < 2; ++i) {
        is >> a.a[i];
    }
    return is;
}
