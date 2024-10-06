#include <bits/stdc++.h>
using namespace std;

vector<string> splitString(const string& str, const string& delimiter = " ") {
    vector<string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    result.push_back(str.substr(start));  // Add the last part

    return result;
}

int main() {
    string str = "rahul mehak vedant greg sam";
    vector<string> words = splitString(str);

    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}