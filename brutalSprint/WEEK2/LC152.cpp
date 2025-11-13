#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    stack<int> st;
    long long currentProd = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currentProd *= nums[i];
        ans = max(ans, (int)currentProd);

        if (nums[i] == 0)
        {
            // reset after 0
            currentProd = 1;
            while (!st.empty())
                st.pop();
            ans = max(ans, 0);
        }
        else if (currentProd < 0)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int firstNegIdx = st.top();
                long long prodAfterFirstNeg = 1;
                for (int j = firstNegIdx + 1; j <= i; j++)
                {
                    prodAfterFirstNeg *= nums[j];
                }
                ans = max(ans, (int)prodAfterFirstNeg);
            }
        }
        else
        {
            ans = max(ans, (int)currentProd);
        }
    }

    return ans;
}