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
    while (t--) {
        int n;
        cin >> n;
        int v;
        cin >> v;
        if (v == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        // Skip the rest of the characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
