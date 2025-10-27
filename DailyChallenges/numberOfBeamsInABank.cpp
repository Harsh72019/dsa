#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string> &bank)
{
    int currentRow = -1;
    int ans = 0;
    int rows = bank.size();
    int cols = bank[0].size();
    for (int i = 0; i < rows; i++)
    {
        int totalOne = 0;
        for (int j = 0; j < cols; j++)
        {
            if (bank[i][j] == '1')
                totalOne++;
        }
        if (currentRow == -1)
        {
            currentRow = totalOne;
            continue;
        }
        ans += currentRow * totalOne;
        if (totalOne != 0)
            currentRow = totalOne;
    }
    return ans;
}