#include<bits/stdc++.h>
using namespace std;

long long divisibleByK(vector<int>& nums, int k) {
    unordered_map<int, long long> freq;
    long long sum = 0;
    long long ans = 0;
    freq[0] = 1;

    for (int x : nums) {
        sum += x;
        int rem = sum % k;
        if (rem < 0) rem += k;

        ans += freq[rem];
        freq[rem]++;
    }
    return ans;
}
int main()
{
    vector<int> arr = {4 ,5 ,0 ,-2 ,-3};
    cout<<divisibleByK(arr , 5);
    return 1;
}