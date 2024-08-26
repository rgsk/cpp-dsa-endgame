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
    Bimap<int, string> bimap;

    bimap.insert(1, "apple");
    bimap.insert(2, "banana");

    cout << "Key 1 maps to value: " << bimap.get_value(1) << endl;
    cout << "Value 'banana' maps to key: " << bimap.get_key("banana") << endl;

    bimap.remove_by_key(1);
    cout << "Key 1 exists after removal? " << bimap.contains_key(1) << endl;
    cout << "Value 'apple' exists after removal? " << bimap.contains_value("apple") << endl;

    return 0;
}