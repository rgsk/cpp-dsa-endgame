#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string toLowerCase(string s) {
        for (char &c : s) {
            if (c <= 'Z') {
                c = c + ('a' - 'A');
            }
        }
    }
};

int main() {
    int v = 'z';
    cout << v << endl;
    v = 'Z';
    cout << v << endl;
    return 0;
}