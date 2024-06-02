#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to create the "partial match" table (also known as "failure function") for the KMP algorithm
std::vector<int> computeLPSArray(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP search algorithm
int KMPSearch(const std::string& pattern, const std::string& text) {
    int m = pattern.length();
    int n = text.length();

    std::vector<int> lps = computeLPSArray(pattern);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    int totalMatches = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // std::cout << "Found pattern at index " << i - j << std::endl;
            totalMatches++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return totalMatches;
}

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Prlong longing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    string text, pattern;
    cin >> text >> pattern;
    cout << KMPSearch(pattern, text) << endl;
}