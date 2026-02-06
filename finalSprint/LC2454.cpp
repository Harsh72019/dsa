#include <bits/stdc++.h>
using namespace std;

vector<int> secondGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);

    stack<int> st1, st2;

    for (int i = 0; i < n; i++)
    {

        while (!st2.empty() && nums[st2.top()] < nums[i])
        {
            ans[st2.top()] = nums[i];
            st2.pop();
        }

        vector<int> temp;
        while (!st1.empty() && nums[st1.top()] < nums[i])
        {
            temp.push_back(st1.top());
            st1.pop();
        }

        for (int j = temp.size() - 1; j >= 0; j--)
        {
            st2.push(temp[j]);
        }

        st1.push(i);
    }

    return ans;
}