#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> digits;
// 10^18 has 19 digits
// we need 19 as first dimension
// 0-9 will be prev_digit
// we are doing prev_digit + 1
// so, we need 11 as second dimension
long long dp[19][11][2][2];  // [pos][prev_digit][tight][leading_zero]

long long countNumbers(int pos, int prev_digit, bool tight, bool leading_zero) {
    if (pos == digits.size()) {
        return 1;  // Successfully formed a valid number
    }

    if (dp[pos][prev_digit + 1][tight][leading_zero] != -1) {
        return dp[pos][prev_digit + 1][tight][leading_zero];
    }

    int limit = tight ? digits[pos] : 9;
    long long result = 0;

    for (int d = 0; d <= limit; d++) {
        if (d != prev_digit || leading_zero) {  // Ensure no two adjacent digits are the same, or allow leading zeros
            result += countNumbers(pos + 1, d, tight && (d == limit), leading_zero && d == 0);
        }
    }

    return dp[pos][prev_digit + 1][tight][leading_zero] = result;
}

long long countValidNumbers(long long n) {
    if (n < 0) return 0;  // Edge case: for numbers less than 0

    digits.clear();
    if (n == 0) return 1;  // Special case when n is 0

    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());

    memset(dp, -1, sizeof(dp));
    return countNumbers(0, -1, true, true);  // Initial call with prev_digit = -1, leading_zero = true
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long a, b;
    cin >> a >> b;

    long long result = countValidNumbers(b) - countValidNumbers(a - 1);
    cout << result << endl;

    return 0;
}