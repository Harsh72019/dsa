#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    bool canPlace(vector<int> &stalls , int k , int dis)
    {
        int lastPosition = stalls[0];
        int cowsUsed = 1;
        for(int i = 1 ; i < stalls.size() ; i++)
        {
            if(stalls[i] - lastPosition >= dis)
            {
                cowsUsed++;
                lastPosition = stalls[i];
            }
        }
        return cowsUsed >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin() , stalls.end());
        int left = 1;
        int right = *max_element(stalls.begin() , stalls.end());
        while(left <= right)
        {
            int mid = left + ((right - left) / 2);
            if(canPlace(stalls , k , mid))
            {   
                left  = mid + 1;   
            }
            else
            {
                right = mid - 1;
            }
        }
        return right;
    }
};