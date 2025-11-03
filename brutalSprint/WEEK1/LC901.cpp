#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int current = 1;
        while (!st.empty() && st.top().first <= price)
        {
            auto it = st.top();
            current += it.second;
            st.pop();
        }
        st.push({price, current});
        return current;
    }
};
