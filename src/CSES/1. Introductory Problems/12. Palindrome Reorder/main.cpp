#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    vector<int> freq(26);

    for (char c : s) {
        freq[c - 'A']++;
    }

    int odd = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) {
            if (odd != -1) {
                cout << "NO SOLUTION" << endl;
                return 0;
            } else {
                odd = i;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i] / 2; j++) {
            cout << (char)(i + 'A');
        }
    }
    if (odd != -1) {
        cout << (char)(odd + 'A');
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < freq[i] / 2; j++) {
            cout << (char)(i + 'A');
        }
    }
    return 0;
}