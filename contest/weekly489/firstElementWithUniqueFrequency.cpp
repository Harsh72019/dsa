#include <bits/stdc++.h>
using namespace std;

int firstUniqueFreq(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (auto it : nums)
    {
        freq[it]++;
    }
    unordered_set<int> st;
    vector<int> toRemove;
    for (auto it : freq)
    {
        if (st.find(it.second) != st.end())
            toRemove.push_back(it.second);
        else
            st.insert(it.second);
    }
    for (auto it : toRemove)
    {
        st.erase(it);
    }

    for (auto it : nums)
    {
        int itFreq = freq[it];
        if (st.find(itFreq) != st.end())
            return it;
    }
    return -1;
}