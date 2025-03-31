#include<bits/stdc++.h>
using namespace std;




vector<int> findTwoElement(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        while(nums[i] != i + 1)
        {
            swap(nums[i] , nums[nums[i] -1 ]);
            if(nums[i] == nums[nums[i] - 1])
            {
                break;
            }
        }
    }
    for(int i = 0 ; i < nums.size() ; i ++)
    {
        if(nums[i] != i + 1)
        {
            ans.push_back(nums[i]);
            ans.push_back(i + 1);
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {11, 1 ,8, 5 ,2 ,4, 5, 7 ,16 ,9, 13, 14, 3 ,17,15 ,6, 12};
    findTwoElement(arr);
    return 1;
}