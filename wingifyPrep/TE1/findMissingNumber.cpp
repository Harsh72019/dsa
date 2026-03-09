#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + ((right - left) /2);
        if(arr[mid] != mid + 1 && arr[mid-1] == mid)
            return mid + 1;
        if(arr[mid] != mid + 1)
            right = mid - 1;
        else    
            left = mid + 1;
    }
    return -1;
}