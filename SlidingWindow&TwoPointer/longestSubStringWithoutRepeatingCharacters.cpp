#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int maxLen = 0;
        int start = 0; 

        for(int end = 0; end < s.size(); end++) {
            char c = s[end];
            if(um.find(c) != um.end() && um[c] >= start) {
              
                start = um[c] + 1;
            }
            um[c] = end; 
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
}