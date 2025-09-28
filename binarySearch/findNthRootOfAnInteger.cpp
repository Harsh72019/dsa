#include <bits/stdc++.h>
using namespace std;

int calculateSquare(int i, int n)
{
    int ans = 1;
    for (int j = 1; j <= n; j++)
        ans = ans * i;
    return ans;
}
int nthRoot(int n, int m)
{
    int low = 0;
    int high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int squares = calculateSquare(mid, n);
        if (squares == m)
        {
            return mid;
        }
        else if (squares < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}