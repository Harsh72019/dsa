#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ansInx = -1;
        int currMin = INT_MAX;
        for(int i = 0 ; i < capacity.size() ; i++)
        {
            if(itemSize <= capacity[i] && capacity[i] < currMin)
            {
                currMin = capacity[i];
                ansInx = i;
            }
        }
        return ansInx;
    }
};