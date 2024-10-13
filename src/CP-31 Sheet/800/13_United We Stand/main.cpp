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
        vector<int> vec;
        int min_element = INT_MAX;
        while (n--) {
            int v;
            cin >> v;
            vec.push_back(v);
            min_element = min(min_element, v);
        }
        int lowest = 0;
        for (int v : vec) {
            if (v == min_element) {
                lowest += 1;
            }
        }
        if (lowest == vec.size()) {
            cout << -1 << endl;
        } else {
            cout << lowest << " " << vec.size() - lowest << endl;
            while (lowest--) {
                cout << min_element << " ";
            }
            cout << endl;
            for (int v : vec) {
                if (v != min_element) {
                    cout << v << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}