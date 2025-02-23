#include<bits/stdc++.h>
using namespace std;



// Almost similar implemenetation to lowerbound

int searchPosition(vector<int> arr , int target){
    int n = arr.size();
    int low = 0 ; 
    int high = arr.size()-1;
    int ans = arr.size();
    while(low <= high)
    {
        int mid = low + (high - low) /2;
        if(arr[mid] >= target)
        {
            high  = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}