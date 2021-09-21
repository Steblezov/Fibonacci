#include <cmath>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Matrix {
    unsigned long long a[2][2];
    Matrix(unsigned long long a_ = 0, unsigned long long b_ = 0, unsigned long long c_ = 0, unsigned long long d_ = 0) {
        a[0][0] = a_;
        a[0][1] = b_;
        a[1][0] = c_;
        a[1][1] = d_;
    }
    static Matrix e() {
        return Matrix(1, 0, 0, 1);
    }
};
struct Vector {
    unsigned long long a[2];

    Vector(unsigned long long x_ = 0, unsigned long long y_ = 0) {
        a[0] = x_;
        a[1] = y_;
    }
    Vector(Matrix& b) {
        a[0] = b.a[0][0];
        a[1] = b.a[1][0];
    }
    static Vector i() {
        return Vector(1, 0);
    }
};

ostream& operator<<(ostream& os, const Vector& a) {
    for (int i = 0; i < 2; ++i) {
        os << a.a[i] << " ";
    }
    return os;
}

ostream& operator<<(ostream& os, const Matrix& a) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            os << a.a[i][j] << " ";
        }
        os << endl;
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

Matrix operator+(const Matrix& a, const Matrix& b) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c.a[i][j] = a.a[i][j] + b.a[i][j];
        }
    }
    return c;
}

istream& operator>>(istream& is, Matrix& a) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            is >> a.a[i][j];
        }
    }
    return is;
}

istream& operator>>(istream& is, Vector& a) {
    for (int i = 0; i < 2; ++i) {
        is >> a.a[i];
    }
    return is;
}
Matrix  cd(Matrix a, int n) {
    if (n == 0)
        return a.e();
    Matrix res = cd(a, n / 2);
    res = res * res;
    if (n % 2) {
        res = res * a;
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    Matrix a(1, 1, 1, 0);
    Matrix c = cd(a, n - 1);
    Vector b(1, 1);
    Vector answer = c * b;
    cout << answer.a[0];
}