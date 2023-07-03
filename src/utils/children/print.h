#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print(vector<T> &vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

template <typename H>
void print(vector<vector<H>> &vec) {
    for (auto v : vec) {
        print(v);
    }
    cout << endl;
}
template <typename T>
void printWithIndexes(vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << i << " : " << vec[i] << endl;
    }
    cout << endl;
}

template <typename T>
void print(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(int v) {
    cout << v << endl;
}
void print(string v) {
    cout << v << endl;
}