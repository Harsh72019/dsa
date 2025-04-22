#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s , int start , int end)
{
    while(start <= end)
    {
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}
void solve(int index , string s , vector<vector<string>>& ans , vector<string>& subAns)
{
    if(index == s.size())
    {
        ans.push_back(subAns);
        return;
    }

    for(int i = index ; i < s.size() ; i++)
    {
        if(isPalindrome(s , index , i))
        {
            subAns.push_back(s.substr(index , i - index + 1));
            solve(i +1  , s , ans , subAns);
            subAns.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> subAns;
    solve(0 , s , ans , subAns);
    return ans;

}