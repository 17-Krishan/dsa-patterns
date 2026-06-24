#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

/*
Computes a^b % MOD
Time: O(log b)
*/

long long modPow(long long a, long long b) {

    long long res = 1;

    a %= MOD;

    while (b) {

        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main() {

    cout << modPow(2, 100) << '\n';

    return 0;
}