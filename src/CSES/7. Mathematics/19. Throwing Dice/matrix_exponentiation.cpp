// video - https://www.youtube.com/watch?v=44I5WoLUWbY

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Matrix multiplication function
vector<vector<long long>> multiply(vector<vector<long long>> &A, vector<vector<long long>> &B) {
    int size = A.size();
    vector<vector<long long>> C(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Matrix exponentiation function
vector<vector<long long>> matrixExponentiation(vector<vector<long long>> &A, long long power) {
    int size = A.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) {
        result[i][i] = 1;  // Initialize the identity matrix
    }
    while (power) {
        if (power % 2) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        power /= 2;
    }
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;

    if (n <= 6) {
        // Base case: for small n, you can directly count the number of ways
        cout << (1LL << (n - 1)) << endl;  // 2^(n-1) for n <= 6
        return 0;
    }

    // Initial DP states (dp[1] to dp[6])
    vector<long long> dp = {32, 16, 8, 4, 2, 1};

    // Transformation matrix based on the recurrence relation
    vector<vector<long long>> T = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}};

    // Exponentiate the transformation matrix to the power (n-6)
    vector<vector<long long>> T_n_minus_6 = matrixExponentiation(T, n - 6);

    // Calculate dp[n] by multiplying the matrix with the base dp vector
    long long result = 0;
    for (int i = 0; i < 6; i++) {
        result = (result + T_n_minus_6[0][i] * dp[i]) % MOD;
    }

    cout << result << endl;

    return 0;
}