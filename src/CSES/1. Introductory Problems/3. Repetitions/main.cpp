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
    int n = s.size();
    int last_index = 0;
    int max_same = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            max_same = max(max_same, i - last_index);
            last_index = i;
        }
    }
    max_same = max(max_same, n - last_index);
    cout << max_same << endl;
}
