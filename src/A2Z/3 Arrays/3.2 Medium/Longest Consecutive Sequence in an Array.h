#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

class Solution {
   public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        // Your code here
        unordered_set<int> st;
        for (int i = 0; i < N; i++) {
            st.insert(arr[i]);
        }
        int longest = 1;
        for (int i = 0; i < N; i++) {
            int el = arr[i];
            int curSeq = 1;
            st.erase(el);
            int smaller = el - 1;
            while (st.find(smaller) != st.end()) {
                st.erase(smaller);
                curSeq++;
                smaller--;
            }
            int larger = el + 1;
            while (st.find(larger) != st.end()) {
                st.erase(larger);
                curSeq++;
                larger++;
            }
            longest = max(longest, curSeq);
        }
        return longest;
    }
};

class Solution2 {
   public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        // Your code here
        sort(arr, arr + N);
        int lastInSeq = arr[0];
        int longest = 1;
        int cur = 1;
        for (int i = 1; i < N; i++) {
            if (arr[i] == lastInSeq + 1) {
                cur++;
                lastInSeq++;
            } else if (arr[i] == lastInSeq) {
                // do nothing
            } else {
                longest = max(longest, cur);
                cur = 1;
                lastInSeq = arr[i];
            }
        }
        longest = max(longest, cur);
        return longest;
    }
};