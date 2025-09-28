#include<bits/stdc++.h>
using namespace std;


string removeKdigits(string num , int k )
{
    if(num.size() == k ) return "0";

    stack<char> st;

    for(char i : num)
    {
        while(!st.empty() && k > 0 && st.top() > i )
        {
            st.pop();
            k--;
        }
        st.push(i);
    }

    while(k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    string ans = "";

    while(st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin() , ans.end());

    int index = 0;

    while(ans[index] == '0' && index < ans.size())
    {
        index++;
    }

    return index == ans.size() ? "0" : ans.substr(index);
}