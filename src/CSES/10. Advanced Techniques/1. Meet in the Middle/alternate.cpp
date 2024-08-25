#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void generate_subset_sums(ll i, ll total, vector<ll>& t, vector<ll>& subset_sums) {
    if (i == t.size()) {
        subset_sums.push_back(total);
        return;
    }
    // no take
    generate_subset_sums(i + 1, total, t, subset_sums);
    // take
    generate_subset_sums(i + 1, total + t[i], t, subset_sums);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, x;
    cin >> n >> x;
    ll half = n / 2;
    vector<ll> first_half(half);
    vector<ll> second_half(n - half);

    for (ll i = 0; i < half; i++) {
        cin >> first_half[i];
    }
    for (ll i = 0; i < n - half; i++) {
        cin >> second_half[i];
    }
    vector<ll> first_subset_sums;
    generate_subset_sums(0, 0, first_half, first_subset_sums);
    vector<ll> second_subset_sums;
    generate_subset_sums(0, 0, second_half, second_subset_sums);
    sort(first_subset_sums.begin(), first_subset_sums.end());
    sort(second_subset_sums.begin(), second_subset_sums.end());

    ll count = 0;
    int i = 0, j = second_subset_sums.size() - 1;
    while (i < first_subset_sums.size() && j >= 0) {
        if (first_subset_sums[i] + second_subset_sums[j] == x) {
            ll first_count = 1, second_count = 1;
            while (i + 1 < first_subset_sums.size() && first_subset_sums[i] == first_subset_sums[i + 1]) {
                i++;
                first_count++;
            }
            while (j - 1 >= 0 && second_subset_sums[j] == second_subset_sums[j - 1]) {
                j--;
                second_count++;
            }
            count += first_count * second_count;
            i++;
            j--;
        } else if (first_subset_sums[i] + second_subset_sums[j] < x) {
            i++;
        } else {
            j--;
        }
    }
    cout << count << endl;
}
