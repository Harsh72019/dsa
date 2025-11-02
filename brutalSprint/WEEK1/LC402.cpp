#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    if (num.size() == k)
        return "0";

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

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int pos = 0;
    while (pos < ans.size() && ans[pos] == '0')
        pos++;
    ans = ans.substr(pos);
    if (ans.empty())
        ans = "0";

    return ans;
}