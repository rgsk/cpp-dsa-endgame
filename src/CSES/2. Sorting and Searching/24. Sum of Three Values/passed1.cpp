#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        mp[vec[i]].push_back(i);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int total = vec[i] + vec[l] + vec[r];
            if (total == x) {
                int a = mp[vec[i]].back() + 1;
                mp[vec[i]].pop_back();
                int b = mp[vec[l]].back() + 1;
                mp[vec[l]].pop_back();
                int c = mp[vec[r]].back() + 1;
                mp[vec[r]].pop_back();
                cout << a << " " << b << " " << c << endl;
                return 0;
            } else if (total < x) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
