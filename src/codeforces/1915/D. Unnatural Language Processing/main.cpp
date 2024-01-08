#include <bits/stdc++.h>

using namespace std;

// greedy
void solve(string s) {
    int n = s.size();
    int i = 0;
    while (i + 3 < n) {
        if (s[i + 3] == 'a' || s[i + 3] == 'e') {
            cout << s.substr(i, 2);
            i += 2;
        } else {
            cout << s.substr(i, 3);
            i += 3;
        }
        cout << ".";
    }
    cout << s.substr(i, n - i) << endl;
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
        int length;
        cin >> length;
        string s;
        cin >> s;
        solve(s);
        t--;
    }
}
