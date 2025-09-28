#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string ans = "";
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] != ' ')
        {
            string k = "";
            while(s[i] != ' ' && i < s.size())
            {
                k += s[i];
                i++;
            }
            k+= " ";
            ans = k + ans;
        }
    }
    return ans.substr(0, ans.size() - 1);
}