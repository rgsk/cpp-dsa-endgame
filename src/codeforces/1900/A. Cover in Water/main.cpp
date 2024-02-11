// https://codeforces.com/problemset/problem/1900/A

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
        int empty = 0;
        int consecutive = 0;

        while (n--) {
            char c;
            cin >> c;
            if (c == '.') {
                empty++;
                consecutive++;
                if (consecutive == 3) {
                    break;
                }
            } else {
                consecutive = 0;
            }
        }

        if (consecutive == 3) {
            cout << 2 << endl;
        } else {
            cout << empty << endl;
        }

        // Skip the rest of the characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
