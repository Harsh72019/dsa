#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> lastOccurence;
        int left = 0;
        int ans = 0;
        for(int right = 0 ; right < s.size() ; right++)
        {
            while(lastOccurence.find(s[right]) != lastOccurence.end())
            {
                lastOccurence.erase(s[left]);
                left++;
            }
            
            ans = max(ans , (right - left + 1));
            lastOccurence[s[right]] = right;
        }
        return ans;
    }