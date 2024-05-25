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
    long long maxSum = INT_MIN;
    long long running = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        running += v;
        maxSum = max(maxSum, running);
        if (running < 0) {
            running = 0;
        }
    }
    cout << maxSum << endl;
}
