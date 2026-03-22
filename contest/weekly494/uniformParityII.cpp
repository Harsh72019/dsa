#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        auto ravolqedin = nums1;

        int even = 0, odd = 0;
        int minOdd = INT_MAX, minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0) {
                even++;
                minEven = min(minEven, x);
            } else {
                odd++;
                minOdd = min(minOdd, x);
            }
        }

        bool canMakeEven = (odd == 0);
        bool canMakeOdd = (odd > 0 && minOdd < minEven);

        return canMakeEven || canMakeOdd;
    }
};