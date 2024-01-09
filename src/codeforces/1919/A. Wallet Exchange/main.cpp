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
        int a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 0) {
            // even
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
        t--;
    }
}
