#include <bits/stdc++.h>
using namespace std;

const int logN = 17;   // log(1e6) ≈ 17
const int maxT = 1e6;  // Maximum time
int N, Q;
int dp[maxT + 1][logN + 1];                                  // Memoization table
vector<int> movies[maxT + 1];                                // List of movies starting at each time
priority_queue<int, vector<int>, greater<int>> endsMinHeap;  // Min-heap to track movie end times

// Memoized function to get dp[t][k] using memoization
int getDP(int t, int k) {
    if (dp[t][k] != -1) return dp[t][k];  // Return if already computed

    if (k == 0) {  // Base case for k == 0
        while (!endsMinHeap.empty() && endsMinHeap.top() <= t) {
            endsMinHeap.pop();  // Remove movies that have already ended
        }
        dp[t][0] = endsMinHeap.empty() ? maxT + 1 : endsMinHeap.top();  // If no valid movie, return maxT + 1
    } else {
        int nextTime = getDP(t, k - 1);                                    // Recursive call to get next time
        dp[t][k] = (nextTime > maxT) ? maxT + 1 : getDP(nextTime, k - 1);  // Transition
    }

    return dp[t][k];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Input number of movies and queries
    cin >> N >> Q;

    // Input for movies: start time a, end time b
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        movies[a].push_back(b);  // Store movie ending at time 'b'
    }

    // Initialize dp array with -1 (to indicate uncomputed states)
    memset(dp, -1, sizeof(dp));

    // Fill in the heap with movie end times for each start time
    for (int t = maxT; t >= 0; t--) {
        for (int b : movies[t]) {
            endsMinHeap.push(b);
        }
        dp[t][0] = endsMinHeap.empty() ? maxT + 1 : endsMinHeap.top();
    }

    // Handle each query
    for (int i = 0; i < Q; i++) {
        int start, end;
        cin >> start >> end;

        int ans = 0;  // Result for the query
        for (int k = logN; k >= 0; k--) {
            if (getDP(start, k) <= end) {
                start = getDP(start, k);
                ans += (1 << k);  // Add the number of movies watched
            }
        }

        // Output the result
        cout << ans << endl;
    }

    return 0;
}