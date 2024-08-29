#include <bits/stdc++.h>
using namespace std;
int factorial(int n) {
    int i = 1;
    int ans = 1;
    while (i <= n) {
        ans *= i;
        i += 1;
    }
    return ans;
}
vector<string> generated;
void perm(int idx, int n, string s) {
    if (idx == n) {
        generated.push_back(s);
        return;
    }
    unordered_set<char> seen;  // Set to track characters at current index
    for (int i = idx; i < n; i++) {
        if (seen.find(s[i]) != seen.end()) {
            continue;  // Skip duplicate characters
        }
        seen.insert(s[i]);  // Mark character as seen
        swap(s[i], s[idx]);
        perm(idx + 1, n, s);
        swap(s[i], s[idx]);  // Backtrack
    }
}

int main() {
    string s = "11344";
    int n = s.size();
    unordered_map<char, int> counts;
    for (char c : s) {
        counts[c] += 1;
    }
    int total = factorial(n);
    for (auto it = counts.begin(); it != counts.end(); it++) {
        total /= factorial(it->second);
    }
    perm(0, s.size(), s);
    cout << "Calculated Size: " << total << endl;
    cout << "Actual Size: " << generated.size() << endl;
    for (auto v : generated) {
        cout << v << endl;
    }
}
