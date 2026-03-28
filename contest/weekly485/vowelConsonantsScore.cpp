#include <bits/stdc++.h>
using namespace std;

bool isVowel(char i)
{
    if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
        return true;
    return false;
}
int vowelConsonantScore(string s)
{
    int c = 0;
    int v = 0;
    for (char i : s)
    {
        if (isalpha(i))
        {
            if (isVowel(i))
                v++;
            else
                c++;
        }
    }
    if (c == 0)
        return 0;
    int ans = v / c;
    return ans;
}