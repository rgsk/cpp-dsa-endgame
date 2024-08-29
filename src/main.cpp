#include <bits/stdc++.h>
using namespace std;
void perm(int idx, int n, string s) {
    if (idx == n) {
        cout << s << endl;
        return;
    }
    for (int i = idx; i < n; i++) {
        if (i != idx && s[i] == s[idx]) {
            continue;
        }
        swap(s[i], s[idx]);
        perm(idx + 1, n, s);
        swap(s[i], s[idx]);
    }
}

int main() {
    string s = "1134";
    perm(0, s.size(), s);
}
