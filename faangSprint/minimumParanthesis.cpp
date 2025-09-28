#include<bits/stdc++.h>
using namespace std;


int minimumParentheses(string pattern) {
    stack<char> st;
    
    for (char c : pattern) {
        if (c == ')' && !st.empty() && st.top() == '(') {
            st.pop(); 
        } else {
            st.push(c); 
        }
    }
    
    return st.size(); 
}
