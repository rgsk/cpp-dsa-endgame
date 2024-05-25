#include <bits/stdc++.h>
using namespace std;

bool nextPermutation(string& s) {
    int n = s.size();
    int firstDropIndex = -1;
    for (int i = n - 1; i > 0; --i) {
        if (s[i - 1] < s[i]) {
            firstDropIndex = i - 1;
            break;
        }
    }
    if (firstDropIndex == -1) {
        return false;
    }
    int firstElementThatIsGreaterThanElementAtFirstDropIndex = -1;
    for (int i = n - 1; i > firstDropIndex; --i) {
        if (s[i] > s[firstDropIndex]) {
            firstElementThatIsGreaterThanElementAtFirstDropIndex = i;
            break;
        }
    }
    swap(s[firstDropIndex], s[firstElementThatIsGreaterThanElementAtFirstDropIndex]);
    reverse(s.begin() + firstDropIndex + 1, s.end());
    return true;
}

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
    while (nextPermutation(s)) {
        vec.push_back(s);
    }
    cout << vec.size() << endl;
    for (string v : vec) {
        cout << v << endl;
    }
}
