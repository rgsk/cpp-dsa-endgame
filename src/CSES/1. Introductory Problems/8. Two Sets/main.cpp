#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    if (n % 4 == 0 || n % 4 == 3) {
        vector<int> s1;
        vector<int> s2;
        int i = n;
        while (i > 0) {
            if (i == 3) {
                s2.push_back(3);
                s1.push_back(1);
                s1.push_back(2);
                break;
            }
            s1.push_back(i);
            i -= 1;
            for (int j = 0; j < 2; j++) {
                s2.push_back(i);
                i -= 1;
            }
            s1.push_back(i);
            i -= 1;
        }
        cout << "YES" << endl;
        cout << s1.size() << endl;
        for (int v : s1) {
            cout << v << " ";
        }
        cout << endl;
        cout << s2.size() << endl;
        for (int v : s2) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}