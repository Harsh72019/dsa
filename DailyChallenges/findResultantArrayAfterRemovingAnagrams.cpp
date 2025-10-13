#include <bits/stdc++.h>
using namespace std;

vector<string> removeAnagrams(vector<string> &words)
{
    if (words.size() == 1)
        return words;
    vector<string> ans;
    int i = 0;
    int j = 1;
    while (j < words.size())
    {
        string originalWord1 = words[i];
        string originalWord2 = words[j];
        string sortedWord1 = words[i];
        string sortedWord2 = words[j];
        sort(sortedWord1.begin(), sortedWord1.end());
        sort(sortedWord2.begin(), sortedWord2.end());
        if (sortedWord1 == sortedWord2)
        {
            j++;
            if (ans.empty() || ans.back() != originalWord1)
                ans.push_back(originalWord1);
        }
        else
        {
            if (ans.empty() || ans.back() != originalWord1)
                ans.push_back(originalWord1);
            ans.push_back(originalWord2);
            i = j;
            j++;
        }
    }
    return ans;
}