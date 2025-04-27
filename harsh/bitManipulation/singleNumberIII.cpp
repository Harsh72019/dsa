#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int xorr = 0;
    for (auto i : nums) {
        xorr ^= i;
    }

    int rightMost = xorr & (-(unsigned int)xorr); 
    int num1 = 0, num2 = 0;

    for (auto i : nums) {
        if (i & rightMost)
            num1 ^= i;
        else
            num2 ^= i;
    }

    return {num1, num2};
}
