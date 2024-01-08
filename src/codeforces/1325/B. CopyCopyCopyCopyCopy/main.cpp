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
        int arr[n];
        int i = 0;
        while (i < n) {
            cin >> arr[i];
            i++;
        }
        sort(arr, arr + n);
        int unique = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                unique++;
            }
        }
        cout << unique << endl;
        t--;
    }
}
