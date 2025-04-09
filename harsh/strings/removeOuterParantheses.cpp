#include<bits/stdc++.h>
using namespace std;


string removeOuterParentheses(string s) {
    stack<char> st;
    string ans = "";
    for(auto i : s)
    {
        if(i == ')' && st.empty())
            continue;
        else if(i == '(')
        {
            if(!st.empty())
                ans += i;
            st.push(i);
        }
        else
        {
            st.pop();
            if(!st.empty())
                ans += i;
        }
    }
    return ans;
}