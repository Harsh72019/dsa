#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (st.empty())
        {
            st.push(it);
            continue;
        }
        char curr = st.top();
        if (it == ')')
        {
            if (curr == '(')
                st.pop();
            else
                st.push(it);
        }
        else
            st.push(it);
    }
    int counter = 0;
    while (!st.empty())
    {
        counter++;
        st.pop();
    }
    return counter;
}