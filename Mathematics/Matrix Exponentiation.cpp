#include <bits/stdc++.h>
using namespace std;

/*
Matrix Exponentiation
Computes nth Fibonacci Number
Time: O(log n)
*/

struct Matrix {

    long long a[2][2];

    Matrix() {
        memset(a, 0, sizeof(a));
    }
};

Matrix multiply(Matrix A, Matrix B) {

    Matrix C;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            for (int k = 0; k < 2; k++) {
                C.a[i][j] += A.a[i][k] * B.a[k][j];
            }
        }
    }

    return C;
}

Matrix power(Matrix M, long long n) {

    Matrix result;

    result.a[0][0] = 1;
    result.a[1][1] = 1;

    while (n) {

        if (n & 1)
            result = multiply(result, M);

        M = multiply(M, M);

        n >>= 1;
    }

    return result;
}

long long fibonacci(long long n) {

    if (n == 0)
        return 0;

    Matrix M;

    M.a[0][0] = 1;
    M.a[0][1] = 1;
    M.a[1][0] = 1;
    M.a[1][1] = 0;

    Matrix R = power(M, n - 1);

    return R.a[0][0];
}

int main() {

    long long n = 10;

    cout << fibonacci(n) << '\n';

    return 0;
}