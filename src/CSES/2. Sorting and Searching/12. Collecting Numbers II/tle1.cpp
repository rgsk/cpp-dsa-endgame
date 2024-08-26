#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
class Bimap {
   public:
    // Insert a new key-value pair
    bool insert(const K& key, const V& value) {
        if (key_to_value.count(key) || value_to_key.count(value)) {
            return false;  // Either key or value already exists
        }
        key_to_value[key] = value;
        value_to_key[value] = key;
        return true;
    }

    // Get value by key
    V get_value(const K& key) const {
        return key_to_value.at(key);
    }

    // Get key by value
    K get_key(const V& value) const {
        return value_to_key.at(value);
    }

    // Remove a key-value pair by key
    void remove_by_key(const K& key) {
        V value = key_to_value.at(key);
        key_to_value.erase(key);
        value_to_key.erase(value);
    }

    // Remove a key-value pair by value
    void remove_by_value(const V& value) {
        K key = value_to_key.at(value);
        key_to_value.erase(key);
        value_to_key.erase(value);
    }

    // Check if a key exists
    bool contains_key(const K& key) const {
        return key_to_value.find(key) != key_to_value.end();
    }

    // Check if a value exists
    bool contains_value(const V& value) const {
        return value_to_key.find(value) != value_to_key.end();
    }

   private:
    map<K, V> key_to_value;
    map<V, K> value_to_key;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    Bimap<int, int> bimap;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bimap.insert(x, i);
    }
    while (m > 0) {
        int a, b;
        cin >> a >> b;
        // swap the values of a and b
        int aval = bimap.get_key(a);
        int bval = bimap.get_key(b);
        bimap.remove_by_key(aval);
        bimap.remove_by_key(bval);
        bimap.insert(aval, b);
        bimap.insert(bval, a);

        int rounds = 1;
        for (int i = 2; i <= n; i++) {
            // effectively we are asking the question
            // whether the current element can go along with previous element
            // in the current round
            // if not, we need to start a new round
            if (bimap.get_value(i - 1) > bimap.get_value(i)) {
                rounds++;
            }
        }
        cout << rounds << endl;
        m--;
    }
}
