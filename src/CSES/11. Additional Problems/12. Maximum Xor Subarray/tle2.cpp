#include <iostream>
#include <set>
#include <vector>

using namespace std;

int findMaxXorSubarray(vector<int>& arr) {
    int n = arr.size();
    int maxXor = 0;
    int prefixXor = 0;

    set<int> xorSet;
    xorSet.insert(0);  // Insert 0 to consider the entire subarray from the start

    for (int i = 0; i < n; ++i) {
        prefixXor ^= arr[i];  // Update prefix XOR

        // Iterate through possible XOR values in the set
        for (int prefix : xorSet) {
            maxXor = max(maxXor, prefixXor ^ prefix);
        }

        // Insert the current prefix XOR into the set
        xorSet.insert(prefixXor);
    }

    return maxXor;
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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << findMaxXorSubarray(arr) << endl;

    return 0;
}