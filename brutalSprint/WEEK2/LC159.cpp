#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s)
{
    int atMost = 2;
    int left = 0;
    int ans = INT_MIN;
    unordered_map<char, int> counts;
    for (int right = 0; right < s.size(); right++)
    {
        counts[s[right]]++;
        while (left <= right && counts.size() > atMost)
        {
            counts[s[left]]--;
            if (counts[s[left]] == 0)
                counts.erase(s[left]);
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}