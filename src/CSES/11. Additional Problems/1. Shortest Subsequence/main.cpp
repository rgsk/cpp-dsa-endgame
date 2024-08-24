#include <bits/stdc++.h>

using namespace std;

// Maximum length of the DNA sequence
const int maxN = 1e6 + 5;

// Variables
int N, cnt;         // N: length of the DNA sequence, cnt: counter for unique characters
char S[maxN];       // Input DNA sequence
bool has[4];        // Array to track which of 'A', 'C', 'G', 'T' have been seen in the current segment
vector<int> segs;   // Stores the end indices of segments where all four characters appear
map<char, int> mp;  // Maps characters 'A', 'C', 'G', 'T' to indices 0, 1, 2, 3

// Initialize the character map
void init() {
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
}

int main() {
    // Input and output redirection for competitive programming
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    init();           // Initialize the map for character to index conversion
    scanf(" %s", S);  // Read the DNA sequence

    N = (int)strlen(S);  // Get the length of the DNA sequence
    for (int i = 0; i < N; i++) {
        int c = mp[S[i]];  // Get the index of the current character in the 'has' array

        // If this character hasn't been seen in the current segment
        if (!has[c]) {
            has[c] = true;  // Mark it as seen
            cnt++;          // Increment the unique character counter

            // If we've seen all 4 characters ('A', 'C', 'G', 'T') in this segment
            if (cnt == 4) {
                fill(has, has + 4, false);  // Reset the 'has' array for the next segment
                segs.push_back(i);          // Store the end index of this segment
                cnt = 0;                    // Reset the unique character counter
            }
        }
    }

    // Output the last character of each complete segment
    for (int i : segs) {
        printf("%c", S[i]);
        // we can actually take any character from the segment
        // getting last character is convinient
    }

    // Find and print the first missing character from the last incomplete segment
    for (int i = 0; i < 4; i++) {
        if (!has[i]) {  // If character 'A', 'C', 'G', or 'T' was not seen in the last segment
            printf("%c\n", "ACGT"[i]);
            return 0;  // Exit after finding the first missing character
        }
    }
    return 0;
}