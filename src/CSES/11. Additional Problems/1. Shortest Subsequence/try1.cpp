#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(const string &dna, const string &seq) {
    int n = dna.size();
    int m = seq.size();
    int j = 0;  // Pointer for seq

    for (int i = 0; i < n && j < m; ++i) {
        if (dna[i] == seq[j]) {
            j++;
        }
    }
    // If j reached the end of seq, it means seq is a subsequence of dna
    return j == m;
}

// Function to generate all subsequences of a given length
bool generateSequences(int length, string &current, const string &bases, const string &dna) {
    if (length == 0) {
        if (!isSubsequence(dna, current)) {
            cout << current << endl;
            return true;
        }
        return false;
    }
    for (char base : bases) {
        current.push_back(base);
        if (generateSequences(length - 1, current, bases, dna)) {
            return true;
        }
        current.pop_back();
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string dna;
    cin >> dna;
    string bases = "ACGT";
    int length = 1;
    // Check for missing subsequences of increasing length
    while (true) {  // Continuously check until a missing sequence is found
        string current = "";
        if (generateSequences(length, current, bases, dna)) {
            break;
        }
        length++;
    }

    return 0;
}