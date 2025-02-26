#include<bits/stdc++.h>
using namespace std;


bool binarySearch(vector<int> arr , int target)
{
    int low = 0 ;
    int high = arr.size()-1;
    while(low <= high)
    {
        int mid = low + (high-low) /2;
        if(arr[mid] == target)
        {
            return true;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}


int main(){
    vector<int> arr = {1 , 2 , 3 , 4 , 5};
    cout<<binarySearch(arr , 2);
    return 0;
}