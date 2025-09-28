#include<bits/stdc++.h>

using namespace std;

 vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> um;

        for(auto i : nums)
        {
            um[i]++;
        }

        priority_queue<pair<int , int>> pq;

        for(auto i : um)
        {
            pq.push({i.second , i.first});
        }

        vector<int> ans;

        for(int i = 0 ; i < k ; i++)
        {
            auto j = pq.top();
            ans.push_back(j.second);
            pq.pop();
        }
        return ans;
    }