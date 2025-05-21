#include<bits/stdc++.h>
using namespace std;

 int totalFruits(vector<int>& fruits) {
        unordered_map<int, int> count;  
        int start = 0, maxLen = 0;

        for (int end = 0; end < fruits.size(); ++end) {
            count[fruits[end]]++;

            
            while (count.size() > 2) {
                count[fruits[start]]--;
                if (count[fruits[start]] == 0)
                    count.erase(fruits[start]);
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }