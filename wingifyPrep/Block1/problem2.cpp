#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &freq, int k)
{
    int maxElement = *max_element(freq.begin(), freq.end());
    bool isMaxTaken = false;
    int seperateChars = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == maxElement)
        {
            if (!isMaxTaken)
                isMaxTaken = true;
            else
                seperateChars += freq[i];
            continue;
        }
        if (freq[i] != maxElement)
            seperateChars += freq[i];
    }
    return seperateChars <= k;
}
int characterReplacement(string s, int k)
{
    int left = 0;
    vector<int> freq(26, 0);
    int ans = 0;
    for (int right = 0; right < s.size(); right++)
    {
        freq[s[right] - 'A']++;
        while (!check(freq, k))
        {
            freq[s[left] - 'A']--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}