#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int prefixProduct = 1;
    int suffixProduct = 1;
    int ans = INT_MIN;
    for(int i = 0 ; i < nums.size() ; i++ )
    {
        prefixProduct *= nums[i];
        suffixProduct *= nums[nums.size() - i - 1];
        ans = max(ans , suffixProduct);
        ans = max(ans , prefixProduct);
        if(prefixProduct == 0)
            prefixProduct = 1;
        if(suffixProduct == 0)
            suffixProduct = 1;
    }
    return ans;
}