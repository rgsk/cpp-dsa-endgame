#include <bits/stdc++.h>
using namespace std;

int getMaxDigit(int n) {
    int maxDigit = 0;
    while (n > 0) {
        maxDigit = max(maxDigit, n % 10);  // Get the largest digit in the current number
        n /= 10;
    }
    return maxDigit;
}

int greedyRemoveDigits(int n) {
    int steps = 0;
    while (n > 0) {
        int maxDigit = getMaxDigit(n);  // Get the largest digit
        n -= maxDigit;                  // Subtract the largest digit from n
        steps++;                        // Count this as a step
    }
    return steps;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << greedyRemoveDigits(n) << endl;

    return 0;
}