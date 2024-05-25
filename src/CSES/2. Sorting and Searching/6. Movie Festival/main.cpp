#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    // we have to take that movie which is ending first
    sort(vec.begin(), vec.end(), compare);
    int last_end = vec[0].second;
    int movies = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i].first >= last_end) {
            movies++;
            last_end = vec[i].second;
        }
    }
    cout << movies << endl;
}
