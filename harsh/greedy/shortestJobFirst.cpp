#include<bits/stdc++.h>
using namespace std;

 long long solve(vector<int>& bt) {
        long long length = bt.size();
        long long total = 0;
        long long waitTime = 0;
        sort(bt.begin() , bt.end());
        for(auto i : bt)
        {
          waitTime += total;
          total += i;
        }
        return (long long )( waitTime / length);
    }