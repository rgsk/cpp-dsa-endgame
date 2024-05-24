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
    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    bool possible = true;
    bool odd = false;
    char odd_char;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second % 2) {
            if (odd) {
                possible = false;
                break;
            }
            odd = true;
            odd_char = it->first;
        }
    }
    if (possible) {
        string first = "";
        string second = "";
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->first != odd_char) {
                for (int i = 0; i < it->second / 2; i++) {
                    first += it->first;
                    second += it->first;
                }
            }
        }
        first += odd_char;
        reverse(second.begin(), second.end());
        string result = first + second;
        cout << result << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }
}