#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> vec = {{1, 2}, {2, 4}, {2, 3}};
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}
