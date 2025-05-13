#include<bits/stdc++.h>
using namespace std;


    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0 , rightMax = 0;
        int totalWaterTrapped = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    totalWaterTrapped += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if(height[right] >= rightMax )
                {
                    rightMax = height[right];
                }
                else
                {
                    totalWaterTrapped += rightMax - height[right];
                }
                right--;
            }
        }
        return totalWaterTrapped;
}
