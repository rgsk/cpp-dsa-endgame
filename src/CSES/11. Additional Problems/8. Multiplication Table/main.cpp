#include <algorithm>
#include <iostream>
using namespace std;

long long countLessEqual(long long x, long long n) {
    long long count = 0;
    for (long long i = 1; i <= n; i++) {
        count += min(x / i, n);
    }
    return count;
}

long long findMiddleElement(long long n) {
    long long left = 1, right = n * n;
    long long desired_count = (n * n + 1) / 2;

    while (left < right) {
        long long mid = (left + right) / 2;
        if (countLessEqual(mid, n) < desired_count) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;
    cout << findMiddleElement(n) << endl;
    return 0;
}