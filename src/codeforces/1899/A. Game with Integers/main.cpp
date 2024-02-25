#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int v;
        cin >> v;
        if (v % 3) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
}

// Approach
// if remainder is 1 or 2
// then "First" or "Vanya" can make the number divisible by 3
// now "Second" or "Vova" can play a move of add 1 or subtract 1
// "First" can make the number divisible by 3 in the next move by playing the opposite move
// if number is already divisible by 3, "First" plays a move
// "Second" can again make it divisible by 3 by playing the opposite move
// this will continue and "First" won't be able to win