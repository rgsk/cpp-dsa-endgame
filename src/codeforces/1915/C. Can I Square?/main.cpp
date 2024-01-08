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
        int n;
        cin >> n;
        long long s = 0;
        while (n > 0) {
            int v;
            cin >> v;
            s += v;

            n--;
        }
        long long root = sqrt(s);
        if (root * root == s) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        t--;
    }
}
