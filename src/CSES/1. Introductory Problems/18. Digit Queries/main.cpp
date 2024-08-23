#include <cmath>
#include <iostream>

using namespace std;

char findDigitAtPosition(long long k) {
    long long length = 1;
    long long count = 9;
    long long start = 1;

    // Step 1: Determine the length of the number where the k-th digit lies
    while (k > length * count) {
        k -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }

    // Step 2: Determine the exact number
    start += (k - 1) / length;

    // Step 3: Determine the exact digit within the number
    string s = to_string(start);
    return s[(k - 1) % length];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q;
    cin >> q;

    while (q--) {
        long long k;
        cin >> k;
        cout << findDigitAtPosition(k) << endl;
    }

    return 0;
}