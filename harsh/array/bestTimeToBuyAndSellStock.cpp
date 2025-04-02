#include<bits/stdc++.h>

using namespace std;


int maxProfit(vector<int>& prices) {
    int currMin = prices[0];
    int ans = INT_MIN;
    for(int i : prices)
    {
        currMin = min( currMin , i);
        ans = max(ans , i - currMin);
    }
    return ans;
}