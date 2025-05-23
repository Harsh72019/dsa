#include<bits/stdc++.h>

using namespace std;


int findKRotation(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;

while (low < high) {
   int mid = low + (high - low) / 2;
   
   if (nums[mid] > nums[high]) {
       low = mid + 1;
   } else {
       high = mid;
   }
}

return low;
}