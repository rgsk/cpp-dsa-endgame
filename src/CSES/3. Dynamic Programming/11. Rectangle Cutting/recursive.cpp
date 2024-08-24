#include <bits/stdc++.h>
using namespace std;

int minCuts(int a, int b) {
    if (a == b) {
        return 0;  // No cuts needed if the rectangle is already a square
    }

    int min_moves = INT_MAX;

    // Try all possible vertical cuts
    for (int i = 1; i < a; ++i) {
        min_moves = min(min_moves, 1 + minCuts(i, b) + minCuts(a - i, b));
    }

    // Try all possible horizontal cuts
    for (int i = 1; i < b; ++i) {
        min_moves = min(min_moves, 1 + minCuts(a, i) + minCuts(a, b - i));
    }

    return min_moves;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    cout << minCuts(a, b) << endl;
    return 0;
}