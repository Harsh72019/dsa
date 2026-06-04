#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<int> memo;
public:
    int solver(int index, vector<int>& prices) {
        if (index >= prices.size()) {
            return 0;
        }
        
        if (memo[index] != -1) {
            return memo[index];
        }

        int maxFreeIdx = 2 * index + 1;
        int minCostNext = INT_MAX;
        
        for (int nextIdx = index + 1; nextIdx <= maxFreeIdx + 1; ++nextIdx) {
            minCostNext = min(minCostNext, solver(nextIdx, prices));
        }
        
        return memo[index] = prices[index] + minCostNext;
    }

    int minimumCoins(vector<int>& prices) {
        memo.assign(prices.size(), -1);
        return solver(0, prices);
    }
};





class Solution {
public:
    void solver(int index, vector<int>& prices, vector<bool>& canGetFree, int &ans, int cost) {
        if (index >= prices.size()) {
            ans = min(ans, cost);
            return;
        }
        
        if (canGetFree[index]) {
            solver(index + 1, prices, canGetFree, ans, cost);
        }
        
        int lastFreeIdx = min((int)prices.size() - 1, 2 * index + 1);
        
        vector<bool> originalState = canGetFree; 
        
        fill(canGetFree.begin() + index + 1, canGetFree.begin() + lastFreeIdx + 1, true);
        
        solver(index + 1, prices, canGetFree, ans, cost + prices[index]);
        
        canGetFree = originalState;
    }

    int minimumCoins(vector<int>& prices) {
        int ans = INT_MAX;
        vector<bool> canGetFree(prices.size(), false);
        solver(0, prices, canGetFree, ans, 0);
        return ans;
    }
};