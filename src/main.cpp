#include <bits/stdc++.h>

#include "sorting/sorting.h"

using namespace std;

int main() {
    int a = 24;

    // print variable
    cout << "Value of a is " << a << endl;
    cout << "this is working now" << endl;
    cout << "wohoo" << endl;
    vector<int> vec = {4, 3, 2, 1};
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    bubble_sort(vec);
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// Output: Value of a is 24