#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's possible to produce 't' products in 'time' seconds
bool canProduceInTime(const vector<long long>& machines, long long time, long long t) {
    long long totalProducts = 0;
    for (const auto& machineTime : machines) {
        totalProducts += time / machineTime;
        if (totalProducts >= t) return true;  // No need to continue if we already have enough products
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n, t;
    cin >> n >> t;
    vector<long long> machines(n);

    for (long long i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    // Binary search for the minimum time
    long long low = 1;
    long long high = *min_element(machines.begin(), machines.end()) * t;
    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canProduceInTime(machines, mid, t)) {
            result = mid;
            high = mid - 1;  // Try for a smaller time
        } else {
            low = mid + 1;  // Increase the time
        }
    }

    cout << result << endl;

    return 0;
}
