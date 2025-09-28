 #include<bits/stdc++.h>

 using namespace std;
 
 
 vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto i : asteroids) {
            if (i > 0) {
                st.push(i);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(i)) {
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    st.push(i);
                } else if (st.top() == abs(i)) {
                    st.pop(); 
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }