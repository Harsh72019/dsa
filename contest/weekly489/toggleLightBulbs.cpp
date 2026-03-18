#include <bits/stdc++.h>
using namespace std;

vector<int> toggleLightBulbs(vector<int> &bulbs)
{
    vector<bool> arr(101, false);
    for (int i = 0; i < bulbs.size(); i++)
    {
        arr[bulbs[i]] = !arr[bulbs[i]];
    }
    vector<int> ans;
    for (int i = 0; i <= 100; i++)
    {
        if (arr[i] == true)
            ans.push_back(i);
    }
    return ans;
}