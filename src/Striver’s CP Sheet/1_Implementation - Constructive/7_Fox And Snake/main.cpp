#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int rows, cols;
    cin >> rows >> cols;
    int i = 0;
    bool last = true;
    while (i < rows) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                cout << "#";
            }
            cout << endl;
        } else {
            if (last) {
                for (int j = 0; j < cols - 1; j++) {
                    cout << ".";
                }
                cout << "#";
                cout << endl;
            } else {
                cout << "#";
                for (int j = 0; j < cols - 1; j++) {
                    cout << ".";
                }
                cout << endl;
            }
            last = !last;
        }
        i++;
    }
    return 0;
}