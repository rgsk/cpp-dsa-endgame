#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;  // duration and deadline
    }

    // Sort tasks by their duration
    sort(tasks.begin(), tasks.end());

    long long current_time = 0;
    long long total_reward = 0;

    for (const auto& task : tasks) {
        int duration = task.first;
        int deadline = task.second;
        current_time += duration;
        total_reward += deadline - current_time;
    }

    cout << total_reward << endl;

    return 0;
}
