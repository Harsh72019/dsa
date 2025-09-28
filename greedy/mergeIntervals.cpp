#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        vector<int> currentInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (currentInterval[1] >= intervals[i][0]) { 
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else {
                ans.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }

        ans.push_back(currentInterval);

        return ans;
    }