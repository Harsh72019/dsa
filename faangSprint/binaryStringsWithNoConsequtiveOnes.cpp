#include <bits/stdc++.h>
using namespace std;

int total(int n, int prev)
{
    if (n == 0)
        return 1;
    int pickOne = 0;
    if (prev != 1)
        pickOne = total(n - 1, 1);
    int notPickOne = total(n - 1, 0);
    return pickOne + notPickOne;
}

int binaryStringWithNoConsecutive1s(int n)
{
    return total(n, 0);
}