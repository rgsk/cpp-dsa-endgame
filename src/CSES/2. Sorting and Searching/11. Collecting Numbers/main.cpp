#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        // effectively we are asking the question
        // whether the current element can go along with previous element
        // in the current round
        // if not, we need to start a new round
        if (pos[i - 1] > pos[i]) {
            rounds++;
        }
    }
    cout << rounds << endl;
}
