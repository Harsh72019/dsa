#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    if (s.size() == 0)
        return 0;
    
    stack<char> st;
    int maxDepth = 0;
    int currentDepth = 0;
    
    for (char c : s) {
        if (c == '(') {
            st.push(c);
            currentDepth++;
            maxDepth = max(maxDepth, currentDepth);
        } else if (c == ')') {
            if (!st.empty()) {
                st.pop();
                currentDepth--;
            } else {
                return -1;
            }
        }
    }
    
    if (!st.empty()) {
        return -1;
    }
    
    return maxDepth;
}