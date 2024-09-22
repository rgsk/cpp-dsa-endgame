#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dijkstra(ll n) {
    // Min-heap (priority queue) to prioritize states with the smallest number of steps
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    set<ll> visited;  // To avoid reprocessing the same number

    pq.push({n, 0});
    visited.insert(n);

    while (!pq.empty()) {
        ll current = pq.top().first;
        ll steps = pq.top().second;
        pq.pop();

        // If we have reached 0, return the number of steps
        if (current == 0) {
            return steps;
        }

        // Extract digits of the current number
        ll temp = current;
        while (temp > 0) {
            ll digit = temp % 10;
            temp /= 10;
            if (digit > 0) {
                ll next_num = current - digit;
                // If the number has not been visited yet
                if (visited.find(next_num) == visited.end()) {
                    pq.push({next_num, steps + 1});  // Increment step count
                    visited.insert(next_num);
                }
            }
        }
    }

    return -1;  // We should never reach here
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;

    cout << dijkstra(n) << endl;

    return 0;
}