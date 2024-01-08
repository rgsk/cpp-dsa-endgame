#include <bits/stdc++.h>

using namespace std;

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
        int dividend, divisor;
        cin >> dividend >> divisor;
        int quotient = ceil((dividend * 1.0) / divisor);
        int value = quotient * divisor - dividend;
        cout << value << endl;
        t--;
    }
}
