#include<bits/stdc++.h>
using namespace std;
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin() , nums.end());
            vector<vector<int>> ans;
            
            for(int i = 0 ; i < nums.size() ; i++)
            {
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                int left = i + 1;
                int right = nums.size()-1 ;
                while(left< right)
                {
                    int sum = nums[i] + nums[left] + nums[right];
                    if(sum == 0)
                    {
                        ans.push_back({nums[i] , nums[left] , nums[right]});
                        left++;
                        right --;
                        while(left < right && nums[left-1] == nums[left]) left++;
                        while(right >  left && nums[right] == nums[right +1 ] ) right--;
                    }
                    else if(sum > 0)
                    {
                        right--;
                    }
                    else
                    {
                        left++;    
                    }
                }
            }
            return ans;
        }

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = threeSum(nums);
    
    cout << "Triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    
    return 0;
}
