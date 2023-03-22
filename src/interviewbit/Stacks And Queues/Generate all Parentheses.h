#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

int isValid(string A) {
    stack<char> st;
    map<char, char> clop;
    clop['}'] = '{';
    clop[')'] = '(';
    clop[']'] = '[';
    for (auto c : A) {
        if (c == '{' || c == '[' || c == '(') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == clop[c]) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
void test1() {
    string A = "[()[]{}]";
    print(isValid(A));
}
void test2() {
    string A = "([)]";
    print(isValid(A));
}