#include <bits/stdc++.h>
using namespace std;

string reverseStringWordWise(string input)
{
    stringstream s1(input);
    string word;
    stack<string> st;
    while(static_cast<bool>(getline(s1 , word , ' ')))
    {
        st.push(word);
    }
    string ans = "";
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
        ans += " ";
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}