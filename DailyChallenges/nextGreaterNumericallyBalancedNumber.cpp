#include <bits/stdc++.h>
using namespace std;
// This question taught me to also look at the contraints
bool check(int n)
{
    int v[9] = {0};
    while (n > 0)
    {
        if (n % 10 == 0)
            return false;
        v[n % 10 - 1]++;
        n /= 10;
    }
    for (int i = 0; i < 9; i++)
    {
        if (v[i] > 0 && v[i] != i + 1)
            return false;
    }
    return true;
}
int nextBeautifulNumber(int n)
{
    for (int i = n + 1; i < n * 1000; i++)
    {
        if (check(i))
            return i;
    }
    return n + 1;
}