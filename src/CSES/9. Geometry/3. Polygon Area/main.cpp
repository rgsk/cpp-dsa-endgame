#include <bits/stdc++.h>
using namespace std;

long long polygon_area(const vector<pair<int, int>>& vertices) {
    int n = vertices.size();
    long long area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += 1LL * vertices[i].first * vertices[j].second;
        area -= 1LL * vertices[i].second * vertices[j].first;
    }
    return abs(area);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first;
        cin >> vertices[i].second;
    }
    cout << polygon_area(vertices) << endl;
}
