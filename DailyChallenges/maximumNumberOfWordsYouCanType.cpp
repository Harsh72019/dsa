#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{
    vector<bool> broken(26, false);
    for (char i : brokenLetters)
    {
        broken[i - 'a'] = true;
    }
    int ans = 0;
    bool doesContains = false;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            if (!doesContains)
            {
                ans++;
            }
            doesContains = false;
        }
        else
        {
            if (broken[text[i] - 'a'])
                doesContains = true;
        }
    }
    if (!doesContains)
        ans++;
    return ans;
}