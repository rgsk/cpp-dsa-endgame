#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        vector<int> powers;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                int c = 0;
                while (x % i == 0) {
                    x /= i;
                    c += 1;
                }
                powers.push_back(c);
            }
        }
        if (x != 1) {
            // works for prime numbers
            // eg for 17, we have to consider 17^1
            powers.push_back(1);
        }
        int numberOfDivisors = 1;
        for (int p : powers) {
            numberOfDivisors *= (p + 1);
        }
        cout << numberOfDivisors << endl;
    }
}
