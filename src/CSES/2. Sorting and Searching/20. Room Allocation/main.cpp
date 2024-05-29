#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Event {
    int time;
    int type;   // 1 for arrival, -1 for departure
    int index;  // Index of the customer
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<Event> events;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1, i});   // Arrival event
        events.push_back({b, -1, i});  // Departure event
    }

    // Sort events, if times are the same, prioritize arrival over departure
    sort(events.begin(), events.end(), [](const Event &e1, const Event &e2) {
        if (e1.time == e2.time)
            return e1.type > e2.type;
        return e1.time < e2.time;
    });

    vector<int> available_rooms;
    vector<int> room_allocation(n);
    int max_rooms_needed = 0;
    int current_rooms_used = 0;

    for (const auto &event : events) {
        if (event.type == 1) {  // Arrival
            if (!available_rooms.empty()) {
                // we can pick any of the available rooms here
                // either last/first or any other
                int room = available_rooms.back();
                available_rooms.pop_back();
                room_allocation[event.index] = room;
            } else {
                current_rooms_used++;
                room_allocation[event.index] = current_rooms_used;
                max_rooms_needed = max(max_rooms_needed, current_rooms_used);
            }
        } else {  // Departure
            available_rooms.push_back(room_allocation[event.index]);
        }
    }

    cout << max_rooms_needed << endl;
    for (int i = 0; i < n; ++i) {
        cout << room_allocation[i] << " ";
    }
    cout << endl;

    return 0;
}
