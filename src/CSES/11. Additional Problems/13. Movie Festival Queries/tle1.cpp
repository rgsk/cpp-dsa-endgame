#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int getMovies(vector<pair<int, int>>& vec, int start, int end) {
    int n = vec.size();
    int last_end = start;
    int movies = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i].first >= last_end) {
            if (vec[i].second > end) {
                return movies;
            }
            movies++;
            last_end = vec[i].second;
        }
    }
    return movies;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    // we have to take that movie which is ending first
    sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;
        cout << getMovies(vec, start, end) << endl;
    }
    return 0;
}