#include <bits/stdc++.h>
using namespace std;

int residuePrefixes(string s)
{
    set<char> dis;
    int total = 0;
    for (int i = 0; i < s.size(); i++)
    {
        dis.insert(s[i]);
        if ((float)((i + 1) % 3) == (float)dis.size())
            total++;
    }

    return total;
}