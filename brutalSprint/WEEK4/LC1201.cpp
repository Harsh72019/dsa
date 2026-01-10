#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcd(long long x, long long y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }

    long long lcm(long long x, long long y)
    {
        return (x / gcd(x, y)) * y;
    }

    int nthUglyNumber(int n, int a, int b, int c)
    {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);

        long long left = 1;
        long long right = (long long)n * min({a, b, c});

        while (left < right)
        {
            long long mid = left + (right - left) / 2;

            long long count =
                mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;

            if (count < n)
                left = mid + 1;
            else
                right = mid;
        }

        return (int)left;
    }
};
