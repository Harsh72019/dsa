#include <bits/stdc++.h>
using namespace std;

int smallestNumber(int n)
{
    int i = 0;
    int num = 0;
    while (num < n)
    {
        num += pow(2, i);
        i++;
    }
    return num;
}