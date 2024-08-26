// solution link - https://usaco.guide/problems/cses-1082-sum-of-divisors/solution
// video -  https://www.youtube.com/watch?v=JqWiWJQOQyU&t=767s

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

// Function to calculate sum from a to b modulo mod
long long sumFromAtoB(long long a, long long b) {
    long long n = (b - a + 1) % MOD;  // Number of terms in the sequence
    long long sum = (a + b) % MOD;    // Sum of the first and last term
    sum = (sum * n) % MOD;            // Multiply by the number of terms
    sum = (sum * TWO_MOD_INV) % MOD;  // Multiply by the modular inverse of 2 modulo 1000000007
                                      // (500000004 is precomputed mod inverse of 2)
    return sum;
}

// we are applying the formula
// for sum of a to b
// (b-a+1) * (a+b) / 2

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long x;
    cin >> x;
    long long total = 0;
    for (long long i = 1; i <= x;) {
        long long quotient = x / i;
        long long next_i = x / quotient + 1;
        long long add = (quotient % MOD) * sumFromAtoB(i, next_i - 1) % MOD;
        total = (total + add) % MOD;
        i = next_i;
    }
    cout << total << endl;
}