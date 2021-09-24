#include <cmath>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include "Matrix.h"
#include "Vector.h"

using namespace std;


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