#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    int initial_xor = 'A' ^ 'B' ^ 'C';
    int t;
    cin >> t;
    while (t > 0) {
        for (int i = 0; i < 3; i++) {
            int xor_value = initial_xor;
            for (int j = 0; j < 3; j++) {
                char c;
                cin >> c;
                if (c != '?') {
                    xor_value ^= c;
                }
            }
            if (xor_value != 0) {
                cout << (char)xor_value << endl;
            }
        }
        t--;
    }
}
