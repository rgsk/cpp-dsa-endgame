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
        int plus = 0;
        int i = 0;
        while (i < n) {
            char c;
            cin >> c;
            if (c == '+') {
                plus += 1;
            }
            i++;
        }
        int minus = n - plus;
        int result = abs(plus - minus);
        cout << result << endl;
        t--;
    }
}
