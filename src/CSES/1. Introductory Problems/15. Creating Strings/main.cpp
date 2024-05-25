#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> vec;
    vec.push_back(s);
    while (next_permutation(s.begin(), s.end())) {
        vec.push_back(s);
    }
    cout << vec.size() << endl;
    for (string v : vec) {
        cout << v << endl;
    }
}
