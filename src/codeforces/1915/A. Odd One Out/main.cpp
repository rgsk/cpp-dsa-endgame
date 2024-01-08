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
        int a, b, c;
        cin >> a >> b >> c;
        int xor_value = a ^ b ^ c;
        cout << xor_value << endl;
        t--;
    }
}
