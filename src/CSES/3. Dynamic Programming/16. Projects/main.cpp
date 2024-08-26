#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2e5 + 5;

struct Project {
    int start, end, reward;
};

vector<Project> projects;
vector<ll> memo(maxN, -1);

// Binary search to find the last project that does not overlap with the current project
int findLastNonOverlapping(int index) {
    int low = 0, high = index - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (projects[mid].end < projects[index].start) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Recursive function with memoization
ll maxReward(int index) {
    if (index < 0) return 0;                    // Base case
    if (memo[index] != -1) return memo[index];  // Return already computed result

    // Option 1: Don't take the current project
    ll result = maxReward(index - 1);

    // Option 2: Take the current project
    int lastNonOverlap = findLastNonOverlapping(index);
    result = max(result, projects[index].reward + maxReward(lastNonOverlap));

    return memo[index] = result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    projects.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    // Sort projects by their ending day
    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
        return a.end < b.end;
    });

    // Compute the maximum reward
    ll result = maxReward(n - 1);
    cout << result << endl;

    return 0;
}