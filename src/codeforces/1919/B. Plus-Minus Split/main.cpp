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
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool notPossible = false;
        int ops = 0;
        for (int i = n - 2; i >= 0; i--) {
            while (arr[i] > 0 && arr[i] >= arr[i + 1]) {
                arr[i] = arr[i] / 2;
                ops += 1;
            }
            if (arr[i] == 0 && arr[i + 1] == 0) {
                notPossible = true;
                break;
            }
        }
        if (notPossible) {
            cout << -1 << endl;
        } else {
            cout << ops << endl;
        }
    }
}
