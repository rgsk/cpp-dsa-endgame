#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    long long temp;
    while (b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t > 0) {
        long long a, b;
        cin >> a >> b;
        long long x;
        if (b % a == 0) {
            x = b * b / a;
        } else {
            x = a * b / gcd(a, b);
        }
        cout << x << endl;
        t--;
    }
}
