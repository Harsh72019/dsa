#include<bits/stdc++.h>
using namespace std;


int romanToInt(string s) {
    unordered_map<char , int> um;
    um['I'] = 1;
    um['V'] = 5;
    um['X'] = 10;
    um['L'] = 50;
    um['C'] = 100;
    um['D'] = 500;
    um['M'] = 1000;
    int ans = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(i > 0 && um[s[i]] > um[s[i-1]])
        {
            ans -= um[s[i-1]];
            ans += (um[s[i]] - um[s[i-1]]);
        }   
        else{
            ans += um[s[i]];
        }
    }
    return ans;
}