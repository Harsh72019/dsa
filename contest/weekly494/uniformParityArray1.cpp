#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, odd = 0;

        for (int x : nums1) {
            if (x % 2 == 0) even++;
            else odd++;
        }

        bool canEven = (even > 0) || (odd > 1);
        bool canOdd = (even > 0 && odd > 0);

        return canEven || canOdd;
    }
};