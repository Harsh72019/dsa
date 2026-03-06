#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0;
        int ans = 0;
        for(int right = 0 ; right < s.size() ; right++ )
        {
            char toAdd = s[right];
            while(left <= right && chars.find(toAdd) != chars.end())
            {
                char toRemove = s[left];
                chars.erase(toRemove);
                left++;
            } 
            chars.insert(toAdd);
            ans = max(ans , right - left + 1);
        }
        return ans;
    }