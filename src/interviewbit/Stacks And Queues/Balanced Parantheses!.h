#include <bits/stdc++.h>

#include "../../utils/utils.h"

using namespace std;
int solve(string A) {
    stack<char> st;
    for (char c : A) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
void test1() {
    string A = "(()())";
    print(solve(A));
}
void test2() {
    string A = "(()";
    print(solve(A));
}