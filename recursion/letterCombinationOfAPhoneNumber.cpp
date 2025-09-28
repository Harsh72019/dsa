#include<bits/stdc++.h>
using namespace std;

void solve(int index , string digits , unordered_map<char , vector<char>>& um , string subAns , vector<string> & ans )
{
    if(subAns.size() == digits.size())
    {
        ans.push_back(subAns);
        return;
    }
    if(index == digits.size())
        return;
    vector<char> digit = um[digits[index]];
    for(char i : digit)
    {
        solve(index + 1 , digits , um , subAns + i , ans);
    }
    
}
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {}; 
    unordered_map<char , vector<char>> um;
    um['2'] = {'a' , 'b' , 'c'};
    um['3'] = {'d' , 'e' , 'f'};
    um['4'] = {'g' , 'h' ,'i'};
    um['5'] = {'j' , 'k' , 'l'};
    um['6'] = {'m' , 'n' , 'o'};
    um['7'] = {'p' , 'q' , 'r' , 's'};
    um['8'] = {'t' , 'u' , 'v'};
    um['9'] = {'w' , 'x' , 'y' ,'z'};
    vector<string> ans;
    solve( 0 , digits , um , "" , ans);
    return ans; 
}