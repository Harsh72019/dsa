#include <bits/stdc++.h>
using namespace std;

string largestEven(string s)
{
    int n = s.size() - 1;
    while (n >= 0 && s[n] % 2 != 0)
        n--;
    if (n == -1)
        return "";
    string ans = s.substr(0, n + 1);
    return ans;
}