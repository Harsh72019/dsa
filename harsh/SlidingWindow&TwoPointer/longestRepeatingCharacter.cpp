#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s , int k)
{
    int start = 0;
    int maxCount = 0;
    int ans = 0;
    vector<int> count(26, 0);
    for(int end = 0 ; end < s.size() ; end++)
    {
        count[s[end] - 'A']++;
        maxCount = max(maxCount, count[s[end] - 'A']);
        while((end - start + 1) - maxCount > k)
        {
            count[s[start] - 'A']--;
            start++;
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}