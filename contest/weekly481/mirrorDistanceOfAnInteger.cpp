#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mirrorDistance(int n)
    {
        int temp = n;
        int reversedNum = 0;
        while (n != 0)
        {
            int rem = n % 10;
            reversedNum = reversedNum * 10 + rem;
            n = n / 10;
        }
        return (int)abs(reversedNum - temp);
    }
};