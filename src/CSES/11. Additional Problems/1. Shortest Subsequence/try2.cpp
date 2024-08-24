#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// Preprocess the DNA string to map each character to the indices where it appears
map<char, vector<int>> preprocessDNA(const string &dna) {
    map<char, vector<int>> char_indices;
    for (int i = 0; i < dna.size(); ++i) {
        char_indices[dna[i]].push_back(i);
    }
    return char_indices;
}

// TRICK: if we have one string and we have to check if other strings are subsequence of it
// then we can use this trick

// Function to check if a sequence is a subsequence of the DNA string using preprocessed data
bool isSubsequence(const string &seq, const map<char, vector<int>> &char_indices) {
    int current_pos = -1;
    for (char c : seq) {
        if (char_indices.find(c) == char_indices.end()) {
            return false;  // If the character doesn't exist in the DNA
        }
        const vector<int> &indices = char_indices.at(c);
        auto it = upper_bound(indices.begin(), indices.end(), current_pos);
        if (it == indices.end()) {
            return false;  // No valid position found
        }
        current_pos = *it;
    }
    return true;
}

// Function to generate all sequences of a given length and check if they are subsequences of the DNA
bool generateSequences(int length, string &current, const string &bases, const map<char, vector<int>> &char_indices) {
    if (length == 0) {
        if (!isSubsequence(current, char_indices)) {
            cout << current << endl;
            return true;  // Found the shortest sequence that is not a subsequence
        }
        return false;
    }
    for (char base : bases) {
        current.push_back(base);
        if (generateSequences(length - 1, current, bases, char_indices)) {
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

    // Preprocess the DNA string to map each character to its indices
    map<char, vector<int>> char_indices = preprocessDNA(dna);

    int length = 1;
    // Check for missing subsequences of increasing length
    while (true) {  // Continuously check until a missing sequence is found
        string current = "";
        if (generateSequences(length, current, bases, char_indices)) {
            break;
        }
        length++;
    }

    return 0;
}