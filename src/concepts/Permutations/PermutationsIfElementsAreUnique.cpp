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
    for (int i = idx; i < n; i++) {
        swap(s[i], s[idx]);
        perm(idx + 1, n, s);
        swap(s[i], s[idx]);
    }
}

int main() {
    string s = "1234";
    int n = s.size();
    perm(0, s.size(), s);
    cout << "Calculated Size: " << factorial(n) << endl;
    cout << "Actual Size: " << generated.size() << endl;
    cout << "Is Sorted: " << is_sorted(generated.begin(), generated.end()) << endl;

    for (auto v : generated) {
        cout << v << endl;
    }
}
