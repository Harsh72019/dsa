#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> arr , int mid , int k )
{
    int currentSum = 0;
    int usedBoards = 1;
    for(auto i : arr)
    {
        if(currentSum + i > mid)
        {
            currentSum = i;
            usedBoards++;
            if(usedBoards > k)
                return false;
        }
        else
            currentSum += i;
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin() , boards.end());
    int high = accumulate(boards.begin() , boards.end() , 0);
    int ans = high;
    while(low <= high)
    {
        int mid = low + (high - low) /2;
        if(check(boards , mid , k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}