#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int , int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int day = 1;
        int total = day;
        while(!st.empty() && st.top().first <= price)
        {
            int value = st.top().second;
            st.pop();
            total+= value;
        }
        st.push({price , total});
        return total;
    }
};
