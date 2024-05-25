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
    vector<int> arrival(n);
    vector<int> leaving(n);
    for (int i = 0; i < n; i++) {
        cin >> arrival[i];
        cin >> leaving[i];
    }
    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());
    int i = 0;
    int j = 0;
    int occupied = 0;
    int max_occupied = 0;
    while (i < n) {
        if (arrival[i] < leaving[j]) {
            occupied += 1;
            max_occupied = max(max_occupied, occupied);
            i += 1;
        } else {
            occupied -= 1;
            j += 1;
        }
    }
    cout << max_occupied << endl;
}
