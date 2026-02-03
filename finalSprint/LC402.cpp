#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;

    for (char c : num)
    {
        while (!st.empty() && k > 0 && st.top() > c)
        {
            st.pop();
            k--;
        }
        st.push(c);
    }

    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    int idx = 0;
    while (idx < ans.size() && ans[idx] == '0')
        idx++;

    return idx == ans.size() ? "0" : ans.substr(idx);
}