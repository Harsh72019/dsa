#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    // int noOfZeros = 0;
    // int mul = 1;
    // for(auto i : nums)
    // {
    //     if(i != 0)
    //         mul *= i;
    //     else
    //         noOfZeros++;
    // }

    // for(int i = 0 ; i < nums.size() ; i++)
    // {

    //     if(noOfZeros == 0)
    //     {
    //         nums[i] = mul / nums[i];
    //     }
    //     else{
    //         if(nums[i] != 0)
    //             nums[i] = 0;
    //         else
    //         {
    //             if(noOfZeros > 1)
    //             {
    //                 nums[i] = 0;
    //             }
    //             else
    //             {
    //                 nums[i] = mul;
    //             }
    //         }
    //     }
    // }
    // return nums;
    int n = nums.size();
    vector<int> ans(n);

    int left = 1 ; int right = 1;
    for(int i = 0 ; i < n ; i ++)
    {
        ans[i] = left;
        left *= nums[i];
    }
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        ans[i] *= right;
        right  *= nums[i];
    }
    return ans;
}