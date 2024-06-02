#include <bits/stdc++.h>
using namespace std;

// Function to compute the LPS array
vector<int> computeLPSArray(const string& s) {
    int n = s.length();
    vector<int> lps(n, 0);
    int length = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;

    vector<int> lps = computeLPSArray(s);
    vector<int> borders;

    int length = lps[s.size() - 1];

    // Collect all borders by tracing back using the LPS array
    while (length > 0) {
        borders.push_back(length);
        length = lps[length - 1];
    }

    sort(borders.begin(), borders.end());

    // Print the border lengths
    for (int borderLength : borders) {
        cout << borderLength << " ";
    }
    cout << endl;

    return 0;
}
