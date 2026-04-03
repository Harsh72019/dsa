#include <bits/stdc++.h>
using namespace std;

string reversePrefix(string s, int k)
{
    int n = s.size();
    reverse(s.begin(), s.begin() + k);
    return s;
}