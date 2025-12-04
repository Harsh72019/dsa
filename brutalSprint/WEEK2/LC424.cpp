#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    vector<int> counts(26, 0);
    int left = 0;
    int maxCount = 0;
    int ans = 0;

    for (int right = 0; right < (int)s.size(); ++right)
    {
        counts[s[right] - 'A']++;
        maxCount = max(maxCount, counts[s[right] - 'A']);

        while ((right - left + 1) - maxCount > k)
        {
            counts[s[left] - 'A']--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}