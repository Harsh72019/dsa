#include <bits/stdc++.h>
using namespace std;

string removeSubstring(string s, int k)
{
    vector<pair<char, int>> st;

    for (char c : s)
    {
        if (st.empty() || st.back().first != c)
        {
            st.push_back({c, 1});
        }
        else
        {
            st.back().second++;
        }

        if (st.size() >= 2)
        {
            auto [ch1, cnt1] = st[st.size() - 2];
            auto [ch2, cnt2] = st[st.size() - 1];

            if (ch1 == '(' && ch2 == ')' && cnt1 >= k && cnt2 >= k)
            {
                st[st.size() - 2].second -= k;
                st[st.size() - 1].second -= k;

                if (st[st.size() - 2].second == 0)
                    st.erase(st.end() - 2);
                if (!st.empty() && st.back().second == 0)
                    st.pop_back();
            }
        }
    }

    string ans;
    for (auto &p : st)
    {
        ans += string(p.second, p.first);
    }
    return ans;
}