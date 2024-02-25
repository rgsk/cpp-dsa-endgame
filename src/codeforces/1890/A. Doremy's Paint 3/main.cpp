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
        unordered_map<int, int> mp;
        int j = 0;
        while (j < n) {
            int v;
            cin >> v;
            mp[v]++;
            j++;
        }
        if (mp.size() == 1) {
            cout << "YES\n";
        } else if (mp.size() == 2) {
            auto i = mp.begin();

            if (i->second == n / 2) {
                cout << "YES\n";
            } else {
                i++;
                if (i->second == n / 2) {
                    cout << "YES\n";

                } else {
                    cout << "NO\n";
                }
            }

        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

// solution
// https://codeforces.com/blog/entry/121813