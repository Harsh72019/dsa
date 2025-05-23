#include<bits/stdc++.h>
using namespace std;


 int kDistinctChar(string& s, int k) {
        unordered_map<char , int> count;
        int start = 0;
        int ans = 0;
        for(int end = 0 ; end < s.size() ; end++)
        {
            count[s[end]]++;
            while(count.size() > k)
            {
                count[s[start]]--;
                if(count[s[start]] == 0)
                {
                    count.erase(s[start]);
                }
            }
            ans = max(ans , end - start + 1);
        }
        return ans;
    }