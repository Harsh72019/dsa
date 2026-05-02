#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s)
    {
        unordered_map<char, int> freq;
        unordered_map<char, int> firstIndex;

        for (int i = 0; i < s.size(); i++)
        {
            if (isVowel(s[i]))
            {
                freq[s[i]]++;
                if (firstIndex.find(s[i]) == firstIndex.end())
                    firstIndex[s[i]] = i;
            }
        }

        vector<char> unique;
        for (auto &p : freq)
        {
            unique.push_back(p.first);
        }

        // Step 3: sort
        sort(unique.begin(), unique.end(), [&](char a, char b)
             {
            if(freq[a] != freq[b])
                return freq[a] > freq[b];
            return firstIndex[a] < firstIndex[b]; });

        string sortedVowels = "";
        for (char c : unique)
        {
            sortedVowels += string(freq[c], c);
        }

        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isVowel(s[i]))
            {
                s[i] = sortedVowels[idx++];
            }
        }

        return s;
    }
};