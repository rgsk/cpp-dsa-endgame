#include <bits/stdc++.h>
using namespace std;
int trailingZerosInFactorial(int n) {
    int count = 0;
    for (int i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << trailingZerosInFactorial(n) << endl;
}