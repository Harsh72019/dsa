#include<bits/stdc++.h>
using namespace std;

int validSubArrays(vector<int> & arr , int k )
{
    int n = arr.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    unordered_map<int , int> frequencies;
    for(int right = 0 ; right < n ; right ++)
    {
        int toIncr = arr[right];
        frequencies[toIncr]++;
        while(frequencies[toIncr] > k)
        {
            int toRed = arr[left];
            frequencies[toRed]--;
            left++;
        }
        ans++;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,1,2,3,1,1};
    int ans = validSubArrays(arr , 2);
    cout<<ans;
    return 1;
}