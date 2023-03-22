#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

string reverseString(string A) {
    stack<char> st;
    for (char c : A) {
        st.push(c);
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

void test1() {
    string s = "rahul";
    print(reverseString(s));
}
