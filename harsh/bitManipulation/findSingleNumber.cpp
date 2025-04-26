#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int XOR = 0;
    for(int i = 0 ; i<nums.size() ; i++)
        XOR = XOR ^ nums[i];
    return XOR;
}