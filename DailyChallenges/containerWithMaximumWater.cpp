#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int ans = -1;
    while (i <= j)
    {
        int currentArea = (min(height[i], height[j])) * (j - i);
        ans = max(ans, currentArea);
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return ans;
}