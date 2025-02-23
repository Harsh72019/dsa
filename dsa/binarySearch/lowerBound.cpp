#include<bits/stdc++.h>


using namespace std;

int lowerBound(vector<int> arr , int target)
{
    int ans = arr.size()-1;
    int low = 0;
    int high = ans;
    int mid;
    while(low <= high)
    {
        mid = low + (high - low) /2;
        if(arr[mid] >= target)
        {
            ans = min(ans , mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
            // ans = min(ans , mid);
        }
    }
    return ans;
}

int main() {
    return 1;
}