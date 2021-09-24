#pragma once
#include "Matrix.h"
struct Vector {
    unsigned long long a[2];

    Vector(unsigned long long x_ = 0, unsigned long long y_ = 0);

    Vector(Matrix& b);

    static Vector i();
};

std::ostream& operator<<(std::ostream& os, const Vector& a);

Vector operator*(const Matrix& a, const Vector& b);

std::istream& operator>>(std::istream& is, Vector& a);