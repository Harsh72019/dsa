#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++)
    {
        int counter = 0;
        int curr = i;
        while (curr != 0)
        {
            int is1 = curr & 1;
            if (is1)
                counter++;
            curr = curr >> 1;
        }
        ans[i] = counter;
    }
    return ans;
}