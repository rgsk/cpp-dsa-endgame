
#include <bits/stdc++.h>
using namespace std;
int trailingZerosInFactorial(int n) {
    int count = 0;
    for (int i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }
    return count;
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
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int distinct = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i] != vec[i - 1]) {
            distinct++;
        }
    }
    cout << distinct << endl;
}