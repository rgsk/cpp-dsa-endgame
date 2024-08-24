#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to multiply two 2x2 matrices under modulo
void multiply(long long F[2][2], long long M[2][2]) {
    long long x = (F[0][0] * M[0][0] % MOD + F[0][1] * M[1][0] % MOD) % MOD;
    long long y = (F[0][0] * M[0][1] % MOD + F[0][1] * M[1][1] % MOD) % MOD;
    long long z = (F[1][0] * M[0][0] % MOD + F[1][1] * M[1][0] % MOD) % MOD;
    long long w = (F[1][0] * M[0][1] % MOD + F[1][1] * M[1][1] % MOD) % MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// Function to raise the matrix to the power n using exponentiation by squaring
void power(long long F[2][2], long long n) {
    if (n == 0 || n == 1) return;

    long long M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0) multiply(F, M);
}

// Function to find the nth Fibonacci number
long long fibonacci(long long n) {
    if (n == 0) return 0;

    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);

    return F[0][0];
}

// matrix exponentiation method to find nth fibonacci number

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}