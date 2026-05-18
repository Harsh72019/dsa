#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int idx;
        for(idx = 1 ; idx < s.size() ; idx++)
        {
            int prev = s[idx - 1];
            int curr = s[idx];
            if(abs(curr - prev) > 2 )
                return false;
        }
        return true;
    }
};