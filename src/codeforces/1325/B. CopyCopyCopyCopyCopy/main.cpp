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
    while (t > 0) {
        int n;
        cin >> n;
        int arr[n];
        int i = 0;
        while (i < n) {
            cin >> arr[i];
            i++;
        }
        sort(arr, arr + n);
        int unique = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                unique++;
            }
        }
        cout << unique << endl;
        t--;
    }
}

/*
approach

if we repeat the array n times
every larger element would start coming after smaller element

eg. 3, 2, 1

3, 2, 1, 3, 2, 1, 3, 2, 1

in this case, 2 comes in 2nd part, 3 comes in 3rd part

we can sort the array and get all the unique elements
(as they all will form the longest increasing subsequence)
*/
