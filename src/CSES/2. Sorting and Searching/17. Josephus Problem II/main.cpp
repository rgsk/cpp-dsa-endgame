// link - https://www.geeksforgeeks.org/cses-solutions-josephus-problem-ii/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Function to print the order in which children are removed
void solve(int N, int K) {
    // 2D array to store ranges of size sqrt(N)
    vector<vector<int> > arr;

    int root = sqrt(N);
    int row = 0, col = 0, count = 0;

    // Construct the 2D vector arr
    vector<int> vec;
    for (int i = 1; i <= N; i++) {
        if (count > root) {
            count = 0;
            arr.push_back(vec);
            vec.clear();
        }
        vec.push_back(i);
        count++;
    }
    if (!vec.empty()) {
        arr.push_back(vec);
    }

    // Iterate till we have removed all the children
    for (int i = 0; i < N; i++) {
        // Fnd the position of the element to be removed
        int steps = K % (N - i);

        // Make jumps till we reach the position of the
        // element to be removed
        while (steps > 0) {
            // If we can jump j elements in the current row,
            // we jump to that column
            if (col + steps < arr[row].size()) {
                col += steps;
                steps = 0;
            }
            // If we cannot jump j elements, we jump over
            // all the elements in the current row and move
            // to the next row
            else {
                steps -= arr[row].size() - col;
                col = 0;
                row++;
            }
            // If all the elements are traversed, we start
            // from the first row again
            if (row >= arr.size()) {
                row = 0;
            }
        }

        // While the current row has lesser columns, move to
        // the next row
        while (arr[row].size() <= col) {
            col = 0;
            row++;
            if (row >= arr.size()) {
                row = 0;
            }
        }
        cout << arr[row][col] << " ";
        // Remove the student from the current row
        arr[row].erase(arr[row].begin() + col);
        if (i != N - 1) {
            // don't run for last element otherwise below while loop will keep running
            while (arr[row].size() <= col) {
                col = 0;
                row++;
                if (row >= arr.size()) {
                    row = 0;
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, K;
    cin >> N >> K;

    solve(N, K);
}
