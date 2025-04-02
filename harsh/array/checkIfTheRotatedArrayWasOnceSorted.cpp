#include<bits/stdc++.h>
using namespace std;
// This was my solution which i came up with okayish but not optimal
bool check(vector<int>& nums) {
    int n = nums.size() - 1;
    int indexToCheck = -1;
  
    for(int i = 1; i <= n ; i ++)
    {
        if(nums[i-1] > nums[i])
        {
            indexToCheck = i;
            break;
        }
    }
   
    if(indexToCheck == -1)
        return true;
    int lastCheckedElement = nums[indexToCheck];
    for(int i = indexToCheck +1  ; i <= n ; i ++)
    {
        if( nums[i - 1 ] > nums[i])
            return false;
        else
            lastCheckedElement = nums[i];
    }
  
    for(int i = 0 ; i < indexToCheck ; i ++)
    {
        if(i == 0)
        {
            if(nums[i] < lastCheckedElement)
                return false;
        }
        else if(nums[i-1] > nums[i])
            return false;
    }
    return true;
}

// This is the optimal code which i understood that if the order breaks more than one time simply return false
bool checkOptimal(vector<int>& nums) {
    int n = nums.size();
    int count = 0 ;
    for(int i = 0 ; i < n ;i ++)
    {
        if(nums[i] > nums[(i + 1) % n ])
            count++;
        if(count > 1)
            return false;
    }   
    return true;
}

int main()
{
    cout<<"Inside Main" <<endl;
    vector<int> arr = {1,2,3};
    cout<<check(arr)<<"Answer"<<endl;
    return 1;
}