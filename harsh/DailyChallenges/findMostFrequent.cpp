#include <bits/stdc++.h>
using namespace std;

bool checkVowel(char s)
{
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return true;
    return false;
}
int maxFreqSum(string s)
{
    map<char, int> um;
    for (char c : s)
    {
        um[c]++;
    }
    int voMax = 0;
    int consMax = 0;
    for (auto it : um)
    {
        if (checkVowel(it.first))
            voMax = max(voMax, it.second);
        else
            consMax = max(consMax, it.second);
    }
    return voMax + consMax;
}