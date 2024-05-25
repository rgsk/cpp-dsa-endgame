#include <bits/stdc++.h>
using namespace std;
void toh(int n, int source, int destination, int auxiliary) {
    if (n == 1) {
        cout << source << " " << destination << endl;
        return;
    }
    toh(n - 1, source, auxiliary, destination);
    cout << source << " " << destination << endl;
    toh(n - 1, auxiliary, destination, source);
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
    int steps = (int)pow(2, n) - 1;
    cout << steps << endl;
    toh(n, 1, 3, 2);
}
