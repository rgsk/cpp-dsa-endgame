#include <bits/stdc++.h>
using namespace std;
long long solve(long long n) {
    if (n == 0) {
        return 0;
    }
    long long x = log2(n);
    long long one = 1;
    long long a = (one << (x - 1)) * x;
    long long b = n - (one << x) + 1;
    long long c = solve(n - (one << x));
    return a + b + c;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;

    cout << solve(n) << endl;
}
