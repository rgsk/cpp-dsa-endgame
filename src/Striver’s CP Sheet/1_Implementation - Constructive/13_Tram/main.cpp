#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int max_passengers = 0;
    int passengers = 0;
    for (int i = 0; i < n; i++) {
        int exit, enter;
        cin >> exit >> enter;
        passengers += enter;
        passengers -= exit;
        max_passengers = max(max_passengers, passengers);
    }
    cout << max_passengers << endl;
    return 0;
}