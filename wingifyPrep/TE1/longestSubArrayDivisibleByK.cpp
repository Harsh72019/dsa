#include<bits/stdc++.h>
using namespace std;

int longestSubArray(vector<int> arr, int k)
{
    int n = arr.size();

    unordered_map<int,int> remIdx;

    int prefixSum = 0;
    int ans = 0;

    remIdx[0] = -1;

    for(int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        int rem = prefixSum % k;

        if(rem < 0)
            rem += k;

        if(remIdx.find(rem) != remIdx.end())
        {
            ans = max(ans, i - remIdx[rem]);
        }
        else
        {
            remIdx[rem] = i;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {4,5,0,-2,-3,1};
    cout<<longestSubArray(arr , 5);
    return 1;
}