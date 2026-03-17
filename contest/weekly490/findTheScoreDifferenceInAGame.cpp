#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreDifference(vector<int> &nums)
    {
        int firstScore = 0;
        int secondScore = 0;
        bool isFirstPlayerTurn = true;
        for (int i = 0; i < nums.size(); i++)
        {
            isFirstPlayerTurn = nums[i] % 2 != 0 ? !isFirstPlayerTurn : isFirstPlayerTurn;
            isFirstPlayerTurn = (i + 1) % 6 == 0 ? !isFirstPlayerTurn : isFirstPlayerTurn;
            if (isFirstPlayerTurn)
                firstScore += nums[i];
            else
                secondScore += nums[i];
        }
        return firstScore - secondScore;
    }
};